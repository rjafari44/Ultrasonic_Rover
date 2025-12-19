#include "myheader.h"

Servo myServo;   // create servo object
const int servoPin{9};       // set servo pin
const int obstacleLimit{20}; // distance threshold

unsigned long forwardStartTime{};          // tracks forward motion start
const unsigned long forwardTimeout{5000};   // 5 seconds

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

  // forward logic
  if (distance > obstacleLimit) {

    // Start moving forward if not already
    if (forwardStartTime == 0) {
      moveForward();
      forwardStartTime = millis();
    }

    // Stop after 5 seconds max
    if (millis() - forwardStartTime >= forwardTimeout) {
      stopMotors();
      forwardStartTime = 0; // reset
    }

    // Exit loop early; forward motion handled
    return;
  } else {
    stopMotors();
    forwardStartTime = 0; // reset in case it wasn't already

    // Back up a bit
    delay(200);
    moveBackward();
    delay(300);
    stopMotors();

    // Look left and right
    leftDist = lookLeft();
    rightDist = lookRight();

    // Decide which way to turn
    if (leftDist > rightDist) {
      turnLeft();
    } else {
      turnRight();
    }

    delay(400);
    stopMotors();
  }
}
