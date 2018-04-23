/*  ________________________________________
 *  | Arduino Uno  |      433 Trasmitter    | 
 *  |--------------|------------------------|
 *  |   5v         |         VCC            | 
 *  |   Data       |         D4             |
 *  |   GND        |         GND            |
 *  |--------------|------------------------|
*/


#define rfTransmitPin 4  //RF Transmitter pin = digital pin 4
#define ledPin 13        //Onboard LED = digital pin 13

void setup(){
  pinMode(rfTransmitPin, OUTPUT);     
  pinMode(ledPin, OUTPUT);    
}

void loop(){
  for(int i=4000; i>5; i=i-(i/3)){
    digitalWrite(rfTransmitPin, HIGH);    
    digitalWrite(ledPin, HIGH);           
    delay(2000);                          
    
    digitalWrite(rfTransmitPin,LOW);      
    digitalWrite(ledPin, LOW);            
    delay(i);                            
  }
}

