#include <Arduino.h>
#include "setupWifi.h"
#include "medeTemp.h"
#include "medeMov.h"

void setup() {
  Serial.begin(115200);
  setupWifi();
  medeTemp();
  medeMov();
  pinMode (SENSORPIR, INPUT);
  pinMode (TERM, INPUT); 
}
void loop() {
 medeTemp();
 medeMov();

}