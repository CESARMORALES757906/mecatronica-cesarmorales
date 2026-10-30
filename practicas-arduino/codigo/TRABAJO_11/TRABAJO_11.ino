int M1=5;
int M2=6;
int LED1=13;
int LED2=12;
int estado=0;
int PERRO=7;

void loop (){
  pinMode (M1,OUTPUT);
  pinMode (M2,OUTPUT);
  pinMode (LED1,OUTPUT);
  pinMode (LED2,OUTPUT);
  pinMode (PERRO,INPUT);
}

void setup (){
  estado = digitalRead (PERRO);
  if (estado==HIGH){
  digitalWrite (M1,HIGH);
  delay(500);
  digitalWrite (M2,HIGH);
  delay(500);
  digitalWrite (LED1,LOW);
  delay(500);
  digitalWrite (LED2,LOW);
  delay(500);  
  }
  else{
  digitalWrite (LED1,HIGH);
  delay(500);
  digitalWrite (LED2,HIGH);
  delay(500);
  digitalWrite (M1,LOW);
  delay(500);
  digitalWrite (M2,LOW);
  delay(500);
  }
}
