#include "Arduino.h"
#include <ESP8266mDNS.h>


void setupMDNS() {
  // Set up mDNS responder:
  if (MDNS.begin("rpipicow")) {              // Start the mDNS responder for esp8266.local
    Serial.println("mDNS responder started");
  } else {
    Serial.println("Error setting up MDNS responder!");
  }
  // Add service to MDNS-SD
  MDNS.addService("http", "tcp", 80);
}

void updateMDNS() {
  MDNS.update();
}