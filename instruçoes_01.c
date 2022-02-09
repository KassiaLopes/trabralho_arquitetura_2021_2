#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void LSL(char vet[], int registradores[], char CPSR[]){
    
    int imediato = 0; //imediado de 5bits
    imediato = (vet[1] & 7) << 2; //and com 7 para saber os 3primeiro bits do segundo digito da direita pra esquerda, deslocado 2 vez para <-
    imediato = imediato  | ((vet[2] & 12) >>2); //2 ultimos bits do terceiro digito
        
    int Lm = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    Lm = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    Lm = (Lm | (vet[3] & 8)) >> 3;
    int Ld = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    
  /* printf("\nLSL");
    printf("%d lm \n", Lm);
    printf("%d ld  \n", Ld);
    printf("%d imedia  \n", imediato);
  */
     // adicionando nos registradores
    registradores[Ld] = (registradores[Lm] << imediato); // atualiza os registradores
    // printf("%d result\n",registradores[Ld] );

    //atualizando CPSR
    Atualiza_CPSR(registradores, CPSR, Ld);

}

void LSR(char vet[], int registradores[], char CPSR[]){
    
    int imediato = 0; //imediado de 5bits
    imediato = (vet[1] & 7) << 2; //and com 7 para saber os 3primeiro bits do segundo digito da direita pra esquerda, deslocado 2 vez para <-
    imediato = imediato  | ((vet[2] & 12) >>2); // 2ultimos bits do terceiro digito
    
    int Lm = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    Lm = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    Lm = (Lm | (vet[3] & 8)) >> 3;
    int Ld = (vet[3] & 7); // 3 primeiros bits do quarto digito ;
    
    // adicionando nos registradores
    registradores[Ld] = (registradores[Lm] >> imediato);
    //atualizando CPSR
    Atualiza_CPSR(registradores, CPSR, Ld);

}

void ASR(char vet[], int registradores[], char CPSR[]){

    int imediato = 0; //imediado de 5bits
    imediato = (vet[1] & 7) << 2; //and com 7 para saber os 3primeiro bits do segundo digito da direita pra esquerda
    //deslocado 2 vez para <-
    imediato = imediato  | ((vet[2] & 12) >>2); // 2ultimos bits do terceiro digito
    
    int Lm = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    Lm = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    Lm = (Lm | (vet[3] & 8)) >> 3;
    int Ld = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    
    // adicionando nos registradores
    registradores[Ld] = Lm >> imediato;

    //atualizando CPSR
    Atualiza_CPSR(registradores, CPSR, Ld);
  
}

void ADD_com_LM(char vet[], int registradores[], char CPSR[]){

    int Lm = 0;
    Lm = (vet[1] & 1) << 2; //pegando o ultimo bit do segundo numero, e deslocando-o para o que sera o 3bit do LM
    // descobrindo os 2 ultimos bits do terceiro bit, movendo o 2bits pra -> e adicionando com o 3bit do LM
    //Assim teremos os 3 bits do LM
    Lm = Lm | ((vet[2] & 12) >> 2);
    int Ln = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    Ln = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    Ln = (Ln| (vet[3] & 8)) >> 3;
    int Ld = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    
    // adicionando nos registradores
    registradores[Ld] = Ln + Lm;

    //atualizando CPSR
    Atualiza_CPSR(registradores, CPSR, Ld);

}

void SUB_com_LM(char vet[], int registradores[], char CPSR[]){
  
  int Lm = 0;
  Lm = (vet[1] & 1) << 2; //pegando o ultimo bit do segundo numero, e deslocando-o para o que sera o 3bit do LM
  // descobrindo os 2 ultimos bits do terceiro bit, movendo o 2bits pra -> e adicionando com o 3bit do LM
  //Assim teremos os 3 bits do LM
  Lm = Lm | ((vet[2] & 12) >> 2);
  int Ln = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
  Ln = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
  Ln = (Ln| (vet[3] & 8)) >> 3;
  int Ld = (vet[3] & 7); //3 primeiros bits do quarto digito ;

  // adicionando nos registradores
  registradores[Ld] = registradores[Ln] - registradores[Lm];

  //atualizando CPSR
  Atualiza_CPSR(registradores, CPSR, Ld);

}

