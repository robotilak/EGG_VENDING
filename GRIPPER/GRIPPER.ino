/*
  EGG VENDING MACHINE CODE FOR Y AXIS TRIAL 1 
 CC NARRENCER , TILAK , CPDO , DENNIS ASHOK
 
 connected to the ATMega 2560
 Gripper start when  
 */


int r1 = 44; // relay fwd 
int r2 = 42; // relay back
int r3 = 40; // relay back
int r4 = 38; // relay fwd

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
  digitalWrite(r1, HIGH);  // REVERSE TURN ON
  digitalWrite(r2, HIGH);
  delay(8000);               // wait for a second
  digitalWrite(r1, LOW);  // REVERSE TURN OFF
  digitalWrite(r2, LOW);
  delay(100);               // wait for a second
  digitalWrite(r3, HIGH);   // FORWARD TURN ON  
  digitalWrite(r4,HIGH);
  delay(8000);               //
  digitalWrite(r3, LOW);   // FORWARD TURN OFF
  digitalWrite(r4,LOW);
  delay(100);
  
}
