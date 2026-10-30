#include <Wire.h>
#include "Adafruit_VEML7700.h"

// Crear objeto del sensor
Adafruit_VEML7700 veml = Adafruit_VEML7700();

void setup() {
  Serial.begin(9600);
  Serial.println(F("Prueba de sensor VEML7700 - Medición de Lux"));
  
  // Inicializar comunicación con el sensor
  if (!veml.begin()) {
    Serial.println(F("No se detecta el sensor VEML7700. Verifica conexiones SDA y SCL."));
    while (1);
  }
  
  // Configuración opcional (puedes cambiarla más adelante)
  veml.setGain(VEML7700_GAIN_1);              // Ganancia normal
  veml.setIntegrationTime(VEML7700_IT_100MS); // Tiempo de integración (100 ms)

  Serial.println(F("Sensor inicializado correctamente."));
  delay(500);
}

void loop() {
  float lux = veml.readLux();   // Leer valor en lux

  Serial.print(F("Intensidad luminosa: "));
  Serial.print(lux);
  Serial.println(F(" lux"));

  delay(1000); // Lectura cada segundo
}
