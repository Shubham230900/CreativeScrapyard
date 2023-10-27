#include <ESP8266WiFi.h>
//pins
const int trigPin = D0; 
const int echoPin = D1; 
const int LED1 = D5;//green
const int LED2 = D6;//yellow
const int LED3 = D7;//red
const int BUZZER = D2;
const int MOTOR = D4;//relay,motor
int motorst=0;
long duration;
int distance;
//setup
void setup() {
pinMode(LED1 , OUTPUT);
pinMode(LED2 , OUTPUT);
pinMode(LED3 , OUTPUT);
pinMode(BUZZER , OUTPUT);
pinMode(MOTOR , OUTPUT);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
Serial.begin(9600);
}
//loop
void loop() { 
   
//calculating water distance from sensor
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;

//contitions

  if (distance >= 0 && distance <= 9) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(BUZZER, HIGH);
    digitalWrite(MOTOR,LOW);
    motorst=0;
    delay(1000);
    Serial.print("1 Distance: ");
    Serial.println(distance);
  }
  else if (distance >= 10 && distance <= 49) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(MOTOR,HIGH);
    delay(1000);
    motorst=0;
    digitalWrite(LED3, LOW);
    digitalWrite(BUZZER, LOW);
    Serial.print("2 Distance: ");
    Serial.println(distance);
    
    }
  else if (distance >= 50 && distance <=75 ) {
    digitalWrite(LED1, HIGH);
    digitalWrite(MOTOR,HIGH);
    delay(1000);
    motorst=1;
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(BUZZER, LOW);
    Serial.print("3 Distance: ");
    Serial.println(distance);
  }
   else if (distance >= 76) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(BUZZER, LOW);
    digitalWrite(MOTOR,LOW);
    Serial.print("4 Distance: ");
    Serial.println(distance);
    motorst=0;
    delay(1000);
   }
}   
