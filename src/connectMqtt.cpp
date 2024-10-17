#include "connectMqtt.h"
#include <WiFiClient.h>
#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient client(espClient);

const char* mqtt_server = "localhost"; //ou 127.17.0.2 ip
const int mqtt_port = 1883;

const char* topicTemperatura = "temperatura"; // sensor lê
const char* topicMovimento = "movimento";
const char* topicEvaporadora = "evaporadora";
const char* topicCondensadora = "condensadora";
const char* topicEstado = "estado";
const char* topicData = "dataAtual";
const char* topicHora = "horaAtual";

void connectMqtt(){
    while (!client.connected()){
    Serial.print("Tentando se conectar ao MQTT");
    delay(2000);
  }
  if (client.connect("esp32Client")){
    Serial.println("Conectado ao MQTT");
  
    client.subscribe(topicTemperatura);
    client.subscribe(topicMovimento);
    client.subscribe(topicEvaporadora);
    client.subscribe(topicCondensadora);
    client.subscribe(topicData);
    client.subscribe(topicHora);
    client.subscribe(topicEstado);

  } else {
    Serial.println("Falha na conexão ao MQTT");
    delay(2000);
}
}