#include "myheader.h"

Servo myServo;
const int servoPin{9};
const int obstacleLimit{20};
unsigned long forwardStartTime{};
const unsigned long forwardTimeout{3000};

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
  bool obstacleDetected{};
  bool forwardTimeoutReached{};

  distance = getDistance();

  obstacleDetected = (distance <= obstacleLimit);
  forwardTimeoutReached = (forwardStartTime != 0 && millis() - forwardStartTime >= forwardTimeout);

  // Start forward motion if path is clear and not already moving
  if (distance > obstacleLimit && forwardStartTime == 0) {
    moveForward();
    forwardStartTime = millis();
  }

  // Run obstacle avoidance if either an obstacle is detected or 5 seconds have elapsed
  if (obstacleDetected || forwardTimeoutReached) {
    stopMotors();
    forwardStartTime = 0; // reset timer

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
