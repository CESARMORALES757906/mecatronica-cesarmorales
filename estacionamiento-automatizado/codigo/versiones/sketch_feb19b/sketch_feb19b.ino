// Definir los pines donde está conectado el sensor infrarrojo y el LED
const int sensorPin = 2; // Cambiar al pin que estás utilizando
const int ledPin = 13;

void setup() {
  // Inicializar el puerto serial para la comunicación
  Serial.begin(9600);
  // Configurar el pin del sensor como entrada
  pinMode(sensorPin, INPUT);
  // Configurar el pin del LED como salida
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Leer el estado del sensor infrarrojo (HIGH o LOW)
  int sensorState = digitalRead(sensorPin);

  // Si el sensor detecta un objeto (estado HIGH), encender el LED
  if (sensorState == HIGH) {
    digitalWrite(ledPin, HIGH); // Encender el LED
    Serial.println("Objeto detectado - LED encendido");
  } else {
    digitalWrite(ledPin, LOW); // Apagar el LED
    Serial.println("Ningún objeto detectado - LED apagado");
  }

  // Esperar un breve tiempo antes de volver a leer el sensor
  delay(500);
}
