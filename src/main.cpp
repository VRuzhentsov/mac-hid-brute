#include "Arduino.h"
#include "Keyboard.h"
#include <ESP8266WiFi.h>
#include "mdnsSetup.h"
#include "HttpWebServer.h"
#include "utils.h"
#include "Brute.h"

#include "WifiCredentials.h"

char wifi_ssid[] = WIFI_SSID;
char wifi_password[] = WIFI_PASSWORD;

HttpWebServer httpServer;
Brute brute;

void setup()
{
  short_blink();
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Keyboard.begin();

  WiFi.mode(WIFI_STA);
  WiFi.begin(wifi_ssid, wifi_password);

  short_blink();
  Serial.print("Connecting to WiFi.");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  short_blink();
  Serial.print("IP: "); Serial.println(WiFi.localIP());

  MDNS.begin("rpipicow");
  httpServer.setup();

  MDNS.addService("http", "tcp", 80);

  delay(5000);
}

void loop()
{
  if(brute.incrementationIsRunning) {
    brute.increment();
  }
  httpServer.update();
  MDNS.update();

  delay(1000);
}