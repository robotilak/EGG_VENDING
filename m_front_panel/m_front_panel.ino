int pulsePin = 7;// digital read coin
int resetPin = 9; 
unsigned long duration = 0;// reads coin duration pulse 
unsigned long reset = 0;
 
void setup() 
{
  pinMode(pulsePin, INPUT);
  reset = pulseIn(resetPin, HIGH);
  duration = pulseIn(pulsePin, HIGH);  
  Serial.begin(9600);
}
 
void loop()

{
  //Clears the LCD and displays the Welcome Note
  clearLCD();
  clearLCD();
  Serial.write(" *** Welcome to the Egg Vending Machine by CPDO & VIT *** ");
  delay(100);
  Serial.print(" *** Welcome to the Egg Vending Machine by CPDO & VIT *** ");
  clearLCD();
  delay(10000);
  do 
  { 
   mainloop();
   Serial.end();
  }
  while(reset>0);
}
  
// Function Declarations //  

// Declaration of the Sensing Loop //
  void mainloop()
{
 
  if (duration > 0)
  {
    for(int i=0;i<2;i++)
    {
    digitalWrite(13,HIGH);  
    delay(1000);
    digitalWrite(13,LOW);
    delay(100);
    Serial.write("Your Credit has been validated");
    Serial.print("Your Credit has been validated");
    delay(100);
    clearLCD();
    Serial.write("Wait for the Eggs to dispense out");
    Serial.print("Wait for the Eggs to dispense out");
    clearLCD();
    delay(100);
    }
  }
  if (Serial.available() >0)
  {
    for(int i=0;i<2;i++)
    {
    digitalWrite(13,HIGH);  
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
    Serial.write("Your Credit has been validated");
      Serial.print("Your Credit has been validated");
    delay(100);
    clearLCD();
    Serial.write("Wait for the Eggs to dispense out");
    Serial.print("Wait for the Eggs to dispense out");
    clearLCD();
    delay(100);
    }
  }
  else
  {
    clearLCD();
    Serial.write("Use Coins or a Smart Card To Get the Eggs");
    Serial.print("Use Coins or a Smart Card To Get the Eggs");
    clearLCD();
    delay(100);
  }  
}



// Declaration for Clearing the LCD
void clearLCD()
{
  Serial.write("\t");
  delay(100);
  Serial.write("\t");
  delay(100);
  Serial.write("\t");
  Serial.write("\t");
  Serial.write("\t");
  Serial.write("\t");
  Serial.write("\t");
  Serial.write("\t");
  Serial.write("\t");
  Serial.write("\t");
}


