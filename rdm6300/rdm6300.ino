/*  
 *    __________________
 *    |RDM6300     xxxxx| P1
 *    |                 |
 * P3 |xx            xxx| P2
 *    -------------------
 *    from : http://9arduino.nisit.net/datasheet/RDM6300.pdf
 *  ________________________________________
 *  | Arduino Uno  |  RFID RDM6300 125khz   | 
 *  |--------------|------------------------|
 *  |   5v         |        5v(P2 pin2)     | 
 *  |   GND        |       GND(P2 pin3)     |
 *  |   2          |        Tx(P1 pin5)     |
 *  |   Anthenna1  |            -           |
 *  |   Anthenna2  |            -           |
 *  |--------------|------------------------|
 *  http://tronixstuff.com/2013/11/19/arduino-tutorials-chapter-15-rfid/
*/

#include <SoftwareSerial.h>
SoftwareSerial RFID(2, 3); // RX and TX

int i;

void setup(){
  RFID.begin(9600);    // start serial to RFID reader
  Serial.begin(9600);  // start serial to PC 
}

void loop(){
  if (RFID.available() > 0){
     i = RFID.read();
     Serial.println(i, DEC);
  }
    RFID.flush(); 
}


