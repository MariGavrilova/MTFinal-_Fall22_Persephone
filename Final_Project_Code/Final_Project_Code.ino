#include <Servo.h>

// setup Servo Background
Servo servoBackground;

//setup Servo Hades
Servo servoHades;

//setup Servo Floor
Servo servoFloor;


//setup button Floor
const int buttonFloorPin = 6;
int buttonFloorState = 0;
int lastButtonFloorState = 0;
bool FloorOpen = false;

//setup button Fruit A
const int buttonAPin = 7;
int buttonAState = 0;
int lastButtonAState = 0;
bool A = false;

//setup button Fruit B
const int buttonBPin = 8;
int buttonBState = 0;
int lastButtonBState = 0;
bool B = false;

//setup button Fruit C
const int buttonCPin = 5;
int buttonCState = 0;
int lastButtonCState = 0;
bool C = false;

//setup button HappyEnd
const int buttonEndPin = 4;
int buttonEndState = 0;
int lastButtonEndState = 0;
bool End = false;

void setup() {
  servoBackground.attach(9); //Background servo goes with pin 9
  servoHades.attach(10); //Hades servo goes with pin 10
  servoFloor.attach(11); //Floor servo goes with pin 11
  servoFloor.write(140);
  servoHades.write(0);
  servoBackground.write(0);

  pinMode(buttonFloorPin, INPUT); //FloorButton goes with pin 6
  pinMode(buttonAPin, INPUT); //FloorButton goes with pin 7
  pinMode(buttonBPin, INPUT); //FloorButton goes with pin 8
  pinMode(buttonCPin, INPUT); //FloorButton goes with pin 5
  pinMode(buttonEndPin, INPUT); //FloorButton goes with pin 5
  Serial.begin(9600);
  Serial.println("Start");
}


void loop() {
  
  // Read floor button
  buttonFloorState = digitalRead(buttonFloorPin);
  if (buttonFloorState != lastButtonFloorState) {
    if (buttonFloorState == HIGH) {
      FloorOpen = true;
      Serial.println("Floor Opens");
    }
  }

  //If the floor is open:
  if (FloorOpen == true) {
    servoFloor.write(80);
    
    // make sunny background on HappyEnd button
    if (buttonEndState != lastButtonEndState) {
      if (buttonEndState == HIGH){
        servoBackground.write(0);
      }else {
      servoBackground.write(180);
      }
    }
  }
  lastButtonFloorState = buttonFloorState;

  buttonAState = digitalRead(buttonAPin);
  buttonBState = digitalRead(buttonBPin);
  buttonCState = digitalRead(buttonCPin);



  //Read fruit A
  if (buttonAState != lastButtonAState) {
    if (buttonAState == HIGH) {
      A = true;
      Serial.println("A is there");
    }
  }

  //Read fruit B
  if (buttonBState != lastButtonBState) {
    if (buttonBState == HIGH) {
      B = true;
      Serial.println("B is there");
    }
  }

  //Read fruit C
  if (buttonCState != lastButtonCState) {
    if (buttonCState == HIGH) {
      C = true;
      Serial.println("C is there");
    }
  }

  //check how many fruit are collected
  if (A && B && C) {
    Serial.println("Three fruit");
    servoHades.write(180);
  } else if ((A && B) || (C && B) || (A && C)) {
    Serial.println("Two fruit");
    servoHades.write(120);
  } else if (A || B || C) {
    Serial.println("One fruit");
    servoHades.write(60);
  } else {
    servoHades.write(0);
    Serial.println("No fruit");
  }

  lastButtonAState = buttonAState;
  lastButtonBState = buttonBState;
  lastButtonCState = buttonCState;

}
