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

 }

// the loop routine runs over and over again forever:
void loop() {

  // Assuming the gripper is going to be on the Left First 

// Write the left X   
  int left_p_grip1 = analogRead(A10); //left position gripper proximity sensor
  float left_p_grip = left_p_grip1 * (5.0 / 1023.0);
  Serial.println(left_p_grip);   
  
// Y axis move down   

// Inside gripper
  int gripper_egg1 = analogRead(A12); // inside gripper
  float gripper_egg = gripper_egg1 * (5.0 / 1023.0);
  Serial.println(gripper_egg);
 
 // GRIPPER CENTER 
  int gripper_c = analogRead(A8); // gripper center
  float gripper_center = gripper_c * (5.0 / 1023.0);
  Serial.println(gripper_center);
  
  // TOP SENSOR
  int top_sensor1 = analogRead(A13); // top_sensor
  float top_sensor = top_sensor1 * (5.0 / 1023.0);
  Serial.println(top_sensor);
  
   // TOP SENSOR
  int con_start1 = analogRead(A2); // otop_sensor
  float con_start = con_start1 * (5.0 / 1023.0);
  Serial.println(con_start);
 
  if (gripper_egg>3)
  {
  digitalWrite(yr3, HIGH);   // DOWN TURN ON  
  digitalWrite(yr4,HIGH);
  delay(200);               //
  digitalWrite(yr3, LOW);   // DOWN TURN OFF
  digitalWrite(yr4,LOW);
  delay(500);
  }
 
 
 // Initilise and grip the egg 
 else  if (gripper_egg<3)
 { // timing to be tuned better 
  digitalWrite(yr3, LOW);   // DOWN TURN OFF
  digitalWrite(yr4,LOW);
  delay(1000);
  
  digitalWrite(gr3, HIGH);  // inverse TURN ON gripping action
  digitalWrite(gr4, HIGH);
  delay(1000);               
  digitalWrite(gr3, LOW);  // inverse turn off, stop gripping action
  digitalWrite(gr4, LOW);
  delay(100);               
  
  // move back y upwards after gripping
  if ( top_sensor<3)
  digitalWrite(yr1, HIGH);  // upwards TURN ON
  digitalWrite(yr2, HIGH);
  delay(500);               
  digitalWrite(yr1, LOW);  // upwards TURN off
  digitalWrite(yr2, LOW);
  delay(150);               
   }
   
   // actions to be taken after the gripper has reached the top
  if (top_sensor>3){ 
  
  // move the gripper to the center
  if(gripper_center<3)
 { digitalWrite(xr1, HIGH);   // RIGHT TURN ON  
  digitalWrite(xr2,HIGH);
  delay(8000);               //
  digitalWrite(xr1, LOW);   //  TURN OFF
  digitalWrite(xr2,LOW);
  delay(200);
 } 
  //code to move the egg tray down
  else 
  {
  digitalWrite(yr3, HIGH);   // DOWN TURN ON  
  digitalWrite(yr4,HIGH);
  delay(400);               //
  digitalWrite(yr3, LOW);   // DOWN TURN OFF
  digitalWrite(yr4,LOW);
  delay(200);
  }
  // conveyor on
  
  /* ungrip
  else if(con_start>3)
  {digitalWrite(gr1, HIGH);  // inverse TURN ON gripping action
  digitalWrite(gr2, HIGH);
  delay(8000);               
  digitalWrite(gr1, LOW);  // inverse turn off, stop gripping action
  digitalWrite(gr2, LOW);
  delay(4000);} */
  
  // move back up
  if(top_sensor<3)
  {
   digitalWrite(yr1, HIGH);  // upwards TURN ON
  digitalWrite(yr2, HIGH);
  delay(200);               
  digitalWrite(yr1, LOW);  // upwards TURN off
  digitalWrite(yr2, LOW);
  delay(300);
  }
 
 
  /*
  digitalWrite(yr1, HIGH);  // REVERSE TURN ON
  digitalWrite(yr2, HIGH);
  delay(3000);               // wait for a second
  digitalWrite(yr1, LOW);  // REVERSE TURN ON
  digitalWrite(yr2, LOW);
  delay(100);               // wait for a second
  */
} 
}
