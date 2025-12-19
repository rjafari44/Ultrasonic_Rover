#include "myheader.h"

Servo myServo; // create servo object
const int servoPin = 9;       // set servo pin
const int obstacleLimit = 20; // limit at which to perform turns

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myServo.attach(servoPin);
  myServo.write(90); // center

  delay(1000);
}

void loop() {
  int distance{};
  int leftDist{};
  int rightDist{};

  distance = getDistance();

  if (distance > obstacleLimit) {
    moveForward();
  } else {
    stopMotors();
    delay(200);

    moveBackward();
    delay(300);
    stopMotors();

    leftDist = lookLeft();
    rightDist = lookRight();

    if (leftDist > rightDist) {
      turnLeft();
    } else {
      turnRight();
    }

    delay(400);
    stopMotors();
  }
}