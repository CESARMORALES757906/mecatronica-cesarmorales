const int NVMD = 5;   //Nivel de velocidad del Motor Derecho
const int NVMI = 6;   //Nivel de velocidad del Motor Izquierdo  

const int MD1 = 9;    //Motor Derecho (IN1)
const int MD2 = 10;    //Motor Derecho (IN2)

const int MI1 = 7;    //Motor Izquierdo (IN3)
const int MI2 = 8;    //Motor Izquierdo (IN4) 

const int SN1 = 0;   //Sensor 1
const int SN2 = 3;   //Sensor 2
const int SN3 = 4;   //Sensor 3
const int SN4 = 13;  //Sensor 4

int BA = 0;      //Boton de Arranque de los Sensores

# define PINBOTON 2
//---Variables de precisión---
unsigned long TA = 0;   //Variable de 32 bits
unsigned long IN = 1;   //Variable de 32 bits (Milisegundos)

//-----Declaracion de salidas y entradas-----
void setup () {
  Serial.begin (9600);
  pinMode(MD1,OUTPUT);    //Motor Derecho
  pinMode(MD2,OUTPUT);    //Motor Derecho

  pinMode(MI1,OUTPUT);    //Motor Izquierdo
  pinMode(MI2,OUTPUT);    //Motor Izquierdo

  pinMode (SN1, INPUT);      //Entrada Sensor 1
  pinMode (SN2, INPUT);      //Entrada Sensor 2
  pinMode (SN3, INPUT);      //Entrada Sensor 3
  pinMode (SN4, INPUT);      //Entrada Sensor 4

  pinMode (NVMD, OUTPUT);   //ENA Motor Derecho
  pinMode (NVMI, OUTPUT);   //ENB Motor Izquierdo
  while (!digitalRead (PINBOTON));
}

void loop () {
  int ESN1 = digitalRead (SN1);   //Estado y lectura del Sensor 1  
  int ESN2 = digitalRead (SN2);   //Estado y lectura del Sensor 2
  int ESN3 = digitalRead (SN3);   //Estado y lectura del Sensor 3
  int ESN4 = digitalRead (SN4);   //Estado y lectura del Sensor 4

  if (millis () - TA >= IN){
    Serial.print ("    /S1---");    //Etiqueta Sensor 1
    Serial.print (ESN1);

    Serial.print ("    /S2---");    //Etiqueta Sensor 2
    Serial.print (ESN2);

    Serial.print ("    /S3---");    //Etiqueta Sensor 3
    Serial.print (ESN3);
    
    Serial.print ("    /S4---");    //Etiqueta Sensor 4
    Serial.print (ESN4);

    Serial.println("\n");
    TA = millis(); 
  }

if (ESN1 == 1 && ESN2 == 1 && ESN3 == 1 && ESN4 == 1) {
  MHA(NVMD, 120, NVMI, 120);
  AVANCE_MT_DER ();
  AVANCE_MT_IZQ ();
} 
else if (ESN1 == 0 && ESN2 == 0 && ESN3 == 0 && ESN4 == 0) {
  MHA(NVMD, 120, NVMI, 120);
  AVANCE_MT_DER ();
  AVANCE_MT_IZQ ();    
}

else if (ESN1 == 1 && ESN2 == 0 && ESN3 == 0 && ESN4 == 0) {
  MHA(NVMD, 255, NVMI, 255);
RETROCESO_MT_DER ();
  AVANCE_MT_IZQ ();      
}
else if (ESN1 == 0 && ESN2 == 1 && ESN3 == 0 && ESN4 == 0) {
  MHA(NVMD, 50, NVMI, 150);  
RETROCESO_MT_DER ();
  AVANCE_MT_IZQ ();    
}
else if (ESN1 == 0 && ESN2 == 0 && ESN3 == 1 && ESN4 == 0) {
  MHA(NVMD, 150, NVMI, 50);    
  AVANCE_MT_DER ();
RETROCESO_MT_IZQ ();
}
else if (ESN1 == 0 && ESN2 == 0 && ESN3 == 0 && ESN4 == 1) {
  MHA(NVMD, 255, NVMI, 255);    
  AVANCE_MT_DER ();
RETROCESO_MT_IZQ ();
}

else if (ESN1 == 1 && ESN2 == 1 && ESN3 == 0 && ESN4 == 0) {
  MHA(NVMD, 255, NVMI, 255);
RETROCESO_MT_DER ();
AVANCE_MT_IZQ ();
}

else if (ESN1 == 0 && ESN2 == 0 && ESN3 == 1 && ESN4 == 1) {
  MHA(NVMD, 255, NVMI, 255);    
RETROCESO_MT_IZQ ();
AVANCE_MT_DER ();
}
}
