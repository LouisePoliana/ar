#include <Arduino.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#include "setupWifi.h"
#include "medeTemp.h"
#include "medeMov.h"

OneWire pino(TERM);                    // instância da classe onewire que se conecta ao pino 32 do esp
DallasTemperature barramento(&pino); // cria instância e passa a o endereço da instância pino (conexão)
DeviceAddress sensor;                // tipo de variável que armazena endereço do sensor de temperatura

void setup() {
  Serial.begin(115200);
  barramento.begin(); 
  delay (500);
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