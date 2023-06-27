#include "Arduino.h"
#include "utils.h"
#include "Keyboard.h"
#ifndef MAC_HID_BRUTE_BRUTE_H
#define MAC_HID_BRUTE_BRUTE_H


class Brute {
  public:
    Brute();
    void increment();
    bool incrementationIsRunning = false;
    int currentPassword = 0;
};


#endif //MAC_HID_BRUTE_BRUTE_H
