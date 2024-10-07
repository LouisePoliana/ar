#include <Arduino.h>
#include "medeMov.h"

#define sensorPir 23

void medeDist() {
    int valorPir = 0;
    int estadoAntes = LOW;
    int estadoAgora =  LOW;
    estadoAntes = estadoAgora;
    estadoAgora = digitalRead(sensorPir);
    if (estadoAntes == LOW && estadoAgora == HIGH) {
        Serial.println("Movimento detectado!");
    } else if (estadoAntes == HIGH && estadoAgora == LOW) {
        Serial.println("Não há movimento!");
    }
}