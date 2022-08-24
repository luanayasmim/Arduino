//Controle de leds atraves do teclado

//declarando portas das leds
int led[]={8, 9 , 10}; //Verde, Amarelo, Vermelho

char read; //Variável de leitura para o teclado

void setup()
{
  //Inicializa a comunicação serial
  Serial.begin(9600); 
  
  //Percorrendo o vetor das leds e declarando o pino como saida
  for(int i=0; i<3; i++){
  	pinMode(led[i], OUTPUT);
  }
  
  
  //Chama a função menu de visualição no Monitor serial
  doMenu();
  
}

void loop()
{
  while(Serial.available()>0){
  	read=Serial.read();
    
    checkRead(read);
  }
}

//Função doMenu
void doMenu(){

  jumpLine(1);
  Serial.println("Automação residêncial");
  Serial.println("Opções com Leds 3° DSN");
  jumpLine(1);
  Serial.println("Utilize o teclado do seu computador");
  Serial.println("Opções:");
  Serial.println("Quarto Vermelho - Q->Acender / W->Apagar");
  Serial.println("Sala Amarela - A->Acender / S->Apagar");
  Serial.println("Cozinha Verde - Z-> Acender / X->Apagar");
  jumpLine(1);
  Serial.println("Conferir Luzes - G-> Verifica Status da casa");
  jumpLine(2);
}

//JumpLine
void jumpLine(int line){
  for(int p=0; p<line; p++){
  	Serial.println("");
  }
}

//checkStatus
void checkRead(){

  jumpLine(1);
  Serial.print("Status das luzes da casa:");
  	if(digitalRead(led[x]==HIGH){
    	Serial.println("Luz ligada!");
    }else{
    	Serial.println("Luz desligada!");
    }
  
  for(int x=0; x<3; x++){
  	Serial.println(verifyColor(x));
    
  }
  jumpLine(2);
}
       
//readKey
void checkRead(char fctread){
  swith(letterUpper(fctread)){
  	case 'Q':
  		modeLed(2, 'A');
  	break;
  	case 'A':
  		modeLed(1, 'A');
  	break;
  	case 'Z':
  		modeLed(0, 'A');
  	break;
  	case 'W':
  		modeLed(2, 'D');
  	break;
  	case 'S':
  		modeLed(1, 'D');
  	break;
  	case 'X':
  		modeLed(0, 'D');
  	break;
  	case 'G':
  		checkStatus();
  	break;
  	default:
  		jumpLine(2);
  		Serial.println("Opção inválida, olhe as opções do menu!");
  		jumpLine(2);
  		doMenu();
  	break;
  }
}
       
//modeLed
void modeLed(int fctLed, char situation){
  String msg;
  //Função para Ligar ou Desligar o LED
  if(situation=='A'){
  	digitalWrite(led[fctLed], HIGH);
  }else if(situation=='D'){
  	digitalWrite(led[fctLed], LOW);
  }
  Serial.println(showMsg(fctLed, situation));
}

String showMsg(int fctMsg, char sitMLed){
  String colorLed;
  String sitLed;
  
  colorLed= verifyStatus(sitMLed);
  
  return "A luz do "+colorLed+" foi "+sitLed+"! :)";
}

String verifyColor(int led){
	String descLed;
  switch(led){
  	case 2:
    	descLed="Quarto -> Led Vermelho";
    break;
    case 1:
    	descLed="Sala -> Led Amarelo";
    break;
  	case 0:
    	descLed="Cozinha -> Led Verde";
    break;
  }
  return descLed;
}
       
String verifyStatus(char estatus){
  String descSts;
  if(estatus=='A'){
  	descSts="Ligada";
  }else{
  	descSts="Desligada";
  }
  return descSts;
}

char letterUpper(char caractere){
  char letter;
  if(isLowerCase(caractere)){
    switch(caractere){
    	case 'q':
      		letter='Q';
      	break;
      	case 'a':
      		letter='A';
      	break;
      	case 'z':
      		letter='Z';
      	break;
      	case 'w':
      		letter='W';
      	break;
      	case 's':
      		letter='S';
      	break;
      	case 'x':
      		letter='X';
      	break;
      	case 'g':
      		letter='G';
      	break;
    }
  }else{
  	letter=caractere;
  }
  return letter;
}