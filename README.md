libosmo-asn1-tcap
=================

This repository contains C-language routing to encode and decode TCAP (ITU Q.771-Q.775).

Homepage
--------

The official homepage of the project is
https://gitea.osmocom.org/ss7-in-c/libosmo-asn1-tcap/

GIT Repository
--------------

You can clone from the official osmo-cbc.git repository using

	git clone https://gitea.osmocom.org/ss7-in-c/libosmo-asn1-tcap/

There is a web interface at <https://gitea.osmocom.org/ss7-in-c/libosmo-asn1-tcap/>

Mailing List
------------

Discussions related to osmo-cbc are happening on the
openbsc@lists.osmocom.org mailing list, please see
https://lists.osmocom.org/mailman/listinfo/openbsc for subscription
options and the list archive.

Please observe the [Osmocom Mailing List
Rules](https://osmocom.org/projects/cellular-infrastructure/wiki/Mailing_List_Rules)
when posting.

Contributing
------------

Our coding standards are described at
https://osmocom.org/projects/cellular-infrastructure/wiki/Coding_standards

We use a Gerrit based patch submission/review process for managing
contributions.  Please see
https://osmocom.org/projects/cellular-infrastructure/wiki/Gerrit for
more details

The current patch queue for libosmo-asn1-tcap can be seen at
https://gerrit.osmocom.org/#/q/project:libosmo-asn1-tcap+status:open


Generating asn1c code
---------------------

The upstream fork maintained by a big contributor
[mouse07410](https://github.com/mouse07410/asn1c) of asn1c is used to generate
TCAP code from from ASN.1 files present in src/sbcap/asn1/.

In order to regenerate the code, one shall adjust the ASN1C_SKELETON_PATH and
ASN1C_BIN_PATH in configure.ac to point to the built & installed asn1c from
mouse07410 (usually `vlm_master` branch). Last generated code was built using
commit hash 2c065550a5a0d08636cad64f4b067c1dcba2f339.

Then, do the usual `autoreconf -fi && ./configure`, using a buildir != srcdir
(important, in order to avoid ending up with temporary files in srcdir and
making it difficult to stash the relevant changes).

Finally, run `make -C src/ regen`, which will regenerate the files and copy over
the skeletons, with git possibly showing changes in the following paths:
- include/osmocom/tcap/
- src/gen/
- src/skel/
