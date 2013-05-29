#!/sbin/sh
#
# This leverages the loki_patch utility created by djrbliss which allows us
# to bypass the bootloader checks on jfltevzw and jflteatt
# See here for more information on loki: https://github.com/djrbliss/loki
#
#
# Run loki patch on boot images with certain bootloaders
#
# Valid bootloaders found in valid_bootloaders file

cat /proc/cmdline | egrep -q -f /system/etc/valid_bootloaders
if [ $? = 0 ];
    then
       cd /tmp
       chmod 777 loki_patch
       dd if=/dev/block/platform/msm_sdcc.1/by-name/aboot of=aboot.img
       ./loki_patch boot aboot.img boot.img boot.lok
        dd if=/tmp/boot.lok of=/dev/block/platform/msm_sdcc.1/by-name/boot

# cleanup
       rm /system/bin/loki_patch
       rm /system/etc/valid_bootloaders
       rm /system/bin/loki.sh
fi
