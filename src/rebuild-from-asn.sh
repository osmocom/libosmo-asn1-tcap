#!/bin/bash
ASN=../asn
asn1c $ASN/DialoguePDUs.asn $ASN/tcap.asn $ASN/UnidialoguePDUs.asn 
find . -type l -exec rm \{\} \;
mv *.h ../include/
