/*
Uses a FOR loop for data and prints a number in various formats.
*/
int x = 0;    // variable

void setup() {
  Serial.begin(9600);      // open the serial port at 9600 bps:    
}

void loop() {  
 clearlcd(); 
 
 
  Serial.print("vignaharatha");       // prints a label
 delay(1000);
 
  
 

  Serial.println("4");      // prints another carriage return
}

//clear the entire line 
void clearline()
{
  Serial.print("                    ");// clear one line
}


void clearlcd()
 { 
   clearline();
   clearline();
   clearline();
   clearline();
  }
