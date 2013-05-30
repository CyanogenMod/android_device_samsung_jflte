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

egrep -q -f /tmp/valid_bootloaders /proc/cmdline
if [ $? -eq 0 ];then
  mkdir -p $C
  dd if=/dev/block/platform/msm_sdcc.1/by-name/aboot of=$C/aboot.img
  /tmp/loki_patch boot $C/aboot.img /tmp/boot.img $C/boot.lok || exit 1
  /tmp/loki_flash boot $C/boot.lok || exit 1
  rm -rf $C
else
  echo '[*] Non-Loki bootloader version detected.'
  dd if=/tmp/boot.img of=/dev/block/mmcblk0p20 || exit 1
fi

exit 0
