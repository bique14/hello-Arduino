/*  ________________________________________
 *  | Arduino Uno  |   KY018 Photo resistor | 
 *  |--------------|------------------------|
 *  | GND          |   GND                  |
 *  | 5V           |   5V(pin2)             |
 *  | A5           |   S(pin3)              |
 *  |--------------|------------------------|
 */
 
int sensorPin = A5; // input in pin 'S'
int ledPin = 13; // select the pin for the LED 
int sensorValue = 0; // variable to store the value coming from the sensor


void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // 9600 baud in monitor
} 


void loop() {
  sensorValue = analogRead(sensorPin);

  if (sensorValue > 160){ // Dark, Light on (pin 'L')
    digitalWrite(ledPin, HIGH);
  }else{                  // Not Dark, Light off (pin 'L')
    digitalWrite(ledPin, LOW);
  }
  delay(1000);
  Serial.println(sensorValue, DEC); // Print light value
}
