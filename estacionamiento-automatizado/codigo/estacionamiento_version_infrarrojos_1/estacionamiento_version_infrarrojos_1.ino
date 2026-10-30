#include <Servo.h>

int num = 0;
int estadoBoton2 = 0;
int estadoAnteriorBoton2 = 0;
int P2 = 3; // Pin para el sensor de infrarrojos
int P3 = 2; // Pin para el sensor de infrarrojos adicional
unsigned long ultimoTiempo = 0; // Variable para almacenar el último tiempo registrado

Servo miServo;

void setup() {
  Serial.begin(9600);
  pinMode(P2, INPUT);
  pinMode(P3, INPUT);
  miServo.attach(11); // Pin del servomotor
}

void loop() {
  estadoBoton2 = digitalRead(P2);
  int estadoSensorAdicional = digitalRead(P3);

  if (estadoBoton2 != estadoAnteriorBoton2) { // Si hay un cambio de estado en el sensor infrarrojo
    delay(50); // Pequeño retraso para evitar el rebote
    if (estadoBoton2 == HIGH && millis() - ultimoTiempo > 5000) { // Si el sensor detecta un objeto y han pasado 5 segundos desde la última detección
      num = num + 1; // Incrementar el número
      if (num >= 10) {
        num = 0;
      }
      miServo.write(90); // Girar el servomotor a 90 grados
      ultimoTiempo = millis(); // Actualizar el tiempo registrado
    }
  }

  if (estadoSensorAdicional == LOW) { // Si el sensor adicional no detecta nada
    miServo.write(0); // Volver el servomotor a su posición original (0 grados)
  }

  estadoAnteriorBoton2 = estadoBoton2;
  
  delay(50);
}
