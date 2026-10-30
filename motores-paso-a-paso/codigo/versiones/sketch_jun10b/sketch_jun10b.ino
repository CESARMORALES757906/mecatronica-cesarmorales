// Definir pines para los motores
#define MOTOR1_IN1 4
#define MOTOR1_IN2 5
#define MOTOR1_IN3 6
#define MOTOR1_IN4 7

#define MOTOR2_IN1 8
#define MOTOR2_IN2 9
#define MOTOR2_IN3 10
#define MOTOR2_IN4 11

const int stepsPerCycle = 10;  // Número de pasos por ciclo
const int stepDelay = 10;      // Delay entre cada paso (ajustable)

unsigned long previousMillis = 0;
int stepIndex = 0;

void setup() {
  // Inicializar comunicación serie
  Serial.begin(9600);

  // Configurar pines del motor 1 como salida
  pinMode(MOTOR1_IN1, OUTPUT);
  pinMode(MOTOR1_IN2, OUTPUT);
  pinMode(MOTOR1_IN3, OUTPUT);
  pinMode(MOTOR1_IN4, OUTPUT);

  // Configurar pines del motor 2 como salida
  pinMode(MOTOR2_IN1, OUTPUT);
  pinMode(MOTOR2_IN2, OUTPUT);
  pinMode(MOTOR2_IN3, OUTPUT);
  pinMode(MOTOR2_IN4, OUTPUT);
  
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
    moveMotor(stepRight, MOTOR1_IN1, MOTOR1_IN2, MOTOR1_IN3, MOTOR1_IN4);
  } else if (button2) {
    Serial.println("Moving left");
    moveMotor(stepLeft, MOTOR1_IN1, MOTOR1_IN2, MOTOR1_IN3, MOTOR1_IN4);
  } else if (button3) {
    Serial.println("Moving one motor right and the other left");
    moveMotor(stepRight, MOTOR1_IN1, MOTOR1_IN2, MOTOR1_IN3, MOTOR1_IN4);
    moveMotor(stepLeft, MOTOR2_IN1, MOTOR2_IN2, MOTOR2_IN3, MOTOR2_IN4);
  } else {
    stopMotors(MOTOR1_IN1, MOTOR1_IN2, MOTOR1_IN3, MOTOR1_IN4);
    stopMotors(MOTOR2_IN1, MOTOR2_IN2, MOTOR2_IN3, MOTOR2_IN4);
  }
}

void moveMotor(void (*stepFunction)(int, int, int, int), int in1, int in2, int in3, int in4) {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= stepDelay) {
    previousMillis = currentMillis;
    stepFunction(in1, in2, in3, in4);
    stepIndex = (stepIndex + 1) % stepsPerCycle;
  }
}

void stepRight(int in1, int in2, int in3, int in4) {
  switch (stepIndex % 4) {
    case 0:
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      break;
    case 1:
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      break;
    case 2:
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      break;
    case 3:
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      break;
  }
}

void stepLeft(int in1, int in2, int in3, int in4) {
  switch (stepIndex % 4) {
    case 0:
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      break;
    case 1:
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      break;
    case 2:
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      break;
    case 3:
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      break;
  }
}

void stopMotors(int in1, int in2, int in3, int in4) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
