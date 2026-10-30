// Definición de los pines para los sensores ultrasónicos
#define TRIGGER1_PIN  9
#define ECHO1_PIN     8
#define TRIGGER2_PIN  7
#define ECHO2_PIN     6

// Definición de los pines para los sensores infrarrojos
#define SENSOR_IZQUIERDO_PIN  11
#define SENSOR_DERECHO_PIN    10

// Definición de los pines para los motores
#define MOTOR_IZQUIERDO_PIN1  5
#define MOTOR_IZQUIERDO_PIN2  4
#define MOTOR_DERECHO_PIN1    3
#define MOTOR_DERECHO_PIN2    2

// Distancia mínima para considerar un obstáculo (en centímetros)
#define DISTANCIA_MINIMA_SENSOR1 15
#define DISTANCIA_MINIMA_SENSOR2 20

unsigned int medirDistancia(int triggerPin, int echoPin);

void setup() {
  // Inicialización de los pines para los sensores ultrasónicos como entrada y salida
  pinMode(TRIGGER1_PIN, OUTPUT);
  pinMode(ECHO1_PIN, INPUT);
  pinMode(TRIGGER2_PIN, OUTPUT);
  pinMode(ECHO2_PIN, INPUT);

  // Inicialización de los pines para los sensores infrarrojos como entrada
  pinMode(SENSOR_IZQUIERDO_PIN, INPUT);
  pinMode(SENSOR_DERECHO_PIN, INPUT);
  
  // Inicialización de los pines de los motores como salida
  pinMode(MOTOR_IZQUIERDO_PIN1, OUTPUT);
  pinMode(MOTOR_IZQUIERDO_PIN2, OUTPUT);
  pinMode(MOTOR_DERECHO_PIN1, OUTPUT);
  pinMode(MOTOR_DERECHO_PIN2, OUTPUT);
  
  // Inicialización del puerto serial para la comunicación
  Serial.begin(9600);
}

void loop() {
  // Realiza mediciones de distancia con ambos sensores ultrasónicos
  unsigned int distancia1 = medirDistancia(TRIGGER1_PIN, ECHO1_PIN);
  unsigned int distancia2 = medirDistancia(TRIGGER2_PIN, ECHO2_PIN);

  // Lecturas de los sensores infrarrojos
  int lecturaIzquierda = digitalRead(SENSOR_IZQUIERDO_PIN);
  int lecturaDerecha = digitalRead(SENSOR_DERECHO_PIN);

  // Muestra las distancias medidas en el monitor serial
  Serial.print("Distancia Sensor 1: ");
  Serial.print(distancia1);
  Serial.println(" cm");
  Serial.print("Distancia Sensor 2: ");
  Serial.print(distancia2);
  Serial.println(" cm");

  // Muestra las lecturas de los sensores infrarrojos en el monitor serial
  Serial.print("Lectura Sensor Izquierdo: ");
  Serial.println(lecturaIzquierda);
  Serial.print("Lectura Sensor Derecho: ");
  Serial.println(lecturaDerecha);

  // Si el Sensor 1 detecta un objeto a menos de 15 cm, avanza y gira a la izquierda
  if (distancia1 < DISTANCIA_MINIMA_SENSOR1 && lecturaIzquierda == LOW && lecturaDerecha == LOW) {
    avanzar();
  }
  
  // Si el Sensor 2 detecta un objeto a menos de 20 cm, avanza y gira a la derecha
  else if (distancia2 < DISTANCIA_MINIMA_SENSOR2 && lecturaIzquierda == LOW && lecturaDerecha == LOW) {
    while (distancia1 >= DISTANCIA_MINIMA_SENSOR1) {
    girarIzquierda();
    distancia1 = medirDistancia(TRIGGER1_PIN, ECHO1_PIN);
    }
  }
  
  else if (lecturaIzquierda == HIGH && lecturaDerecha == LOW) {  
    girarDerecha();
  } 
  else if (lecturaIzquierda == LOW && lecturaDerecha == HIGH) {
    girarIzquierda();
  } 
  else if (lecturaIzquierda == LOW && lecturaDerecha == LOW) {
    retroceder(); // Ambos sensores detectan algo, retrocede
  } 
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

// Función para hacer que el robot avance
void avanzar() {
  digitalWrite(MOTOR_IZQUIERDO_PIN1, HIGH);
  digitalWrite(MOTOR_IZQUIERDO_PIN2, LOW);
  digitalWrite(MOTOR_DERECHO_PIN1, HIGH);
  digitalWrite(MOTOR_DERECHO_PIN2, LOW);
}

// Función para hacer que el robot gire a la izquierda
void girarIzquierda() {
  digitalWrite(MOTOR_IZQUIERDO_PIN1, LOW);
  digitalWrite(MOTOR_IZQUIERDO_PIN2, HIGH);
  digitalWrite(MOTOR_DERECHO_PIN1, HIGH);
  digitalWrite(MOTOR_DERECHO_PIN2, LOW);
}

// Función para hacer que el robot gire a la derecha
void girarDerecha() {
  digitalWrite(MOTOR_IZQUIERDO_PIN1, HIGH);
  digitalWrite(MOTOR_IZQUIERDO_PIN2, LOW);
  digitalWrite(MOTOR_DERECHO_PIN1, LOW);
  digitalWrite(MOTOR_DERECHO_PIN2, HIGH);
}

void retroceder() {
  digitalWrite(MOTOR_IZQUIERDO_PIN1, LOW) ;
  digitalWrite(MOTOR_IZQUIERDO_PIN2, HIGH) ;
  digitalWrite(MOTOR_DERECHO_PIN1, LOW);
  digitalWrite(MOTOR_DERECHO_PIN2, HIGH);
}
