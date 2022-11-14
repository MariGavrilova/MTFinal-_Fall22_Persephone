#include <Servo.h>

// setup Servo Background
Servo servoBackground;
const int buttonPin2 = 2;

//setup Servo Hades
Servo servoHades;
const int buttonPin3 = 3;

//setup Servo Floor
Servo servoFloor;
const int buttonPin4 = 4;

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
const int buttonCPin = 9;
int buttonCState = 0;
int lastButtonCState = 0;
bool C = false;


void setup() {
  servoBackground.attach(9); //Background servo goes with pin 9
  pinMode(buttonPin2, INPUT);
  servoBackground.attach(10); //Hades servo goes with pin 10
  pinMode(buttonPin3, INPUT);
  servoBackground.attach(11); //Floor servo goes with pin 11
  pinMode(buttonPin4, INPUT);

  pinMode(buttonFloorPin, INPUT); //FloorButton goes with pin 6 
  pinMode(buttonAPin, INPUT); //FloorButton goes with pin 7
  pinMode(buttonBPin, INPUT); //FloorButton goes with pin 8
  pinMode(buttonCPin, INPUT); //FloorButton goes with pin 9
  Serial.begin(9600);
  Serial.println("Start Part A");
}


void loop() {

  buttonFloorState = digitalRead(buttonFloorPin);

  // Read floor button
  if (buttonFloorState != lastButtonFloorState){
    if (buttonFloorState == HIGH) {
      FloorOpen = true;
      Serial.println("Start gathering A B and C");
    }
  }

  //If the floor is open:
  if (FloorOpen == true){

    buttonAState = digitalRead(buttonAPin);
    buttonBState = digitalRead(buttonBPin);
    buttonCState = digitalRead(buttonCPin);

    //Read fruit A
    if (buttonAState != lastButtonAState){
      if (buttonAState == HIGH){
        A = true;
      }
    }

    //Read fruit B
    if (buttonBState != lastButtonBState){
      if (buttonBState == HIGH){
        B = true;
      }
    }
    
    //Read fruit C
    if (buttonCState != lastButtonCState){
      if (buttonCState == HIGH){
        C = true;
      }
    }

    if (A || B || C){
      Serial.println("One fruit");
    }
    if (A || B || C){
      Serial.println("Two fruit");
    }
    if (A && B && C){
      Serial.println("Three fruit");
    }

    lastButtonAState = buttonAState;
    lastButtonBState = buttonBState;
    lastButtonCState = buttonCState;

    
  }
  lastButtonFloorState = buttonFloorState;



  /*
  if (digitalRead(buttonPin2) == HIGH){
    servoBackground.write(180);                      
  } else{
    servoBackground.write(0);
  }
  */
}
