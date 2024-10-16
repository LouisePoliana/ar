#include <WiFi.h>
#include "setupWifi.h"

#define WIFI_SSID "Metropole"
#define WIFI_SENHA "908070Metropole"

void setupWifi(){
  WiFi.begin (WIFI_SSID, WIFI_SENHA);
  while ((WiFi.status() != WL_CONNECTED)) {
    delay(1000);
    Serial.println("Tentando conectar-se ao wifi");
  }
  Serial.println("Conectado ao wifi!");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP() );
  digitalWrite (LED_INTERNO, HIGH);
  }