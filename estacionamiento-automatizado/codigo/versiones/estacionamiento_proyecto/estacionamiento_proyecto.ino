#include <Servo.h>

int num = 0;
int estadoBoton2 = 0;
int P2 = 3;
int P1 = 2;
int P3 = 12;
int SERVO = 11;
int ANGULO_INICIAL = 0;
int ANGULO_FINAL = 90;

Servo miServo;


void setup (){
Serial.begin(9600);
pinMode(P2, INPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);

  pinMode(P1, INPUT);  // Configuramos los pines de los botones como entrada
  pinMode(P3, INPUT);
  
  miServo.attach(SERVO);  // Inicializamos el servo en el pin correspondiente
  miServo.write(ANGULO_INICIAL);  // Movemos el servo a la posición inicial



}

void loop(){

  if (digitalRead(P1) == HIGH) {  // Cuando el botón no está presionado (HIGH)
    miServo.write(ANGULO_FINAL);  // Movemos el servo a 90 grados
    delay(500);  // Esperamos un momento para evitar rebotes de botón
  }
  
  // Verificamos si se presiona el segundo botón
  if (digitalRead(P3) == HIGH) {  // Cuando el botón no está presionado (HIGH)
    miServo.write(ANGULO_INICIAL);  // Movemos el servo a 0 grados (posición inicial)
    delay(500);  // Esperamos un momento para evitar rebotes de botón
  }

estadoBoton2 = digitalRead(P2);
Serial.print("estadoBoton2");
Serial.println(estadoBoton2);
delay(100);
Serial.print("num");
Serial.println(num);
delay(100);


if (estadoBoton2 == HIGH) {
    num = num + 1;
  if (num >= 10){
      num=0;
  }
}
switch (num) {
case 0:
digitalWrite(4,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
break;
  
case 1:
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
digitalWrite(10,LOW);
break;
  
case 2:
digitalWrite(4,LOW);
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,HIGH);
break;
  
case 3:
digitalWrite(4,LOW);
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
break;
  
case 4:
digitalWrite(4,LOW);
digitalWrite(5,LOW);
digitalWrite(6,HIGH);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
digitalWrite(10,LOW);
break;
  
case 5:
digitalWrite(4,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
break;
  
case 6:
digitalWrite(4,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
break;
  
case 7:
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
digitalWrite(10,LOW);
break;
  
case 8:
digitalWrite(4,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
break;
  
case 9:
digitalWrite(4,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
digitalWrite(10,LOW);
}

delay(50);
}
