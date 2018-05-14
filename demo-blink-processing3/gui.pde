import controlP5.*;
import processing.serial.*;

ControlP5 cp5;
Serial port;

String inData="";
int i = 0 ;
void setup(){
  size(400,400);
  int i = 0;
  println(Serial.list());
  port = new Serial(this, Serial.list()[2], 9600);
  port.clear();
  port.bufferUntil('\n');
  
  cp5 = new ControlP5(this);
  
  cp5.addTextfield("text1")
     .setPosition(100,100)
     .setSize(100,20)
     .setCaptionLabel("Data")
     .setFont(createFont("Verdana", 16))
     ;
  
  cp5.addButton("OnOff")
     .setValue(0)
     .setPosition(250, 100)
     ;
     
  cp5.addKnob("knob1").setSize(100,200)
     .setPosition(150,250)
     .setMax(255)
     .setMin(0)
     .setValue(100)
     ;
     
   //cp5.addTextlabel("label")
   // .setText("Count : ")
   // .setPosition(100,50)
   // .setColorValue(0xffffff00)
   // .setFont(createFont("Georgia",20))
   // ;
}


void draw(){
  Textfield t = (Textfield) cp5.getController("text1");
  t.setText(inData);
  cp5.getController("slider1").setValue(int(inData));
  //cp5.getController("knob1").setValue(int(inData));
}

void OnOff(){
  println("Button pressed");
  port.write("A");  
  cp5.getController("knob1").setValue(i);
  i++;
}

void serialEvent(Serial port){
  inData = port.readStringUntil('\n');
  inData = trim(inData);
  println(inData);
}
