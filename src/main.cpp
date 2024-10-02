#include <Arduino.h>
#include <WiFi.h>
#include <DallasTemperature.h>  //sensor de temperatura
#include <OneWire.h>

#define WIFI_SSID "Metropole"
#define WIFI_SENHA "908070Metropole"

#define LED_INTERNO 2
#define sensorTemp 33
#define sensorPir 23

OneWire pino(32);
DallasTemperature barramento(&pino);
DeviceAddress sensor;
  
int valorPir = 0;
int estadoAntes = LOW;
int estadoAgora =  LOW;
int intervalo;
float temp;
float tempAtual = 0;
static unsigned long antes = 0;
unsigned long agora = millis();


void setupWifi(){
  WiFi.begin (WIFI_SSID, WIFI_SENHA);
  while ((WiFi.status() != WL_CONNECTED)) {
    delay(1000);
    Serial.println("Tentando conectar-se ao wifi");
  }
  Serial.println("Conectado ao wifi!");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP() );
  }

void medeTemp() {
  Serial.println("Iniciando a medição da temperatura");
  if ((agora-antes) >= 60000){
    barramento.requestTemperatures();
    temp = barramento.getTempC(sensor);
    if (temp >0 && temp <50){
      tempAtual = temp;
      Serial.print("Temperatura: ");
      Serial.print(tempAtual);
      digitalWrite(LED_INTERNO, HIGH);
      delayMicroseconds(3000); //3 segundos
      digitalWrite(LED_INTERNO, LOW);
      antes = agora;
  } 
  }
}
void medeDist (){
 estadoAntes = estadoAgora;
 estadoAgora = digitalRead(sensorPir);
  if (estadoAntes == LOW && estadoAgora == HIGH){
    Serial.print("Movimento detectado!");
  }else if (estadoAntes == HIGH && estadoAgora == LOW) {
    Serial.print("Não há movimento!");
  }
  }

void loop() {
  setupWifi();
  medeTemp();
  medeDist();
}
void setup() {
  Serial.begin(115200);
  setupWifi();
  medeTemp();
  medeDist();
  pinMode (sensorPir, INPUT);
  
}