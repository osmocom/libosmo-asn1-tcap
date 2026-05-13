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

struct testvector {
	const char *name;
	const unsigned char *vector;
	size_t vector_len;
};
static struct testvector testvectors[] = {
	{ .name = "Begin", .vector = pkt_begin, .vector_len = sizeof(pkt_begin) },
};

int main(int argc, char **argv)
{
	asn_dec_rval_t rc;

	printf("Basic TCAP decode testing.\n");
	struct TCAP_TCMessage _tcapmsg = {};

	for (int i = 0; i < ARRAY_SIZE(testvectors); i++) {
		struct TCAP_TCMessage *tcapmsg = &_tcapmsg;
		memset(tcapmsg, 0, sizeof(*tcapmsg));
		printf("Decoding testvector no %d - %s\n", i, testvectors[i].name);

		rc = ber_decode(0, &asn_DEF_TCAP_TCMessage, (void **)&tcapmsg, testvectors[i].vector, testvectors[i].vector_len);
		if (rc.code != RC_OK)
			printf("Broken decoding %u at byte %lu\n", rc.code, rc.consumed);
		else
			asn_fprint(stdout, &asn_DEF_TCAP_TCMessage, tcapmsg);

		ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_TCAP_TCMessage, tcapmsg);
	}

	uint8_t buf[] = {0x00, 0x01, 0x02, 0x03};

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

	printf("All tests passed.\n");
	return 0;
}
