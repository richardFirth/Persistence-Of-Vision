
/*
Arduino Pro or Pro Mini 
ATmega328 (5v, 16 mHZ)

// POV system to spin Clockwise

 */

#include <SparkFunDS1307RTC.h>
#include <Wire.h>

#define button 11
#define hallEffect 10

#define refreshrate  900

void printCharacters(String theCharacters);
void printTime();

void setup() {

  Serial.begin(9600);
  Serial.println("PersistantVisionClock");
  Serial.println("Last Modified 19Aug2017");

   pinMode(2,OUTPUT); // outermost
   pinMode(3,OUTPUT);
   pinMode(4,OUTPUT);
   pinMode(5,OUTPUT);
  
   pinMode(6,OUTPUT);
   pinMode(7,OUTPUT);
   pinMode(8,OUTPUT);
   pinMode(9,OUTPUT); // innermost
   
   pinMode(hallEffect,INPUT); // hall effect
   pinMode(button,INPUT); // button
   
   LoopHighLow();

    rtc.begin();
    rtc.set12Hour();

  if (digitalRead(button) == HIGH) {
    rtc.autoTime();
    LoopHighLow();
  } 
  delay(1000);
}

void loop() {


  if (digitalRead(hallEffect) == HIGH) {

  } else {
    delayMicroseconds(100);
    if (digitalRead(hallEffect) == LOW) {  // this double check prevents the thing from flickering randomly as it spins.

      printCharacters(String(rtc.hour()) + ":");
      if (rtc.minute() < 10) printCharacters("0"); // Print leading '0' for minute
      printCharacters(String(rtc.minute()) + ":"); // Print minute
      if (rtc.second() < 10) printCharacters("0"); // Print leading '0' for second
      printCharacters(String(rtc.second())); // Print second
     
      rtc.update();
    }
  }

}


void LoopHighLow()
{
  for(int x=2;x<10;x++)  {  highLow(x);  }
}

void highLow(int thePin)
{
  digitalWrite(thePin,HIGH);
  delay(150);
  digitalWrite(thePin,LOW);
}




