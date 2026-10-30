int estado=5;
int DOG=8;
int CAT=4;

void setup() {
pinMode(DOG,INPUT);
pinMode (CAT,OUTPUT);
}

void loop() {
estado= digitalRead (DOG);
if (estado == LOW){
digitalWrite(CAT,HIGH);


}
else  {
digitalWrite(CAT,LOW);
}
}