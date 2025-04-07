# ESP8266_ESP-IDF_DS18B20

Stand alone implementation of a DS18B20 interface using the ESP-IDF framework on an ESP8266

## Status

* 2025-04-06 "hello world" example working
* Code from @aZholtikov builds but does not detect devices.

## 2025-04-06 Plan

Follow along with the instructions at <https://github.com/HankB/Fun_with_ESP8266/tree/main/SDK_bare> to build a test bed for DS18B20 drivers. Output will be to the serial monitor - no WiFi will be employed.

## 2025-04-06 steps

```text
. ~/Programming/ESP8266/Fun_with_ESP8266/esp-idf/bin/activate # or wherever your venv is located
echo $IDF_PATH # Verify that IDF_PATH is set
cp -r $IDF_PATH/examples/get-started/hello_world/* . #Copy project files
# Except for the README!
cat $IDF_PATH/examples/get-started/hello_world/README.md
export PATH="$PATH:$HOME/esp/xtensa-lx106-elf/bin" # add to PATH if needed
make menuconfig
make
make flash monitor
```

Contents of `hello_world` README.md

```text
# Hello World Example

Starts a FreeRTOS task to print "Hello World"

See the README.md file in the upper level 'examples' directory for more information about examples.
```

No changes for `make menuconfig` (for now) - just save and exit. And it works. Output (excluding restart countdown)

```text

 ets Jan  8 2013,rst cause:2, boot mode:(3,7)

load 0x40100000, len 7544, room 16 
tail 8
chksum 0xc3
load 0x3ffe8408, len 24, room 0 
tail 8
chksum 0x4a
load 0x3ffe8420, len 3468, room 0 
tail 12
chksum 0x47
csum 0x47
I (83) boot: ESP-IDF v3.4-104-g2f586ea4 2nd stage bootloader
I (83) boot: compile time 13:05:56
I (85) qio_mode: Enabling default flash chip QIO
I (100) boot: SPI Speed      : 40MHz
I (113) boot: SPI Mode       : QIO
I (125) boot: SPI Flash Size : 2MB
I (138) boot: Partition Table:
I (149) boot: ## Label            Usage          Type ST Offset   Length
I (172) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (195) boot:  1 phy_init         RF data          01 01 0000f000 00001000
I (219) boot:  2 factory          factory app      00 00 00010000 000f0000
I (242) boot: End of partition table
I (255) esp_image: segment 0: paddr=0x00010010 vaddr=0x40210010 size=0x1cc54 (117844) map
0x40210010: _stext at ??:?

I (338) esp_image: segment 1: paddr=0x0002cc6c vaddr=0x4022cc64 size=0x06d9c ( 28060) map
I (352) esp_image: segment 2: paddr=0x00033a10 vaddr=0x3ffe8000 size=0x00544 (  1348) load
I (360) esp_image: segment 3: paddr=0x00033f5c vaddr=0x40100000 size=0x00080 (   128) load
I (388) esp_image: segment 4: paddr=0x00033fe4 vaddr=0x40100080 size=0x0512c ( 20780) load
I (424) boot: Loaded app from partition at offset 0x10000
Hello world!
This is ESP8266 chip with 1 CPU cores, WiFi, silicon revision 1, 2MB external flash
```

## 2025-04-06 find a driver

* <https://pdacontrolen.com/esp32-ds18b20-sensor-on-esp-idf-temperature-onewire/> ESP32 but worth a shot. Nope. Fails right off the bat.
* <https://github.com/aZholtikov/zh_ds18b20> requires <https://github.com/aZholtikov/zh_onewire> Files build. Runs but does not detect any onewire devices.
* <https://github.com/electronicayciencia/esp8266-learning/tree/main/ds1820> No devices then crashes. :-/
