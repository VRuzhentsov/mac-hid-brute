#include "Arduino.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <LEAmDNS.h>
#include <HTTPUpdateServer.h>

#ifndef MAC_HID_BRUTE_SETUPWEBSERVER_H
#define MAC_HID_BRUTE_SETUPWEBSERVER_H

class HttpWebServer {
  public:
    HttpWebServer();
    void setup();
    void update();
  private:
    WebServer server;
    void handleRoot();
//    static void notFound(AsyncWebServerRequest *request);
};

#endif //MAC_HID_BRUTE_SETUPWEBSERVER_H
