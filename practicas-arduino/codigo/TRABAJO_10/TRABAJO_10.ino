int estado=0;
int DOG=8;
int CAT=4;

void setup() {
pinMode(DOG,INPUT);
pinMode(CAT,OUTPUT);
}

void loop() {
 estado = digitalRead(DOG);
if (estado==HIGH){
  digitalWrite(CAT,HIGH);
}
else{
  digitalWrite(CAT,LOW);
}
}

 