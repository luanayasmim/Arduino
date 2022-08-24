//Notas musicais com buzzer e com Leds

//Notas Musicais
int DO = 262;//Nota Dó
int RE = 294;//Nota Ré
int MI = 330;//Nota Mi
int FA = 349;//Nota Fa
int SOL= 392;//Nota Sol
int LA = 440;//Nota Lá
int SI = 494;//Nota Si
int DO_2=523;//Nota Dó2

//Leds para piscarem
int Led1=12;
int Led2=11;
int Led3=10;
int Led4= 9;
int Led5= 8;
int Led6= 7;
int Led7= 6;
int Led8= 5;

//Pino do Buzzer
int pinoBuzzer=13;

//Array para armazenar as notas
int melodia[]={
  DO, RE, MI, FA, SOL, LA, SI, DO_2
};

//Array para armazenar os Leds
int pisca_pisca[]={
  Led1, Led2, Led3, Led4, Led5, Led6, Led7, Led8
};


void setup(){
  //Configura as saídas
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
  pinMode(Led5, OUTPUT);
  pinMode(Led6, OUTPUT);
  pinMode(Led7, OUTPUT);
  pinMode(Led8, OUTPUT);
}


void loop(){
  //Estrutura FOR para percorrer o array
  for(int i=0;i<8;i++){
    digitalWrite(pisca_pisca[i], HIGH);
    tone(pinoBuzzer, melodia[i]);//Toca de acordo com a nota
    delay(500);//Duração do som
  }
  //Exemplo aprimorado com noTone()
  noTone(pinoBuzzer);
  delay(500);
  
  //Estrutura FOR para percorrer o array
  for(int z=7;z>=0;z--){
    digitalWrite(pisca_pisca[z], LOW);
    tone(pinoBuzzer, melodia[z]);//Toca de acordo com a nota
    delay(500);//Duração do som
  }
  
  noTone(pinoBuzzer);
  delay(500);
}