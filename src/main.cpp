#include <Arduino.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#include <NTPClient.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
#include "setupWifi.h"
#include "medeTemp.h"
#include "medeMov.h"
#include "connectMQTT.h"
#include "obterDatahora.h"

OneWire pino(TERM);                    // instância da classe onewire que se conecta ao pino 32 do esp
DallasTemperature barramento(&pino); // cria instância e passa a o endereço da instância pino (conexão)
DeviceAddress sensor;                // tipo de variável que armazena endereço do sensor de temperatura
/*WiFiClient espClient;
PubSubClient client;
const char* topicTemperatura; // sensor lê
const char* topicMovimento;
const char* topicEvaporadora;
const char* topicCondensadora;
const char* topicEstado;
const char* topicData;
const char* topicHora;
*/
void setup() {
  Serial.begin(115200);
  barramento.begin(); 
  delay (500);
  setupWifi();
  medeTemp();
  medeMov();
  connectMqtt();
  pinMode (SENSORPIR, INPUT);
  pinMode (TERM, INPUT); 
}
void loop() {
 medeTemp();
 medeMov();
 connectMqtt();
 client.loop();

}