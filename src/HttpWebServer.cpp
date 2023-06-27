#include "Arduino.h"
#include "HttpWebServer.h"

HttpWebServer::HttpWebServer() : server(80) {
}

void HttpWebServer::handleRoot() {
  this->server.send(200, "application/json", "{ \"status\": \"ok\" }");
}

void HttpWebServer::setup() {
  this->server.on("/", [this]() { this->handleRoot(); });  //Associate handler function to path
  server.begin();
  Serial.println("Server started");
}

void HttpWebServer::update() {
  this->server.handleClient();
}
