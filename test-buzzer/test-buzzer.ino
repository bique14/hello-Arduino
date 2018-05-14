/*  ______________________________________
 *  | Arduino Uno  |        Buzzer        | 
 *  |--------------|----------------------|
 *  | GND          |       - (left pin)   |
 *  | 5V           |        (mid pin)     |
 *  | A0           |        (right pin)   |
 *  |--------------|----------------------|
*/

int speakerPin = A0;
int volume = 130;
void setup () {
  pinMode (speakerPin, OUTPUT);
  Serial.begin(9600);
}
void loop () {
  for(volume; volume<150; volume++){
    analogWrite (speakerPin, volume);
    delay (100);
    Serial.println(volume);
  }
  
  volume = 120;
}
