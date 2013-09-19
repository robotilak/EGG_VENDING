 /*
 EGG VENDING MACHINE CODE FOR COMPLETE CONTROL    
 CC NARRENCER , TILAK , CPDO , DENNIS ASHOK
  */ 
// Variable Declaration 

int xr1 = 36;// x fwd
int xr2 = 34;// x fwd
int xr3 = 32;// x rev
int xr4 = 30;// x rev

int yr1 = 28;// y Top
int yr2 = 26;// y Top
int yr3 = 24;// y Bott
int yr4 = 22;// y Top


int gr1 = 44; // gripper fwd 
int gr2 = 42; // gripper fwd 
int gr3 = 40; // gripper rev
int gr4 = 38; // gripper rev

int cr1 = 23;// conveyor


// the setup routine runs once when you press reset:

void setup() 
{ 
  Serial.begin(9600); 
  // initialize the digital pin as an output.
  pinMode(yr1, OUTPUT);
  pinMode(yr2, OUTPUT);
  pinMode(yr3, OUTPUT);
  pinMode(yr4, OUTPUT);
  // x axis innitilaization 
  pinMode(xr1, OUTPUT);
  pinMode(xr2, OUTPUT);
  pinMode(xr3, OUTPUT);
  pinMode(xr4, OUTPUT);
  
  //gripper
  pinMode(gr1, OUTPUT);
  pinMode(gr2, OUTPUT);
  pinMode(gr3, OUTPUT);
  pinMode(gr4, OUTPUT);
  
  // conveyor
  pinMode(cr1, OUTPUT);

 }

///////////// the loop routine runs over and over again forever:

void loop() 

{
  // Write the left X   
  int left_p_grip1 = analogRead(A10); //left position gripper proximity sensor
  float left_p_grip = left_p_grip1 * (5.0 / 1023.0);
  Serial.println("left_p_grip:"left_p_grip);   
  // Inside gripper
  int gripper_egg1 = analogRead(A12); // inside gripper
  float gripper_egg = gripper_egg1 * (5.0 / 1023.0);
  Serial.println("gripper_egg:"gripper_egg);
  // GRIPPER CENTER 
  int gripper_c = analogRead(A8); // gripper center
  float gripper_center = gripper_c * (5.0 / 1023.0);
  Serial.println("gripper_center:"gripper_center);
  // TOP SENSOR
  int top_sensor1 = analogRead(A13); // top_sensor
  float top_sensor = top_sensor1 * (5.0 / 1023.0);
  Serial.println("top_sensor:"top_sensor);
  // conveyor
  int con_start1 = analogRead(A2); // conveyor
  float con_start = con_start1 * (5.0 / 1023.0);
  Serial.println("con_start:"con_start);


//PROGRAM//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  if(gripper_egg>3)
  {
    ydown();  
  }
  
  if (gripper_egg<3)
  {
    grip();
    delay(300);
    
  if (top_sensor<3)
  {
    yup();
  }
  }
  if(top_sensor>3 && gripper_center<3)
  {
    xrr();
    delay(100);
    
    if(gripper_center>3 && con_start>3)
    {
      ydown();
      delay(5000);
      cy(); 
      delay(100); 
      ungrip();
    }
  }
}// END of program



//FUNCTIONS//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
// conveyor movement
void cy()
{
  // cy for call();
  digitalWrite(cr1, HIGH);   // FORWARD TURN ON  
  delay(4000);               //
  digitalWrite(cr1, LOW);   // FORWARD TURN OFF
  delay(100);
}

// gripper movement
void grip()
{
  digitalWrite(gr3, HIGH);   // gripp TURN ON  
  digitalWrite(gr4,HIGH);
  delay(1000);               
  digitalWrite(gr3, LOW);   // grip TURN OFF
  digitalWrite(gr4,LOW);
  delay(10);
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

// x axis movement
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

// y axis movement  
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
  delay(200);               
  digitalWrite(yr3, LOW);  // down TURN ON
  digitalWrite(yr4, LOW);
  delay(300); 
}

