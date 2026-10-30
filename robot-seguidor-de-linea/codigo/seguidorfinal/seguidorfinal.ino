const int NVMD = 10;   //Nivel de velocidad del Motor Derecho  PWM MOTOR DERECHO 
const int NVMI = 11;   //Nivel de velocidad del Motor Izquierdo  PWM MOTOR IZQUIERDO 
 
const int MD1 = 2;    //Motor Derecho (IN1)
const int MD2 = 3;    //Motor Derecho (IN2)

const int MI1 = 4;    //Motor Izquierdo (IN3)
const int MI2 = 7;    //Motor Izquierdo (IN4) 

const int SN1 = 5;   //Sensor 1 EN PINES DIGITALES
const int SN2 = 6;   //Sensor 2 EN PINES DIGITALES 

///////////////////NO MOVER //////////////////////////////

unsigned long TA = 0;   //Variable de 32 bits
unsigned long IN = 1;   //Variable de 32 bits (Milisegundos)
///////////////////////////////////////////////////////////

void setup () {
  Serial.begin (9600);
  pinMode(MD1,OUTPUT);    //Motor Derecho
  pinMode(MD2,OUTPUT);    //Motor Derecho

  pinMode(MI1,OUTPUT);    //Motor Izquierdo
  pinMode(MI2,OUTPUT);    //Motor Izquierdo

  pinMode (SN1, INPUT);      //Entrada Sensor 1
  pinMode (SN2, INPUT);      //Entrada Sensor 2

  pinMode (NVMD, OUTPUT);   //ENA Motor Derecho
  pinMode (NVMI, OUTPUT);   //ENB Motor Izquierdo


//PRUEBA DE FUNCIONAMIENTO DE MOTORES (CAMBIAR VALOR4ES Y FUNCIONES PARA ASEGURARSE DE QUE TODO ESTA CONECTADI BIEN)
  MHA(NVMD, 150, NVMI, 150);
  AVANCE_MT_DER ();
  AVANCE_MT_IZQ ();

//LA FUNCION HACE QUE NO SE EJCUTE LA LINEA SIGIENTE SI EL BOTN NO ES PRESIONADO 

}

//BUCLE Y LECTURA DE LOS SENSORES 
void loop () {
  int ESN1 = digitalRead (SN1);   //Estado y lectura del Sensor 1  
  int ESN2 = digitalRead (SN2);   //Estado y lectura del Sensor 2

  if (millis () - TA >= IN){
    Serial.print ("    /S1---");    //Etiqueta Sensor 1
    Serial.print (ESN1);

    Serial.print ("    /S2---");    //Etiqueta Sensor 2
    Serial.print (ESN2);

    Serial.println("\n");
    TA = millis(); 
  }

// 0 ES BLACO --- 1 ES NEGRO
// PARA MODIFICAR LAS VELOCIDADES ES EN MHA (VALORES NUMERICOS)

//RECTAS
if (ESN1 == 1 && ESN2 == 1) { //TODOS EN NEGRO 
  MHA(NVMD, 150, NVMI, 150);
  AVANCE_MT_DER ();
  AVANCE_MT_IZQ ();
} 

else if (ESN1 == 0 && ESN2 == 0 ) { //TODOS EN BLANCO 
  MHA(NVMD, 150, NVMI, 150);
  AVANCE_MT_DER ();
  AVANCE_MT_IZQ ();    
}

////////////////////PROBAR VELOCIDADES PARA VER EN QUE CASO FUNCIONA MEJOR
//GIROS (MAYOR LA VELOCIDAD QUE EN RECTAS)
else if (ESN1 == 1 && ESN2 == 0 ) { //DESVIACION HACIA LA IZQUIERDA
  MHA(NVMD, 180, NVMI, 180);
RETROCESO_MT_DER ();
  AVANCE_MT_IZQ ();      
}

else if (ESN1 == 0 && ESN2 == 1) {  //DESVIACION HACIA LA DERCHA 
  MHA(NVMD, 180, NVMI, 180);    
RETROCESO_MT_IZQ ();
AVANCE_MT_DER ();
}
}
