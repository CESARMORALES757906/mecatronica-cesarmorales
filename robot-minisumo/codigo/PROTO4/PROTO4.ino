// Definición de pines para los sensores infrarrojos
#define sensorIzquierdo 10 // Pin digital para el sensor izquierdo
#define sensorDerecho 11   // Pin digital para el sensor derecho

// Definición de pines para los sensores ultrasónicos
#define TRIGGER1_PIN  9
#define ECHO1_PIN     8
#define TRIGGER2_PIN  7
#define ECHO2_PIN     6

// Definición de pines para motores
#define MOTOR_LEFT_PIN1  5
#define MOTOR_LEFT_PIN2  4
#define MOTOR_RIGHT_PIN1 3
#define MOTOR_RIGHT_PIN2 2

// Distancia mínima para considerar un obstáculo (en centímetros)
#define DISTANCIA_MINIMA_SENSOR1 15
#define DISTANCIA_MINIMA_SENSOR2 20

// Prototipo de la función para medir distancia
unsigned int medirDistancia(int triggerPin, int echoPin);

void setup() {
  // Configurar pines de los sensores infrarrojos como entrada
  pinMode(sensorIzquierdo, INPUT);
  pinMode(sensorDerecho, INPUT);

  // Configurar pines de los sensores ultrasónicos como salida
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
  // Lecturas de los sensores infrarrojos
  int lecturaIzquierda = digitalRead(sensorIzquierdo);
  int lecturaDerecha = digitalRead(sensorDerecho);

  // Realiza mediciones de distancia con ambos sensores ultrasónicos
  unsigned int distancia1 = medirDistancia(TRIGGER1_PIN, ECHO1_PIN);
  unsigned int distancia2 = medirDistancia(TRIGGER2_PIN, ECHO2_PIN);
  
  // Muestra las lecturas de los sensores infrarrojos en el monitor serial
  Serial.print("Lectura Sensor Izquierdo: ");
  Serial.println(lecturaIzquierda);
  Serial.print("Lectura Sensor Derecho: ");
  Serial.println(lecturaDerecha);
  
  // Muestra las distancias medidas en el monitor serial
  Serial.print("Distancia Sensor 1: ");
  Serial.print(distancia1);
  Serial.println(" cm");
  Serial.print("Distancia Sensor 2: ");
  Serial.print(distancia2);
  Serial.println(" cm");

  // Lógica de seguimiento de línea
  if (lecturaIzquierda == HIGH && lecturaDerecha == LOW) {
    girarIzquierda();
  } 
  else if (lecturaIzquierda == LOW && lecturaDerecha == HIGH) {
    girarDerecha();
  } 
  else if (lecturaIzquierda == HIGH && lecturaDerecha == HIGH) {
    retroceder();
  }
  else {
    // Si el Sensor 1 detecta un objeto a menos de 15 cm, avanza y gira a la izquierda
    if (distancia1 < DISTANCIA_MINIMA_SENSOR1) {
      avanzar();
    }
    // Si el Sensor 2 detecta un objeto a menos de 20 cm, gira continuamente a la izquierda hasta que el sensor 1 no detecte un objeto
    else if (distancia2 < DISTANCIA_MINIMA_SENSOR2) {
      while (distancia1 >= DISTANCIA_MINIMA_SENSOR1) {
        girarDerecha();
        delay(100);
        distancia1 = medirDistancia(TRIGGER1_PIN, ECHO1_PIN);
      }
    }
    // Si no se detecta ningún objeto, avanza recto
    else {
      girarIzquierda();
    }
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

// Funciones de control de motores
void retroceder() {
  digitalWrite(MOTOR_LEFT_PIN1, HIGH);
  digitalWrite(MOTOR_LEFT_PIN2, LOW);
  digitalWrite(MOTOR_RIGHT_PIN1, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);
}

void avanzar() {
  digitalWrite(MOTOR_LEFT_PIN1, LOW);
  digitalWrite(MOTOR_LEFT_PIN2, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN1, LOW);
  digitalWrite(MOTOR_RIGHT_PIN2, HIGH);
}

void girarIzquierda() {
  digitalWrite(MOTOR_LEFT_PIN1, LOW);
  digitalWrite(MOTOR_LEFT_PIN2, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN1, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);
}

void girarDerecha() {
  digitalWrite(MOTOR_LEFT_PIN1, HIGH);
  digitalWrite(MOTOR_LEFT_PIN2, LOW);
  digitalWrite(MOTOR_RIGHT_PIN1, LOW);
  digitalWrite(MOTOR_RIGHT_PIN2, HIGH);
}
