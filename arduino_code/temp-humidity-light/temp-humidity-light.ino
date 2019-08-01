#include <dht.h>

dht DHT;

#define DHT11_PIN 7
#define SHOCK_PIN 2
#define PIR_PIN   3
#define LED_PIN   4
#define LIGHT_PIN A0 // select the analog input pin for the photoresistor

void setup(){
  Serial.begin(9600);
  pinMode(SHOCK_PIN, INPUT);          // shock sensor pin set to input
  pinMode(PIR_PIN, INPUT);            // declare the PIR sensor as input
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  int motionDetected = digitalRead(PIR_PIN);  // Read the PIR sensor
  Serial.print("Temperature = ");
  Serial.print(DHT.temperature);
  Serial.println(" ℃");
  Serial.print("Humidity = ");
  Serial.print(DHT.humidity);
  Serial.println(" %");
  Serial.print("Light = ");
  Serial.print(analogRead(LIGHT_PIN)); // Ma
  Serial.println(" %");
  if (digitalRead(SHOCK_PIN)) // shock detected?
  {    
    Serial.println("SHOCK!!");
  }
  if(motionDetected == HIGH) //If motion detected
  {
    Serial.println("MOVEMENT!!");
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  
  delay(5000);
}
