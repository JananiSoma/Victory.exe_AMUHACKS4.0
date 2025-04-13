// Pin definitions for sound sensors
const int soundSensor1 = A0;
const int soundSensor2 = A1;

// Sound threshold
const int soundThreshold = 500;

// LED pins for traffic light
const int redPin = 6;
const int yellowPin = 7;
const int greenPin = 8;

void setup() {
  // LED pin setup
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  int sensorValue1 = analogRead(soundSensor1);
  int sensorValue2 = analogRead(soundSensor2);

  // Condition for Sensor 1 (Ambulance Detected - Give Way)
  if (sensorValue1 > soundThreshold) {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);  // Only Green ON
  }
  // Condition for Sensor 2 (Emergency Alert - All Lights)
  else if (sensorValue2 > soundThreshold) {
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, HIGH);  // All ON
  }
  else {
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);  // Default to Red ON
  }

  delay(500);  // Check every 0.5 seconds
}
