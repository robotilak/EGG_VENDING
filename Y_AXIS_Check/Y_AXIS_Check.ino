/*
  EGG eVENDING MACHINE CODE FOR Y AXIS TRIAL 1 
 CC NARRENCER , TILAK , CPDO , DENNIS ASHOK
 
 */ 
int r1 = 13;
int r2 = 12;
int r3 = 11;
int r4 = 10;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(r1, HIGH);   // FORWARD TURN ON  
  digitalWrite(r4,HIGH);
  delay(4000);               //
  digitalWrite(r1, LOW);   // FORWARD TURN OFF
  digitalWrite(r4,LOW);
  delay(100);
  digitalWrite(r2, HIGH);  // REVERSE TURN ON
  digitalWrite(r3, HIGH);
  delay(3000);               // wait for a second
  digitalWrite(r2, LOW);  // REVERSE TURN ON
  digitalWrite(r3, LOW);
  delay(100);               // wait for a second
}
