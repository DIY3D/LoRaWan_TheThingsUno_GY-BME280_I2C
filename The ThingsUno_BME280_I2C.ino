#include <TheThingsNetwork.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Set your AppEUI and AppKey
const char *appEui = "70B3D57EF....etc...etc."; //find this key in TTN Console 
const char *appKey = "8B428345212F795EF93194..etc...etc."; //find this key in TTN Console

#define SEALEVELPRESSURE_HPA (1013.25) 
#define loraSerial Serial1
#define debugSerial Serial

// Replace REPLACE_ME with TTN_FP_EU868 or TTN_FP_US915
#define freqPlan TTN_FP_EU868

Adafruit_BME280 bme;

TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);

void setup() {
   
  debugSerial.begin(9600);
  loraSerial.begin(57600);

  if (!bme.begin(0x76)) {
    debugSerial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
  
  // Wait a maximum of 10s for Serial Monitor
  while (!debugSerial && millis() < 10000);
    
  debugSerial.println("-- STATUS");
  ttn.showStatus();

  debugSerial.println("-- JOIN");
  ttn.join(appEui, appKey);
  
}
void loop() {

  debugSerial.println("-- LOOP");

    uint32_t temperature = bme.readTemperature() * 100;
    uint32_t humidity = bme.readHumidity() * 100;
    uint32_t pressure = bme.readPressure()  / 100;
    uint32_t altitude = (bme.readAltitude(SEALEVELPRESSURE_HPA));

    byte payload[6];
    payload[0] = (temperature >> 8) & 0xFF;
    payload[1] = temperature & 0xFF;
    payload[2] = (pressure >>8) & 0xFF;
    payload[3] = pressure & 0xFF;
    payload[4] = (humidity >> 8) & 0xFF;
    payload[5] = humidity & 0xFF;

    
  ttn.sendBytes(payload, sizeof(payload)); 
  
  delay(10000);   
}

