/*
  EGG VENDING MACHINE CODE FOR Y AXIS TRIAL 1 
 CC NARRENCER , TILAK , CPDO , DENNIS ASHOK
 
 */

int cr1 = 23;// conveyor

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(cr1, OUTPUT);
    
}

// the loop routine runs over and over again forever:
void loop() {
 
cy();
delay(1000);
}

void cy()
{
  // cy for call();
  digitalWrite(cr1, HIGH);   // FORWARD TURN ON  
  delay(4000);               //
  digitalWrite(cr1, LOW);   // FORWARD TURN OFF
  delay(100);
}

