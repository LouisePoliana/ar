#ifndef MEDETEMP_H
#define MEDETEMP_H
#define TERM 32

extern float temp;
extern float tempAtual;
static unsigned long antes;
extern OneWire pino;                  
extern DallasTemperature barramento;
extern DeviceAddress sensor;              

void medeTemp();

#endif