int VERDE=8;
int AMARILLO=9;
int ROJO=10;
int VERDE1=11;
int AMARILLO1=12;
int ROJO1=13;
void setup() {
  pinMode (VERDE,OUTPUT);
  pinMode (AMARILLO,OUTPUT);
  pinMode (ROJO,OUTPUT);
  pinMode (VERDE1,OUTPUT);
  pinMode (AMARILLO1,OUTPUT);
  pinMode (ROJO1,OUTPUT);
}

void loop() {
  digitalWrite (ROJO1,HIGH);
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
  digitalWrite (ROJO1,LOW);
  delay (100);
  digitalWrite (ROJO,HIGH);
  digitalWrite (VERDE1,HIGH);
  delay (2000);
  digitalWrite (VERDE1,LOW);
  delay (100);
  digitalWrite (AMARILLO1,HIGH);
  delay (1000);
  digitalWrite (AMARILLO1,LOW);
  delay (100);
  digitalWrite (AMARILLO1,HIGH);
  delay (200);
  digitalWrite (AMARILLO1,LOW);
  delay (100);
  digitalWrite (AMARILLO1,HIGH);
  delay (200);
  digitalWrite (AMARILLO1,LOW);
  delay (100);
    digitalWrite (ROJO,LOW);
  delay (100);
}