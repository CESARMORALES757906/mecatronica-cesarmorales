# define NVMD 5
# define NVMI 6

# define MD1 8
# define MD2 9   

# define MI1 4
# define MI2 7

void TB5512FNG () {
  pinMode(NVMI, OUTPUT);
  pinMode(NVMD, OUTPUT);
  pinMode(MD1, OUTPUT);
  pinMode(MD2, OUTPUT);
  pinMode(MI1, OUTPUT);
  pinMode(MI2, OUTPUT);
}

void MOTOR_RIGHT(int VELOCIDAD) {
  analogWrite(NVMD, VELOCIDAD);
    digitalWrite(MD1, HIGH);
    digitalWrite(MD2, LOW);
}

void MOTOR_LEFT (int VELOCIDAD){
  analogWrite (NVMI, VELOCIDAD);
    digitalWrite(MI1, LOW);
    digitalWrite(MI2, HIGH);
}

void MOTORES (int LEFT, int RIGHT){
  MOTOR_LEFT (LEFT);
  MOTOR_RIGHT (RIGHT);
}
