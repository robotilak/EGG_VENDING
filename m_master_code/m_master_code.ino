 /*
  EGG eVENDING MACHINE CODE FOR Y AXIS TRIAL 1 
 CC NARRENCER , TILAK , CPDO , DENNIS ASHOK
 
 */ 
int xr1 = 36;// x fwd
int xr2 = 34;
int xr3 = 32;// x rev
int xr4 = 30;

int yr1 = 28;// y relay fwd
int yr2 = 26;
int yr3 = 24;// y rev
int yr4 = 22;


int gr1 = 44; // gripper fwd 
int gr2 = 42; 
int gr3 = 40; // gripper rev
int gr4 = 38; 

int cr1 = 23;// conveyor
boolean grip_value = false , ungrip_value = false;
///////////////////////////////////////
//global 
int left_p_grip1=0;
float left_p_grip =0.0;
int gripper_egg1 = 0;
float gripper_egg = 0.0;
int top_sensor1 =0;
float gripper_center =0.0;
int gripper_c = 0;
float top_sensor = 0.0;
int con_end1 = 0;
float con_end =0.0;
int con_start1 = 0;
float con_start = 0.0;
/////////////////////////////////////////

// the setup routine runs once when you press reset:
void setup() { 
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
  
  // conveyor
   pinMode(cr1, OUTPUT);
   
     // initialize the digital pin as an output.
  pinMode(gr1, OUTPUT);
  pinMode(gr2, OUTPUT);
  pinMode(gr3, OUTPUT);
  pinMode(gr4, OUTPUT);


 }

///////////// the loop routine runs over and over again forever:

void loop() 
{

// Write the left X   
  left_p_grip1 = analogRead(A10); //left position gripper proximity sensor
   left_p_grip = left_p_grip1 * (5.0 / 1023.0);
  Serial.println(left_p_grip);   
  
// Inside gripper
   gripper_egg1 = analogRead(A12); // inside gripper
   gripper_egg = gripper_egg1 * (5.0 / 1023.0);
  Serial.println(gripper_egg);
 
 // GRIPPER CENTER 
   gripper_c = analogRead(A8); // gripper center
   gripper_center = gripper_c * (5.0 / 1023.0);
  Serial.println(gripper_center);
  
  // TOP SENSOR
   top_sensor1 = analogRead(A13); // top_sensor
   top_sensor = top_sensor1 * (5.0 / 1023.0);
  Serial.println(top_sensor);
  // conveyor end
   con_end1 = analogRead(A10); //left position gripper proximity sensor
   con_end = con_end1 * (5.0 / 1023.0);
  Serial.println(con_end);   
  
  
  // conveyor
   con_start1 = analogRead(A2); // conveyor
   con_start = con_start1 * (5.0 / 1023.0);
  Serial.println(con_start);


//PROGRAM//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 1st half
if (gripper_center<3)
{
  while(gripper_egg>3 && left_p_grip>3)
  {
    ydown();
    delay(100);
    update();
    
  }
  while(gripper_egg<3 && top_sensor<3)
  {
    grip();
    delay(1000);
    update();
    if(grip_value = true)
    break;
  }
  while ( top_sensor<3 && gripper_center<3)
  {
    yup();
    delay(1000);
    update();
  }
  while(top_sensor>3 && gripper_center<3)
  {
    xrr();
    delay(1000);
    update();
  }
   
}

delay(4000);
/// 2nd half
if(con_end<3 && gripper_center>3)
{
  while(con_start<3 && gripper_egg<3)
  {
    ydown();
    delay(1000);
    update();
  }
  while (con_start>3 && gripper_center>3)//gripper_egg<3)
  {
    ungrip();
    delay(1000);
    update();
   // break;
   if(ungrip_value == true)
   break;
  }
  while(con_end<3 && con_start>3)
  {
    cy();
    delay(1000);
    update();
  }
}


}
//FUNCTIONS//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void n()
{ delay(10000);
} 
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
  grip_value = true;
   digitalWrite(gr3, HIGH);   // gripp TURN ON  
  digitalWrite(gr4,HIGH);
  delay(14000);               
  digitalWrite(gr3, LOW);   // grip TURN OFF
  digitalWrite(gr4,LOW);
  delay(10);
}

void ungrip()
{
  ungrip_value = true;
  digitalWrite(gr1, HIGH);  // ungrip TURN ON
  digitalWrite(gr2, HIGH);
  delay(10000);               
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
  return;
}

void ydown()
{
  digitalWrite(yr3, HIGH);  // down TURN ON
  digitalWrite(yr4, HIGH);
  delay(200);               
  digitalWrite(yr3, LOW);  // down TURN ON
  digitalWrite(yr4, LOW);
  delay(700);
}
void update()
{
 // Write the left X   
  left_p_grip1 = analogRead(A10); //left position gripper proximity sensor
   left_p_grip = left_p_grip1 * (5.0 / 1023.0);
  Serial.println(left_p_grip);   
  
// Inside gripper
   gripper_egg1 = analogRead(A12); // inside gripper
   gripper_egg = gripper_egg1 * (5.0 / 1023.0);
  Serial.println(gripper_egg);
 
 // GRIPPER CENTER 
   gripper_c = analogRead(A8); // gripper center
   gripper_center = gripper_c * (5.0 / 1023.0);
  Serial.println(gripper_center);
  
  // TOP SENSOR
   top_sensor1 = analogRead(A13); // top_sensor
   top_sensor = top_sensor1 * (5.0 / 1023.0);
  Serial.println(top_sensor);
  // conveyor end
   con_end1 = analogRead(A10); //left position gripper proximity sensor
   con_end = con_end1 * (5.0 / 1023.0);
  Serial.println(con_end);   
  
  
  // conveyor
   con_start1 = analogRead(A2); // conveyor
   con_start = con_start1 * (5.0 / 1023.0);
  Serial.println(con_start); 
}