void ADD_com_imediato3(char vet[], int registradores[], char CPSR[]){
    int imediato = 0; //imediado de 3 bit
    imediato = (vet[1] & 1) << 2; //pegando o ultimo bit do segundo numero, e deslocando-o para o que sera o 3bit do imediado
    // descobrindo os 2 ultimos bits do terceiro bit, movendo o 2bits pra -> e adicionando com o 3bit do imediado
    //Assim teremos os 3 bits do imediado
    imediato = imediato | ((vet[2] & 12) >> 2);
    int Ln = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    Ln = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    Ln = (Ln| (vet[3] & 8)) >> 3;
    int Ld = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    // reg destino
     registradores[Ld] = registradores[Ln] + imediato; // soma o valor do reg com o operando
}

void SUB_com_imediato3(char vet[], int registradores[], char CPSR[]){
    int imediato = 0; //imediado de 3 bit
    imediato = (vet[1] & 1) << 2; //pegando o ultimo bit do segundo numero, e deslocando-o para o que sera o 3bit do imediado
    // descobrindo os 2 ultimos bits do terceiro bit, movendo o 2bits pra -> e adicionando com o 3bit do imediado
    //Assim teremos os 3 bits do imediado
    imediato = imediato | ((vet[2] & 12) >> 2);
    int Ln = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    Ln = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    Ln = (Ln| (vet[3] & 8)) >> 3;
    int Ld = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    //reg de destino
     registradores[Ld] = registradores[Ln] - imediato;  //subtração entre o reg e o operando(ime)
}


void MOV_com_imediato8(char vet[], int registradores[], char CPSR[]){

    int LD_LN = 0;
    LD_LN = (vet[1] & 7); //descobrindo os 3 primeiros bits do segundo digito

    int imediato = 0;
    imediato = ((vet[2] & 15) << 4); //bits do 8 primeiros bits
    imediato = imediato |(vet[3] & 15);

     registradores[LD_LN] = imediato; // carrega no reg destino o valor do operando(endereçamento imediato)
}

void CMP_com_imediato8(char vet[], int registradores[], char CPSR[]){
    int LD_LN = 0;
    LD_LN = (vet[1] & 7); //descobrindo os 3 primeiros bits do segundo digito

    int imediato = 0;
    imediato = ((vet[2] & 15) << 4); //bits do 8 primeiros bits
    imediato = imediato |(vet[3] & 15);

     registradores[LD_LN] = registradores[LD_LN]-imediato ; // comparação imediato com reg

    Atualiza_CPSR(registradores, CPSR, LD_LN);
     /*
     0=habilitada 1 desabilitada
        if(ld==0){ // são iguais
            Z=1  
        }
        else if(ld +) imed<{
            N=1
        }else imed> 
            N=0
     */
}
void ADD_com_imediato8(char vet[], int registradores[], char CPSR[]){
    int Ld = 0;
    Ld = (vet[1] & 7); //descobrindo os 3 primeiros bits do segundo digito

    int imediato = 0;
    imediato = ((vet[2] & 15) << 4); //bits do 8 primeiros bits
    imediato = imediato |(vet[3] & 15);

    registradores[Ld] = registradores[Ld] + imediato;
}

void SUB_com_imediato8(char vet[], int registradores[], char CPSR[]){
    int Ld = 0;
    Ld = (vet[1] & 7); //descobrindo os 3 primeiros bits do segundo digito

    int imediato = 0;
    imediato = ((vet[2] & 15) << 4); //bits do 8 primeiros bits
    imediato = imediato |(vet[3] & 15);

     registradores[Ld] = registradores[Ld] - imediato;
}

void AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(char vet[], int registradores[], char CPSR[]){
    
    int LM_LS = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    LM_LS = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    LM_LS = (LM_LS | (vet[3] & 8)) >> 3;
    int registrador_destino = (vet[3] & 7); //3 primeiros bits do quarto digito ;

     registradores[Ld] = registradores[Ln] - registradores [Lm]
}

