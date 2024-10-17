#include <DallasTemperature.h>
#include <OneWire.h>
#include "medeTemp.h"

float temp;
float tempAtual = 0;
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
    }
    antes = agora; // atualização fora do if
  }
}