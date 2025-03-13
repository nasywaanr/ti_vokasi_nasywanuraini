#include <Arduino.h>

// Define pin numbers
const int buttonPin = 19;  // GPIO19 connected to the pushbutton
const int ledPin = 18;     // GPIO18 connected to the LED
const int relayPin = 23;   // GPIO23 connected to the relay module

void setup() {
  // Set pin modes
  pinMode(buttonPin, INPUT_PULLUP);  // Set the button pin as an input with an internal pull-up resistor
  pinMode(ledPin, OUTPUT);           // Set the LED pin as an output
  pinMode(relayPin, OUTPUT);         // Set the relay pin as an output
  
  // Initialize the outputs to be OFF
  digitalWrite(ledPin, LOW);
  digitalWrite(relayPin, LOW);
}

void loop() {
  // Read the state of the button
  int buttonState = digitalRead(buttonPin);
  
  // Check if the button is pressed
  // Since the button is wired to pull the pin LOW when pressed, we check for LOW
  if (buttonState == LOW) {
    digitalWrite(ledPin, HIGH);     // Turn on the LED
    digitalWrite(relayPin, HIGH);   // Turn on the relay
  } else {
    digitalWrite(ledPin, LOW);      // Turn off the LED
    digitalWrite(relayPin, LOW);    // Turn off the relay
  }
}
