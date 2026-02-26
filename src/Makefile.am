AM_CFLAGS = -I$(top_srcdir)/include/ -I$(top_srcdir)/src/skel $(ASN_MODULE_CFLAGS) $(TALLOC_CFLAGS)

SKEL_SRC = \
	skel/ANY.c \
	skel/ANY_ber.c \
	skel/BIT_STRING.c \
	skel/BIT_STRING_print.c \
	skel/BIT_STRING_rfill.c \
	skel/GraphicString.c \
	skel/INTEGER.c \
	skel/INTEGER_ber.c \
	skel/INTEGER_print.c \
	skel/INTEGER_rfill.c \
	skel/NULL.c \
	skel/NULL_ber.c \
	skel/NULL_print.c \
	skel/NULL_rfill.c \
	skel/NativeInteger.c \
	skel/NativeInteger_ber.c \
	skel/NativeInteger_print.c \
	skel/NativeInteger_rfill.c \
	skel/OBJECT_IDENTIFIER.c \
	skel/OBJECT_IDENTIFIER_print.c \
	skel/OBJECT_IDENTIFIER_rfill.c \
	skel/OCTET_STRING.c \
	skel/OCTET_STRING_ber.c \
	skel/OCTET_STRING_print.c \
	skel/OCTET_STRING_rfill.c \
	skel/OPEN_TYPE.c \
	skel/OPEN_TYPE_ber.c \
	skel/ObjectDescriptor.c \
	skel/asn_SEQUENCE_OF.c \
	skel/asn_SET_OF.c \
	skel/asn_application.c \
	skel/asn_bit_data.c \
	skel/asn_codecs_prim.c \
	skel/asn_codecs_prim_ber.c \
	skel/asn_internal.c \
	skel/asn_random_fill.c \
	skel/ber_decoder.c \
	skel/ber_tlv_length.c \
	skel/ber_tlv_tag.c \
	skel/constraints.c \
	skel/constr_CHOICE.c \
	skel/constr_CHOICE_ber.c \
	skel/constr_CHOICE_print.c \
	skel/constr_CHOICE_rfill.c \
	skel/constr_SEQUENCE.c \
	skel/constr_SEQUENCE_OF.c \
	skel/constr_SEQUENCE_OF_ber.c \
	skel/constr_SEQUENCE_ber.c \
	skel/constr_SEQUENCE_print.c \
	skel/constr_SEQUENCE_rfill.c \
	skel/constr_SET_OF.c \
	skel/constr_SET_OF_ber.c \
	skel/constr_SET_OF_print.c \
	skel/constr_SET_OF_rfill.c \
	skel/constr_TYPE.c \
	skel/der_encoder.c \
	$(NULL)

GEN_SRC = \
	gen/TCAP_AARE-apdu.c \
	gen/TCAP_AARQ-apdu.c \
	gen/TCAP_ABRT-apdu.c \
	gen/TCAP_ABRT-source.c \
	gen/TCAP_AUDT-apdu.c \
	gen/TCAP_Abort.c \
	gen/TCAP_Associate-result.c \
	gen/TCAP_Associate-source-diagnostic.c \
	gen/TCAP_Begin.c \
	gen/TCAP_Component.c \
	gen/TCAP_ComponentPortion.c \
	gen/TCAP_Continue.c \
	gen/TCAP_DestTransactionID.c \
	gen/TCAP_Dialog1.c \
	gen/TCAP_DialoguePDU.c \
	gen/TCAP_DialoguePortion.c \
	gen/TCAP_ERROR.c \
	gen/TCAP_EXTERNAL.c \
	gen/TCAP_End.c \
	gen/TCAP_ErrorCode.c \
	gen/TCAP_ExternalPDU.c \
	gen/TCAP_GeneralProblem.c \
	gen/TCAP_Invoke.c \
	gen/TCAP_InvokeIdType.c \
	gen/TCAP_InvokeProblem.c \
	gen/TCAP_OPERATION.c \
	gen/TCAP_OrigTransactionID.c \
	gen/TCAP_Parameter.c \
	gen/TCAP_P-AbortCause.c \
	gen/TCAP_RLRE-apdu.c \
	gen/TCAP_RLRQ-apdu.c \
	gen/TCAP_Reason.c \
	gen/TCAP_Reject.c \
	gen/TCAP_Release-request-reason.c \
	gen/TCAP_Release-response-reason.c \
	gen/TCAP_ReturnError.c \
	gen/TCAP_ReturnErrorProblem.c \
	gen/TCAP_ReturnResult.c \
	gen/TCAP_ReturnResultProblem.c \
	gen/TCAP_TCMessage.c \
	gen/TCAP_UniDialoguePDU.c \
	gen/TCAP_Unidirectional.c \
	$(NULL)

