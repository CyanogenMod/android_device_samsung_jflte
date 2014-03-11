/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm.h"

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    UNUSED(msm_id);
    UNUSED(msm_ver);
    UNUSED(board_type);

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    property_get("ro.bootloader", bootloader);

    if (strstr(bootloader, "I337M")) {
        /* jfltecan */
        property_set("ro.build.fingerprint", "samsung/jfltevl/jfltecan:4.2.2/JDQ39/I337MVLUAMDJ:user/release-keys");
        property_set("ro.build.description", "jfltevl-user 4.2.2 JDQ39 I337MVLUAMDJ release-keys");
        property_set("ro.product.model", "SGH-I337M");
        property_set("ro.product.device", "jfltecan");
        property_set("telephony.lteOnGsmDevice", "1");
        property_set("ro.telephony.default_network", "9");
    } else if (strstr(bootloader, "I337")) {
        /* jflteatt */
        property_set("ro.product.device", "jflteatt");
        property_set("ro.product.model", "SAMSUNG-SGH-I337");
        property_set("ro.build.fingerprint", "samsung/jflteuc/jflteatt:4.4.2/KOT49H/I337UCUFNB1:user/release-keys");
        property_set("ro.build.description", "jflteuc-user 4.4.2 KOT49H I337UCUFNB1 release-keys");
        property_set("telephony.lteOnGsmDevice", "1");
        property_set("ro.telephony.default_network", "9");
    } else if (strstr(bootloader, "R970C")) {
        /* jfltecri */
        property_set("ro.build.fingerprint", "samsung/jfltecri/jfltecri:4.2.2/JDQ39/R970CVVUAME4:user/release-keys");
        property_set("ro.build.description", "jfltecri-user 4.2.2 JDQ39 R970CVVUAME4 release-keys");
        property_set("ro.product.model", "SCH-R970C");
        property_set("ro.product.device", "jfltecri");
        property_set("ro.telephony.default_cdma_sub", "0");
        property_set("ro.telephony.ril.v3", "newDriverCallU");
        property_set("telephony.lteOnCdmaDevice", "1");
        property_set("ro.telephony.default_network", "8");
    } else if (strstr(bootloader, "R970X")) {
        /* jfltecsp */
        property_set("ro.build.fingerprint", "samsung/jfltecsp/jfltecsp:4.2.2/JDQ39/R970XWWUAMFA:user/release-keys");
        property_set("ro.build.description", "jfltecsp-user 4.2.2 JDQ39 R970XWWUAMFA release-keys");
        property_set("ro.product.model", "SCH-R970X");
        property_set("ro.product.device", "jfltecsp");
        property_set("ro.telephony.default_cdma_sub", "0");
        property_set("ro.telephony.ril.v3", "newDriverCallU");
        property_set("telephony.lteOnCdmaDevice", "1");
        property_set("ro.telephony.default_network", "8");
        property_set("telephony.sms.pseudo_multipart", "1");
    } else if (strstr(bootloader, "L720")) {
        /* jfltespr */
        property_set("ro.build.fingerprint", "samsung/jfltespr/jfltespr:4.2.2/JDQ39/L720VPUAMDL:user/release-keys");
        property_set("ro.build.description", "jfltespr-user 4.2.2 JDQ39 L720VPUAMDL release-keys");
        property_set("ro.product.model", "SPH-L720");
        property_set("ro.product.device", "jfltespr");
        property_set("ro.telephony.ril.v3", "newDriverCallU");
        property_set("telephony.lteOnCdmaDevice", "1");
        property_set("ro.telephony.default_network", "8");
        property_set("telephony.sms.pseudo_multipart", "1");
    } else if (strstr(bootloader, "M919")) {
        /* jfltetmo */
        property_set("ro.build.fingerprint", "samsung/jfltetmo/jfltetmo:4.3/JSS15J/M919UVUEMK2:user/release-keys");
        property_set("ro.build.description", "jfltetmo-user 4.3 JSS15J M919UVUEMK2 release-keys");
        property_set("ro.product.model", "SGH-M919");
        property_set("ro.product.device", "jfltetmo");
        property_set("telephony.lteOnGsmDevice", "1");
        property_set("ro.telephony.default_network", "9");
    } else if (strstr(bootloader, "R970")) {
        /* jflteusc */
        property_set("ro.build.fingerprint", "samsung/jflteusc/jflteusc:4.2.2/JDQ39/R970VXUAMD9:user/release-keys");
        property_set("ro.build.description", "jflteusc-user 4.2.2 JDQ39 R970VXUAMD9 release-keys");
        property_set("ro.product.model", "SCH-R970");
        property_set("ro.product.device", "jflteusc");
        property_set("ro.telephony.default_cdma_sub", "0");
        property_set("ro.telephony.ril.v3", "newDriverCallU");
        property_set("telephony.lteOnCdmaDevice", "1");
        property_set("ro.telephony.default_network", "8");
        property_set("telephony.sms.pseudo_multipart", "1");
    } else if (strstr(bootloader, "I545")) {
        /* jfltevzw */
        property_set("ro.build.fingerprint", "Verizon/jfltevzw/jfltevzw:4.3/JSS15J/I545VRUEMK2:user/release-keys");
        property_set("ro.build.description", "jfltevzw-user 4.3 JSS15J I545VRUEMK2 release-keys");
        property_set("ro.product.model", "SCH-I545");
        property_set("ro.product.device", "jfltevzw");
        property_set("ro.telephony.default_cdma_sub", "0");
        property_set("ro.telephony.ril.v3", "newDriverCallU");
        property_set("ro.cdma.home.operator.alpha", "Verizon");
        property_set("ro.cdma.home.operator.numeric", "311480");
        property_set("telephony.lteOnCdmaDevice", "1");
        property_set("ro.telephony.default_network", "10");
    } else if (strstr(bootloader, "I9505G")) {
        /* jgedlte */
        property_set("ro.build.fingerprint", "samsung/jgedlteue/jgedlte:4.4.2/KOT49H.S001/131204:user/release-keys");
        property_set("ro.build.description", "jgedlteue-user 4.4.2 KOT49H.S001 131204 release-keys");
        property_set("ro.product.model", "GT-I9505G");
        property_set("ro.product.device", "jgedlte");
        property_set("telephony.lteOnGsmDevice", "1");
        property_set("ro.telephony.default_network", "9");
    } else if (strstr(bootloader, "I9505")) {
        /* jfltexx */
        property_set("ro.build.fingerprint", "samsung/jfltexx/jflte:4.2.2/JDQ39/I9505XXUAMDE:user/release-keys");
        property_set("ro.build.description", "jfltexx-user 4.2.2 JDQ39 I9505XXUAMDE release-keys");
        property_set("ro.product.model", "GT-I9505");
        property_set("ro.product.device", "jfltexx");
        property_set("telephony.lteOnGsmDevice", "1");
        property_set("ro.telephony.default_network", "9");
    } else if (strstr(bootloader, "I9508")) {
        /* jfltezm */
        property_set("ro.build.fingerprint", "samsung/jfltezm/jflte:4.2.2/JDQ39/I9508ZMUAMG1:user/release-keys");
        property_set("ro.build.description", "jfltezm-user 4.2.2 JDQ39 I9508ZMUAMG1 release-keys");
        property_set("ro.product.model", "GT-I9508");
        property_set("ro.product.device", "jfltezm");
        property_set("telephony.lteOnGsmDevice", "1");
        property_set("ro.telephony.default_network", "9");
    }

    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    ERROR("Found bootloader id %s setting build properties for %s device\n", bootloader, devicename);
}
