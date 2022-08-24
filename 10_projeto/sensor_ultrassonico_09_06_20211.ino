//Declarar variável
int cm = 0;//Centímetros

void setup(){
  //Iniciar comunicação serial
  Serial.begin(9600);
}
void loop(){
  //Execução da função readDistance
  cm = 0.01723*readDistance(7, 7);
  Serial.print(cm);
  Serial.println("cm");
  delay(100);//Espera por 100 milisegundos
  
}
long readDistance(int triggerPin, int echoPin){
  pinMode(triggerPin, OUTPUT);//Limpa a leitura
  digitalWrite(triggerPin, LOW);
  delay(200);
  //Setar o trigger pin para HIGH  por 100 milliseconds
  digitalWrite(triggerPin, HIGH);
  delay(100);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, HIGH);
}