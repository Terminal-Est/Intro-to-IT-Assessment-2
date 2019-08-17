#include <SPI.h>
#include <WiFiNINA.h>
#include "arduino_secrets.h"

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;
int keyIndex = 0; //For WEP
int countUp;

int status = WL_IDLE_STATUS; //WL not W
IPAddress server(192, 168, 1, 2);
IPAddress ip;
WiFiClient client;

void setup() {

  Serial.begin(9600);
  Serial.println("Attempting to connect to WPA network, please wait....");
  Serial.print("SSID: ");
  Serial.println(ssid);

  status = WiFi.begin(ssid, pass);
  if (status != WL_CONNECTED) {
    Serial.println("This sucks ass");
    while (true);
  }
  else {
    ip = WiFi.localIP();
    Serial.println("Connected to WiFi");
    Serial.print("The Arduino IP is: ");
    Serial.println(ip);
    Serial.println("\nStarting server conenction...");
    if  (client.connect(server, 80)) {
      Serial.println("Client Connected!");
    }
  }
  while (countUp < 1) {
    if (!client.connected()) {
      Serial.println("Client Disconnected!");
      countUp += 1;
    }
  }
}
void loop() {
  while (client.connected()) {
    while (client.available()) {
      char c = client.read();
      Serial.print(c);
    }
  }
}
