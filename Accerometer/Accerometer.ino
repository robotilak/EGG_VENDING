int led = 13;// x axis front light whien go up
int led1 = 14;
int led2 = 15;

const int numReadingsx = 10;
int readingsx[numReadingsx];      
int indexx = 0;                  
int totalx = 0;                  
int averagex = 0;               
int inputPinx = A0;
const int numReadingsy = 10;
int readingsy[numReadingsy];      
int indexy = 0;                  
int totaly = 0;                  
int averagey = 0;               
int inputPiny = A1;
const int numReadingsz = 10;
int readingsz[numReadingsz];      
int indexz = 0;                  
int totalz = 0;                  
int averagez = 0;               
int inputPinz = A1;

void setup()
{
 
  Serial.begin(9600);                   
    for (int thisReadingx = 0; thisReadingx < numReadingsx; thisReadingx++)
    readingsx[thisReadingx] = 0;
    for (int thisReadingy = 0; thisReadingy < numReadingsy; thisReadingy++)
    readingsy[thisReadingy] = 0;
    for (int thisReadingz = 0; thisReadingz < numReadingsz; thisReadingz++)
    readingsz[thisReadingz] = 0;
    pinMode(led, OUTPUT);
    pinMode(led1, OUTPUT);    
    pinMode(led2, OUTPUT);
}

void loop() {
 
  totalx= totalx - readingsx[indexx];
  totaly= totaly - readingsy[indexy];   
  totalz= totalz - readingsz[indexz];   
  readingsx[indexx] = analogRead(inputPinx);
  readingsy[indexy] = analogRead(inputPiny);
  readingsz[indexz] = analogRead(inputPinz);
  totalx= totalx + readingsx[indexx];
  totaly= totaly + readingsy[indexy];  
  totalz= totalz + readingsz[indexz];  
  indexx = indexx + 1;
  indexy = indexy + 1;  
  indexz = indexz + 1;  
   if (indexx >= numReadingsx)              
    
   indexx = 0;                           
   averagex = totalx / numReadingsx;
   if (indexy >= numReadingsy)              
    
   indexy = 0;                           
   averagey = totaly / numReadingsy;
  if (indexz >= numReadingsz)              
    
   indexz = 0;                           
   averagez = totalz / numReadingsz;   
  Serial.print("x: ");
  Serial.print(averagex);
  Serial.print(" | y: ");
  Serial.print(averagey); 
  Serial.print(" | z: ");
  Serial.println(averagez);
  delay(50);
          
  
  if (averagex<345)
  {
   digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50); 
  }
  else
  {
    digitalWrite(led, LOW);
 
 delay(50);
  }
  if (averagey<345)
  {
   digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50); 
  }
  else
  {
    digitalWrite(led1, LOW);
 
 delay(50);
  }
  if (averagey<345)
  {
   digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50); 
  }
  else
  {
    digitalWrite(led2, LOW);
 
 delay(50);
  }
}
