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

**Upload your own code**
if  you can make your own code  and upload to ESP8266 instead of using the AT command follow this step : 

 1. write your code in Arduino IDE choosing **NodeMCU(ESP-12E)** board
 2. bring your USB to TTL converter
 3. connect G0 pin to GND before you connect the supply to enter the ESP8266 in programming mode.
 4. follow this connection after ensuring step 3 is done 
 
|TTL|ESP  |
|--|--|
| 5V | 5V |
| GND | GND |
| TX | RX |
| RX | TX |
 5. click upload code in Arduino IDE then disconnect the G0 from the GND then restart the ESP8266 
 
 **NOTE:** every time you want to upload the code, make the steps above
**NOTE:** if your upload your own code you will lost the AT Command functionality

