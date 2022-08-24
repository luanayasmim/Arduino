#include <Servo.h>

/*-------------------
Controle de LEDs através do teclado aprimorado
levando em consideração a ideia de automoção residencial
*/
			 //LED Verde    //LED Amarelo   //LED Verde
int led[] = {8,             9,              10};
char leitura; //Variável para armazenar o que foi digitado

int cm = 0; //Centímetros 

bool servoSituacao = false;
bool servoSituacaoDistancia = false;

//Criando um objeto da classe servo
Servo servoMotorObj; //Cria um novo objeto Servo

//Pino digital associado ao controle do servomotor
int const servoMotorPIN = 7;

//Variável usada para armazenar o valor lido no potenciômetro
int valPotenciometro;

void setup()
{
 Serial.begin(9600); //Inicializa a comunicação serial
 
 servoMotorObj.attach(servoMotorPIN); //Setando o servo motor
  
  //Estrutura de repetição FOR
  //   Start Stop Increment
  for(int i = 0; i < 3; i++)
  {
  	pinMode(led[i], OUTPUT); //Setando no Arduino os pinos de saída
  							 //de acordo com o vetor
  }
  //Chamada de função para montagem de um menu na saída Serial
  montaMenu();
}

void loop()
{
  
  //execução da função readDistance
  cm = 0.01723 * readDistance(6, 6);
  
  distanciaAlteraPortao();
  
  while(Serial.available() > 0) //Verifica se há conexão com a serial
  {
    leitura = Serial.read(); //Lê o dado vindo da serial no computador 
    						 //e armazena na variável leitura
    trataLeitura(leitura);
  }
}

//Função de exibição do menu na Saída Serial
void montaMenu()
{
  Serial.println("---------------------------------------------");
  Serial.println("--A U T O M O Ç Ã O   R E S I D E N C I A L--");
  Serial.println("---------  Opções com Leds 3° DSN   ---------");
  Serial.println("---------------------------------------------");
  Serial.println("** Utilize o seu teclado de seu computador **");
  Serial.println("--- Q U A R T O (L E D   V E R M E L H O) ---");
  Serial.println("-  Q -> Acende a Luz  /  W -> Apaga a Luz   -");
  Serial.println("---------------------------------------------");
  Serial.println("------ S A L A (L E D   A M A R E L O) ------");
  Serial.println("-  A -> Acende a Luz  /  S -> Apaga a Luz   -");
  Serial.println("---------------------------------------------");
  Serial.println("----- C O Z I N H A (L E D   V E R D E) -----");
  Serial.println("-  Z -> Acende a Luz  /  X -> Apaga a Luz   -");
  Serial.println("---------------------------------------------");
  Serial.println("---- P O R T Ã O (S E R V O   M O T O R) ----");
  Serial.println("-  L -> Abrir potão  /  M -> Fechar portão  -");
  Serial.println("---------------------------------------------");
  Serial.println("------- S T A T U S   D O S   L E D s -------");
  Serial.println("-               G - Verifica                -");
  Serial.println("---------------------------------------------");
  //Pular linhas em branco
  pulaLinha(2);
}

//Função para pular duas linhas em branco
void pulaLinha(int qtdeLinhas)
{
 for(int p = 0; p < qtdeLinhas; p++)
 {
  Serial.println(""); 
 }
}

//Função para verificar o Status dos LEDs
void situacaoLeds()
{
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("---------------------------------------------");
 Serial.println("--A U T O M A Ç Ã O   R E S I D E N C I A L--"); 
 Serial.println("------  S T A T U S   D A S   L U Z E S------"); 
 Serial.println("---------------------------------------------");
  
 //Estrutura FOR para verificar as três luzes
  for(int x = 0; x < 3; x++)
  {
    Serial.print  ("-- ");
    Serial.print  (verificaCor(x));
    if(digitalRead(led[x]) == HIGH)
    {
      Serial.println(": LUZ LIGADA"); 
    }
    else
    {
      Serial.println(": LUZ DESLIGADA");
    }
    Serial.println("---------------------------------------------");
  }
  Serial.print  ("-- ");
  Serial.println("Portão -> " + verificaServo(servoSituacao));
  Serial.println("---------------------------------------------");

  //Pular 2 linhas em branco
  pulaLinha(2);
}

//Função que trata a leitura do teclado
void trataLeitura(char fctleitura)
{
  switch(letraUpper(fctleitura))
  {
    case 'Q':
    	//Acende o LED Vermelho
    	alteraLed(2,'A'); //Parâmetro A - Acender
    	break;
    case 'A':
    	//Acende o LED Amarelo
    	alteraLed(1,'A'); //Parâmetro A - Acender
    	break;
    case 'Z':
    	//Acende o LED Verde
    	alteraLed(0,'A'); //Parâmetro A - Acender
    	break;
    case 'W':
    	//Apaga o LED Vermelho
    	alteraLed(2,'D'); //Parâmetro D - Desligar
    	break;
    case 'S':
    	//Apaga o LED Amarelo
    	alteraLed(1,'D'); //Parâmetro D - Desligar
    	break;
    case 'X':
    	//Apaga o LED Verde
    	alteraLed(0,'D'); //Parâmetro D - Desligar
    	break;
    case 'G':
    	situacaoLeds();
    	break;
    case 'L':
    	//Apaga o LED Verde
    	alteraServo('A'); //Parâmetro A - Aberto
    	break;
    case 'M':
    	//Apaga o LED Verde
    	alteraServo('F'); //Parâmetro F - Fechado
    	break;
    default:
    	Serial.println("---------------------------------------------");
    	Serial.println("-- Opção inválida, olhe as opções do menu! --");
    	Serial.println("---------------------------------------------");
    	//Pula linhas em branco
    	pulaLinha(2);
    	montaMenu();
		break;
  } 
}

