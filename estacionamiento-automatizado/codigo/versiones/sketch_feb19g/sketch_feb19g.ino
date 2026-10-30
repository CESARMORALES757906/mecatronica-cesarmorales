#include <Servo.h>

int num = 0;
int estadoSensor1 = 0;
int estadoAnteriorSensor1 = 0;
int estadoSensor2 = 0;
int estadoAnteriorSensor2 = 0;
int pinSensor1 = 2; // Primer sensor IR
int pinSensor2 = 3; // Segundo sensor IR
Servo miServo;

void setup() {
  Serial.begin(9600);
  pinMode(pinSensor1, INPUT);
  pinMode(pinSensor2, INPUT);
  pinMode(12, OUTPUT); // Ejemplo de pin de control del motor
  miServo.attach(12); // Asigna el pin al servo motor
}

void loop() {
  estadoSensor1 = digitalRead(pinSensor1);
  estadoSensor2 = digitalRead(pinSensor2);

  if (estadoSensor1 != estadoAnteriorSensor1) { // Si hay un cambio de estado en el sensor IR1
    delay(50); // Pequeño retraso para evitar el rebote
    if (estadoSensor1 == HIGH) { // Si el sensor IR1 detecta algo
      num = num + 1; // Incrementar el número
      if (num >= 10) {
        num = 0;
      }
    }
  }

  estadoAnteriorSensor1 = estadoSensor1;

  if (estadoSensor2 != estadoAnteriorSensor2) { // Si hay un cambio de estado en el sensor IR2
    delay(50); // Pequeño retraso para evitar el rebote
    if (estadoSensor2 == HIGH) { // Si el sensor IR2 detecta un objeto
      // Mueve el motor 90 grados
      miServo.write(90);
      delay(6000); // Espera 6 segundos
      // Vuelve el motor a su posición original
      miServo.write(0);
    }
  }

  estadoAnteriorSensor2 = estadoSensor2;

  switch (num) {
    case 0:
      // Configuración para el caso 0
      break;
    // Añade configuraciones para los otros casos si es necesario
  }

  delay(50);
}
