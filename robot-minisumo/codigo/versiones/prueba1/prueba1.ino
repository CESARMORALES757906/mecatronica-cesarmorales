int TRIG=11;
    int ECO=10; 
    int DISTANCIA;
    int DURACION;
    int M1=5; 
    int M2=4;
    int V1=3;
    int B2=2;
    int SENSORD;
    int SENSORT;
    int SD=7;
    int ST=6;
   
  void setup(){
    pinMode(TRIG, OUTPUT);
    pinMode(ECO, INPUT);
    pinMode(M1, OUTPUT);
    pinMode(M2, OUTPUT);
    pinMode(B1, OUTPUT);
    pinMode(B2, OUTPUT);
    pinMode(SD, INPUT);
    pinMode(ST, INPUT);
      
    Serial.begin(9600);  
  
}
  void loop(){
     
      
    digitalWrite(TRIG, HIGH);
   delay(1);
   digitalWrite(TRIG, LOW);
   DURACION=pulseIn(ECO, HIGH);
   DISTANCIA=DURACION/58.2;
    Serial.println(DISTANCIA);
      
      if(DISTANCIA>40)
      {
      digitalWrite(M1,LOW);
      digitalWrite(M2,HIGH);//MOTOR DERECHO
      digitalWrite(V1,LOW);
      digitalWrite(B2,LOW); // MOTOR IZQ
      }
      if(DISTANCIA<40)
      {
      digitalWrite(M1,HIGH);
      digitalWrite(M2,LOW);//MOTOR DERECHO
      digitalWrite(V1,LOW);
      digitalWrite(B2,HIGH); // MOTOR IZQ
      }   
           
    if (digitalRead(SD)==HIGH){
      digitalWrite(M1,LOW);
      digitalWrite(M2,HIGH);//MOTOR DERECHO
      digitalWrite(V1,LOW);
      digitalWrite(B2,HIGH); // MOTOR IZQ
    }
    if(digitalRead(ST)==HIGH){
      digitalWrite(M1,HIGH);
      digitalWrite(M2,LOW);//MOTOR DERECHO
      digitalWrite(V1,HIGH);
      digitalWrite(B2,LOW); // MOTOR IZQ
    }
   }
