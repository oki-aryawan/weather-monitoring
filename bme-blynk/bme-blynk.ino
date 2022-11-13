#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;

char auth[] = "xxxxx";
char ssid[] = "xxxxx";
char pass[] = "xxxxx";

BlynkTimer timer;

void setup() {
  if (!bme.begin(0x76)) {
    Serial.println("Error, check wiring!");
    while (1);
  }
    Blynk.begin(auth, ssid, pass);

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}

void loop() {

    Blynk.run();
  timer.run();
}

void sendSensor()
{
  //don't send more that 10 values per second.
  Blynk.virtualWrite(V5, bme.readTemperature());
  Blynk.virtualWrite(V6, bme.readPressure());
  Blynk.virtualWrite(V7, bme.readAltitude(SEALEVELPRESSURE_HPA);
  Blynk.virtualWrite(V8, bme.readHumidity();
}