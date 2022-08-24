//Controle de led utilizando o teclado do computador

//declaração das portas digitais
int ledRed=10;
int ledYellow=9;
int ledGreen=8;
char read; //Váriavel para armazenar o que foi digitado no teclado
//Váriaveis do tipo char armazenam 1 bit
//char!=string


void setup()
{
  //Declarando as saidas dos pinos
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  
  //Comunicação serial
  Serial.begin(9600);
}

void loop()
{
  while(Serial.available()>0){
  read=Serial.read();
    
    if(read=='Q' || read =='q'){
    	digitalWrite(ledRed, HIGH);
    }else if (read=='W' || read=='w'){
    	digitalWrite(ledRed, LOW);
    }else if(read=='A' || read=='a'){
    	digitalWrite(ledYellow, HIGH);
    }else if(read=='S' || read=='s'){
    	digitalWrite(ledYellow, LOW);
    }else if(read=='Z' || read=='z'){
    	digitalWrite(ledGreen, HIGH);
    }else if(read=='X' || read=='x'){
    	digitalWrite(ledGreen, LOW);
    }
    
  }
}