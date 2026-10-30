// Definir pines para el motor 1
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

// Definir pines para el motor 2
#define IN5 8
#define IN6 9
#define IN7 10
#define IN8 11

const int stepsPerCycle = 10;  // Número de pasos por ciclo
const int stepDelay = 50;      // Delay entre cada paso (ajustable)

void setup() {
  // Inicializar comunicación serie
  Serial.begin(9600);

  // Configurar pines del motor 1 como salida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Configurar pines del motor 2 como salida
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  
  // Configurar pines de los pulsadores como entrada
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(12, INPUT);
}

void loop() {
  bool button1 = digitalRead(2) == HIGH;
  bool button2 = digitalRead(3) == HIGH;
  bool button3 = digitalRead(12) == HIGH;

  if (button1) {
    Serial.println("Moving right");
    for (int i = 0; i < stepsPerCycle; i++) {
      stepRight();
    }
  } else if (button2) {
    Serial.println("Moving left");
    for (int i = 0; i < stepsPerCycle; i++) {
      stepLeft();
    }
  } else if (button3) {
    Serial.println("Moving one motor right and the other left");
    for (int i = 0; i < stepsPerCycle; i++) {
      stepOpposite();
    }
  } else {
    stopMotors();
  }
  delay(10); // Añadir un pequeño retraso para estabilidad
}

void stepRight() {
  // Secuencia de pasos para mover a la derecha
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  delay(stepDelay);  // Reducir este valor para aumentar la velocidad
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  delay(stepDelay);  // Reducir este valor para aumentar la velocidad

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  delay(stepDelay);  // Reducir este valor para aumentar la velocidad

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  delay(stepDelay);  // Reducir este valor para aumentar la velocidad
}

void stepLeft() {
  // Secuencia de pasos para mover a la izquierda
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  delay(stepDelay);  // Reducir este valor para aumentar la velocidad

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  delay(stepDelay);  // Reducir este valor para aumentar la velocidad

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  delay(stepDelay);  // Reducir este valor para aumentar la velocidad

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  delay(stepDelay);  // Reducir este valor para aumentar la velocidad
}

void stepOpposite() {
  // Secuencia de pasos para mover un motor a la derecha y otro a la izquierda
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  delay(stepDelay);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  delay(stepDelay);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  delay(stepDelay);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  delay(stepDelay);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, LOW);
}
