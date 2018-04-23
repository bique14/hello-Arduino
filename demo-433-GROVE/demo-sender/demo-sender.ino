// transmitter

/*  ________________________________________
 *  | Arduino Mega |   Grove 433 Sender     | 
 *  |--------------|------------------------|
 *  |   5v         |         VCC            | 
 *  |   12         |         SIG            |
 *  |   GND        |         GND            |
 *  |--------------|------------------------|
*/

/*  I have one cable and two arduino so ..
 *  ______________________________________________________________________________________________________
 *  | Arduino Uno  |   Grove 433 Recevier   |      BreadBord    |   Grove 433 Recevier   |  Arduino Mega  |
 *  |--------------|------------------------|-------------------|------------------------|----------------|
 *  |   5v         |         VCC            |   <= same pin =>  |         VCC            |       5v       |
 *  |   11         |         SIG            |          -        |         SIG            |       12       |
 *  |   GND        |         GND            |   <= same pin =>  |         GND            |       GND      |
 *  |--------------|------------------------|-------------------|------------------------|----------------|
*/

#include <VirtualWire.h>
#undef int
#undef abs
#undef double
#undef float
#undef round

void setup(){
    Serial.begin(9600);    // Debugging only
    Serial.println("sender");

    // Initialise the IO and ISR
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);  // Bits per sec
}

void loop(){
    const char *msg = "hello";

    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
    delay(200);
}
