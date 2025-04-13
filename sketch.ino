#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Create an LCD object with the I2C address 0x27 and the size 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int soundSensor1 = A0; // Left Sound Sensor
const int soundSensor2 = A1; // Right Sound Sensor

const int soundThreshold = 500; // Adjust based on sensor testing

// LED pins for traffic light (updated to match simulation connections)
const int redPin = 4;   // Red LED connected to pin 4
const int yellowPin = 5; // Yellow LED connected to pin 5
const int greenPin = 6;  // Green LED connected to pin 6

enum State { NORMAL, AMBULANCE_LEFT };
State currentState = NORMAL;

void setup() {
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  // Initialize LCD
  lcd.begin(16, 2);
  lcd.print("Traffic Light");  // Display an initial message on LCD
  delay(2000);  // Wait for 2 seconds before showing the next message

  // Start in normal traffic mode
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
}

void loop() {
  int leftSound = analogRead(soundSensor1);
  int rightSound = analogRead(soundSensor2);

  // Print sound values every loop
  Serial.print("Left Sound: ");
  Serial.print(leftSound);
  Serial.print(" | Right Sound: ");
  Serial.println(rightSound);

  if (leftSound > soundThreshold && currentState != AMBULANCE_LEFT) {
    // Ambulance detected on the left side, turn on all lights
    Serial.println("🚑 Ambulance detected on LEFT - All lights ON");

    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, HIGH);

    lcd.clear(); // Clear previous message
    lcd.print("🚑 Ambulance Left");  // Display ambulance message
    currentState = AMBULANCE_LEFT;
  }
  else if (leftSound <= soundThreshold && rightSound <= soundThreshold && currentState == AMBULANCE_LEFT) {
    // Back to normal traffic after ambulance has passed
    Serial.println("🛑 Normal Traffic - Default Red");

    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);

    lcd.clear(); // Clear previous message
    lcd.print("🛑 Normal Traffic");  // Display normal traffic message
    currentState = NORMAL;
  }

  delay(300); // Small delay to reduce serial flooding
}
