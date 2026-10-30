int estado=0;
int DOG=8;
int CAT=4;


void setup() {
  // put your setup code here, to run once:
pinMode(DOG,INPUT);
pinMode (CAT,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
estado= digitalRead (DOG);
if (estado == LOW){
digitalWrite(CAT,LOW);


}
else  {
digitalWrite(CAT,HIGH);
}
}