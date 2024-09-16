const unsigned int Light_PIN = D1;
const unsigned int Moisture_PIN = D2;
const unsigned int Temp_Analog = A0;

void setup(){
  Serial.begin(9600);
  pinMode(Light_PIN, INPUT);      
  pinMode(Moisture_PIN, INPUT);      
  pinMode(Temp_Analog, INPUT);
}

void loop(){
//Temprature Sensor
  int temprature = analogRead (Temp_Analog) - 730;
//Moisture Sensor
  int Moisture = digitalRead(Moisture_PIN);
//Light Blocking
  int LDR = digitalRead(Light_PIN);
  //Serial.println("LDR:");
  Serial.println(LDR);
  //Serial.println("Moisture:");
  Serial.println(Moisture);
  //Serial.println("Temp:");
  Serial.println(temprature);
  delay(500);
}









//#include <PubSubClient.h>
//#include "ThingsBoard.h"
//#include <ESP8266WiFi.h>
//
//#define WIFI_AP             "SinaR"
//#define WIFI_PASSWORD       "0420sina"
//#define TOKEN               "ESP8266"
//#define THINGSBOARD_SERVER  "192.168.43.199"
//
//WiFiClient espClient;
//ThingsBoard tb(espClient);
//int status = WL_IDLE_STATUS;
//
//void setup()
//{
//  Serial.begin(9600);
//  WiFi.begin(WIFI_AP, WIFI_PASSWORD);
//  InitWiFi();
//}
//
//void loop()
//{
//  delay(500);
//  
//  if (WiFi.status() != WL_CONNECTED) {
//    reconnect();
//  }
//  if (!tb.connected()) {
//    Serial.print("Connecting to: ");
//    Serial.print(THINGSBOARD_SERVER);
//    Serial.print(" with token ");
//    Serial.println(TOKEN);
//    if (!tb.connect(THINGSBOARD_SERVER,TOKEN)) {
//      Serial.println("Failed to connect");
//      return;
//    }
//  }
//
//  Serial.println("Sending data...");
//  int temprature = analogRead (Temp_Analog);
//  int Moisture = digitalRead(Moisture_PIN);
//  int LDR = digitalRead(Light_PIN);
//  tb.sendTelemetryInt("temperature", temprature);
//  tb.sendTelemetryInt("moisture", Moisture);
//  tb.sendTelemetryInt("light", LDR);
//  tb.loop();
//}
//
//void InitWiFi()
//{
//  Serial.println("Connecting to AP ...");
//  WiFi.begin(WIFI_AP, WIFI_PASSWORD);
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//  }
//  Serial.println("Connected to AP");
//}
//
//void reconnect() {
//  status = WiFi.status();
//  if ( status != WL_CONNECTED) {
//    WiFi.begin(WIFI_AP, WIFI_PASSWORD);
//    while (WiFi.status() != WL_CONNECTED) {
//      delay(500);
//      Serial.print(".");
//    }
//    Serial.println("Connected to AP");
//  }
//}
