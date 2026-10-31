#include <Arduino.h>
#include <WiFi.h>

#define LED_PIN 2

const char* ssid = "";
const char* password = "";

void setup() {
  // use webserver to send hello message to ensure connection is live
  Serial.begin(115200);
  delay(1000);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Connecting to phone hotspot");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected successfully!");
  Serial.print("IP Address assigned by phone: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Your main code here
  
}