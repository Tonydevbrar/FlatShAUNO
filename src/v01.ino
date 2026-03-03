//# 
//# Ready to compile programm
//# IF YOU DON'T KNOW WHAT YOU'RE DOING: DO NOT EDIT.
//# FlatShAuto source for Arduino uno.
//#
#include <Stepper.h>
String inputString = "";
boolean stringComplete = false;
int lstate = 0 ;
#define STEPS 32
Stepper stepper (STEPS, 8, 10, 9, 11);
void setup() {
  Serial.begin(9600);
  inputString.reserve(200);
  stepper.setSpeed(200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}
void loop() {
  if (stringComplete) {
    Serial.println("Received:");
    Serial.println(inputString);
    if (inputString.equals("fled1")) {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("LED: ON");
    } 
    if (inputString.equals("fled0")) {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("LED: OFF");
    }
    if (inputString.equals("flock0")) {
      stepper.step(1024);
      Serial.println("Lock: unlocked"); 
    }
    if (inputString.equals("flock1")) {
      stepper.step(0-1024);
      Serial.println("Lock: locked"); 
    }
    if (inputString.equals("flight1")) {
      Serial.println("Light: Not included yet"); 
    }
    if (inputString.equals("flight0")) {
      Serial.println("Light: Not included yet"); 
    }
    if (inputString.equals("help")) {
        char *helptext =
            "FlatSh - Shell with unique ideas       .\n"
            "The following commands are built in    :\n"
            "  fled1/0    1 = led on, 0 = led off   .\n"
            "  flock1/0   1 = lock on, 0 = lock off .\n"
            "  flight1/0  1 = light on 0 = light off.\n"
            "  help       Print this help text      .\n";
        Serial.println(helptext);
    }
    else {Serial.println("FlatSh: command not found");}
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent(){
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      stringComplete = true;
    } else {
      inputString += inChar ;
    }
  }
}
