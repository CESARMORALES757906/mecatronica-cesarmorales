
int estado=0;
int DOG=8;
int l1= 3;
int l2= 4;
int l3= 5;
int l4= 6;
int l5= 7;

void setup() {

pinMode(DOG,INPUT);
pinMode (l1, OUTPUT);
pinMode (l2, OUTPUT);
pinMode (l3, OUTPUT);
pinMode (l4, OUTPUT);
pinMode (l5, OUTPUT);
}

void loop() {
estado = digitalRead(DOG);
if(estado==HIGH){ 
  digitalWrite (l1,HIGH);
  digitalWrite (l2,HIGH);
  digitalWrite (l3,HIGH);
  digitalWrite (l4,HIGH);
  digitalWrite (l5,HIGH);

}
else{ 
  digitalWrite(l1,LOW);
  digitalWrite(l2,LOW);
  delay(500);
  digitalWrite(l3,LOW);
  digitalWrite(l4,LOW);
  digitalWrite(l5,LOW);

}
}