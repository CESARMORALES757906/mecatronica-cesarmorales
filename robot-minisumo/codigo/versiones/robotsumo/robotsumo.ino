#include <Arduino.h>

// Definición de pines
int motorIzquierdo1 = 2;
int motorIzquierdo2 = 3;
int motorDerecho1 = 4;
int motorDerecho2 = 5;

int sensorIzquierdo = 6;
int sensorCentro = 7;
int sensorDerecho = 8;

int trigPin = 9;
int echoPin = 10;

void setup() {
  Serial.begin(9600);

  // Configurar pines como salida o entrada
  pinMode(motorIzquierdo1, OUTPUT);
  pinMode(motorIzquierdo2, OUTPUT);
  pinMode(motorDerecho1, OUTPUT);
  pinMode(motorDerecho2, OUTPUT);
  
  pinMode(sensorIzquierdo, INPUT);
  pinMode(sensorCentro, INPUT);
  pinMode(sensorDerecho, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Lecturas de sensores
  int lecturaIzquierdo = digitalRead(sensorIzquierdo);
  int lecturaCentro = digitalRead(sensorCentro);
  int lecturaDerecho = digitalRead(sensorDerecho);

  // Lógica de control del robot
  if (lecturaIzquierdo == HIGH && lecturaCentro == HIGH && lecturaDerecho == HIGH) {
    // El robot está en el centro, verifica la distancia con el sensor ultrasónico
    if (obstaculoCerca()) {
      retroceder();
    } else {
      buscar();
    }
  } else if (lecturaIzquierdo == LOW && lecturaCentro == HIGH && lecturaDerecho == HIGH) {
    // Giro a la derecha para volver al centro
    girarDerecha();
  } else if (lecturaIzquierdo == HIGH && lecturaCentro == HIGH && lecturaDerecho == LOW) {
    // Giro a la izquierda para volver al centro
    girarIzquierda();
  } else if (lecturaIzquierdo == HIGH && lecturaCentro == LOW && lecturaDerecho == HIGH) {
    // Giro a la izquierda para volver al centro
    girarIzquierda();
    delay(2000);
    girarDerecha();
    delay(2000);
  } else {
    // Si no es ninguno de los casos anteriores, retrocede
    buscar();
  }
}

// Funciones de movimiento
void avanzar() {
  digitalWrite(motorIzquierdo1, HIGH);
  digitalWrite(motorIzquierdo2, LOW);
  digitalWrite(motorDerecho1, HIGH);
  digitalWrite(motorDerecho2, LOW);
}

void retroceder() {
  digitalWrite(motorIzquierdo1, LOW);
  digitalWrite(motorIzquierdo2, HIGH);
  digitalWrite(motorDerecho1, LOW);
  digitalWrite(motorDerecho2, HIGH);
}

void girarIzquierda() {
  digitalWrite(motorIzquierdo1, LOW);
  digitalWrite(motorIzquierdo2, HIGH);
  digitalWrite(motorDerecho1, HIGH);
  digitalWrite(motorDerecho2, LOW);
}

void girarDerecha() {
  digitalWrite(motorIzquierdo1, HIGH);
  digitalWrite(motorIzquierdo2, LOW);
  digitalWrite(motorDerecho1, LOW);
  digitalWrite(motorDerecho2, HIGH);
}

void buscar() {
  digitalWrite(motorIzquierdo1, LOW);
  digitalWrite(motorIzquierdo2, HIGH);
  digitalWrite(motorDerecho1, LOW);
  digitalWrite(motorDerecho2, LOW);
}

// Función para verificar si hay un obstáculo cercano usando el sensor ultrasónico
bool obstaculoCerca() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duracion = pulseIn(echoPin, HIGH, 20000);  // Ajusta el tiempo máximo de espera según tus necesidades
  int distancia = duracion / 58.2;

  Serial.print("Distancia del obstáculo: ");
  Serial.print(distancia);
  Serial.println(" cm");

  return distancia < 20;  // Ajusta este umbral según la distancia a la que quieres detectar obstáculos
}
