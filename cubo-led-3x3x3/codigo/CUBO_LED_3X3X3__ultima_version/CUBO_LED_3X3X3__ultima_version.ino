void setup() {
 for (int pin = 2; pin < 14; pin++) {
 pinMode (pin,OUTPUT); 
     }
}

void loop() {    ///////////////// DESDE AQUI EMPIEZA LA PROGRAMACION

 for (int pin = 5; pin < 14; pin++) {      //LOS NIVELES ASCINDEN Y DESCINDEN
  digitalWrite(pin, HIGH);
 }
 
 for (int pin = 2; pin < 5; pin++) {
  digitalWrite(pin, HIGH);
  delay(400);
 }
   for (int pin = 4; pin > 1; pin--) {
  digitalWrite(pin, LOW);
  delay(400);
 }
  for (int pin = 2; pin < 14; pin++) {    //APAGAMOS TODO
  digitalWrite(pin, LOW);
 }
////////////////////////////////// LAS CUATRO ESQUINAS PARPADEAN
     digitalWrite(5, HIGH);   
     digitalWrite(7, HIGH);
     digitalWrite(11, HIGH);
     digitalWrite(13, HIGH);
     digitalWrite(2, HIGH);
     digitalWrite(4, HIGH);
     delay(400);
     digitalWrite(2, LOW);
     digitalWrite(4, LOW);
     delay(400);
     digitalWrite(5, HIGH);   
     digitalWrite(7, HIGH);
     digitalWrite(11, HIGH);
     digitalWrite(13, HIGH);
     digitalWrite(2, HIGH);
     digitalWrite(4, HIGH);
     delay(400);
     digitalWrite(2, LOW);
     digitalWrite(4, LOW);
     delay(400);     
     digitalWrite(5, HIGH);   
     digitalWrite(7, HIGH);
     digitalWrite(11, HIGH);
     digitalWrite(13, HIGH);
     digitalWrite(2, HIGH);
     digitalWrite(4, HIGH);
     delay(400);
     digitalWrite(2, LOW);
     digitalWrite(4, LOW);
     delay(500);
     
  for (int pin = 2; pin < 14; pin++) {    //APAGAMOS TODO
  digitalWrite(pin, LOW);
 }
 //////////////////////////////////////ENCENDEMOS LAS COLUMNAS EXTIERIORES, EN FORM A SECUEMCIAL
      digitalWrite(13, HIGH);      
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      delay(200);   
  for (int pin = 2; pin < 14; pin++) {    
  digitalWrite(pin, LOW);
 }
      digitalWrite(12, HIGH); 
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      delay(200);   
  for (int pin = 2; pin < 14; pin++) {    
  digitalWrite(pin, LOW);
 }
      digitalWrite(11, HIGH); 
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      delay(200);   
  for (int pin = 2; pin < 14; pin++) {    
  digitalWrite(pin, LOW);
 }
      digitalWrite(8, HIGH); 
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      delay(200);   
  for (int pin = 2; pin < 14; pin++) {    
  digitalWrite(pin, LOW);
 }
      digitalWrite(5, HIGH); 
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      delay(200);   
  for (int pin = 2; pin < 14; pin++) {    
  digitalWrite(pin, LOW);
 }
      digitalWrite(6, HIGH); 
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      delay(200);   
  for (int pin = 2; pin < 14; pin++) {    
  digitalWrite(pin, LOW);
 }
      digitalWrite(7, HIGH); 
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      delay(200);   
  for (int pin = 2; pin < 14; pin++) {    
  digitalWrite(pin, LOW);
 }
      digitalWrite(10, HIGH); 
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      delay(200);   
  for (int pin = 2; pin < 14; pin++) {    
  digitalWrite(pin, LOW);
}
////////////////////////////////////////// ENCIENDEN LOS LEDS DE A 1, DE ARRIBA HACIA ABAJO
   digitalWrite(4, HIGH);
   for (int pin = 5; pin < 14; pin++) {    
   digitalWrite(pin, HIGH);
    delay(200);
 }
  for (int pin = 2; pin < 14; pin++) {    
  digitalWrite(pin, LOW);
   }
   
   digitalWrite(3, HIGH);
   for (int pin = 5; pin < 14; pin++) {  
   digitalWrite(pin, HIGH);
    delay(200);
 }
  for (int pin = 2; pin < 14; pin++) {    
  digitalWrite(pin, LOW);
   }
    digitalWrite(2, HIGH);
   for (int pin = 5; pin < 14; pin++) {  
   digitalWrite(pin, HIGH);
    delay(200);
 }
  for (int pin = 2; pin < 14; pin++) {    
  digitalWrite(pin, LOW);
   }

///////////////////////////////////////////////////////////////  BAJAN Y SUBEN LAS COLUMNAS
   for (int pin = 13; pin > 4; pin--) {  
   digitalWrite(pin, HIGH);
   }
   for (int pin = 4; pin > 1; pin--) {  
   digitalWrite(pin, HIGH);
    delay(200);
}
   for (int pin = 2; pin < 14; pin++) {    
  digitalWrite(pin, LOW);
 }
   for (int pin = 5; pin < 14; pin++) {  
   digitalWrite(pin, HIGH);
   }
   for (int pin = 2; pin < 5; pin++) {  
   digitalWrite(pin, HIGH);
    delay(200);
}
   for (int pin = 2; pin < 14; pin++) {    
  digitalWrite(pin, LOW);
 }

////////////////////////////////////////////////////// COLUMNA CENTRAL FIJA, COLUMNAS EXTERNAS SECUENCIALES.
digitalWrite(9, HIGH);
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
delay(200);
digitalWrite(13, HIGH);
delay(200);
digitalWrite(13, LOW);
digitalWrite(12, HIGH);
delay(200);
digitalWrite(12, LOW);
digitalWrite(11, HIGH);
delay(200);
digitalWrite(11, LOW);
digitalWrite(8, HIGH);
delay(200);
digitalWrite(8, LOW);
digitalWrite(5, HIGH);
delay(200);
digitalWrite(5, LOW);
digitalWrite(6, HIGH);
delay(200);
digitalWrite(6, LOW);
digitalWrite(7, HIGH);
delay(200);
digitalWrite(7, LOW);
digitalWrite(10, HIGH);
delay(200); 
//////////////////////////////////////////////////////////////
digitalWrite(7, HIGH);
digitalWrite(10, LOW);
delay(200);
digitalWrite(6, HIGH);
digitalWrite(7, LOW);
delay(200);
digitalWrite(5, HIGH);
digitalWrite(6, LOW);
delay(200);
digitalWrite(8, HIGH);
digitalWrite(5, LOW);
delay(200);
digitalWrite(11, HIGH);
digitalWrite(8, LOW);
delay(200);
digitalWrite(12, HIGH);
digitalWrite(11, LOW);
delay(200);
digitalWrite(13, HIGH);
digitalWrite(12, LOW);
delay(200);
   for (int pin = 2; pin < 14; pin++) {    //APAGAMOS TODO
  digitalWrite(pin, LOW);
 }
//////////////////////////////////////////ENCIENDEN COLUMNA POR COLUMNA SECUENCIAL
  for (int pin = 2; pin < 14; pin++) { 
  digitalWrite(pin, HIGH);
  delay(150);
  }
////////////////////////////////////////////COLUMNA CENTRAL ENCNEDIDA,ENCENDIO CUBO COMPLETO
digitalWrite(9, HIGH);
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
delay(500);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);
delay(500);
  digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
