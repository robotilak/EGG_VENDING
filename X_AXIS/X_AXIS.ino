/*
  EGG VENDING MACHINE CODE FOR Y AXIS TRIAL 1 
 CC NARRENCER , TILAK , CPDO , DENNIS ASHOK
 
 */

int xr1 = 36;
int xr2 = 34;
int xr3 = 32;
int xr4 = 30;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(xr1, OUTPUT);
  pinMode(xr2, OUTPUT);
  pinMode(xr3, OUTPUT);
  pinMode(xr4, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() { 
 xll();
 delay(1000);
 xrr();
 delay(1000);
 }
void xrr()
{
  digitalWrite(xr1, HIGH);   // RIGHT TURN ON  
  digitalWrite(xr2,HIGH);
  delay(4000);               //
  digitalWrite(xr1, LOW);   //  TURN OFF
  digitalWrite(xr2,LOW);
  delay(100);
}
void xll()
{ 
  digitalWrite(xr3, HIGH);   // LEFT TURN ON  
  digitalWrite(xr4,HIGH);
  delay(4000);               //
  digitalWrite(xr3, LOW);   //  LEFT OFF
  digitalWrite(xr4,LOW);
  delay(100);
  }

