
int v_s_min[6] = {1023, 1023, 1023, 1023, 1023, 1023};
int v_s_max[6] = {0, 0, 0, 0, 0, 0};
volatile int s_p[6];
boolean online;

int l_CASO;

void calibracion() {

  int v_s[6];

  for (int j = 0; j < 100; j++) {
    delay(1);
    v_s[0] = analogRead(A0);
    v_s[1] = analogRead(A1);
    v_s[2] = analogRead(A2);
    v_s[3] = analogRead(A3);
    v_s[4] = analogRead(A4);
    v_s[5] = analogRead(A5);

    for (int i = 0; i < 6; i++) {

      Serial.print(v_s[i]);
      Serial.print("\t");

    }
    Serial.println();

    for (int i = 0; i < 6; i++) {
      if (v_s[i] < v_s_min[i]) {
        v_s_min[i] = v_s[i];
      }
    }


    for (int i = 0; i < 6; i++) {
      if (v_s[i] > v_s_max[i]) {
        v_s_max[i] = v_s[i];
      }
    }
  }

  Serial.println();
  Serial.print("Mínimos ");
  Serial.print("\t");

  for (int i = 0; i < 6; i++) {

    Serial.print(v_s_min[i]);
    Serial.print("\t");

  }
  Serial.println();
  Serial.print("Máximos ");
  Serial.print("\t");

  for (int i = 0; i < 6; i++) {

    Serial.print(v_s_max[i]);
    Serial.print("\t");

  }
  Serial.println();
  Serial.println();
  Serial.println();
}

void readsensors() {
  volatile int ESN[6];
  ESN[0] = analogRead(A0);
  ESN[1] = analogRead(A1);
  ESN[2] = analogRead(A2);
  ESN[3] = analogRead(A3);
  ESN[4] = analogRead(A4);
  ESN[5] = analogRead(A5);

  for (int i = 0; i < 6; i++) {
    if (ESN[i] < v_s_min[i]) {
      ESN[i] = v_s_min[i];
    }
    if (ESN[i] > v_s_max[i]) {
      ESN[i] = v_s_max[i];
    }
    s_p[i] = map(ESN[i], v_s_min[i], v_s_max[i], 100, 0);
  }

  for (int i = 0; i < 6; i++) {
    Serial.print("   SEN");
    Serial.print(i + 1);
    Serial.print("...  ");
    Serial.print(s_p[i]);
  }
  Serial.println();

  CASO = 0;

  if (s_p[0] >= 30 && s_p[1] >= 30 && s_p[2] >= 30 &&
      s_p[3] >= 30 && s_p[5] >= 30 && s_p[5] >= 30) {
    CASO = 0;
  }
  else if (s_p[0] <= 30 && s_p[1] <= 30 && s_p[2] <= 30 &&
           s_p[3] <= 30 && s_p[4] <= 30 && s_p[5] <= 30) {
    CASO = 1;
  }
  else if (s_p[0] <= 30 && s_p[1] >= 30 && s_p[2] >= 30 &&
           s_p[3] >= 30 && s_p[4] >= 30 && s_p[5] >= 30) {
    CASO = 2;
  }
  else if (s_p[0] >= 30 && s_p[1] <= 30 && s_p[2] >= 30 &&
           s_p[3] >= 30 && s_p[4] >= 30 && s_p[5] >= 30) {
    CASO = 3;
  }
  else if (s_p[0] >= 30 && s_p[1] >= 30 && s_p[2] <= 30 &&
           s_p[3] >= 30 && s_p[4] >= 30 && s_p[5] >= 30) {
    CASO = 4;
  }
  else if (s_p[0] >= 30 && s_p[1] >= 30 && s_p[2] >= 30 &&
           s_p[3] <= 30 && s_p[4] >= 30 && s_p[5] >= 30) {
    CASO = 5;
  }
  else if (s_p[0] >= 30 && s_p[1] >= 30 && s_p[2] >= 30 &&
           s_p[3] >= 30 && s_p[4] <= 30 && s_p[5] >= 30) {
    CASO = 6;
  }
  else if (s_p[0] >= 30 && s_p[1] >= 30 && s_p[2] >= 30 &&
           s_p[3] >= 30 && s_p[4] >= 30 && s_p[5] <= 30) {
    CASO = 7;
  }
  else if (s_p[0] <= 30 && s_p[1] <= 30 && s_p[2] >= 30 &&
           s_p[3] >= 30 && s_p[4] >= 30 && s_p[5] >= 30) {
    CASO = 8;
  }
  else if (s_p[0] >= 30 && s_p[1] >= 30 && s_p[2] <= 30 &&
           s_p[3] <= 30 && s_p[4] >= 30 && s_p[5] >= 30) {
    CASO = 9;
  }
  else if (s_p[0] >= 30 && s_p[1] >= 30 && s_p[2] >= 30 &&
           s_p[3] >= 30 && s_p[4] <= 30 && s_p[5] <= 30) {
    CASO = 10;
  }
  else if (s_p[0] >= 30 && s_p[1] <= 30 && s_p[2] <= 30 &&
           s_p[3] >= 30 && s_p[4] >= 30 && s_p[5] >= 30) {
    CASO = 11;
  }
  else if (s_p[0] >= 30 && s_p[1] >= 30 && s_p[2] >= 30 &&
           s_p[3] <= 30 && s_p[4] <= 30 && s_p[5] >= 30) {
    CASO = 12;
  }
}





