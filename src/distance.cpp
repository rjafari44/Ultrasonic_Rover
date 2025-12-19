#include "myheader.h"

// function to calculate distance
int getDistance() {
  long duration{};

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 25000);
  if (duration == 0) {
    return 999;
  } 
  else {
    return duration * 0.034 / 2;
  }
}

// ---------- Servo Scan ----------
int lookLeft() {
  int distance{};
  myServo.write(150);
  delay(500);
  distance = getDistance();
  myServo.write(90);
  delay(200);
  return distance;
}

int lookRight() {
    int distance{};
    myServo.write(30);
    delay(500);
    distance = getDistance();
    myServo.write(90);
    delay(200);
    return distance;
}