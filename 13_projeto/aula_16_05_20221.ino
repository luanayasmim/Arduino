// Constantes referentes aos semafóros e buzzer
//

const int carroVermelho=12;
const int carroAmarelo=11;
const int carroVerde=10;
const int pedVermelho=9;
const int pedVerde=8;
const int botao=2;
const int buzzer=7;
const int ldr=A0;
int tempoTravessia=5000;
unsigned long changeTime;


void setup()
{
  pinMode(carroVermelho, OUTPUT);
  pinMode(carroAmarelo, OUTPUT);
  pinMode(carroVerde, OUTPUT);
  pinMode(pedVermelho, OUTPUT);
  pinMode(pedVerde, OUTPUT);
  pinMode(botao, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ldr, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int state=digitalRead(botao);
  int leitura_ldr=analogRead(ldr);
  
  Serial.println(leitura_ldr);
  
  if(leitura_ldr>400){
  	digitalWrite(carroVerde, HIGH);
    digitalWrite(pedVermelho, HIGH);
    
    if(state==HIGH &&(millis()-changeTime)>5000){
    	changeLights();
    }
  }else{
  	noturno();
  }
}

void changeLights(){
	digitalWrite(carroVerde, LOW);
  	digitalWrite(carroAmarelo, HIGH);
  	delay(2000);
  	digitalWrite(carroAmarelo, LOW);
  	digitalWrite(carroVermelho, HIGH);
  	delay(1000);
  	digitalWrite(pedVermelho, LOW);
  	digitalWrite(pedVerde, HIGH);
  	tone(buzzer, 1500, 250);
  	delay(tempoTravessia);
  	
    for(int x=0;x<10;x++){
    	tone(buzzer, 1000, 250);
      	digitalWrite(pedVerde, HIGH);
      	delay(250);
      	digitalWrite(pedVerde, LOW);
      	delay(250);
    }
  	
  	digitalWrite(pedVermelho, HIGH);
  	delay(500);
  	digitalWrite(carroVermelho, LOW);
    delay(1000);
  	digitalWrite(carroVerde, HIGH);
    changeTime=millis();
}

void noturno(){
	apagaTudo();
  for(int j=0; j<10;j++){
  	digitalWrite(carroAmarelo, HIGH);
    digitalWrite(pedVerde, HIGH);
    delay(250);
    digitalWrite(carroAmarelo, LOW);
    digitalWrite(pedVerde, LOW);
    delay(250);
    
  }
}

void apagaTudo(){
	digitalWrite(carroVerde, LOW);
  	digitalWrite(carroAmarelo, LOW);
  	digitalWrite(carroVermelho, LOW);
  	digitalWrite(pedVerde, LOW);
  	digitalWrite(pedVermelho, LOW);
}
