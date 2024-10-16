#ifndef MEDEMOV_H
#define MEDEMOV_H
#define SENSORPIR 23
#define LED1 26
#define LED2 27
//extern int estadoAntes;  // Declare a variável
//extern int estadoAgora;  // Declare a variável

extern int estadoMovimento; // 0 = não detectado, 1 = detectado
extern unsigned long ultimoTempo; // Tempo da última detecção
extern unsigned long intervalo; // 10 segundos para resetar o estado
extern unsigned long tempoSemMovimento; // 5 segundos para mensagem de não movimento


void medeMov();

#endif
