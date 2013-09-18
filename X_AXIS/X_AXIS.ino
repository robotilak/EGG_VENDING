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
  digitalWrite(xr1, HIGH);   // RIGHT TURN ON  
  digitalWrite(xr2,HIGH);
  delay(4000);               //
  digitalWrite(xr1, LOW);   //  TURN OFF
  digitalWrite(xr2,LOW);
  delay(100);
  digitalWrite(xr3, HIGH);  // REVERSE TURN ON
  digitalWrite(xr4, HIGH);
  delay(3000);               // wait for a second
  digitalWrite(xr3, LOW);  // REVERSE TURN ON
  digitalWrite(xr4, LOW);
  delay(100);               // wait for a second
}
