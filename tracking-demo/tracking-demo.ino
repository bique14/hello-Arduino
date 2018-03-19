/*  ______________________________________
 *  | Arduino Uno  |   Tracking Sensor    | 
 *  |--------------|----------------------|
 *  | GND          |        GND           |
 *  | 5V           |        VCC           |
 *  | 8            |        OUT           |
 *  |--------------|----------------------|
*/

int LED = 13 ;// define LED Interface
int isLinePin = 8; // define the obstacle avoidance sensor interface
int isLine = HIGH;// define numeric variables val
void setup ()
{
  pinMode (LED, OUTPUT) ;// define LED as output interface
  pinMode (isLinePin, INPUT) ;// define the obstacle avoidance sensor output interface
  Serial.begin(9600);
}
void loop ()
{
  isLine = digitalRead (isLinePin) ;// digital interface will be assigned a value of 3 to read val
  // return 0 : have Line 
  // return 1 : not have Line
  
  if (isLine == LOW) // When the obstacle avoidance sensor detects a signal, LED flashes
  {
    Serial.println("0 : found line!!");
    digitalWrite (LED, HIGH);
  }
  else
  {
    Serial.println("1 : not found");
    digitalWrite (LED, LOW);
  }
  delay(200);
}
