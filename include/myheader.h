#pragma once

// include the necessary header files for the servo and arduino nano
#include <Servo.h>
#include <Arduino.h>

// set motor driver pins of integer type
inline constexpr int ENA = 3;
inline constexpr int IN1 = 4;
inline constexpr int IN2 = 8;
inline constexpr int IN3 = 6;
inline constexpr int IN4 = 7;
inline constexpr int ENB = 5;

// set ultrasonic pins of integer type
inline constexpr int trigPin = 10;
inline constexpr int echoPin = 11;

// declare the Servo object externally
extern Servo myServo;

// functions for gathering distances from the servo + ultrasonic combo
int getDistance();
int lookLeft();
int lookRight();

// functions for motor movements
void moveForward();
void moveBackward();
void turnLeft();
void turnRight();
void stopMotors();
