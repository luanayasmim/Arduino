// Piano

//Notas Musicais
int DO=262;//Nota Dó
int RE=294;//Nota Ré
int MI=330;//Nota Mi
int FA=349;//Nota Fá
int SOL=392;//Nota Sol
int LA=440;//Nota Lá
int SI=494;//Nota Si
int DO_2=523;//Nota Dó2

//Pino do Buzzer
int pino_buzzer=13;

//Botões
int c_botao=8;//Botão de dó
int d_botao=7;//Botão de ré
int e_botao=6;//Botão de mi
int f_botao=5;//Botão de fá
int g_botao=4;//Botão de sol
int a_botao=3;//Botão de lá
int b_botao=2;//Botão de si
int c2_botao=1;//Botão de dó2

//Variável do estado do botão
int botaoC_status;
int botaoD_status;
int botaoE_status;
int botaoF_status;
int botaoG_status;
int botaoA_status;
int botaoB_status;
int botaoC2_status;

//Configurando as portas de entrada e saída de dados:
void setup(){
  pinMode(c_botao, INPUT);
  pinMode(d_botao, INPUT);
  pinMode(e_botao, INPUT);
  pinMode(f_botao, INPUT);
  pinMode(g_botao, INPUT);
  pinMode(a_botao, INPUT);
  pinMode(b_botao, INPUT);
  pinMode(c2_botao, INPUT);
  
  pinMode(pino_buzzer, OUTPUT);
}


//Atribuindo as notas aos botões:
void loop(){
	//Leitura do estado do botão p/ dó:
  	botaoC_status=digitalRead(c_botao);
  	
  	if(botaoC_status==HIGH){
    	tone(pino_buzzer, DO);
    	delay(500);
    }else{
      noTone(pino_buzzer);
     }
  //Leitura do estado do botão p/ ré:
  	botaoD_status=digitalRead(d_botao);
  	
  	if(botaoD_status==HIGH){
    	tone(pino_buzzer, RE);
    	delay(500);
    }else{
      	noTone(pino_buzzer);
    }
  //Leitura do estado do botão p/ mi:
  	botaoE_status=digitalRead(e_botao);
  	
  	if(botaoE_status==HIGH){
    	tone(pino_buzzer, MI);
    	delay(500);
    }else{
      	noTone(pino_buzzer);
    }
  //Leitura do estado do botão p/ fá:
  	botaoF_status=digitalRead(f_botao);
  	
  	if(botaoF_status==HIGH){
    	tone(pino_buzzer, FA);
    	delay(500);
    }else{
      	noTone(pino_buzzer);
    }
  //Leitura do estado do botão p/ sol:
  	botaoG_status=digitalRead(g_botao);
  	
  	if(botaoG_status==HIGH){
    	tone(pino_buzzer, SOL);
    	delay(500);
    }else{
      	noTone(pino_buzzer);
    }
  //Leitura do estado do botão p/ lá:
  	botaoA_status=digitalRead(a_botao);
  	
  	if(botaoA_status==HIGH){
    	tone(pino_buzzer, LA);
    	delay(500);
    }else{
      	noTone(pino_buzzer);
    }
  //Leitura do estado do botão p/ si:
  	botaoB_status=digitalRead(b_botao);
  	
  	if(botaoB_status==HIGH){
    	tone(pino_buzzer, SI);
    	delay(500);
    }else{
      	noTone(pino_buzzer);
    }
  //Leitura do estado do botão p/ dó2:
  	botaoC2_status=digitalRead(c2_botao);
  	
  	if(botaoC2_status==HIGH){
    	tone(pino_buzzer, DO_2);
    	delay(500);
    }else{
      	noTone(pino_buzzer);
    }
}
