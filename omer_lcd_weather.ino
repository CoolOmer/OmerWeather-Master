/*
 *  Author: Syed Omer Hassan
 *  Date: January 12th, 2024
 *  Description: Onto the next part! After my first sketch worked,
 *  I made this duplicate of my initial sketch BUT this time the DHT11
 *  will print the temps and humidity levels to my LCD 16x2 display! I
 *  also heavily modified this program to include an "alarm" whenever
 *  any of the following conditions are true (see "if" and "else if" below).
 */

// Include libraries and define
// pin, as well as sensor type.
#include <Wire.h>  
#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 6  // The digital pin 6
                  // is what I'll use.

#define DHTTYPE DHT11  // Clarifying the sensor
                       // model that I'm using.

DHT dht(DHTPIN, DHTTYPE);

//testing?
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int humidtempBuzz = 9;

void setup() {
  
  lcd.begin(16, 2);  //Starts the LCD 16x2 display
  dht.begin();       //as well as the DHT11 sensor.

  pinMode(humidtempBuzz, OUTPUT);  //Set buzzer as output.

}

void loop() {

 delay(1500);
  float h = dht.readHumidity();      // Humidity, Regular: 40%
  float t = dht.readTemperature();   // Celcius, Regular 20C

  if (isnan(h) || isnan(t)) {
   lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("Error Found!");
   delay(1000);
   return;
  }

  lcd.clear();

  lcd.setCursor(0, 0);    //This part of the loop simply
  lcd.print(h);           //prints the humidity and temp
  lcd.print(" % ");       //on the bottom row of the LCD.

  lcd.setCursor(0, 1);
  lcd.print(t);
  lcd.print(" C");

  // **************************************
  // ***** ALL POSSIBLE CONDITIONS ***** //
  // **************************************
  if ((h >= 61) && (t >= 5) && (t <= 35)) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(h);
    lcd.print(" % ");
    lcd.print(" Too Humid!");

    lcd.setCursor(0,1);
    lcd.print(t);
    lcd.print(" C");

    tone(humidtempBuzz, 1000);   // Send 1KHz sound signal...
    delay(500);                  // ...for 0.5 secs
    noTone(humidtempBuzz);       // Stop sound...
    delay(200);                  // ...for 0.2 secs
  }

  else if ((h <= 29) && (t >= 5) && (t <= 35)) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(h);
    lcd.print(" % ");
    lcd.print(" Too Dry!");

    lcd.setCursor(0,1);
    lcd.print(t);
    lcd.print(" C");

    tone(humidtempBuzz, 1000);   // Send 1KHz sound signal...
    delay(500);                  // ...for 0.5 secs
    noTone(humidtempBuzz);       // Stop sound...
    delay(200);                  // ...for 0.2 secs
  }

  else if ((t <= 4) && (h >= 30) && (h <= 60)) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(h);
    lcd.print(" % ");

    lcd.setCursor(0,1);
    lcd.print(t);
    lcd.print(" C");
    lcd.print(" Too Cold! ");

    tone(humidtempBuzz, 1000);   // Send 1KHz sound signal...
    delay(500);                  // ...for 0.5 secs
    noTone(humidtempBuzz);       // Stop sound...
    delay(500);                  // ...for 0.5 secs
  }

  else if ((t >= 36) && (h >= 30) && (h <= 60)) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(h);
    lcd.print(" % ");

    lcd.setCursor(0,1);
    lcd.print(t);
    lcd.print(" C");
    lcd.print(" Too Hot! ");

    tone(humidtempBuzz, 1000);   // Send 1KHz sound signal...
    delay(500);                  // ...for 0.5 secs
    noTone(humidtempBuzz);       // Stop sound...
    delay(500);                  // ...for 0.5 secs
  }

  else if ((t >= 36) && (h >= 61)) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(h);
    lcd.print(" % ");
    lcd.print(" Too Humid! ");

    lcd.setCursor(0,1);
    lcd.print(t);
    lcd.print(" C");
    lcd.print(" Too Hot! ");

    tone(humidtempBuzz, 1000);   // Send 1KHz sound signal...
    delay(500);                  // ...for 0.5 secs
    noTone(humidtempBuzz);       // Stop sound...
    delay(500);                  // ...for 0.5 secs
  }

  else if ((t >= 36) && (h <= 29)) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(h);
    lcd.print(" % ");
    lcd.print(" Too Dry! ");

    lcd.setCursor(0,1);
    lcd.print(t);
    lcd.print(" C");
    lcd.print(" Too Hot! ");

    tone(humidtempBuzz, 1000);   // Send 1KHz sound signal...
    delay(500);                  // ...for 0.5 secs
    noTone(humidtempBuzz);       // Stop sound...
    delay(500);                  // ...for 0.5 secs
  }

  else if ((t <= 4) && (h <= 29)) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(h);
    lcd.print(" % ");
    lcd.print(" Too Dry! ");

    lcd.setCursor(0,1);
    lcd.print(t);
    lcd.print(" C");
    lcd.print(" Too Cold! ");

    tone(humidtempBuzz, 1000);   // Send 1KHz sound signal...
    delay(500);                  // ...for 0.5 secs
    noTone(humidtempBuzz);       // Stop sound...
    delay(500);                  // ...for 0.5 secs
  }

  else if ((t <= 4) && (h >= 61)) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(h);
    lcd.print(" % ");
    lcd.print(" Too Humid! ");

    lcd.setCursor(0,1);
    lcd.print(t);
    lcd.print(" C");
    lcd.print(" Too Cold! ");

    tone(humidtempBuzz, 1000);   // Send 1KHz sound signal...
    delay(500);                  // ...for 0.5 secs
    noTone(humidtempBuzz);       // Stop sound...
    delay(500);                  // ...for 0.5 secs
  }

  else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(h);
    lcd.print(" % ");

    lcd.setCursor(0,1);
    lcd.print(t);
    lcd.print(" C");
  }
    delay(1000);
}
