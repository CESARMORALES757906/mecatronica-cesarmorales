//INCLUIMOS LA LIBRERIA DE LOS SENSORES QTR
#include <QTRSensors.h>


//botones
int btn1=12;
int btn2=11;

//DECLARAMOS ENTRADAS PARA EL PUENTE H AL ARDUINO
int PWMA=9;
int AIN2=8;
int AIN1=7;
int PWMB=3;
int BIN2=4;
int BIN1=5;
int STANDBY  = 6;
///DECLARAMOS SALIDA PARA SEÑALIZAR EL CALIBRADO
int LED = 13;
//VARIABLES DE ALMACENAMIENTO
int P=0;
int I=0;
int D=0;
int LAST=0;
float vel;
//DECLARAMOS VELOCIDAD 
int VelMax = 100;  
//////////////////////////////////////////////////////////////////////////////////////////
//
#define NUM_SENSORS   8     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   11     // emitter is controlled by digital pin 2

// DECLARAMOS ENTRAS PARA LOS SENSORES
QTRSensorsRC qtra((unsigned char[]) {17, 16, 15, 14, 13, 12, 11, 10},
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];

unsigned int position=0;

void setup()
{
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(PWMA,OUTPUT);
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(PWMB,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);
  pinMode(STANDBY,OUTPUT);

  pinMode(LED,OUTPUT);

  delay(1500);
  digitalWrite(LED,HIGH);
  //prendemos el led (LED, HIGH);
   for (int j = 0; j <200; j++)  
 {                                 
    qtra.calibrate();            // codigo para programar el sensor                     
}
 digitalWrite(LED,LOW);
 //APAGAMOS EL LED 

 //INICIAMOS EL ARANQUE DE LOS MOTOS                                                                   
 digitalWrite(AIN1,LOW);
 digitalWrite(AIN2,HIGH);
 
 digitalWrite(BIN1,HIGH);
 digitalWrite(BIN2,LOW);
 
 analogWrite(PWMA,0);
 analogWrite(PWMB,0);
 //HABILITAMOS EL PUENTE H PARA EL FUNCIONAMIENTO DEL MISMO
 digitalWrite(STANDBY, HIGH);
}


void loop(){
  if(digitalRead(btn1==1)){
  for(;;){
    qtra.read(sensorValues);
   position = qtra.readLine(sensorValues, QTR_EMITTERS_ON, 0);
   P = ((position)-(3500)); /// ERROR/////FRENOS////
   if(P<-3500){
     analogWrite(PWMA,200); // VELOCIDAD PARA EL MOTOR DERECHO
     analogWrite(PWMB,255); //  VELOCIDAD PARA EL MOTOR IZQUIERDO
     digitalWrite(AIN1,LOW);   ///FRENTE
     digitalWrite(AIN2,HIGH);
     digitalWrite(BIN1,LOW);  ///RETROCEDE
     digitalWrite(BIN2,HIGH);
     
     }
     else if (P>3500){
     analogWrite(PWMA,255); // VELOCIDAD PARA EL MOTOR DERECHO
     analogWrite(PWMB,200); //  VELOCIDAD PARA EL MOTOR IZQUIERDO
     digitalWrite(AIN1,HIGH);   ///RETROCEDE
     digitalWrite(AIN2,LOW);
     digitalWrite(BIN1,HIGH);  ///FRENTE
     digitalWrite(BIN2,LOW);
     }
   
   else{   D= (P - LAST); /// ERROR MENOS EL ERROR ANTERIOR , DERIVATIVO
   I=(P+ LAST); //INTEGRAL
   vel=(P*0.02)+(D*1.20)+(I*0.0052);
   ///VELOCIDAMAX =VELOCIDAD PUNTA , V

   if(vel >VelMax) vel=VelMax;
   if(vel<-VelMax) vel=-VelMax;


   analogWrite(PWMA,VelMax-vel); // VELOCIDAD PARA EL MOTOR DERECHO
   analogWrite(PWMB,VelMax+vel); //  VELOCIDAD PARA EL MOTOR IZQUIERDO

   digitalWrite(AIN1,LOW);   ///FRENTE
   digitalWrite(AIN2,HIGH);
   digitalWrite(BIN1,HIGH);  ///FRENTE
   digitalWrite(BIN2,LOW);
 
   LAST=P;
   }


   }
}
}


