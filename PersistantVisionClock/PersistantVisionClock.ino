
/*
Arduino Pro or Pro Mini 
ATmega328 (5v, 16 mHZ)

// POV system to spin Clockwise

 */

#include <SparkFunDS1307RTC.h>
#include <Wire.h>

#define refreshrate  900

void printCharacters(String theCharacters);
void printTime();

int n = 0;

void setup() {

  Serial.begin(9600);
  Serial.println("PersistantVisionClock");
  Serial.println("Last Modified 13Aug2017");

   pinMode(2,OUTPUT); // outermost
   pinMode(3,OUTPUT);
   pinMode(4,OUTPUT);
   pinMode(5,OUTPUT);
  
   pinMode(6,OUTPUT);
   pinMode(7,OUTPUT);
   pinMode(8,OUTPUT);
   pinMode(9,OUTPUT); // innermost
   
   pinMode(10,INPUT); // hall effect
   
   LoopHighLow();

    rtc.begin();
    rtc.set12Hour();
  //rtc.autoTime();
  // e.g. 7:32:16 | Monday October 31, 2016:
  // rtc.setTime(16, 32, 9, 4, 18, 1, 17);  // Uncomment to manually set time
  delay(1000);
}

void loop() {


  if (digitalRead(10) == HIGH) {

  } else {

  printCharacters(String(rtc.hour()) + ":");
  if (rtc.minute() < 10) printCharacters("0"); // Print leading '0' for minute
  printCharacters(String(rtc.minute()) + ":"); // Print minute
  if (rtc.second() < 10) printCharacters("0"); // Print leading '0' for second
  printCharacters(String(rtc.second())); // Print second
  rtc.update();
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




