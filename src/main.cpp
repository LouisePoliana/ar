#include <Arduino.h>
#include "setupWifi.h"
#include "medeTemp.h"
#include "medeMov.h"

void setup() {
  Serial.begin(115200);
  setupWifi();
  medeTemp();
  medeMov();
  pinMode (23, INPUT);
  pinMode (32, INPUT_PULLUP); 
}
void loop() {
 medeTemp();
 medeMov();
}