#include <Servo.h>

int num = 0;
int estadoBoton2 = 0;
int estadoAnteriorBoton2 = 0;
int P2 = 3;
int P3 = 2;
unsigned long ultimoTiempo = 0; // Variable para almacenar el último tiempo registrado

Servo miServo;

void setup() {
  Serial.begin(9600);
  pinMode(P2, INPUT);
  pinMode(P3, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  miServo.attach(11); // Pin del servomotor
}

void mostrarNumero(int n) {
  switch (n) {
    case 0:
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      break;
    case 1:
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      break;
    case 2:
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      break;
    case 3:
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      break;
    case 4:
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      break;
    case 5:
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      break;
    case 6:
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      break;
    case 7:
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      break;
    case 8:
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      break;
    case 9:
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      break;
  }
}

void loop() {
  estadoBoton2 = digitalRead(P2);
  int estadoSensorAdicional = digitalRead(P3);
  
  if (estadoBoton2 != estadoAnteriorBoton2) { // Si hay un cambio de estado en el botón
    delay(50); // Pequeño retraso para evitar el rebote
    if (estadoBoton2 == HIGH && millis() - ultimoTiempo > 3000) { // Si el botón se ha soltado y han pasado 5 segundos
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

  mostrarNumero(num);

  delay(50);
}
