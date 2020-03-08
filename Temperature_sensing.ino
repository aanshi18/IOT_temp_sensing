#include <ESP8266WiFi.h>
#include<ESP8266HTTPClient.h>
#include "DHT.h"

#define DHTTYPE DHT11
#define DHT_pin D5

DHT dht (DHT_pin,DHTTYPE);

const char* ssid="OPPO F11 Pro";
const char* pass="123456789";

void setup(){

  Serial.begin (115200);
  WiFi.begin(ssid,pass);

  while(WiFi.status()!=WL_CONNECTED){
    delay(100);
    Serial.print("...");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");
  Serial.println(WiFi.localIP());
  delay(100);
  dht.begin();
  delay(100);
  
}
void loop(){

  if(WiFi.status()==WL_CONNECTED){
    HTTPClient http;

    float h=dht.readHumidity();
    float t= dht.readTemperature();

    Serial.println("temperature =");
    Serial.print(t);
    Serial.println("humidity =");
    Serial.print(h);
    delay(800);

    String url = "http://127.0.0.1:1880/#flow/70f7d80.455b528";
    String api = "/data";
    url += api;
    
    

    
    }
}
