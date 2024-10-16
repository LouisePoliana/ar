#include <Arduino.h>
#include "medeMov.h"

int estadoMovimento = 0; // Definição da variável
unsigned long ultimoTempo = 0; // Definição da variável
unsigned long intervalo = 10000; // Definição da variável
unsigned long tempoSemMovimento = 5000; // 5 segundos

void medeMov() {
  int leitura = digitalRead(SENSORPIR);
  
  // Se o sensor detecta movimento
  if (leitura == HIGH && estadoMovimento == 0) {
    Serial.println("Movimento detectado!");
    digitalWrite (LED1, HIGH);
    delayMicroseconds (4000);
    estadoMovimento = 1;
    ultimoTempo = millis(); // Armazena o tempo da detecção
  }

  // Se o sensor não detecta movimento
  if (leitura == LOW && estadoMovimento == 1) {
    // Se passou o tempo sem movimento
    if (millis() - ultimoTempo >= tempoSemMovimento) { //tempo é igual a 5 segundos
      Serial.println("Não há movimento.");
      digitalWrite (LED2, HIGH);
      delayMicroseconds (4000);
      estadoMovimento = 0; // Reseta o estado
    }
  }
  // Verifica se o tempo desde a última detecção excedeu o intervalo
  if (estadoMovimento == 1 && (millis() - ultimoTempo > intervalo)) { // se há movimento e o tempo é maior do que 10 segundos
    Serial.println("Houve movimento a mais de 10 segundos");
    estadoMovimento = 0; // Reseta o estado após o intervalo
  }
}