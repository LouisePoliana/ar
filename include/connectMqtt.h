#ifndef CONNECTMQTT_H
#define CONNECTMQTT_H
#include <PubSubClient.h>
#include <WiFi.h>

void connectMqtt();

extern const char *mqtt_server; //ou 127.17.0.2 ip
extern const int mqtt_port;

extern WiFiClient espClient;
extern PubSubClient client;

extern const char* topicTemperatura;
extern const char* topicMovimento;
extern const char* topicEvaporadora;
extern const char* topicCondensadora;
extern const char* topicEstado;
extern const char* topicData;
extern const char* topicHora;

// Intervalo de envio de dados
//extern const unsigned long enviaMQTT; // em milissegundos

#endif