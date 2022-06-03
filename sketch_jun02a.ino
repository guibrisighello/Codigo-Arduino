#include <Servo.h>
#define pinPIR 7

Servo servo1; // Cria um objeto servo

// Variável para armazenar a posição do servo1
int pos = 0;

void setup() {
  pinMode(pinPIR, INPUT);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  servo1.attach(11);
}


void loop() {
  bool valorPIR = digitalRead(pinPIR);
  if (valorPIR) {
    Serial.println("DETECTADO");
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    for(pos = 0; pos < 180; pos += 1){
      servo1.write(pos);
      delay(50);
    }
    for(pos = 180; pos>=1; pos-=1){
      servo1.write(pos);
      delay(10);
    }
  }
  else {
    Serial.println("-------");
  }
}
