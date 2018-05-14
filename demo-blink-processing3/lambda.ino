void setup(){
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  Serial.begin(9600);
}

void loop(){
  delay(100);
  if(Serial.available()){
    while(Serial.available()){
      if(Serial.read() == 'A'){
        Serial.println(!digitalRead(13));
        Serial.println("kuay nahee");
        digitalWrite(13, !digitalRead(13));
      }
    }
  }
}
