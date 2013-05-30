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

export C=/tmp/loki_tmpdir

egrep -q -f /system/etc/valid_bootloaders /proc/cmdline
if [ $? -eq 0 ];then
  mkdir -p $C
  dd if=/dev/block/platform/msm_sdcc.1/by-name/aboot of=$C/aboot.img
  /system/bin/loki_patch boot $C/aboot.img /tmp/boot.img $C/boot.lok || exit 1
  /system/bin/loki_flash boot $C/boot.lok || exit 1
  rm -rf $C
fi

exit 0
