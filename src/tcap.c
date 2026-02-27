/* libosmo-asn1-tcap public API */
/* (C) 2025 by sysmocom s.f.m.c. GmbH <info@sysmocom.de>
 * All Rights Reserved
 *
 * SPDX-License-Identifier: GPL-2.0+
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdint.h>
#include <unistd.h>
#include <errno.h>

#include <osmocom/tcap/asn_codecs.h>
#include <osmocom/tcap/TCAP_TCMessage.h>

__thread void *tcap_talloc_asn1_ctx;

int osmo_asn1_tcap_decode(struct TCAP_TCMessage *tcapmsg, const uint8_t *data, size_t data_len)
{

	asn_dec_rval_t asn_rc;

	memset(tcapmsg, 0, sizeof(struct TCAP_TCMessage));

	asn_rc = ber_decode(0, &asn_DEF_TCAP_TCMessage, (void **)&tcapmsg, data, data_len);
	if (asn_rc.code != RC_OK)
		return -EINVAL;
	return 0;
}

int osmo_asn1_tcap_TCMessage_decode(struct TCAP_TCMessage *tcapmsg, const uint8_t *data, size_t data_len, void *talloc_ctx)
{
	int rc;
	tcap_talloc_asn1_ctx = talloc_ctx;
	rc = osmo_asn1_tcap_decode(tcapmsg, data, data_len);
	tcap_talloc_asn1_ctx = NULL;
	return rc;
}

void osmo_asn1_tcap_TCMessage_free_contents(struct TCAP_TCMessage *tcapmsg)
{
	ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_TCAP_TCMessage, tcapmsg);
}