void alteraServo(char situacao)
{
 
  if(situacao == 'A')
 {
   valPotenciometro = map (1023, 0, 1023, 0, 180);
   servoMotorObj.write(valPotenciometro);
   Serial.println("Portão Aberto!");
   servoSituacao = true;
 }
  else if(situacao == 'F')
 {
   valPotenciometro = map (0, 0, 1023, 0, 180);
   servoMotorObj.write(valPotenciometro);
   delay(15);
   Serial.println("Portão Fechado!");
   servoSituacao = false;
 }  
}


void alteraLed(int fctLed, char situacao)
{
 String msg;
 //Função para Ligar ou Desligar o LED
 if(situacao == 'A')
 {
   digitalWrite(led[fctLed], HIGH);
 }
  else if(situacao == 'D')
 {
    digitalWrite(led[fctLed], LOW);
 }
  Serial.println(mostraMsg(fctLed, situacao));
}

String mostraMsg(int fctMLed, char sitMLed)
{
  //Vamos parametrizar a mensagem ao usuário
  String corLed;
  String sitLed;
  
  //Função para verificação da cor do LED
  corLed = verificaCor(fctMLed);
  
  //Verificamos a situação
  sitLed = verificaStatus(sitMLed);
  
  //Como é uma função que retorna valor, daremos um return
  return "A Luz do " + corLed + " foi " + sitLed+ "! :)";
}
                 
String verificaCor(int led)
{
  String descLed;
  //Verificamos a cor do LED da Operação
  switch(led)
  {
   case 2:
   		descLed = "Quarto -> LED Vermelho";
    	break;
   case 1:
    	descLed = "Sala -> LED Amarelo";
    	break;
   case 0:
    	descLed = "Cozinha -> LED Verde";
    	break; 
  }
  //Como é uma função que retorna valor, daremos um return
  return descLed;
}
                 
String verificaStatus(char estatus)
{
  String descSts;
  if(estatus == 'A')
  {
  	descSts = "Ligada";
  }                
  else
  {
  	descSts = "Desligada";
  }
  //Como é uma função que retorna valor, daremos um return
  return descSts;
}

String verificaServo(bool servoSituacao)
{
  String servoMsg;
  
  if(servoSituacao == true)
  {
    servoMsg = "ABERTO";
  }
  else
  {
    servoMsg = "FECHADO";
  }
  
  return servoMsg;  
}

char letraUpper(char caractere)
{
  char letra;
  //Verifica se o caractere passado é minúsculo
  if(isLowerCase(caractere))
  {
  	switch(caractere)
  	{
  	 case 'q':
    	letra = 'Q';
    	break;
     case 'a':
    	letra = 'A';
    	break;
     case 'z':
    	letra = 'Z';
    	break;
     case 'w':
    	letra = 'W';
    	break;
     case 's':
    	letra = 'S';
    	break;
     case 'x':
    	letra = 'X';
    	break;
     case 'g':
    	letra = 'G';
    	break;
     case 'l':
    	letra = 'L';
    	break;
     case 'm':
    	letra = 'M';
    	break;
  	}
  }
  else
  {
    letra = caractere;
  }
  return letra;
}

void distanciaAlteraPortao()
{
   if(cm < 100)
   {    
    	if(!servoSituacaoDistancia)
        {
          	valPotenciometro = map (1023, 0, 1023, 0, 180);
   			servoMotorObj.write(valPotenciometro);
   			servoSituacao = true;
          	servoSituacaoDistancia = true;
        }
   }
   else
   { 
    	if(servoSituacaoDistancia)
        {
           	valPotenciometro = map (0, 0, 1023, 0, 180);
   			servoMotorObj.write(valPotenciometro);
   			servoSituacao = false;
          	servoSituacaoDistancia = false;
        }
   } 
}

//Função de leitura da distância
long readDistance(int triggerPin, int echoPin)
{
 	pinMode(triggerPin,OUTPUT); //Limpa a Leitura 
  	digitalWrite(triggerPin, LOW);
  	delay(200);
  
  //Setar o trigger pin para HIGH por 100 millisecond(s)
  	digitalWrite(triggerPin, HIGH);
  	delay(100);
  	digitalWrite(triggerPin,LOW);
  	pinMode(echoPin, INPUT);
  
  //Ler o Echo pin, e retorando o tempo do som
  	return pulseIn(echoPin, HIGH);
}

