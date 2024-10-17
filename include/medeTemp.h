#ifndef MEDETEMP_H
#define MEDETEMP_H
#define TERM 32

#include <DallasTemperature.h>
#include <OneWire.h>

extern float temp;
extern float tempAtual;
static unsigned long antes;
extern OneWire pino;                  
extern DallasTemperature barramento;
extern DeviceAddress sensor; 
extern unsigned long enviaMQTT;
             

void medeTemp();

#endif