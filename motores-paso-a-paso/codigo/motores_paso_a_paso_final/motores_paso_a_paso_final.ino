void setup() {
  // Iniciar la comunicación serie a 9600 baudios
  Serial.begin(9600);

  // Configurar pines de los motores como salida
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  // Configurar pines de los pulsadores como entrada
  pinMode(2, INPUT); // Pulsador 1
  pinMode(3, INPUT); // Pulsador 2
  pinMode(12, INPUT); // Pulsador 3

  // Mensaje de inicio
  Serial.println("Setup completo. Esperando entradas...");
}

void loop() {
  // Leer el estado de los pulsadores
  bool button1 = digitalRead(2) == HIGH;
  bool button2 = digitalRead(3) == HIGH;
  bool button3 = digitalRead(12) == HIGH;

  // Imprimir el estado de los pulsadores en el Monitor Serie
  Serial.print("Button1: ");
  Serial.print(button1);
  Serial.print(", Button2: ");
  Serial.print(button2);
  Serial.print(", Button3: ");
  Serial.println(button3);

  // Si no se presiona ningún botón, no hacer nada
  if (!button1 && !button2 && !button3) {
    stopMotors(); // Asegurarse de que los motores estén apagados
    Serial.println("No button pressed. Motors stopped.");
    delay(500); // Añadir un retraso para evitar demasiadas impresiones
    return; // Salir de loop() y no hacer nada
  }

  if (button1) {
    // Secuencia para mover hacia la derecha
    Serial.println("Moving right");
    digitalWrite(4, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    digitalWrite(6, LOW);
    digitalWrite(10, LOW);
    digitalWrite(7, LOW);
    digitalWrite(11, LOW);
    delay(10);

    digitalWrite(4, LOW);
    digitalWrite(8, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(10, LOW);
    digitalWrite(7, LOW);
    digitalWrite(11, LOW);
    delay(10);

    digitalWrite(4, LOW);
    digitalWrite(8, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(11, LOW);
    delay(10);

    digitalWrite(4, LOW);
    digitalWrite(8, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    digitalWrite(6, LOW);
    digitalWrite(10, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(11, HIGH);
    delay(10);
  } else if (button2) {
    // Secuencia para mover hacia la izquierda
    Serial.println("Moving left");
    digitalWrite(4, LOW);
    digitalWrite(8, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    digitalWrite(6, LOW);
    digitalWrite(10, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(11, HIGH);
    delay(10);

    digitalWrite(4, LOW);
    digitalWrite(8, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(11, LOW);
    delay(10);

    digitalWrite(4, LOW);
    digitalWrite(8, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(10, LOW);
    digitalWrite(7, LOW);
    digitalWrite(11, LOW);
    delay(10);

    digitalWrite(4, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    digitalWrite(6, LOW);
    digitalWrite(10, LOW);
    digitalWrite(7, LOW);
    digitalWrite(11, LOW);
    delay(10);
  } else if (button3) {
    // Secuencia para mover uno hacia la derecha y otro hacia la izquierda
    Serial.println("Moving one motor right and the other left");
    digitalWrite(4, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    digitalWrite(6, LOW);
    digitalWrite(10, LOW);
    digitalWrite(7, LOW);
    digitalWrite(11, HIGH);
    delay(10);

    digitalWrite(4, LOW);
    digitalWrite(8, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(6, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(11, LOW);
    delay(10);

    digitalWrite(4, LOW);
    digitalWrite(8, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(7, LOW);
    digitalWrite(11, LOW);
    delay(10);

    digitalWrite(4, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    digitalWrite(6, LOW);
    digitalWrite(10, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(11, LOW);
    delay(10);
  }
}

void stopMotors() {
  digitalWrite(4, LOW);
  digitalWrite(8, LOW);
  digitalWrite(5, LOW);
  digitalWrite(9, LOW);
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
  digitalWrite(7, LOW);
  digitalWrite(11, LOW);
}
