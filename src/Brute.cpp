#include "Brute.h"

Brute::Brute() = default;

void Brute::increment(){
  if(this->currentPassword <= 999999) {
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