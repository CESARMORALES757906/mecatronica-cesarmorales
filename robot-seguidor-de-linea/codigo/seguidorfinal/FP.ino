void MHA(int NVELMD, int VELMD, int NVELMI, int VELMI){
  analogWrite(NVELMD, VELMD);
  analogWrite(NVELMI, VELMI);
}
//Avance de los motores
void AVANCE_MT_DER (){
  digitalWrite (MD1, LOW);
  digitalWrite (MD2, HIGH);
}

void AVANCE_MT_IZQ (){
  digitalWrite (MI1, HIGH);
  digitalWrite (MI2, LOW);
}

//Retroceso de los motores 
void RETROCESO_MT_DER (){
  digitalWrite (MD1, HIGH);
  digitalWrite (MD2, LOW);  
}

void RETROCESO_MT_IZQ (){
  digitalWrite (MI1, LOW);
  digitalWrite (MI2, HIGH);  
}