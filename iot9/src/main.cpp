#include <Arduino.h>
#include "DHT.h"

#define DHTPIN 27     
#define DHTTYPE DHT22   

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx Sensor Test"));
  dht.begin();
}

void loop() {
  delay(500);

  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature();    // Temperature in Celsius
  float tempF = dht.readTemperature(true); // Temperature in Fahrenheit

  // Cek apakah pembacaan sensor gagal
  if (isnan(humidity) || isnan(tempC) || isnan(tempF)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Hitung heat index
  float heatIndexF = dht.computeHeatIndex(tempF, humidity);
  float heatIndexC = dht.computeHeatIndex(tempC, humidity, false);

  // Tampilkan hasil pembacaan sensor
  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(tempC);
  Serial.print(F("°C "));
  Serial.print(tempF);
  Serial.print(F("°F  Heat index: "));
  Serial.print(heatIndexC);
  Serial.print(F("°C "));
  Serial.print(heatIndexF);
  Serial.println(F("°F"));
}
