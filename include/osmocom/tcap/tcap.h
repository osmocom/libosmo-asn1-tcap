/* libosmo-asn1-tcap public API */
#pragma once

#include <stdint.h>
#include <unistd.h>

#include <osmocom/tcap/TCAP_TCMessage.h>

void *osmo_asn1_tcap_set_talloc_ctx(void *tall_ctx);

int osmo_asn1_tcap_decode(struct TCAP_TCMessage *tcapmsg, const uint8_t *data, size_t data_len);

void osmo_asn1_tcap_TCMessage_free_contents(struct TCAP_TCMessage *tcapmsg);
