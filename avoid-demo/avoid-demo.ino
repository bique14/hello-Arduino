/*  _________________________________________________
 *  | Arduino Uno  |   IR Obstacle Avoidance Sensor | 
 *  |--------------|--------------------------------|
 *  | GND          |        GND                     |
 *  | 5V           |        VCC                     |
 *  | 2            |        OUT                     |
 *  |--------------|--------------------------------|
*/

int LED = 13; // LED onboard
int isObstaclePin = 2;  // input pin
int isObstacle = HIGH;  // HIGH = no obstacle

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(isObstaclePin, INPUT);
  Serial.begin(9600);  
}

void loop() {
  isObstacle = digitalRead(isObstaclePin); 
  // return 0 : have obstacle, 
  // return 1 : clear
 
  if (isObstacle == LOW)
  {
    Serial.println("0 : have obstacle");
    digitalWrite(LED, HIGH);
  }
  else
  {
    Serial.println("1 : clear");
    digitalWrite(LED, LOW);
  }
  delay(200);
}

