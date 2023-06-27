#include <ESP8266WebServer.h>
#ifndef MAC_HID_BRUTE_SETUPWEBSERVER_H
#define MAC_HID_BRUTE_SETUPWEBSERVER_H

class HttpWebServer {
  public:
    HttpWebServer();
    void setup();
    void update();
  private:
    ESP8266WebServer server;
    void handleRoot();
};

#endif //MAC_HID_BRUTE_SETUPWEBSERVER_H
