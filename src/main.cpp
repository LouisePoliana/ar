#include <Arduino.h>
#include "setupWifi.h"
#include "medeTemp.h"
#include "medeMov.h"

void setup() {
  Serial.begin(115200);
  setupWifi();
  medeTemp();
  medeDist();
  pinMode (sensorPir, INPUT);
  pinMode (32, INPUT_PULLUP); 
}
void loop() {
 medeTemp();
 medeDist();
}