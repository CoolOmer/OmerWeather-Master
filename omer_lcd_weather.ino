/*
 *  Author: Syed Omer Hassan
 *  Date: January 12th, 2024
 *  Description: Onto the next part! After my first sketch worked,
 *  I made this duplicate of my initial sketch BUT this time the DHT11
 *  will print the temps and humidity levels to my LCD 16x2 display! I
 *  also heavily modified this program to include an "alarm" whenever
 *  any of the following conditions are true (see "if" and "else if" below).
 *  
 *  Jan 13th: Successfully managed to print to the LCD using sensor stats!
 *  Jan 14th: Added all the extra conditions to trigger the alarm system.
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

//Defining the LCD1602's associated pins and connections.
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int humidtempBuzz = 9;

void setup() {
  
  lcd.begin(16, 2);  //Starts the LCD 16x2 display
  dht.begin();       //as well as the DHT11 sensor.

  pinMode(humidtempBuzz, OUTPUT);  //Set buzzer as output.

}

void loop() {

 delay(1000);
  float h = dht.readHumidity();      // Humidity, Regular: 40%
  float t = dht.readTemperature();   // Celcius, Regular 20C

  if (isnan(h) || isnan(t)) {     // "isnan" refers to no reading
   lcd.clear();                   // from the temperature sensor,
   lcd.setCursor(0, 0);           // so ideally this statement
   lcd.print("Error Found!");     // should never print.
   delay(1000);
   return;
  }

  lcd.clear();

  lcd.setCursor(0, 0);    //This part of the loop simply
  lcd.print(h);           //prints the humidity and temp
  lcd.print(" % ");       //on the bottom row of the LCD.

  lcd.setCursor(0, 1);
  lcd.print(t);
  lcd.print(" C ");

  // **************************************
  // ***** ALL POSSIBLE CONDITIONS ***** //
  // **************************************
  if ((h >= 61) && (t >= 5) && (t <= 35)) {    // This part of the loop will sound
    lcd.clear();                               // the alarm and print "too humid!"
    lcd.setCursor(0,0);                        // if "h >= 61," "t >=5," and "t <= 35."
    lcd.print(h);
    lcd.print(" % ");
    lcd.print("Too Humid!");

    lcd.setCursor(0,1);
    lcd.print(t);
    lcd.print(" C ");

    tone(humidtempBuzz, 1000);   // Send 1KHz sound signal...
    delay(500);                  // ...for 0.5 secs
    noTone(humidtempBuzz);       // Stop sound...
    delay(200);                  // ...for 0.2 secs
  }

  else if ((h <= 29) && (t >= 5) && (t <= 35)) {    // This part of the loop will sound
    lcd.clear();                                    // the alarm and print "too dry!" if
    lcd.setCursor(0,0);                             // "h <= 29," "t >=5," and "t <= 35."
    lcd.print(h);
    lcd.print(" % ");
    lcd.print("Too Dry!");

    lcd.setCursor(0,1);
    lcd.print(t);
    lcd.print(" C ");

    tone(humidtempBuzz, 1000);   // Send 1KHz sound signal...
    delay(500);                  // ...for 0.5 secs
    noTone(humidtempBuzz);       // Stop sound...
    delay(200);                  // ...for 0.2 secs
  }

  else if ((t <= 4) && (h >= 30) && (h <= 60)) {    // This part of the loop will sound
    lcd.clear();                                    // the alarm and print "too cold!" if
    lcd.setCursor(0,0);                             // "t <= 4," "h >= 30," and "h <= 60."
    lcd.print(h);
    lcd.print(" % ");

    lcd.setCursor(0,1);
    lcd.print(t);
    lcd.print(" C ");
    lcd.print("Too Cold!");

    tone(humidtempBuzz, 1000);   // Send 1KHz sound signal...
    delay(500);                  // ...for 0.5 secs
    noTone(humidtempBuzz);       // Stop sound...
    delay(500);                  // ...for 0.5 secs
  }

  else if ((t >= 36) && (h >= 30) && (h <= 60)) {     // This part of the loop will sound
    lcd.clear();                                      // the alarm and print "too hot!" if
    lcd.setCursor(0,0);                               // "t >= 36," "h >= 30," and "h<= 60."
    lcd.print(h);
    lcd.print(" % ");

    lcd.setCursor(0,1);
    lcd.print(t);
    lcd.print(" C ");
    lcd.print("Too Hot!");

    tone(humidtempBuzz, 1000);   // Send 1KHz sound signal...
    delay(500);                  // ...for 0.5 secs
    noTone(humidtempBuzz);       // Stop sound...
    delay(500);                  // ...for 0.5 secs
  }

  else if ((t >= 36) && (h >= 61)) {    // This part of the loop will sound the alarm
    lcd.clear();                        // and print "too humid!" and "too hot!" if
    lcd.setCursor(0,0);                 // "t >= 36" and "h >= 61."
    lcd.print(h);
    lcd.print(" % ");
    lcd.print("Too Humid!");

    lcd.setCursor(0,1);
    lcd.print(t);
    lcd.print(" C" );
    lcd.print("Too Hot!");

    tone(humidtempBuzz, 1000);   // Send 1KHz sound signal...
    delay(500);                  // ...for 0.5 secs
    noTone(humidtempBuzz);       // Stop sound...
    delay(500);                  // ...for 0.5 secs
  }

  else if ((t >= 36) && (h <= 29)) {    // This part of the loop will sound the alarm
    lcd.clear();                        // and print "too dry!" and "too hot!" if
    lcd.setCursor(0,0);                 // "t >= 36" and "h <= 29."
    lcd.print(h);
    lcd.print(" % ");
    lcd.print("Too Dry!");

    lcd.setCursor(0,1);
    lcd.print(t);
    lcd.print(" C ");
    lcd.print("Too Hot!");

    tone(humidtempBuzz, 1000);   // Send 1KHz sound signal...
    delay(500);                  // ...for 0.5 secs
    noTone(humidtempBuzz);       // Stop sound...
    delay(500);                  // ...for 0.5 secs
  }

  else if ((t <= 4) && (h <= 29)) {    // This part of the loop will sound the alarm
    lcd.clear();                       // and print "too dry!" and "too cold!" if
    lcd.setCursor(0,0);                // "t <= 4" and "h <= 29."
    lcd.print(h);
    lcd.print(" % ");
    lcd.print("Too Dry!");

    lcd.setCursor(0,1);
    lcd.print(t);
    lcd.print(" C ");
    lcd.print("Too Cold!");

    tone(humidtempBuzz, 1000);   // Send 1KHz sound signal...
    delay(500);                  // ...for 0.5 secs
    noTone(humidtempBuzz);       // Stop sound...
    delay(500);                  // ...for 0.5 secs
  }

  else if ((t <= 4) && (h >= 61)) {    // This part of the loop will sound the alarm
    lcd.clear();                       // and print "too humid!" and "too cold!" if
    lcd.setCursor(0,0);                // "t <= 4" and "h >= 61."
    lcd.print(h);
    lcd.print(" % ");
    lcd.print("Too Humid!");

    lcd.setCursor(0,1);
    lcd.print(t);
    lcd.print(" C ");
    lcd.print("Too Cold!");

    tone(humidtempBuzz, 1000);   // Send 1KHz sound signal...
    delay(500);                  // ...for 0.5 secs
    noTone(humidtempBuzz);       // Stop sound...
    delay(500);                  // ...for 0.5 secs
  }

  else {                     // If none of the conditions above are true,
    lcd.clear();             // then print the temp and humidity as usual.
    lcd.setCursor(0,0);
    lcd.print(h);
    lcd.print(" % ");

    lcd.setCursor(0,1);
    lcd.print(t);
    lcd.print(" C ");
  }
    delay(1000);
}
