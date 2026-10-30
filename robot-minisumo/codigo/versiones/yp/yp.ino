int TRIG=11;
    int ECO=10; 
    int DISTANCIA;
    int DURACION;
    int M1=5; 
    int M2=4;
    int B1=3;
    int B2=2;
    int SenD=7;
    int SenT=6;
   
  void setup(){
    pinMode(TRIG, OUTPUT);
    pinMode(ECO, INPUT);
    pinMode(M1, OUTPUT);
    pinMode(M2, OUTPUT);
    pinMode(B1, OUTPUT);
    pinMode(B2, OUTPUT);
    pinMode(SenD, INPUT);
    pinMode(SenT, INPUT);
      
    Serial.begin(9600);  
  
}

  void loop(){    
   digitalWrite(TRIG, HIGH);
   delay(1);
   digitalWrite(TRIG, LOW);
   DURACION=pulseIn(ECO, HIGH);
   DISTANCIA=DURACION/58.2;
   Serial.println(DISTANCIA);

  int value1 = 0;                        // Variable temporal que usaremos para recoger la señal del sensor izquierdo
  int value2 = 0;                        // Variable temporal que usaremos para recoger la señal del sensor derecho
  value1 = digitalRead(SenD);     // lectura digital de pin del sensor1
  value2 = digitalRead(SenT);     // lectura digital de pin del sensor2
  
      if(DISTANCIA>40)
      {
      digitalWrite(M1,LOW);
      digitalWrite(M2,HIGH);//MOTOR DERECHO
      digitalWrite(B1,LOW);
      digitalWrite(B2,LOW); // MOTOR IZQ
      }
      if(DISTANCIA<40)
      {
      digitalWrite(M1,HIGH);
      digitalWrite(M2,LOW);//MOTOR DERECHO
      digitalWrite(B1,LOW);
      digitalWrite(B2,HIGH); // MOTOR IZQ
      } 

      if (value1 == HIGH && value2 == LOW) 
      {
      Serial.println("adelante");
      MotorAdelante();    
      }
  
      if (value1 == LOW && value2 == HIGH) 
     {
      Serial.println("detenido");
      MotorStop();    
     }
   
     delay(20);                             // Hacemos una pausa en milisegundos, de forma que leemos el sensor cada dicho tiempo
     }
  
     void MotorAdelante()
    {
    digitalWrite (M1, HIGH);            // Motor Izquierdo atras
    digitalWrite (M2, LOW);  
    digitalWrite (B1, HIGH);            // Motor Derecho adelante
    digitalWrite (B2, LOW); 
    }

    void MotorStop()
    {
    digitalWrite (M1, LOW);             // Motor Izquierdo adelante
    digitalWrite (M2, HIGH);  
    digitalWrite (B1, LOW);             // Motor Derecho atras
    digitalWrite (B2, HIGH);
    }