ASN_MODULE_SRC = \
	$(GEN_SRC) \
	$(SKEL_SRC) \
	$(NULL)

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
	TCAP_RLRQ-apdu.h \
	TCAP_Component.h \
	TCAP_Parameter.h \
	TCAP_TCMessage.h \
	TCAP_ComponentPortion.h \
	TCAP_OrigTransactionID.h \
	TCAP_Associate-result.h \
	TCAP_AUDT-apdu.h \
	TCAP_GeneralProblem.h \
	TCAP_Begin.h \
	TCAP_DialoguePDU.h \
	TCAP_Release-response-reason.h \
	TCAP_ExternalPDU.h \
	TCAP_AARQ-apdu.h \
	TCAP_Continue.h \
	TCAP_asn_constant.h \
	TCAP_DialoguePortion.h \
	TCAP_InvokeIdType.h \
	TCAP_UniDialoguePDU.h \
	TCAP_End.h \
	TCAP_ReturnResult.h \
	TCAP_Abort.h \
	TCAP_Dialog1.h \
	TCAP_OPERATION.h \
	TCAP_Reject.h \
	TCAP_Invoke.h \
	TCAP_ReturnError.h \
	TCAP_Release-request-reason.h \
	TCAP_Reason.h \
	TCAP_ReturnErrorProblem.h \
	TCAP_ABRT-apdu.h \
	TCAP_ERROR.h \
	TCAP_AARE-apdu.h \
	TCAP_DestTransactionID.h \
	TCAP_ErrorCode.h \
	TCAP_Unidirectional.h \
	TCAP_ABRT-source.h \
	TCAP_InvokeProblem.h \
	TCAP_ReturnResultProblem.h \
	TCAP_P-AbortCause.h \
	TCAP_EXTERNAL.h \
	TCAP_RLRE-apdu.h \
	TCAP_Associate-source-diagnostic.h \
	$(NULL)

ASN_MODULE_INC = \
	$(SKEL_HEADER_FILES) \
	$(GEN_HEADER_FILES) \
	$(NULL)

# This is _NOT_ the library release version, it's an API version.
# Please read Chapter 6 "Library interface versions" of the libtool
# documentation before making any modification
LIBVERSION=1:0:0

libosmo_asn1_tcap_la_LDFLAGS = -version-info $(LIBVERSION) -no-undefined -export-symbols-regex '^osmo_'

libosmo_asn1_tcap_la_LIBADD = $(TALLOC_LIBS)

libosmo_asn1_tcap_la_SOURCES =	\
	tcap.c \
	$(ASN_MODULE_SRC)

lib_LTLIBRARIES=libosmo-asn1-tcap.la

regen: regenerate-from-asn1-source

regenerate-from-asn1-source:
	rm -f $(top_srcdir)/src/gen/*.c
# Remove all .h files except our tcap.h:
	find $(top_srcdir)/include/osmocom/tcap/ -type f -name '*.h' -type f -not -name 'tcap.h' -delete
	ASN1C_PREFIX="TCAP_" ${ASN1C_BIN_PATH} \
		-S $(ASN1C_SKELETON_PATH) \
		-D $(top_srcdir)/src/gen \
		-fcompound-names \
		-gen-BER \
		-no-gen-APER \
		-no-gen-XER \
		-no-gen-JER \
		-no-gen-OER \
		-no-gen-UPER \
		-no-gen-example \
		$(top_srcdir)/asn/DialoguePDUs.asn \
		$(top_srcdir)/asn/tcap.asn \
		$(top_srcdir)/asn/UnidialoguePDUs.asn \
		$(NULL)
# Remove comments with paths
	for i in $(top_srcdir)/src/gen/*; do \
		sed -i \
			-e '/^ \*.*found in "/d' \
			-e '/^ \*.*`asn1c -S/d' \
			$$i; \
	done
# Move *.h files (skeleton and generated) to include/osmocom/tcap and adjust
# #include <...> in *.c and *.h files
	cd $(top_srcdir)/src/gen && \
		../../move-asn1-header-files.sh osmocom/tcap $(ASN_MODULE_INC)
#Patch mem alloc defines to use talloc:
	sed -i "s/#define\tASN_INTERNAL_H/#define\tASN_INTERNAL_H\n#include <talloc.h>/g" $(top_srcdir)/include/osmocom/tcap/asn_internal.h
	sed -i "s/#define\tCALLOC/extern void *tcap_talloc_asn1_ctx;\n#define\tCALLOC/g" $(top_srcdir)/include/osmocom/tcap/asn_internal.h
	sed -i "s/calloc(nmemb, size)/talloc_zero_size(tcap_talloc_asn1_ctx, (nmemb) * (size))/g" $(top_srcdir)/include/osmocom/tcap/asn_internal.h
	sed -i "s/malloc(size)/talloc_size(tcap_talloc_asn1_ctx, size)/g" $(top_srcdir)/include/osmocom/tcap/asn_internal.h
	sed -i "s/realloc(oldptr, size)/talloc_realloc_size(tcap_talloc_asn1_ctx, oldptr, size)/g" $(top_srcdir)/include/osmocom/tcap/asn_internal.h
	sed -i "s/free(ptr)/talloc_free(ptr)/g" $(top_srcdir)/include/osmocom/tcap/asn_internal.h
# Move skeleton *.c files to src/skel
	rm -rf $(top_srcdir)/src/skel
	mkdir $(top_srcdir)/src/skel
	for i in $(top_srcdir)/src/gen/*; do \
		case $$i in \
		*/TCAP_*) \
			;; \
		*.c) \
			mv -v "$$i" $(top_srcdir)/src/skel/ \
			;; \
		esac; \
	done
# Remove files we don't need
	rm $(top_srcdir)/src/gen/Makefile.am.libasncodec
