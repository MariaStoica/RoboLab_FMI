// 27 Oct 2015
// code for Andrei and Maria's prototype 1: Whiteboard - from SmartCardboard
// with listeners

#include <stdafx.h>
#include <targetver.h>

#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>

#include <Robotel.h>
#include <Observer.h>
#include <Observee.h>
#include <DistanceSensor.h>
#include <ColorSensor.h>

//#include <string>
//#include <vector>
//#include <algorithm>

int MOTOR2_PIN1 = 5;
int MOTOR2_PIN2 = 3;
int MOTOR1_PIN1 = 9;
int MOTOR1_PIN2 = 6;

Robotel* robotel;
DistanceSensor* distance_front; // pin 0
DistanceSensor* distance_left;  // pin 1
DistanceSensor* distance_right; // pin 2
ColorSensor* color_back;        // pin 3
ColorSensor* color_left;        // pin 4
ColorSensor* color_right;       // pin 5

int val_distance_front, val_distance_left, val_distance_right;
int val_color_back, val_color_left, val_color_right;

void setup() {
  // put your setup code here, to run once:
  
  // setam sloturile motoarelor pe output
  pinMode(MOTOR1_PIN1, OUTPUT);
  pinMode(MOTOR1_PIN2, OUTPUT);
  pinMode(MOTOR2_PIN1, OUTPUT);
  pinMode(MOTOR2_PIN2, OUTPUT);
  
  // setam sloturile pentru input de la sezori
  pinMode(val_distance_front, INPUT);
  pinMode(val_distance_left, INPUT);
  pinMode(val_distance_right, INPUT);
  pinMode(val_color_back, INPUT);
  pinMode(val_color_left, INPUT);
  pinMode(val_color_right, INPUT);
  
  robotel = new Robotel();
  distance_front = new DistanceSensor(0, "distance front"); // nu trebuia pus un ; la metoda virtuala din Observer
  distance_left = new DistanceSensor(1, "distance left");
  distance_right = new DistanceSensor(2, "distance right");
  color_back = new ColorSensor(3, "color back");
  color_left = new ColorSensor(4, "color left");
  color_right = new ColorSensor(5, "color right");

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  

}
