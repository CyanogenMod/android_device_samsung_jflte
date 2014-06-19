#!/system/bin/sh
#
# This leverages the loki_patch utility created by djrbliss
# See here for more information on loki: https://github.com/djrbliss/loki
#

export C=/data/local/tmp/loki_tmpdir
RECSIZE=$1
RECSHA1=$2
BOOTSIZE=$3
BOOTSHA1=$4

mkdir -p $C

egrep -q -f /system/etc/loki_bootloaders /proc/cmdline
if [ $? -eq 0 ]; then
  need_lok=1
fi

if ! applypatch -c EMMC:$C/recovery.img:$RECSIZE:$RECSHA1; then
  log -t recovery "Installing new recovery image"

  if [ $need_lok -eq 1 ]; then
    dd if=/dev/block/platform/msm_sdcc.1/by-name/aboot of=$C/aboot.img
    dd if=/dev/block/platform/msm_sdcc.1/by-name/recovery of=$C/recovery.lok
    dd if=/dev/block/platform/msm_sdcc.1/by-name/boot of=$C/boot.lok
    /system/bin/loki_tool unlok $C/recovery.lok $C/recovery.img
    /system/bin/loki_tool unlok $C/boot.lok $C/boot.img
  else
    dd if=/dev/block/platform/msm_sdcc.1/by-name/boot of=$C/boot.img
  fi

  applypatch -b /system/etc/recovery-resource.dat EMMC:$C/boot.img:$BOOTSIZE:$BOOTSHA1 EMMC:$C/recovery.img $RECSHA1 $RECSIZE $BOOTSHA1:/system/recovery-from-boot.p || exit 1

  if [ $need_lok -eq 1 ]; then
    /system/bin/loki_tool patch recovery $C/aboot.img $C/recovery.img $C/recovery.lok || exit 1
    /system/bin/loki_tool flash recovery $C/recovery.lok || exit 1
  else
    dd if=/tmp/boot.img of=/dev/block/platform/msm_sdcc.1/by-name/recovery
  fi
else
  log -t recovery "Recovery image already installed"
fi

rm -rf $C
exit 0
