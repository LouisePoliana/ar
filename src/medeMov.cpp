#include <Arduino.h>
#include "medeMov.h"

void medeMov() {
    int estadoAntes = LOW;
    int estadoAgora =  LOW;
    estadoAntes = estadoAgora;
    estadoAgora = digitalRead(SENSORPIR);
    if (estadoAntes == LOW && estadoAgora == HIGH) {
        Serial.println("Movimento detectado!");
    } else if (estadoAntes == HIGH && estadoAgora == LOW) {
        Serial.println("Não há movimento!");
    }
}