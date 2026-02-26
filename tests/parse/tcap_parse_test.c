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


static const unsigned char pkt1[] = {0x62, 0x06, 0x48, 0x04, 0x00, 0x01, 0x02, 0x03};

static int write_stream(const void *buffer, size_t size, void *key)
{
	uint8_t *buf = (uint8_t *)buffer;
	for (int i = 0; i < size; i++)
		printf("%02X ", buf[i]);
	printf("\n");
	return 0;
}

int main(int argc, char **argv)
{
	asn_dec_rval_t rc;
	struct TCAP_TCMessage *tcapmsg;
	tcapmsg = CALLOC(1, sizeof(*tcapmsg));

	printf("Basic TCAP decode testing.\n");

	rc = ber_decode(0, &asn_DEF_TCAP_TCMessage, (void **)&tcapmsg, pkt1, sizeof(pkt1));
	if (rc.code != RC_OK)
		printf("Broken encoding %u at byte %lu\n", rc.code, rc.consumed);

	asn_fprint(stdout, &asn_DEF_TCAP_TCMessage, tcapmsg);
	ASN_STRUCT_FREE(asn_DEF_TCAP_TCMessage, tcapmsg);


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
