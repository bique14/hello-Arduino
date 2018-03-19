/*  ______________________________
 *  | Arduino Uno  |   LCD(I2C)   |
 *  |--------------|--------------|
 *  | GND          |   GND(pin1)  |
 *  | 5V           |   VCC(pin2)  |
 *  | A4           |   SDA(pin3)  |
 *  | A5           |   SCL(pin4)  |
 *  |--------------|--------------|
 *  
 *  I2C address : 0x3F
 *  Source for check I2C addrees : https://playground.arduino.cc/Main/I2cScanner?action=sourceblock&num=1
*/
 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x3F for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup(){
  lcd.begin();
}

int i = 0;
int h=12,m=40,s=0;

void loop(){
  if(s == 10){
    s = 0;
    m++;
  }
  if(m == 3){
    m = 0;
    h++;
  }
  if(h == 24){
    h = 0;
  }
  s++;

  char buf_h[50];
  sprintf(buf_h, "%02d",h);
  lcd.setCursor(0, 0);  // index, number of line
  lcd.print(buf_h);
  lcd.setCursor(2, 0);
  if(s%2==0){
    lcd.print(":");
  }else{
    lcd.print(" ");
  }


  char buf_m[50];
  sprintf(buf_m, "%02d",m);
  lcd.setCursor(3, 0);
  lcd.print(buf_m);
  lcd.setCursor(5, 0);
  if(s%2==0){
    lcd.print(":");
  }else{
    lcd.print(" ");
  }


  char buf_s[50];
  sprintf(buf_s, "%02d",s);
  lcd.setCursor(6, 0);
  lcd.print(buf_s);
  
  delay(1000);
}

