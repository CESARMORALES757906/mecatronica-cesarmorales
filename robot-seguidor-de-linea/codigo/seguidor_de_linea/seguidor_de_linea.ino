// Definición de pines para los sensores infrarrojos
const int sensorIzquierdo = 2; // Pin digital para el sensor izquierdo
const int sensorDerecho = 3;   // Pin digital para el sensor derecho

// Definición de pines para motores
const int motorIzquierdoAdelante = 4;
const int motorIzquierdoAtras = 5;
const int motorDerechoAdelante = 6;
const int motorDerechoAtras = 7;

void setup() {
  // Configurar pines de los sensores como entrada
  pinMode(sensorIzquierdo, INPUT);
  pinMode(sensorDerecho, INPUT);

  // Configurar pines de los motores como salida
  pinMode(motorIzquierdoAdelante, OUTPUT);
  pinMode(motorIzquierdoAtras, OUTPUT);
  pinMode(motorDerechoAdelante, OUTPUT);
  pinMode(motorDerechoAtras, OUTPUT);
}

void loop() {
  // Lecturas de los sensores
  int lecturaIzquierda = digitalRead(sensorIzquierdo);
  int lecturaDerecha = digitalRead(sensorDerecho);

  // Lógica de seguimiento de línea
  if (lecturaIzquierda == HIGH && lecturaDerecha == LOW) {
    girarDerecha();
  } else if (lecturaIzquierda == LOW && lecturaDerecha == HIGH) {
    girarIzquierda();
  } else {
    avanzar();
  }
}

// Funciones de control de motores
void avanzar() {
  digitalWrite(motorIzquierdoAdelante, HIGH);
  digitalWrite(motorIzquierdoAtras, LOW);
  digitalWrite(motorDerechoAdelante, HIGH);
  digitalWrite(motorDerechoAtras, LOW);
}

void girarIzquierda() {
  digitalWrite(motorIzquierdoAdelante, LOW);
  digitalWrite(motorIzquierdoAtras, HIGH);
  digitalWrite(motorDerechoAdelante, HIGH);
  digitalWrite(motorDerechoAtras, LOW);
}

void girarDerecha() {
  digitalWrite(motorIzquierdoAdelante, HIGH);
  digitalWrite(motorIzquierdoAtras, LOW);
  digitalWrite(motorDerechoAdelante, LOW);
  digitalWrite(motorDerechoAtras, HIGH);
}
