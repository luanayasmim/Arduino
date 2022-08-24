//Declarando as váriaveis
int red = 13;
int blue= 12;
int green=11;
int buzzer=9;
int potenciometro=A0;
int ldr=A1;

//Declarando sinal do potenciometro
float sinalP;

//Declarando a leitura do fotorresistor
int leitura;

//Declarando as notas para o buzzer
int DO=262;//Nota Dó
int RE=294;//Nota Ré
int MI=330;//Nota Mi
int FA=349;//Nota Fá
int SOL=392;//Nota Sol
int LA=440;//Nota Lá
int SI=494;//Nota Si
int DO_2=523;//Nota Dó2

void setup()
{
  Serial.begin(9600);
  //Configurando as portas
  pinMode(ldr, INPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(potenciometro, INPUT);
}

//Funções responsáveis por executar o brilho selecionado
void redFuncao(){
  digitalWrite(red, HIGH);
  digitalWrite(blue, LOW);
  digitalWrite(green, LOW);
}
void blueFuncao(){
  digitalWrite(red, LOW);
  digitalWrite(blue, HIGH);
  digitalWrite(green, LOW);
}
void greenFuncao(){
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(green, HIGH);
}
void purpleFuncao(){
  digitalWrite(red, 255);
  digitalWrite(blue, 207);
  digitalWrite(green, 0);
}

void loop()
{
  //Atribuindo o sensor de luminosidade
  //Se o ambiente estiver claro o sistema não vai iniciar
  leitura=analogRead(ldr); 
  sinalP = analogRead(A0);
  Serial.println(sinalP);
  Serial.println(leitura);
  
  if(leitura >500){
     
      //Atribuindo as cores para o led
      
    if(sinalP>=0 && sinalP<=250){
        purpleFuncao();
        tone(buzzer, DO);
        delay(200);
        tone(buzzer, RE);
        delay(200);
        noTone(buzzer);
      } else if(sinalP>250 && sinalP<=500){
        blueFuncao();
        tone(buzzer, MI);
        delay(200);
        tone(buzzer, FA);
        delay(200);
        noTone(buzzer);
      } else if(sinalP>500 && sinalP<=750){
        redFuncao();
        tone(buzzer, SOL);
        delay(200);
        tone(buzzer, LA);
        delay(200);
        noTone(buzzer);
      } else if(sinalP>750 && sinalP<=1023){
        greenFuncao();
        tone(buzzer, SI);
        delay(200);
        tone(buzzer, DO_2);
        delay(200);
        noTone(buzzer);
      } 
  }
}   
         
        