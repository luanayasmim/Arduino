//Declaração das variáveis
int ledVerm=13;
int ledAmar=12;
int ledVerd=11;
int tempo=300;
//Configuração dos pinos
void setup(){
  pinMode(ledVerm, OUTPUT);
  pinMode(ledAmar, OUTPUT);
  pinMode(ledVerd, OUTPUT);
}
//Sequência de acionamento dos LEDs
void loop(){
  digitalWrite(ledVerm,HIGH);
  digitalWrite(ledAmar,HIGH);
  digitalWrite(ledVerd,HIGH);
  delay(tempo);//Aguardo o valor em milisegundos da variável tempo
//Sequência de desligamento das LEDs
  digitalWrite(ledVerm,LOW);
  digitalWrite(ledAmar,LOW);
  digitalWrite(ledVerd,LOW);
  delay(tempo);//Pausa
//Acender led vermelha
  digitalWrite(ledVerm,HIGH);
   delay(tempo);//Pausa
//Acender led amarela
  digitalWrite(ledAmar,HIGH);
   delay(tempo);//Pausa
//Acender led Verde
  digitalWrite(ledVerd,HIGH);
  delay(tempo);//Pausa
//Sequência de desligamento
  digitalWrite(ledVerm,LOW);
  digitalWrite(ledAmar,LOW);
  digitalWrite(ledVerd,LOW);
  delay(tempo);//Pausa
}