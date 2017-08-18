


void printCharacters(String theCharacters)
{
  for(int x=0;x<theCharacters.length();x++)
  {
    //Serial.println(theCharacters.charAt(x));
    displayCharacter(theCharacters.charAt(x));
  }
}

void displayCharacter(char theCharacter)
{
  if (theCharacter == '0')  { number0(); }
  if (theCharacter == '1')  { number1(); }
  if (theCharacter == '2')  { number2(); }
  if (theCharacter == '3')  { number3(); }
  if (theCharacter == '4')  { number4(); }
  if (theCharacter == '5')  { number5(); }
  if (theCharacter == '6')  { number6(); }
  if (theCharacter == '7')  { number7(); }
  if (theCharacter == '8')  { number8(); }
  if (theCharacter == '9')  { number9(); }
  if (theCharacter == ':')  { numberColon(); }
  delayMicroseconds(refreshrate);
  
}

void flipLight(boolean a, boolean b, boolean c, boolean d, boolean e)
{
a ? digitalWrite(2,HIGH) : digitalWrite(2,LOW) ;
b ? digitalWrite(3,HIGH) : digitalWrite(3,LOW) ;
c ? digitalWrite(4,HIGH) : digitalWrite(4,LOW) ;  
d ? digitalWrite(5,HIGH) : digitalWrite(5,LOW) ;  
e ? digitalWrite(6,HIGH) : digitalWrite(6,LOW) ;
delayMicroseconds(refreshrate);
}


void allOnOff(boolean offOrOn)
{
  if (offOrOn) {
    for(int x=2;x<10;x++)
    {
    digitalWrite(x,HIGH);
    }
  } else {
    for(int x=2;x<10;x++)
    {
    digitalWrite(x,LOW);
    }
  }

}

