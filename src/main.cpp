/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"
#include "Keyboard.h"

#include "WifiCredentials.h"

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

int currentPassword = 0;
bool incrementationIsRunning = true;

void short_blink() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}

void increment(){
  if(currentPassword <= 999999) {
    String password = String(currentPassword);
    while (password.length() < 6) {
      password = "0" + password; // If the number has less than 6 digits, prepend 0s to it
    }
    Keyboard.println(password);

    short_blink();

    delay(10000);

    currentPassword++; // Increase the password by 1
  } else {
    incrementationIsRunning = false;
  }
}

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Keyboard.begin();

  delay(5000);
}

void loop()
{
  if(incrementationIsRunning) {
    increment();
  }

  delay(1000);
}