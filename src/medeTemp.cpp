#include <DallasTemperature.h>
#include <OneWire.h>
#include <NTPClient.h>
#include "medeTemp.h"
#include "connectMqtt.h"

float temp;
float tempAtual = 0;
unsigned long enviaMQTT = millis() + 60000;
void medeTemp()
{
  static unsigned long antes = 0;
  unsigned long agora = millis();
 if ((agora - antes) >= 60000) //
  {
    barramento.requestTemperatures();     // solicita ao sensor que envie a leitura da temperatura
    temp = barramento.getTempCByIndex(0); // obtém a temp em celsius no 0
    if (temp > 0 && temp < 50)
    {
      tempAtual = temp;
      Serial.print("Temperatura: ");
      Serial.print(tempAtual);
      Serial.println("ºC");
      const char* temperatura = "tempAtual"; // Definindo o tópico corretamente
      char payload[8]; // Buffer para armazenar a string da temperatura
      // Formata a temperatura como uma string
        snprintf(payload, sizeof(payload), "%.2f", tempAtual); // Formata a temperatura com 2 casas decima
        if (millis() >= enviaMQTT){ //Se for maior ou igual a 1 minuto
          client.publish(temperatura, payload); // Publica a temperatura
          enviaMQTT = millis()+60000;
    }
    antes = agora; // atualização fora do if
  }
}
}