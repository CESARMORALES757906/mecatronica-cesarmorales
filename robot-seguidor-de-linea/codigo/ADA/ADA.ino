# define PINBUTTON_1 2
# define LED 10

int CASO; 
int VELOCIDAD_MOTOR_DERECHO;
int VELOCIDAD_MOTOR_IZQUIERDO;
void setup() {
  Serial.begin(9600);

  pinMode(11, OUTPUT);
  digitalWrite(11, HIGH);
  OUT_BOT();
  TB5512FNG ();
  MOTORES (0, 0);

  FLASH();
  delay(300);

  digitalWrite(11, LOW);
  FLASH();
  delay(300);
  digitalWrite(LED, HIGH);
  delay(300);
  Serial.println();
  Serial.println();
  Serial.println("----------HOLA");
  Serial.println("----------PRESIONA EL BOTON PARA CONTINUAR");
  Serial.println();
  CON_BOT ();
  calibracion ();
  CON_BOT();
  digitalWrite(11, HIGH);
  digitalWrite(LED, LOW);
}

void loop() {
  readsensors ();
  Serial.print ("   CASO_LINE--- ");
  Serial.print (CASO);
  GET_POS ();
  MOTORES (VELOCIDAD_MOTOR_IZQUIERDO, VELOCIDAD_MOTOR_DERECHO);
}


void CON_BOT() {
  while (!digitalRead(PINBUTTON_1)) {
  }
}

void FLASH() {
  digitalWrite(LED, HIGH);
  delay(300);
  digitalWrite(LED, LOW);
}

void OUT_BOT() {
  pinMode (PINBUTTON_1, INPUT);
  pinMode (LED, OUTPUT);
}

