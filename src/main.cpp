#include <Arduino.h>

#define LED_PIN 2
// Define Motor Driver Pins
const int pinENA = 12; // PWM Speed Control Pin
const int pinIN1 = 14; // Direction Pin 1
const int pinIN2 = 27; // Direction Pin 2

// Direction Constants
const int FORWARD = 1;
const int BACKWARD = 0;

void setup() {
  // Initialize all motor control pins as outputs
  pinMode(LED_PIN, OUTPUT);
  pinMode(pinENA, OUTPUT);
  pinMode(pinIN1, OUTPUT);
  pinMode(pinIN2, OUTPUT);
}

void loop() {
  // Spin Forward at half speed (128 out of 255) for 2 seconds
  controlMotor(FORWARD, 128);
  delay(2000);

  // Stop the motor for 1 second
  controlMotor(FORWARD, 0);
  delay(1000);

  // Spin Backward at full speed (255) for 2 seconds
  controlMotor(BACKWARD, 255);
  delay(2000);

  // Stop the motor for 1 second
  controlMotor(FORWARD, 0);
  delay(1000);
}

/**
 * Controls a single motor's direction and speed.
 * @param direction: 1 for FORWARD, 0 for BACKWARD
 * @param speed: PWM value from 0 (stopped) to 255 (full speed)
 */
void controlMotor(int direction, int speed) {
  // Write the PWM speed to the enable pin
  analogWrite(pinENA, speed);

  // Set direction pins
  if (direction == FORWARD) {
    digitalWrite(pinIN1, HIGH);
    digitalWrite(pinIN2, LOW);
  } else {
    digitalWrite(pinIN1, LOW);
    digitalWrite(pinIN2, HIGH);
  }
}