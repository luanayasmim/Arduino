//Declarar as variáveis controle
int v_botao=12;
int v_ledRed=11;

//Declarar a variável de estado
int v_estado;

//Configurar as portas
void setup() {
  pinMode(v_botao,INPUT);
  pinMode(v_ledRed,OUTPUT);
}

void loop() {
  //Leitura do estado do botão
  v_estado=digitalRead(v_botao);

  //Validação
  if(v_estado==HIGH){
    //Acender o Led
    digitalWrite(v_ledRed,HIGH);
    //delay(1000)
  }else{
    //Apagar o Led
    digitalWrite(v_ledRed, LOW);
  }
}