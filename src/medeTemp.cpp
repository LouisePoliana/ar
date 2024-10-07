#include <DallasTemperature.h>
#include <OneWire.h>
#include "medeTemp.h"

OneWire pino(32); //instância da classe onewire que se conecta ao pino 32 do esp
DallasTemperature barramento(&pino); //cria instância e passa a o endereço da instância pino (conexão)
DeviceAddress sensor; //tipo de variável que armazena endereço do sensor de temperatura

void medeTemp() {
    float temp;
    float tempAtual = 0;
    static unsigned long antes = 0;
    unsigned long agora = millis();
  Serial.println("Iniciando a medição da temperatura");
  if ((agora-antes) >= 60000){
    barramento.requestTemperatures();  //solicita ao sensor que envie a leitura da temperatura
    temp = barramento.getTempC(sensor); //obtém temperatura em Celsius
    if (temp >0 && temp <50){
      tempAtual = temp;
      Serial.print("Temperatura: ");
      Serial.print(tempAtual);
      antes = agora;
  } 
  }
}