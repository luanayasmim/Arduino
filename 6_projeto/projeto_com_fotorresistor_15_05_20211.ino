//Declarar variáveis
int ldr = A0;//Vai receber valores entre 0 e 1023
int ledVermelho = 13;
int ledAmarelo = 12;
int ledVerde = 11;
int leitura;

void setup(){
  pinMode(ldr, INPUT);//Declarar sensor LDR
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  Serial.begin(9600);//Inicializ a comunicação serial
}

void loop(){
  leitura=analogRead(ldr);
  Serial.print("Luminosidade lida: ");
  Serial.println(leitura);
  
  if(leitura<=20){
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
    Serial.println("Ambiente escuro");
  }
  
  if(leitura>20&& leitura<=255){
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
    Serial.println("Ambiente pouco iluminado");
  }
  
  if(leitura>=256 && leitura <=500){
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);
    Serial.println("Ambiente com iluminação média");
  }
  
  if(leitura>=501){
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, HIGH);
    Serial.println("Ambiente bem iluminado");
  }
  delay(1000);
}