//Aula 01(24-03-2021)

//pinMode[Entradas e Saídas]
//HIGH(Ligado)e LOW(Desligado)
//delay(pausa)

int ledRed=13;
int ledYellow=12;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledYellow,HIGH);
  delay(500);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledYellow, LOW);
  delay(500);
}