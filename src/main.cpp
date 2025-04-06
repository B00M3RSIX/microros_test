#include <Arduino.h>
// Pin definitions
const int ledPin = 13;  // Teensy 4.0 has an onboard LED connected to pin 13

// Variables
int ledState = LOW;           // LED state
unsigned long previousMillis = 0;  // Store the last time LED was updated
const long interval = 1000;        // Blink interval (milliseconds)

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  
  // Optional: Start serial for debugging
  Serial.begin(9600);
  Serial.println("Teensy 4.0 Blink Sketch Started");
}

void loop() {
  // Check if it's time to blink the LED
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    // Save the last time you blinked the LED
    previousMillis = currentMillis;
    
    // Toggle the LED state
    if (ledState == LOW) {
      ledState = HIGH;
      Serial.println("LED ON");
    } else {
      ledState = LOW;
      Serial.println("LED OFF");
    }
    
    // Update the LED
    digitalWrite(ledPin, ledState);
  }
}