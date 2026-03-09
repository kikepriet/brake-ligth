#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;
const int ledPin = 13;
int16_t ax, ay, az;
int umbral = -3000; // Ajustar según la sensibilidad deseada

void setup() {
  Wire.begin();
  Serial.begin(9600);
  mpu.initialize();
  pinMode(ledPin, OUTPUT);
}

void loop() {
  mpu.getAcceleration(&ax, &ay, &az); // Leer aceleración
  
  // Imprimir para monitorear y calibrar
  Serial.println(ax); 

  if (ax < umbral) { // Si desacelera (el valor disminuye)
    digitalWrite(ledPin, HIGH); // Encender luz LED
  } else {
    digitalWrite(ledPin, LOW); // Apagar luz
  }
  delay(50);
}
