/*
 *  Author: Syed Omer Hassan
 *  Date: January 11th, 2024
 *  Description: This program I made is essentially the "stepping stone"
 *  for my final project! This program uses the DHT11 temp / humidity
 *  sensor to print out the temps and humidity to the SerialMonitor.
 *  When I see that my program works, I will integrate it into the LCD.
 */


// Include libraries and define
// pin, as well as sensor type.
#include "DHT.h"
#define DHTPIN 6  // The digital pin 6
                  // is what I'll use.

#define DHTTYPE DHT11   // Clarifying the sensor
                        // model that I'm using.


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);                     // Start SerialMonitor
  Serial.println("Initializing DH11!");   // to print statements.

  dht.begin();   // Similar format as SerialMonitor command,
                 // except this is exclusively for initializing
                 // my DHT11 module and starts sensing surroundings.
}

void loop() {
  
  delay(2000);
 
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  

  if (isnan(h) || isnan(t) || isnan(f)) {                 // This will essentially notify me that
    Serial.println("Uh-oh, can't read anything ...");     // there's some issue reading from the
    return;                                               // the sensor, if everything equals to zero.
  }

  Serial.print("Humidity: ");     // This will simply print the humidity
  Serial.print(h);                // and temperature to the SerialMonitor
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");

}
