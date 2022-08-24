// Semaforo interativo
//

int carroVermelho=12;
int carroAmarelo=11;
int carroVerde=10;
int pedVermelho=8;
int pedVerde=9;
int botao=2; //pino do interruptor
int tempoTravessia=5000; //tempo para atravessar a rua
unsigned long changeTime;

void setup()
{
  pinMode (carroVermelho, OUTPUT);
  pinMode (carroAmarelo, OUTPUT);
  pinMode (carroVerde, OUTPUT);
  pinMode (pedVermelho, OUTPUT);
  pinMode (pedVerde, OUTPUT);
  pinMode (botao, OUTPUT);
  //liga a luz verde dos carros e a vermelha para os pedestres
  digitalWrite (carroVerde, HIGH);
  digitalWrite (pedVermelho, HIGH);
}

void loop()
{
  int state=digitalRead (botao);
  if (state==HIGH && (millis()-changeTime)>5000){
  	//Ativa a função para mudar as luzes
    changeLights();//Executa o bloco changeLights()
  }
}

void changeLights(){
	digitalWrite (carroVerde, LOW); //Desliga o verde
	digitalWrite (carroAmarelo, HIGH); //Liga o amarelo
  	delay(2000);//Espera 2 segundos
  	digitalWrite (carroAmarelo, LOW); //Desliga o amarelo
	digitalWrite (carroVermelho, HIGH); //Liga o vermelho
  	delay(1000);//Espera 1 segundo
  	digitalWrite (pedVermelho, LOW); //Desliga o vemelho do pedestre
	digitalWrite (pedVerde, HIGH); //Liga o verde
  	delay(tempoTravessia);
  
  for(int x=0; x<10; x++){
  	digitalWrite (pedVerde, HIGH); //Liga o verde do pedestre
    delay(250);//espera 250 milisegundos
    digitalWrite (pedVerde, LOW); //Desliga o verde do pedestre
    delay(250);//espera 250 milisegundos
  }
  
	digitalWrite (pedVermelho, HIGH);//Liga o sinal vermelho do pedestre
  	delay(500);//espera 500 milisegundos
  	digitalWrite (carroVermelho, LOW);//Desliga o sinal vermelho do carro
  	delay(1000);//espera 1 segundo
  	digitalWrite (carroVerde, HIGH); //Liga o verde
  	changeTime=millis();//Tempo desde a última alteração de luzes

}