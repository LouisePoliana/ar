#ifndef OBTERDATAHORA_H
#define OBTERDATAHORA_H
#include <NTPClient.h>
#include <WiFiUdp.h>

void obterDatahora();

extern WiFiUDP udp;
extern NTPClient ntp(udp, "a.st1.ntp.br", -3 * 3600, 60000); //servidor ntp (DUVIDA NA DECLARACAO)
extern char dataFormatada[64];
extern char horaFormatada[64];
struct tm data; //DUVIDA NA DECLARACAO

#endif