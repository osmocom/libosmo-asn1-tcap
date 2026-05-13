/* TCAP parsing tests */
#include <complex.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

#include <osmocom/tcap/asn_codecs.h>
#include <osmocom/tcap/constr_TYPE.h>
#include <osmocom/tcap/OCTET_STRING.h>
#include <osmocom/tcap/ber_decoder.h>

#include <osmocom/tcap/asn_internal.h>
#include <osmocom/tcap/TCAP_TCMessage.h>
#include <osmocom/tcap/TCAP_OrigTransactionID.h>
#include <stdlib.h>

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#endif /* ARRAY_SIZE */

static int write_stream(const void *buffer, size_t size, void *key)
{
	uint8_t *buf = (uint8_t *)buffer;
	for (int i = 0; i < size; i++)
		printf("%02X ", buf[i]);
	printf("\n");
	return 0;
}

/* Transaction Capabilities Application Part
 *     begin
 *         Destination Transaction ID
 *             dtid: 00010203
 */
static const unsigned char pkt_begin[] = { 0x62, 0x06, 0x48, 0x04, 0x00, 0x01, 0x02, 0x03 };

/* Transaction Capabilities Application Part
 *     end
 *         Destination Transaction ID
 *             dtid: 7fc2923a
 */
static const unsigned char pkt_end[] = { 0x64, 0x06, 0x49, 0x04, 0x7f, 0xc2, 0x92, 0x3a };

/* TCAP End, dtid 0xc9143d64
 * Transaction Capabilities Application Part
 *     end
 *         Destination Transaction ID
 *             dtid: c9143d64
 *         oid: 0.0.17.773.1.1.1 (id-as-dialogue)
 *         dialogueResponse
 *             Padding: 7
 *             protocol-version: 80
 *                 1... .... = version1: True
 *             application-context-name: 0.4.0.0.1.0.1.3 (networkLocUpContext-v3)
 *             result: accepted (0)
 *             result-source-diagnostic: dialogue-service-user (1)
 *                 dialogue-service-user: null (0)
 */
static const unsigned char pkt_end_dialog[] = {
	0x64, 0x32, 0x49, 0x04, 0xc9, 0x14, 0x3d, 0x64, 0x6b, 0x2a, 0x28, 0x28,
	0x06, 0x07, 0x00, 0x11, 0x86, 0x05, 0x01, 0x01, 0x01, 0xa0, 0x1d, 0x61,
	0x1b, 0x80, 0x02, 0x07, 0x80, 0xa1, 0x09, 0x06, 0x07, 0x04, 0x00, 0x00,
	0x01, 0x00, 0x01, 0x03, 0xa2, 0x03, 0x02, 0x01, 0x00, 0xa3, 0x05, 0xa1,
	0x03, 0x02, 0x01, 0x00 };

/* TCAP End, dtid 0xc9143d64
 * Transaction Capabilities Application Part
 *     end
 *         Destination Transaction ID
 *             dtid: c9143d64
 *         oid: 0.0.17.773.1.1.1 (id-as-dialogue)
 *         components: 1 item
 * GSM Mobile Application
 *     Component: returnError (3)
 *         returnError
 *             invokeID: 1
 *             errorCode: localValue (0)
 *                 localValue: roamingNotAllowed (8)
 *             roamingNotAllowedCause: plmnRoamingNotAllowed (0)
 */
static const unsigned char pkt_end_component[] = {
	0x64, 0x15, 0x49, 0x04, 0xc9, 0x14, 0x3d, 0x64, 0x6c, 0x0d, 0xa3, 0x0b,
	0x02, 0x01, 0x01, 0x02, 0x01, 0x08, 0x30, 0x03, 0x0a, 0x01, 0x00 };

