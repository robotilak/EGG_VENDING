int pulsePin = 7;// digital read coin
int resetPin = 9; // 
unsigned long duration = 0;// reads coin duration pulse 
unsigned long reset = 0;
 
void setup() 
{
  pinMode(pulsePin, INPUT);
  reset = pulseIn(resetPin, HIGH);
  duration = pulseIn(pulsePin, HIGH);// this for the   
  Serial.begin(9600);
}
 
void loop()

{
  //Clears the LCD and displays the Welcome Note
 clearlcd();
 Serial.print("Welcome ");
 delay(5000);
 Serial.println("4");      // prints another carriage return
 
 clearlcd();
 delay(100);
 Serial.print("Vending Machine");
 delay(5000);
 Serial.println("4");      // prints another carriage return
 
 clearlcd();
 delay(100);
 Serial.print("cc CPDO-VIT");
 delay(2000);
 Serial.println("4");      // prints another carriage return
 
 clearlcd();
 delay(100);
 while(reset==0)
 {
 coin();
 RFID();
 nothing();
 }
 delay(2000);
 update();
}
  
// Function Declarations //  

// Declaration of the Sensing Loop //
void coin()
{
 
  if (duration >0)
  {
    digitalWrite(13,HIGH);  
    delay(2000);
    digitalWrite(13,LOW);
    delay(200);
    Serial.print("Payment Made");
    Serial.println("4");      // prints another carriage return
    delay(3000);
    clearlcd();
    Serial.print("Please Wait");
    Serial.println("4");      // prints another carriage return
    clearlcd();
    delay(3000);
    Serial.print("Kindly collet your tray");
    Serial.println("4");      // prints another carriage return
    clearlcd();
    delay(5000);
    reset=1;
    
    }
}
  
void RFID()
{if (Serial.available() >0)
  {
    digitalWrite(13,HIGH);  
    delay(2000);
    digitalWrite(13,LOW);
    delay(100);
    Serial.print("Credit validated");
    delay(5000);
    Serial.println("4");      // prints another carriage return
    clearlcd();
    Serial.print("Egg to dispense out");
    delay(5000);
    clearlcd();
    Serial.println("4");      // prints another carriage return
    reset=1;
    
   }
}
void nothing ()
 {
    clearlcd();
    Serial.print("Use Coins or Card");
    delay(1000);
    Serial.println("4");      // prints another carriage return
    clearlcd();
    delay(100);
  }  


// Clearing LCD
void clearline()
{
  Serial.print("                    ");// clear one line
}


void clearlcd()
 { 
   clearline();
   clearline();
   clearline();
   clearline();
  }

void update()
{
  reset=0;
}