delay(500);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);
delay(500);
  digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
delay(500);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);
delay(500);
  digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
delay(500);
//////////////////////////////////////////////////////
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);
delay(800);
digitalWrite(5, LOW);
digitalWrite(6, HIGH);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, HIGH);
digitalWrite(13, LOW);
delay(250);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, HIGH);
digitalWrite(8, LOW);
digitalWrite(10, LOW);
digitalWrite(11, HIGH);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
delay(250);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
delay(250);
digitalWrite(5, HIGH);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, HIGH);
delay(250);
digitalWrite(5, LOW);
digitalWrite(6, HIGH);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, HIGH);
digitalWrite(13, LOW);
delay(250);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, HIGH);
digitalWrite(8, LOW);
digitalWrite(10, LOW);
digitalWrite(11, HIGH);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
delay(250);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
delay(250);
digitalWrite(5, HIGH);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, HIGH);
delay(250);
digitalWrite(5, LOW);
digitalWrite(6, HIGH);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, HIGH);
digitalWrite(13, LOW);
delay(250);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, HIGH);
digitalWrite(8, LOW);
digitalWrite(10, LOW);
digitalWrite(11, HIGH);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
delay(250);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
delay(250);
digitalWrite(5, HIGH);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, HIGH);
delay(250);
///////////////////////////////////////////////////// APAGADO

digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
delay(700);
////////////////////////////////////////////////ENCENDIDO POR CAPAS
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
delay(400);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
delay(400);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(11, HIGH);
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);
delay(400);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
digitalWrite(5, HIGH);
digitalWrite(8, HIGH);
digitalWrite(11, HIGH);
delay(400);
digitalWrite(5, LOW);
digitalWrite(8, LOW);
digitalWrite(11, LOW);
digitalWrite(6, HIGH);
digitalWrite(9, HIGH);
digitalWrite(12, HIGH);
delay(400);
digitalWrite(6, LOW);
digitalWrite(9, LOW);
digitalWrite(12, LOW);
digitalWrite(7, HIGH);
digitalWrite(10, HIGH);
digitalWrite(13, HIGH);
delay(400);
digitalWrite(7, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(12, HIGH);
digitalWrite(11, HIGH);
delay(400);
digitalWrite(12, LOW);
digitalWrite(11, LOW);
digitalWrite(13, LOW);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
delay(400);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
delay(400);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(10, HIGH);
digitalWrite(13, HIGH);
delay(400);
digitalWrite(10, LOW);
digitalWrite(13, LOW);
digitalWrite(7, LOW);
digitalWrite(6, HIGH);
digitalWrite(9, HIGH);
digitalWrite(12, HIGH);
delay(400);
digitalWrite(6, LOW);
digitalWrite(9, LOW);
digitalWrite(12, LOW);
digitalWrite(5, HIGH);
digitalWrite(8, HIGH);
digitalWrite(11, HIGH);
delay(400);
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
delay(500);

//////////////////////////OTRO EFECTO0000000000000000
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);
delay(1000);
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
delay(2000);


}
