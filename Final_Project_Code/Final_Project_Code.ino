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
  Serial.begin(9600);
  Serial.println("Start");
}


void loop() {

  buttonFloorState = digitalRead(buttonFloorPin);
  // Read floor button
  if (buttonFloorState != lastButtonFloorState) {
    if (buttonFloorState == HIGH) {
      FloorOpen = true;
      Serial.println("Floor Opens");
    }
  }

  //If the floor is open:
  if (FloorOpen == true) {
    servoFloor.write(80);
    servoBackground.write(180);
  }
  lastButtonFloorState = buttonFloorState;

  buttonAState = digitalRead(buttonAPin);
  buttonBState = digitalRead(buttonBPin);



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
  /*
      if (A || B){
        Serial.println("One fruit");
        servoHades.write(80);
      }*/
  if (A && B) {
    Serial.println("Two fruit");
    servoHades.write(180);
  } else if (A || B) {
    Serial.println("One fruit");
    servoHades.write(80);
  } else {
    servoHades.write(0);
    Serial.println("No fruit");
  }

  lastButtonAState = buttonAState;
  lastButtonBState = buttonBState;





}


/*
  if (digitalRead(buttonPin2) == HIGH){
  servoBackground.write(180);
  } else{
  servoBackground.write(0);
  }
*/

