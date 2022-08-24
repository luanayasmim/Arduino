//LCD 
//Incluir a biblioteca para operar o LCD
#include <LiquidCrystal.h>

//Iniciando a biblioteca e informando os pinos que serão utilizados
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
  //Definindo a estrutura do LCD
  	lcd.begin(16, 2);
}

void loop(){
  	//Limpando a tela do LCD
  	lcd.clear();
  
  	//Posicionando o cursor na linha e coluna do LCD
  	lcd.setCursor(2,0);
  
  	//Mostrando o texto
  	lcd.print("Etec de Embu");
  
  	//Posicionando o cursor na linha e coluna do LCD
  	lcd.setCursor(3,1);
  	
  	//Mostrando o texto
  	lcd.print("Aula de TP");
  
  	//Desloca o texto todo para a esquerda
  	for(int posicao=0; posicao<15; posicao++){
    	lcd.scrollDisplayLeft();
      	delay(300);
    }
  
  	//Desloca o texto todo para a direita
  	for(int posicao=0; posicao<30; posicao++){
    	lcd.scrollDisplayRight();
      	delay(300);
    }
}