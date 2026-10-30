#include <Servo.h>

#define TRIGGER_PIN  2  // Pin del arduino al que está conectado el pin TRIG del sensor ultrasónico
#define ECHO_PIN     3  // Pin del arduino al que está conectado el pin ECHO del sensor ultrasónico
#define SERVO_PIN    9  // Pin del arduino al que está conectado el servo motor

#define MAX_DISTANCE 30 // Distancia máxima de detección en centímetros

Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  myServo.attach(SERVO_PIN);
}

void loop() {
  long duration, distance;
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.println(distance);

  if (distance < MAX_DISTANCE) {
    // Si la distancia es menor que 30cm, girar el servo a 90 grados
    myServo.write(90);
  } else {
    // Si no, mantener el servo en su posición inicial (por ejemplo, 0 grados)
    myServo.write(0);
  }
  
  delay(100); // Pequeña pausa antes de la próxima lectura
}
