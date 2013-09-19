/*
  EGG VENDING MACHINE CODE FOR Y AXIS TRIAL 1 
 CC NARRENCER , TILAK , CPDO , DENNIS ASHOK
 
 connected to the ATMega 2560
 Gripper start when  
 */


int gr1 = 44; // relay fwd 
int gr2 = 42; // relay back
int gr3 = 40; // relay back
int gr4 = 38; // relay fwd

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(gr1, OUTPUT);
  pinMode(gr2, OUTPUT);
  pinMode(gr3, OUTPUT);
  pinMode(gr4, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
grip();
delay(1000);
ungrip();
delay(1000);
 
}

void grip()
{
   digitalWrite(gr3, HIGH);   // gripp TURN ON  
  digitalWrite(gr4,HIGH);
  delay(3000);               
  digitalWrite(gr3, LOW);   // grip TURN OFF
  digitalWrite(gr4,LOW);
  delay(100);
}

void ungrip()
{
  digitalWrite(gr1, HIGH);  // ungrip TURN ON
  digitalWrite(gr2, HIGH);
  delay(3000);               
  digitalWrite(gr1, LOW);  // ungrip TURN OFF
  digitalWrite(gr2, LOW);
  delay(100);     
}  


