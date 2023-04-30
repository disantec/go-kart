// This code is to run a all wheel drive go kart using brushless dc motors controlled via PWM

// Import the necessary libraries
#include <Arduino.h>
#include <Servo.h>

const int motorPin = 9;
const int motorThrottlePin = A0;
const int modePotPin = A1;

// Create a Servo object for the motor
Servo motor;

// Define the variables for the motor speed and direction
int motorSpeedValue = 0;
int motorDirection = 1;

// the setup function runs once when you press reset or power the board

void setup() {
  // Attach the motor to the motorPin
  motor.attach(motorPin);

  // Set the motor speed to 0 on startup
  motorSpeedValue = 0;

  // Set the motor direction to neutral on startup
  motorDirection = 0;
  
}

// the loop function runs over and over again forever
void loop() {
  // Read the value of the mode potentiometer
  int modePotValue = analogRead(modePotPin);


  // If the mode potentiometer is at a low voltage, turn off the motor
  if (modePotValue < 512) {
    motorDirection = 0;
  }

  // If the mode potentiometer is at a medium voltage, turn the motor mode
  if (modePotValue > 512 && modePotValue < 1023) {
    motorDirection = 1;
  }

  // If the mode potentiometer is at a high voltage, turn the motor backward
  if (modePotValue > 1023) {
    motorDirection = -1;
  }

  motorSpeedValue=analogRead(motorThrottlePin)*motorDirection;

  // Set the motor speed
  motor.write(motorSpeedValue);
}