/* TCAP End, dtid 0xc9143d64
 * Transaction Capabilities Application Part
 *     end
 *         Destination Transaction ID
 *             dtid: c9143d64
 *         oid: 0.0.17.773.1.1.1 (id-as-dialogue)
 *         dialogueResponse
 *             Padding: 7
 *             protocol-version: 80
 *                 1... .... = version1: True
 *             application-context-name: 0.4.0.0.1.0.1.3 (networkLocUpContext-v3)
 *             result: accepted (0)
 *             result-source-diagnostic: dialogue-service-user (1)
 *                 dialogue-service-user: null (0)
 *         components: 1 item
 * GSM Mobile Application
 *     Component: returnError (3)
 *         returnError
 *             invokeID: 1
 *             errorCode: localValue (0)
 *                 localValue: roamingNotAllowed (8)
 *             roamingNotAllowedCause: plmnRoamingNotAllowed (0)
 */

static const unsigned char pkt_end_dialog_component[] = {
	0x64, 0x41, 0x49, 0x04, 0xc9, 0x14, 0x3d, 0x64, 0x6b, 0x2a, 0x28, 0x28,
	0x06, 0x07, 0x00, 0x11, 0x86, 0x05, 0x01, 0x01, 0x01, 0xa0, 0x1d, 0x61,
	0x1b, 0x80, 0x02, 0x07, 0x80, 0xa1, 0x09, 0x06, 0x07, 0x04, 0x00, 0x00,
	0x01, 0x00, 0x01, 0x03, 0xa2, 0x03, 0x02, 0x01, 0x00, 0xa3, 0x05, 0xa1,
	0x03, 0x02, 0x01, 0x00, 0x6c, 0x0d, 0xa3, 0x0b, 0x02, 0x01, 0x01, 0x02,
	0x01, 0x08, 0x30, 0x03, 0x0a, 0x01, 0x00 };

struct testvector {
	const char *name;
	const unsigned char *vector;
	size_t vector_len;
};
static struct testvector testvectors[] = {
	{ .name = "Begin", .vector = pkt_begin, .vector_len = sizeof(pkt_begin) },
	{ .name = "End", .vector = pkt_end, .vector_len = sizeof(pkt_end) },
	{ .name = "End with Dialog", .vector = pkt_end_dialog, .vector_len = sizeof(pkt_end_dialog) },
	{ .name = "End with Component", .vector = pkt_end_component, .vector_len = sizeof(pkt_end_component) },
	{ .name = "End with Dialog & Component", .vector = pkt_end_dialog_component, .vector_len = sizeof(pkt_end_dialog_component) },
};

static int encode_tests(void)
{
	uint8_t buf[] = {0x00, 0x01, 0x02, 0x03};

	printf("Basic TCAP encode testing.\n");

	struct TCAP_TCMessage msg = {
		.present = TCAP_TCMessage_PR_begin,
		.choice.begin = {
			.otid = {
				.buf = buf,
				.size = 4,
			},
		},
	};

	der_encode(&asn_DEF_TCAP_TCMessage, &msg, write_stream, NULL);
	return 0;
}

static int decode_tests(void)
{
	int ret = 0;
	asn_dec_rval_t rc;

	printf("Basic TCAP decode testing.\n");
	struct TCAP_TCMessage _tcapmsg = {};

	for (int i = 0; i < ARRAY_SIZE(testvectors); i++) {
		printf("Decoding testvector no %d - %s\n", i, testvectors[i].name);
		struct TCAP_TCMessage *tcapmsg = &_tcapmsg;

		memset(tcapmsg, 0, sizeof(*tcapmsg));
		rc = ber_decode(0, &asn_DEF_TCAP_TCMessage, (void **)&tcapmsg, testvectors[i].vector, testvectors[i].vector_len);
		if (rc.code != RC_OK) {
			ret = 1;
			printf("Broken decoding %u at byte %lu\n", rc.code, rc.consumed);
		} else
			asn_fprint(stdout, &asn_DEF_TCAP_TCMessage, tcapmsg);

		ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_TCAP_TCMessage, tcapmsg);
	}

	return ret;
}

int main(int argc, char **argv)
{
	if (decode_tests())
		return 1;

	if (encode_tests())
		return 1;

	printf("All tests passed.\n");
	return 0;
}
