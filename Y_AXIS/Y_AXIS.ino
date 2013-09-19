/*
  EGG VENDING MACHINE CODE FOR Y AXIS TRIAL 1 
 CC NARRENCER , TILAK , CPDO , DENNIS ASHOK
 
 */

int yr1 = 28;
int yr2 = 26;
int yr3 = 24;
int yr4 = 22;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(yr1, OUTPUT);
  pinMode(yr2, OUTPUT);
  pinMode(yr3, OUTPUT);
  pinMode(yr4, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  yup();
  delay(500);
  ydown();
  delay(1000);
              
}

void yup()
{
  digitalWrite(yr1, HIGH);   // up TURN ON  
  digitalWrite(yr2,HIGH);
  delay(500);               //
  digitalWrite(yr1, LOW);   // up TURN OFF
  digitalWrite(yr2,LOW);
  delay(100);
}

void ydown()
{
  digitalWrite(yr3, HIGH);  // down TURN ON
  digitalWrite(yr4, HIGH);
  delay(500);               
  digitalWrite(yr3, LOW);  // down TURN ON
  digitalWrite(yr4, LOW);
  delay(100); 
}
