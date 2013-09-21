/* this code was developed tilak narrender and abhilash for the egg vending machine 
front pannel controller

*/

int pulsePin = 7;
unsigned long duration = 0;
 
void setup() 
{
  pinMode(pulsePin, INPUT);  
  Serial.begin(9600);
  Serial.write("\t");
  Serial.write(" *** Welcome to the Egg Vending Machine *** ");
  delay(1000);
  Serial.write("\t");
  delay(10000);

}
 
void loop()
{
  duration = pulseIn(pulsePin, HIGH);
  
  if (duration > 0)
  {
    for(int i=0;i<2;i++)
    {
    digitalWrite(13, HIGH);  
    delay(100);
    Serial.write("Your Credit has been validated");
    delay(10000);
    Serial.write("Wait for the Eggs to dispense out");
    delay(10000);
    }
  }
  if (Serial.available() >0)
  {
    for(int i=0;i<2;i++)
    {
    digitalWrite(13,HIGH);  
    delay(1000);
    digitalWrite(13,LOW);
    delay(100);
    Serial.write("Your Credit has been validated");
    delay(10000);
    Serial.write("\t");
    Serial.write("Wait for the Eggs to dispense out");
    Serial.write("\t");
    delay(10000);
    }
  }
  else
  {
  Serial.write("\t");
  Serial.write("Use Coins or a Smart Card To Get the Eggs");
  delay(1000);
  Serial.write("\t");
  }
}


