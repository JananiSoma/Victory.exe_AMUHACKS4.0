#include <LiquidCrystal.h>

// Pin definitions
const int soundSensor1 = A0;
const int soundSensor2 = A1;
const int soundSensor3 = A2;
const int soundSensor4 = A3;

// Threshold for sound level to detect ambulance
const int soundThreshold = 500; // Adjust this value as per sensor sensitivity

// Create LCD object
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Initialize the LCD
  lcd.begin(16, 2);  // 16 characters and 2 lines
  lcd.setCursor(0, 0);
  lcd.print("Ambulance System");
  delay(2000);  // Wait for 2 seconds
  lcd.clear();
}

void loop() {
  // Read the sound sensor values
  int sensorValue1 = analogRead(soundSensor1);
  int sensorValue2 = analogRead(soundSensor2);
  int sensorValue3 = analogRead(soundSensor3);
  int sensorValue4 = analogRead(soundSensor4);

  // Display on the LCD
  lcd.setCursor(0, 0);

  // Check if any of the sound sensors detect an ambulance sound (based on the threshold)
  if (sensorValue1 > soundThreshold || sensorValue2 > soundThreshold || sensorValue3 > soundThreshold || sensorValue4 > soundThreshold) {
    lcd.clear();
    lcd.print("Ambulance Detected");
  } else {
    lcd.clear();
    lcd.print("No Detection");
  }

  delay(500);  // Wait for 0.5 second before checking again
}
