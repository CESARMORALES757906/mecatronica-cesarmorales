#include <Servo.h>
int TRIGGER_PIN=9;
int ECHO_PIN=10;
int SERVO_PIN=11;
int a=2;
int b=3;
int c=4;
int d=5;
int e=6;
int f=7;
int g=8;
int contador=0;
int boton;
int MAX_DISTANCE=30;

Servo myServo;

void setup() {
    Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  myServo.attach(SERVO_PIN);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
}

void loop() {
   long duration, distance;
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.println(distance);

  if (distance < MAX_DISTANCE) {
    // Si la distancia es menor que 30cm, girar el servo a 90 grados
    myServo.write(90);
  } else {
    // Si no, mantener el servo en su posición inicial (por ejemplo, 0 grados)
    myServo.write(0);
  }
  
  delay(100); // Pequeña pausa antes de la próxima 
  
  Serial.println(contador);
  boton=digitalRead(MAX_DISTANCE);
  delay(300);//Anti rebote
  if(boton==1){
    if(contador==9){
      contador=0;
    }else{
     contador++; 
    }
  }
  
  if(contador==0){
    digitalWrite(a,HIGH);//número 0
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,LOW);//número 0
  }
  if(contador==1){
    digitalWrite(a,LOW);//número 1
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);//número 1
  }
  if(contador==2){
    digitalWrite(a,HIGH);//número 2
    digitalWrite(b,HIGH);
    digitalWrite(c,LOW);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);//número 2
  }
  if(contador==3){
    digitalWrite(a,HIGH);//número 3
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);//número 3
  }
  if(contador==4){
    digitalWrite(a,LOW);//número 4
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);//número 4
  }
  if(contador==5){
    digitalWrite(a,HIGH);//número 5
    digitalWrite(b,LOW);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);//número 5
  }
  if(contador==6){
    digitalWrite(a,HIGH);//número 6
    digitalWrite(b,LOW);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);//número 6
  }
  if(contador==7){
    digitalWrite(a,HIGH);//número 7
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);//número 7
  }
  if(contador==8){
    digitalWrite(a,HIGH);//número 8
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);//número 8
  }
  if(contador==9){
    digitalWrite(a,HIGH);//número 9
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);//número 9
  }
 
}
