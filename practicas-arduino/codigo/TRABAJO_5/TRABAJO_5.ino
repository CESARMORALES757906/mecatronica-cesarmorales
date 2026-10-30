int VERDE=8;
int AMARILLO=9;
int ROJO=10;
void setup() {
  pinMode (VERDE,OUTPUT);
  pinMode (AMARILLO,OUTPUT);
  pinMode (ROJO,OUTPUT);
}

void loop() {
  digitalWrite (VERDE,HIGH);
  delay (2000);
  digitalWrite (VERDE,LOW);
  delay (100);
  digitalWrite (AMARILLO,HIGH);
  delay (1000);
  digitalWrite (AMARILLO,LOW);
  delay (100);
  digitalWrite (AMARILLO,HIGH);
  delay (200);
  digitalWrite (AMARILLO,LOW);
  delay (100);
  digitalWrite (AMARILLO,HIGH);
  delay (200);
  digitalWrite (AMARILLO,LOW);
  delay (100);
  digitalWrite (ROJO,HIGH);
  delay (3000);
  digitalWrite (ROJO,LOW);
  delay (100);
}
SS