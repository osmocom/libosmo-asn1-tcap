/* libosmo-asn1-tcap public API */
#pragma once

#include <stdint.h>
#include <unistd.h>

#include <osmocom/tcap/TCAP_TCMessage.h>

int osmo_asn1_tcap_decode(struct TCAP_TCMessage *tcapmsg, const uint8_t *data, size_t data_len) OSMO_DEPRECATED("Use osmo_asn1_tcap_TCMessage_decode() instead");

int osmo_asn1_tcap_TCMessage_decode(struct TCAP_TCMessage *tcapmsg, const uint8_t *data, size_t data_len, void *talloc_ctx);

void osmo_asn1_tcap_TCMessage_free_contents(struct TCAP_TCMessage *tcapmsg);
