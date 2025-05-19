#include "temperatura.h"
#include <Arduino.h>

void setupTemperatureSensor() {
  // e.g., analogRead setup
  pinMode(A0, INPUT);
}

float readTemperature() {
  int analogValue = analogRead(A0);
  return (analogValue / 1023.0) * 100.0;  // Example conversion
}

