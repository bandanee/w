// OmniSensor v5.1 - Hybrid Blink
#include <ArduinoJson.h>
const int ledPin = 2;
unsigned long prev = 0;
int state = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (millis() - prev >= 500) {
    prev = millis();
    state = !state;
    digitalWrite(ledPin, state);
    
    StaticJsonDocument<64> doc;
    doc["led"] = state;
    doc["v"] = "1.0";
    serializeJson(doc, Serial);
    Serial.println();
  }
}