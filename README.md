# LoRaWan_TheThingsUno_GY-BME280_I2C

This is a basic Arduinocode for the BMPE280 (temperature/humidity/pressure and altitude sensor) with The Things Uno.
There is also a Payload converter you can copy to:

Your TTN Console --> Applications --> YourApplication --> Devices --> Payload Formats. 


The Wire library for your Uno is bundled with Arduino AVR Boards. You can verify that you have the latest version of Arduino AVR Boards by doing this:

Tools > Board > Boards Manager
Wait for download to finish
Click on "Arduino AVR Boards"
If you see an "Update" button appear then you don't have the latest version installed. If you don't see an "Update" button then you already have the latest version installed.

There are several BME280 library's avialable. Here we use 2 Adafruit  library's. You can find them:

Adafruit_Sensor.h:
https://github.com/adafruit/Adafruit_Sensor

Adafruit_BME280.h:
https://github.com/adafruit/Adafruit_BME280_Library

The GY-BME280 is in I2C mode and has the following PinSetting:

GY-BME280_I2C----------------------------The ThingsUno
  
	Vcc					3.3V
	Gnd					Gnd 
	SCL					SCL
	SDA 					SDA
