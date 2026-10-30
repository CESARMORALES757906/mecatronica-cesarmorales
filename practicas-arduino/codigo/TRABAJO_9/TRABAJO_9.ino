int estado=0;
int L1=1;
int L2=2;
int L3=3;
int L4=4;
int L5=5;
int L6=6;
int L7=7;
int L8=8;
int DOG=13;

void setup() {
pinMode(L1,OUTPUT);
pinMode(L2,OUTPUT);
pinMode(L3,OUTPUT);
pinMode(L4,OUTPUT);
pinMode(L5,OUTPUT);
pinMode(L6,OUTPUT);
pinMode(L7,OUTPUT);
pinMode(L8,OUTPUT);
pinMode(DOG,INPUT);
}

void loop() {
 estado = digitalRead(DOG);
if (estado==HIGH){
  digitalWrite(L2,HIGH);
  digitalWrite(L6,HIGH);
  digitalWrite(L4,HIGH);
  digitalWrite(L8,HIGH);
  delay (500);
  digitalWrite(L2,LOW);
  digitalWrite(L4,LOW);
  digitalWrite(L6,LOW);
  digitalWrite(L8,LOW);
  delay (500);
}
else{
  digitalWrite(L1,HIGH);
  digitalWrite(L3,HIGH);
  digitalWrite(L5,HIGH);
  digitalWrite(L7,HIGH);
  delay (1000);
  digitalWrite(L1,LOW);
  digitalWrite(L3,LOW);
  digitalWrite(L5,LOW);
  digitalWrite(L7,LOW);
  delay (1000);
}
}

 