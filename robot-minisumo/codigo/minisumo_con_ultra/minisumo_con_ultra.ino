// Definición de los pines para los sensores ultrasónicos
#define TRIGGER1_PIN  9
#define ECHO1_PIN     8
#define TRIGGER2_PIN  7
#define ECHO2_PIN     6

// Definición de los pines para los motores
#define MOTOR_LEFT_PIN1  5
#define MOTOR_LEFT_PIN2  4
#define MOTOR_RIGHT_PIN1 3
#define MOTOR_RIGHT_PIN2 2

// Distancia mínima para considerar un obstáculo (en centímetros)
#define DISTANCIA_MINIMA_SENSOR1 20
#define DISTANCIA_MINIMA_SENSOR2 20

void setup() {
  // Inicialización de los pines para los sensores ultrasónicos como entrada y salida
  pinMode(TRIGGER1_PIN, OUTPUT);
  pinMode(ECHO1_PIN, INPUT);
  pinMode(TRIGGER2_PIN, OUTPUT);
  pinMode(ECHO2_PIN, INPUT);
  
  // Inicialización de los pines de los motores
  pinMode(MOTOR_LEFT_PIN1, OUTPUT);
  pinMode(MOTOR_LEFT_PIN2, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN1, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN2, OUTPUT);

  // Inicialización del puerto serial para la comunicación
  Serial.begin(9600);
}

void loop() {
  // Realiza mediciones de distancia con ambos sensores
  unsigned int distancia1 = medirDistancia(TRIGGER1_PIN, ECHO1_PIN);
  unsigned int distancia2 = medirDistancia(TRIGGER2_PIN, ECHO2_PIN);

  // Muestra las distancias medidas en el monitor serial
  Serial.print("Distancia Sensor 1: ");
  Serial.print(distancia1);
  Serial.println(" cm");
  Serial.print("Distancia Sensor 2: ");
  Serial.print(distancia2);
  Serial.println(" cm");

  // Si el Sensor 1 detecta un objeto a menos de 15 cm, avanza y gira a la izquierda
  if (distancia1 < DISTANCIA_MINIMA_SENSOR1) {
    avanzar();
  }
  // Si el Sensor 2 detecta un objeto a menos de 20 cm, avanza y gira a la derecha
  else if (distancia2 < DISTANCIA_MINIMA_SENSOR2) {
    girarIzquierda();
  }
  // Si no se detecta ningún objeto, avanza recto
  else {
    girarDerecha();
  }
}

// Función para medir la distancia utilizando un sensor ultrasónico
unsigned int medirDistancia(int triggerPin, int echoPin) {
  // Generar un pulso corto en el pin TRIGGER
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  // Leer el tiempo que tarda en llegar el eco
  unsigned long tiempo = pulseIn(echoPin, HIGH);
  
  // Convertir el tiempo a distancia (en centímetros)
  unsigned int distancia = tiempo / 58;
  
  return distancia;
}

// Función para hacer que el mini sumo avance
void avanzar() {
  digitalWrite(MOTOR_LEFT_PIN1, HIGH);
  digitalWrite(MOTOR_LEFT_PIN2, LOW);
  digitalWrite(MOTOR_RIGHT_PIN1, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);
  delay(500);
}

// Función para hacer que el mini sumo gire a la derecha
void girarDerecha() {
  digitalWrite(MOTOR_LEFT_PIN1, HIGH);
  digitalWrite(MOTOR_LEFT_PIN2, LOW);
  digitalWrite(MOTOR_RIGHT_PIN1, LOW);
  digitalWrite(MOTOR_RIGHT_PIN2, HIGH);
 
  // Breve pausa para el giro
  delay(500);
}

// Función para hacer que el mini sumo gire a la izquierda
void girarIzquierda() {
  digitalWrite(MOTOR_LEFT_PIN1, LOW);
  digitalWrite(MOTOR_LEFT_PIN2, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN1, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);
 
  // Breve pausa para el giro
  delay(500);
}
