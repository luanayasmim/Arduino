//Declaração de variáveis
	int potenciometro = A0;
	int ledVerde = 12;
	int ledAmarela = 11;
	int ledLaranja = 10;
	int ledAzul = 9;
	int ledVermelha = 8;
	int valorLid;

void setup(){
  Serial.begin(9600);
  pinMode(potenciometro, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarela, OUTPUT);
  pinMode(ledLaranja, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledVermelha, OUTPUT);
}

void loop(){
  //Valor lido no potenciometro
  	valorLid = analogRead(potenciometro);
  	Serial.println(valorLid);
  
  //Leitura abaixo de 10 apaga todos
  	if(valorLid<10){
    	digitalWrite(ledVerde, LOW);
    	digitalWrite(ledAmarela, LOW);
    	digitalWrite(ledLaranja, LOW);
    	digitalWrite(ledAzul, LOW);
    	digitalWrite(ledVermelha, LOW);
  	}
  //Leitura entre 10 e 249 acende o verde
  	if(valorLid>=10 && valorLid<=249){
      	digitalWrite(ledVerde, HIGH);
     	digitalWrite(ledAmarela, LOW);
      	digitalWrite(ledLaranja, LOW);
      	digitalWrite(ledAzul, LOW);
      	digitalWrite(ledVermelha, LOW);
    }
  //Leitura entre 250 e 499 acende o verde e o amarelo
  	if(valorLid>=250 && valorLid<= 499){
      	digitalWrite(ledVerde, HIGH);
      	digitalWrite(ledAmarela, HIGH);
      	digitalWrite(ledLaranja, LOW);
      	digitalWrite(ledAzul, LOW);
      	digitalWrite(ledVermelha, LOW);
    }
  //Leitura entre 500 e 724 acende o verde, amarelo e laranja
  	if(valorLid>=500 && valorLid<=724){
      	digitalWrite(ledVerde, HIGH);
      	digitalWrite(ledAmarela, HIGH);
      	digitalWrite(ledLaranja, HIGH);
      	digitalWrite(ledAzul, LOW);
      	digitalWrite(ledVermelha, LOW);
    }
  //Leitura entre 725 e 824 acende o verde, amarelo, laranja e azul
  	if(valorLid>=725 && valorLid<=824){
      	digitalWrite(ledVerde, HIGH);
      	digitalWrite(ledAmarela, HIGH);
      	digitalWrite(ledLaranja, HIGH);
      	digitalWrite(ledAzul, HIGH);
      	digitalWrite(ledVermelha, LOW);
    }
  //Leitura acima de 825 acende todos os leds
  	if(valorLid>=825){
      	digitalWrite(ledVerde, HIGH);
      	digitalWrite(ledAmarela, HIGH);
      	digitalWrite(ledLaranja, HIGH);
      	digitalWrite(ledAzul, HIGH);
      	digitalWrite(ledVermelha, HIGH);
    }
}