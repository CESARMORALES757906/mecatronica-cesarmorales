#define echoPin 9
#define trigPin 10

long duracion;
int distancia;

int M1=2; 
int M2=3;
int B1=7;
int B2=8;
int ENA=5;
int ENB=6;

int variableGiro=0;

int IRI=13;
int IRC=12;
int IRD=11;

void setup (){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IRI, INPUT);
  pinMode(IRC, INPUT);
  pinMode(IRD, INPUT);

  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duracion = pulseIn(echoPin, HIGH);
  distancia = duracion/58.2;
  Serial.print("distancia ");
  Serial.print(distancia);
  Serial.print(" cm");
  delay(50);

  if (distancia<40) {
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);

    digitalWrite(M1,LOW);
    digitalWrite(M2,HIGH);
    digitalWrite(B1,LOW);
    digitalWrite(B2,HIGH);
    delay(500);
  }

  if (distancia>40) {
    variableGiro=0;
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);

    digitalWrite(M1,LOW);
    digitalWrite(M2,HIGH);
    digitalWrite(B1,LOW);
    digitalWrite(B2,HIGH);
    delay(500);
  }
  
  if (distancia>40 && variableGiro==0) {
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);

    digitalWrite(M1,LOW);
    digitalWrite(M2,HIGH);
    digitalWrite(B1,HIGH);
    digitalWrite(B2,LOW);
    delay(15);
  }

  if (distancia>40 && variableGiro==1) {
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);

    digitalWrite(M1,HIGH);
    digitalWrite(M2,LOW);
    digitalWrite(B1,LOW);
    digitalWrite(B2,HIGH);
    delay(15);
  }
  
  if (digitalRead(IRI) == 0 || digitalRead(IRC) == 0 || digitalRead(IRD) == 0) {
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);

    digitalWrite(M1,HIGH);
    digitalWrite(M2,LOW);
    digitalWrite(B1,HIGH);
    digitalWrite(B2,LOW);
    delay(2000);
  }
}
