#include "myheader.h"

// function to calculate distance
int getDistance() {
  long sum{};
  int count{};
  long duration{};
  long avgDuration{};
  int distance{};

  for (int i{}; i < 3; i++) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH, 25000);

    if (duration > 0) {
      sum += duration;
      count++;
    }

    delay(5);
  }

  if (count == 0) {
    return 999;
  }

  avgDuration = (sum / count);
  distance = (avgDuration * 0.034 / 2 + 0.5);

  return distance;
}


// ---------- Servo Scan ----------
int lookLeft() {
  int distance1{};
  int distance2{};
  int avgDistance{};

  myServo.write(135);
  delay(500);
  distance1 = getDistance();

  myServo.write(180);
  delay(500);
  distance2 = getDistance();

  myServo.write(90);
  delay(300);

  avgDistance = (distance1 + distance2)/2;

  return avgDistance;
}

int lookRight() {
    int distance1{};
    int distance2{};
    int avgDistance{};

    myServo.write(45);
    delay(500);
    distance1 = getDistance();

    myServo.write(0);
    delay(500);
    distance2 = getDistance();

    myServo.write(90);
    delay(200);

    avgDistance = (distance1 + distance2)/2;

    return avgDistance;
}