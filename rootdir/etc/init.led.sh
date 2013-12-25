#!/system/bin/sh

# prevent boot led from overriding charging led
if [ `cat /sys/class/power_supply/battery/charge_now` = "0" ]; then
    echo 0 > /sys/class/sec/led/led_pattern
fi
