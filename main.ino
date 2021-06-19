/*
   author: Khaled Wael
   date started:1/5/2021
   date ended: 1/7/2021

   objective: This program is
   for RCJ car that is provided
   with all these sensors.

   country: Egypt 
   Entity: Awasis science
   supervised by: Ahmed Tarek
*/
extern "C"{
  #include "MotorDriver.h"
  #include "PID.h"
  #include "Tilt.h"
  #include "serial_communication.h"
}
#include <Servo.h>
Servo myservo1;
Servo myservo2;

void setup() {
  //intializing serial port with baud rate of 9600
  serial.begin(9600);
  myservo1.attach(A0);
  myservo2.attach(A1);
  qtr.setTypeRC();
  //Set up the sensor array pins
  qtr.setSensorPins((const uint8_t[]) {
    10, 11, 12, 14, 15, 16, 18, 19
  }, SensorCount);
  qtr.setEmitterPin(7);//LEDON PIN

  pinMode(mode, OUTPUT);
  pinMode(aphase, OUTPUT);
  pinMode(aenbl, OUTPUT);
  pinMode(bphase, OUTPUT);
  pinMode(benbl, OUTPUT);
  digitalWrite(mode, HIGH);

  delay(500);
  pinMode(LED_BUILTIN, OUTPUT);

  bool done = false;
  forward_brake(0, 0);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(buttonstart) == HIGH) {
    onoff = ! onoff;
    if (onoff = true) {
      delay(1000);//a delay when the robot starts
    }
    else {
      delay(50);
    }
  }
  if (onoff == true) {
    PID_control();
  }
  else {
    forward_brake(0, 0);
  }
}
}
