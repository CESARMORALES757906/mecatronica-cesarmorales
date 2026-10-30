int L1=8;
int L2=9;
int L3=10;
int L4=11;
int L5=12;
int estado=0;
int DOG=13;

void setup() {
pinMode(L1,OUTPUT);
pinMode(L2,OUTPUT);
pinMode(L3,OUTPUT);
pinMode(L4,OUTPUT);
pinMode(L5,OUTPUT);
pinMode(DOG,INPUT);
}
void loop() {
 estado = digitalRead(DOG);
if (estado==HIGH){
  digitalWrite(L1,HIGH);
  digitalWrite(L2,HIGH);
  digitalWrite(L3,HIGH);
  digitalWrite(L4,HIGH);
  digitalWrite(L5,HIGH);
  delay (500);

}
else{
  digitalWrite(L1,LOW);
  digitalWrite(L2,LOW);
  delay (500);
}
}

 