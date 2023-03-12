#include "DualVNH5019MotorShieldMod3.h"
DualVNH5019MotorShieldMod3 md;


void setup() {
  Serial.begin(115200);
  //start the motor shields and motor pins
  md.init();

  pinMode(LED_BUILTIN, OUTPUT);
}

int speedOfMotors = 500;
int speedOfMotorsRotate = 200;

void moveForward(){
  digitalWrite(LED_BUILTIN, HIGH);

  md.setM1Speed(-speedOfMotors);
  md.setM2Speed(speedOfMotors);
  md.setM3Speed(-speedOfMotors);
  md.setM4Speed(speedOfMotors);
}

void moveBackward(){
  digitalWrite(LED_BUILTIN, HIGH);

  speedOfMotors = -speedOfMotors;
  md.setM1Speed(-speedOfMotors);
  md.setM2Speed(speedOfMotors);
  md.setM3Speed(-speedOfMotors);
  md.setM4Speed(speedOfMotors);
  speedOfMotors = -speedOfMotors;
}

void moveLeft(){
  digitalWrite(LED_BUILTIN, HIGH);

  md.setM1Speed(speedOfMotorsRotate);
  md.setM2Speed(speedOfMotorsRotate);
  md.setM3Speed(speedOfMotorsRotate);
  md.setM4Speed(speedOfMotorsRotate);
}

void moveRight(){
  digitalWrite(LED_BUILTIN, HIGH);

  speedOfMotorsRotate = -speedOfMotorsRotate;
  md.setM1Speed(speedOfMotorsRotate);
  md.setM2Speed(speedOfMotorsRotate);
  md.setM3Speed(speedOfMotorsRotate);
  md.setM4Speed(speedOfMotorsRotate);
  speedOfMotorsRotate = -speedOfMotorsRotate;
}
void stop(){
  md.setM1Speed(0);
  md.setM2Speed(0);
  md.setM3Speed(0);
  md.setM4Speed(0);
}
void cube(){
  digitalWrite(LED_BUILTIN, HIGH);

  int speedkvad = 150;
  int del = 1000;
  //forward
  md.setM1Speed(-speedkvad);
  md.setM2Speed(speedkvad);
  md.setM3Speed(-speedkvad);
  md.setM4Speed(speedkvad);
  delay(del);
  stop();
  delay(100);

  //right
  md.setM1Speed(-speedkvad);
  md.setM2Speed(-speedkvad);
  md.setM3Speed(speedkvad);
  md.setM4Speed(speedkvad);
  delay(del);
  stop();
  delay(100);

  //down
  md.setM1Speed(speedkvad);
  md.setM2Speed(-speedkvad);
  md.setM3Speed(speedkvad);
  md.setM4Speed(-speedkvad);
  delay(del);
  stop();
  delay(100);

  //left
  md.setM1Speed(speedkvad);
  md.setM2Speed(speedkvad);
  md.setM3Speed(-speedkvad);
  md.setM4Speed(-speedkvad);
  delay(del);
  stop();
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    Serial.print("You sent me: ");
    Serial.println(data);

    if (data == "SET_SPEED"){
      String speed = Serial.readStringUntil('\n');
      speedOfMotors = speed.toInt();
      Serial.print("I set speed to ");
      Serial.println(speed);
    }
    if (data == "FORWARD"){
      moveForward();
    }
    if (data == "BACKWARD"){
      moveBackward();
    }
    if (data == "LEFT"){
      moveLeft();
    }
    if (data == "RIGHT"){
      moveRight();
    }

    if (data == "CUBE"){
      cube();
    }
    
    if (data == "STOP"){
      digitalWrite(LED_BUILTIN, LOW);
      md.setM1Speed(0);
      md.setM2Speed(0);
      md.setM3Speed(0);
      md.setM4Speed(0);
    }
  }
}
