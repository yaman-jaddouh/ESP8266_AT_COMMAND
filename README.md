**ESP8266 Embedded Wi-Fi Serial Communication Module**
|PINS| Details  |
|--|--|
| 5V|  Connect to 5v power|
| GND | GND |
| TX| Connect it to the RX of MCU |
| RX| Connect it to the TX of MCU |
| G0| NC |

**Note**: when you powered the module make sure that G0 pin not connected to anything .

Please visit the [channel](https://t.me/ESP8266_AT) to see all update and upgrade Developed by Yaman jaddouh
**Explanations**
you can use this module without need to code it just see the commands and communicate with it .

 -  use http request with two methods (GET,POST).
 -  use filesystem with the module using Write , Read or Add.(512KB)
 -  use ESP-NOW protocol to fast communicate with two modules 
-  update the frameware without need to re-programmed the module , just use ***UPDATE*** command 


**Command List**
| Commands  ||||
|--|--|--|-
|WICON|WISTA|WIIP|BAUD
|HTGET|HTPOST|VERSION|RESET
|DEFUALT|CHECKUPDATE|UPDATE|FSREAD
|FSREMOVE|FSLIST|FSADD|FSWRITE
|MACADDR|NOWINIT|NOWDEINIT|NOWADD
|NOWSEND|

full explanation can found in [URL](https://github.com/yaman-jaddouh/ESP8266_AT_COMMAND/blob/c2007f5adf6f493788e2e5063b34595fe1ae4245/ESP8266%20AT%20command.pdf)

