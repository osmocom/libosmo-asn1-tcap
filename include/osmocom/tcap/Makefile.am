SKEL_HEADER_FILES = \
	ANY.h \
	BIT_STRING.h \
	GraphicString.h \
	INTEGER.h \
	NULL.h \
	NativeInteger.h \
	OBJECT_IDENTIFIER.h \
	OCTET_STRING.h \
	OPEN_TYPE.h \
	ObjectDescriptor.h \
	asn_SEQUENCE_OF.h \
	asn_SET_OF.h \
	asn_application.h \
	asn_bit_data.h \
	asn_codecs.h \
	asn_codecs_prim.h \
	asn_config.h \
	asn_internal.h \
	asn_ioc.h \
	asn_random_fill.h \
	asn_system.h \
	ber_decoder.h \
	ber_tlv_length.h \
	ber_tlv_tag.h \
	constraints.h \
	constr_CHOICE.h \
	constr_SEQUENCE.h \
	constr_SEQUENCE_OF.h \
	constr_SET_OF.h \
	constr_TYPE.h \
	der_encoder.h \
	$(NULL)

GEN_HEADER_FILES = \
	TCAP_AARE-apdu.h \
	TCAP_AARQ-apdu.h \
	TCAP_ABRT-apdu.h \
	TCAP_ABRT-source.h \
	TCAP_AUDT-apdu.h \
	TCAP_Abort.h \
	TCAP_Associate-result.h \
	TCAP_Associate-source-diagnostic.h \
	TCAP_Begin.h \
	TCAP_Component.h \
	TCAP_ComponentPortion.h \
	TCAP_Continue.h \
	TCAP_DestTransactionID.h \
	TCAP_Dialog1.h \
	TCAP_DialoguePDU.h \
	TCAP_DialoguePortion.h \
	TCAP_ERROR.h \
	TCAP_EXTERNAL.h \
	TCAP_End.h \
	TCAP_ErrorCode.h \
	TCAP_ExternalPDU.h \
	TCAP_GeneralProblem.h \
	TCAP_Invoke.h \
	TCAP_InvokeIdType.h \
	TCAP_InvokeProblem.h \
	TCAP_OPERATION.h \
	TCAP_OrigTransactionID.h \
	TCAP_Parameter.h \
	TCAP_P-AbortCause.h \
	TCAP_RLRE-apdu.h \
	TCAP_RLRQ-apdu.h \
	TCAP_Reason.h \
	TCAP_Reject.h \
	TCAP_Release-request-reason.h \
	TCAP_Release-response-reason.h \
	TCAP_ReturnError.h \
	TCAP_ReturnErrorProblem.h \
	TCAP_ReturnResult.h \
	TCAP_ReturnResultProblem.h \
	TCAP_TCMessage.h \
	TCAP_UniDialoguePDU.h \
	TCAP_Unidirectional.h \
	TCAP_asn_constant.h \
	$(NULL)

version.h: version.h.tpl
	$(AM_V_GEN)$(MKDIR_P) $(dir $@)
	$(AM_V_GEN)sed \
		-e "s/{{VERSION}}/$$(echo '@VERSION@' | cut -d. -f1-3)/g" \
		-e "s/{{VERSION_MAJOR}}/$$(echo '@VERSION@' | cut -d. -f1)/g" \
		-e "s/{{VERSION_MINOR}}/$$(echo '@VERSION@' | cut -d. -f2)/g" \
		-e "s/{{VERSION_PATCH}}/$$(echo '@VERSION@' | cut -d. -f3)/g" \
		$< > $@

BUILT_SOURCES = \
	version.h \
	$(NULL)

EXTRA_DIST = \
	     version.h.tpl \
	     $(NULL)

osmo_asn1_tcap_HEADERS = \
	$(SKEL_HEADER_FILES) \
	$(GEN_HEADER_FILES) \
	version.h \
	$(NULL)

osmo_asn1_tcapdir = $(includedir)/osmocom/tcap
