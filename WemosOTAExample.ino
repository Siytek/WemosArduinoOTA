#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>
#include "basicOTA.h"
 
// Set WiFi credentials
#define WIFI_SSID "YOUR SSID"
#define WIFI_PASS "YOUR PASSWORD"
 
void setup() {

  // Setup LED
  pinMode(LED_BUILTIN, OUTPUT);
  
  // Setup serial port
  Serial.begin(115200);
  Serial.println();
 
  //Begin WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASS);
 
  // Connecting to WiFi...
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  // Loop continuously while WiFi is not connected
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }
 
  // Connected to WiFi
  Serial.println();
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

  // Setup Firmware update over the air (OTA)
  setup_OTA();
 
}
 
void loop() {

  // Check for OTA updates
  ArduinoOTA.handle();

  // Blink LED
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  
 
}
