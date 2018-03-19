/*  ________________________________
 *  | Arduino Uno  |   RFID-RC522   | 
 *  |--------------|----------------|
 *  |   3.3v       |     3.3v       | (its working in 5v but its dangerous for module)
 *  |   RST        |     D9         |
 *  |   GND        |     GND        |
 *  |   IRQ        |      -         |
 *  |   MISO       |     D12        |
 *  |   MOSI       |     D11        |
 *  |   SCK        |     D13        |
 *  |   SDA        |     D10        |
 *  |--------------|----------------|
*/

#include "SPI.h"
#include "MFRC522.h"

#define SS_PIN 10
#define RST_PIN 9
#define SP_PIN 8

MFRC522 rfid(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
//   rfid.PCD_AntennaOn();
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;

  // Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  // Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }

  String strID_HEX = "";
  
  for (byte i = 0; i < 4; i++) {
    strID_HEX += (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
      String(rfid.uid.uidByte[i], HEX) +
      (i!=3 ? ":" : "");
  }
  
  strID_HEX.toUpperCase();

  Serial.print("card id: ");
  Serial.println(strID_HEX);

  // if tap the card, light is on.
  if (strID_HEX) {
    digitalWrite(A0, HIGH);
  } else {
    digitalWrite(A0, LOW);
  }
  

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  

}
