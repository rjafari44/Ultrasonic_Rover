#pragma once

#include <Servo.h>
#include <Arduino.h>

// motor pins
inline constexpr int ENA = 3;
inline constexpr int IN1 = 4;
inline constexpr int IN2 = 8;
inline constexpr int IN3 = 6;
inline constexpr int IN4 = 7;
inline constexpr int ENB = 5;

// ultrasonic pins
inline constexpr int trigPin = 10;
inline constexpr int echoPin = 11;

extern Servo myServo;

int getDistance();
int lookLeft();
int lookRight();

void moveForward();
void moveBackward();
void turnLeft();
void turnRight();
void stopMotors();
