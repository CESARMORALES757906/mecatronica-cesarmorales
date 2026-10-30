const int pecho = 2; //la pata echo del CI va al pin 2 
const int ptrig = 3; //la pata trigger del CI va al pin 3
int duracion, distancia; //para calcular distacia
void setup() { 
 Serial.begin(9600); //in
 pinMode(pecho, INPUT); //define el pin 2 como entrada (pecho) 
 pinMode(ptrig, OUTPUT); //define el pin 3 como salida (ptrig) 
} 
void loop() { 
 digitalWrite(ptrig, LOW); //al comenzar el loop el trigger debe estar en LOW
 delay(10); 
 digitalWrite(ptrig, HIGH); //genera el pulso de trigger por 0,01 ms
 delay(0.01); 
 digitalWrite(ptrig, LOW); 
 duracion = pulseIn(pecho, HIGH); //tiempo de ida y vuelta en microsegundos
 distancia = (duracion/2)*0.034; //distancia
 delay(10); //para darle tiempo 
 if ((distancia >= 500)||(distancia <= 0)){ //si la distancia es mayor de 5 m
 Serial.println("----------
 } 
 else{ 
 Serial.print(distancia);
 Serial.println(" cm"); 
 } 
 delay(100); //para que los datos por el serial no aparezcan tan deprisa 
}