void STR_STRH_STRB_LDRSBpre_LDR_LDRH_LDRB_LDRSHpre(char vet[], int registradores[], char CPSR[]){
    
    int Ld = (vet[3] & 7); //3 primeiros bits do quarto digito ;

    int LN = 0;
    LN =((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito  
    LN = (LN | (vet[3] & 8)) >> 3;

    int Lm = 0;
    Lm = ((vet[2] & 7) << 1);
    Lm = Lm | ((vet[2] & 8) >> 3); 

     registradores[Ld] = registradores[Ln] - registradores [Lm]
}

//falta CPY

void STR_LDR_com_Ln_immed_x4(char vet[], int registradores[], char CPSR[]){
    int Ld = (vet[3] & 7); //3 primeiros bits do quarto digito ;

    int Ln = 0;
    Ln =((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito  
    Ln = (Ln | (vet[3] & 8)) >> 3;

    int imediato = 0;
    imediato = ((vet[1] & 7) << 2);
    imediato = imediato | ((vet[2] & 12) >> 2);
    imediato = imediato * 4;
    
    registradores[Ln]= registradores[Ln] + imediato; // endereço do operando
    registradores[Ld] = registradores[Ln]; // recebe conteudo de Ln
}

void STRB_LDRB_com_ln_imediato(char vet[], int registradores[], char CPSR[]){
    int Ld = (vet[3] & 7); //3 primeiros bits do quarto digito ;

    int Ln = 0;
    Ln =((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito  
    Ln = (Ln | (vet[3] & 8)) >> 3;

    int imediato = 0;
    imediato = ((vet[1] & 7) << 2);
    imediato = imediato | ((vet[2] & 12) >> 2);

     registradores[Ld] = registradores[Ln] - registradores [Ld];
}

void STRH_LDRH_com_Ln_immed_x2(char vet[], int registradores[], char CPSR[]){
    
    int Ld = (vet[3] & 7); //3 primeiros bits do quarto digito ;

    int Ln = 0;
    Ln =((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito  
    Ln = (Ln | (vet[3] & 8)) >> 3;

    int imediato = 0;
    imediato = ((vet[1] & 7) << 2);
    imediato = imediato | ((vet[2] & 12) >> 2);
    imediato = imediato * 2;

     registradores[Ld] = registradores[Ln] - registradores [Lm]
}

void STR_LDR_ADD_com_ld_sp_pc_com_immediato8_x4(char vet[], int registradores[], char CPSR[]){
    //concerta ADD prints 
    int Ld = 0;
    Ld = (vet[1] & 7); //descobrindo os 3 primeiros bits do segundo digito

    int imediato = 0;
    imediato = ((vet[2] & 15) << 4); //bits do 8 primeiros bits
    imediato = imediato |(vet[3] & 15);

    imediato = imediato * 4;

     registradores[Ld] = registradores[Ln] - registradores [Lm]
}

void ADD_Ld_pc_immed_x4(char vet[], int registradores[], char CPSR[]){
    int Ld = 0;
    Ld = (vet[1] & 7); //descobrindo os 3 primeiros bits do segundo digito

    int imediato = 0;
    imediato = ((vet[2] & 15) << 4); //bits do 8 primeiros bits
    imediato = imediato |(vet[3] & 15);

    imediato = imediato * 4;

     registradores[Ld] = pc + imediato;
}

void ADD_Ld_sp_immed_x4(char vet[], int registradores[], char CPSR[]){
    int Ld = 0;
    Ld = (vet[1] & 7); //descobrindo os 3 primeiros bits do segundo digito

    int imediato = 0;
    imediato = ((vet[2] & 15) << 4); //bits do 8 primeiros bits
    imediato = imediato |(vet[3] & 15);

    imediato = imediato * 4

     registradores[Ld] = sp + imediato;
}

void ADD_SUB_com_sp_imediato7(char vet[], int registradores[], char CPSR[]){

    int imediato = 0;
    imediato = ((vet[2] & 7) << 4);

    imediato = imediato | (vet[3]); //pegando os ultimos 7bits

    imediato = imediato * 4; 

     registradores[sp] = registradores[sp] + imediato;
}
 
