#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/*
void execult(char buffer1 [], char buffer2[], int registradores[], char CPSR[]){
    ConvertChar(buffer1); 
    Decodifica(buffer1, registradores, CPSR); // 4 primeiros bytes
        //
    ConvertChar(buffer2); 
    Decodifica(buffer2, registradores, CPSR); // 4 primeiros bytes
}
*/

void ConvertChar(char vet[]){
    
    for (int i = 0; i < 4; i++){ 
        //caso seja de 0 a 9
        if((vet[i] >= '0') && (vet[i] <= '9')){
            vet[i] = vet[i] - '0'; //operacao para trasforma de char p/ int

        }
        //caso seja de a - f
        if((vet[i] >= 'a') && (vet[i] <= 'f')){
            vet[i] = vet[i] - 'W'; //operacao para trasforma de char p/ int
 
        }
        else if (vet[i] > 'f'){ //corrigir tal caso
            printf("O digito invalido, digite um digito em hexadecimal\n");
        }
    }
}



//parametros: vetor de char, arquivo de destino
void Decodifica(char vet[], int registradores[], char CPSR[]){

    //primeiro digito = 4bits primeiros da instruçao thumb
    switch (vet[0]){
    case 0:
        if((vet[1] >> 3) == 0){
            //caso LSL
            LSL(vet, registradores, CPSR);
        }
        if((vet[1] >> 3) == 1){
            //caso LSR
            LSR(vet, registradores, CPSR);
        } 
    case 1:
         //instruçao ASR
        if((vet[1] >> 3) == 0){
            ASR(vet, registradores, CPSR);
        }
        //instruçoes ADD / SUB com LM
        if ((vet[1] >> 1) == 4 ){
            //instruçao ADD com LM
            ADD_com_LM(vet, registradores, CPSR);

        }
       
        break;
    if ((vet[1] >> 1) == 5 ){
            //instruçao SUB com LM
            SUB_com_LM(vet, registradores, CPSR);

        }
        //instrução ADD/SUB imediado de 3bits
        if ((vet[1] >> 1) == 6 ){
            ADD_com_imediato3(vet, registradores, CPSR);

        }
        if ((vet[1] >> 1) == 7 ){
            //instruçao SUB com imediado
           SUB_com_imediato3(vet, registradores, CPSR);

        }

        break;
    case 2:
        //Instruçoes MOV/ CMP com imediado de 8bits 
        if ((vet[1] >> 3) == 0){
           void MOV_com_imediato8(vet, registradores, CPSR);

        }
        if ((vet[1] >> 3) == 1){
           void CMP_com_imediato8(vet, registradores, CPSR);
        }
       
        break;
    
     case 3:
     //instrução ADD/ SUB com imediado de 8 bits
      if ((vet[1] >> 3) == 0){
            void ADD_com_imediato8(vet, registradores, CPSR);

        }
        if ((vet[1] >> 3) == 1){
            void SUB_com_imediato8(vet, registradores, CPSR);
        }
        
        break;

    
    case 4:
       /**instruçoes AND | EOR | LSL | LSR |ASR | ADC | SBC | ROR| TST | NEG | CMP | CMN | ORR | MUL | BIC | MVN
        CPY Ld, Lm |ADD | MOV Ld, Hm| ADD | MOV Hd, Lm| ADD | MOV Hd, Hm|CMP|CMP|CMP|BX | BLX |LDR Ld, [pc, #immed*4]*/

        if (vet[1]  == 0){
            //instruçoes AND | EOR | LSL | LSR 
            if((vet[2] & 12) == 0){
                //instruçao AND
               void AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet,registradores,CPSR);
            } 
            if((vet[2] & 12) == 4){
                //instrução EOR
              void AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet,registradores,CPSR);
            }
            if((vet[2] & 12) == 8){
                //instrução LSL
              void AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet,registradores,CPSR);
            }
            if((vet[2] & 12) == 12){
                //instrução LSR
               void AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet,registradores,CPSR);
            }
        }
        if (vet[1] == 1){
            //instruçoes ASR | ADC | SBC | ROR
            if((vet[2] & 12) == 0){
                 //instrução ASR
              void AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet,registradores,CPSR);

            }
            if((vet[2] & 12) == 4){
                 //instrução ADC
              void AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet,registradores,CPSR);
            }
            if((vet[2] & 12) == 8){
                 //instrução SBC
               void AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet,registradores,CPSR);
            
            if((vet[2] & 12) == 12){
                 //instrução ROR
               void AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet,registradores,CPSR);
            }

        }
        if (vet[1] == 2){
            //instruçoes TST | NEG | CMP | CMN |
            if((vet[2] & 12) == 0){
                 //instrução TST
               void AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet,registradores,CPSR);

            }
            if((vet[2] & 12) == 4){
                 //instrução NEG
                void AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet,registradores,CPSR);
            }
            if((vet[2] & 12) == 8){
                 //instrução CMP
                void AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet,registradores,CPSR);
            }
            if((vet[2] & 12) == 12){
                 //instrução CMN
               void AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet,registradores,CPSR);
            }

        }
        if (vet[1] == 3){
            //instruçoes ORR | MUL | BIC | MVN
            if((vet[2] & 12) == 0){
                 //instrução ORR
               void AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet,registradores,CPSR);

            }
            if((vet[2] & 12) == 4){
                 //instrução NEG
               void AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet,registradores,CPSR);
            }
            if((vet[2] & 12) == 8){
                 //instrução CMP
               void AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet,registradores,CPSR);
            }
            if((vet[2] & 12) == 12){
                 //instrução CMN
               void AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet,registradores,CPSR);
            }
        }
        if (vet[1] == 6){
            //INSTRUÇOES CPY Ld, Lm
            if((vet[2] & 12) == 0){
                 //instrução CPY 
                void AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet,registradores,CPSR);

            }

            //continua com as instruções do Hugo
      case 5:
        if(vet[1] == 0){
            //instruçao STR 
            void STR_STRH_STRB_LDRSBpre_LDR_LDRH_LDRB_LDRSHpre(vet, registradores, CPSR);

        }
        if(vet[1] == 1){
            //instruçao | STRH 
            void STR_STRH_STRB_LDRSBpre_LDR_LDRH_LDRB_LDRSHpre(vet, registradores, CPSR);

        }
        if(vet[1] == 2){
            //instruçao | STRB
            void STR_STRH_STRB_LDRSBpre_LDR_LDRH_LDRB_LDRSHpre(vet, registradores, CPSR);

        }
        if(vet[1] == 3){
            //instruçao | LDRSB pre
           void STR_STRH_STRB_LDRSBpre_LDR_LDRH_LDRB_LDRSHpre(vet, registradores, CPSR);

        }
        if(vet[1] == 8){
            //instruçao LDR 
           void STR_STRH_STRB_LDRSBpre_LDR_LDRH_LDRB_LDRSHpre(vet, registradores, CPSR);

        }
        if(vet[1] == 9){
            //instruçao | LDRH 
           void STR_STRH_STRB_LDRSBpre_LDR_LDRH_LDRB_LDRSHpre(vet, registradores, CPSR);
        }
        if(vet[1] == 10){
            //instruçao | LDRB 
           void STR_STRH_STRB_LDRSBpre_LDR_LDRH_LDRB_LDRSHpre(vet, registradores, CPSR);

        }
        if(vet[1] == 11){
            //instruçao  LDRSH pre
           void STR_STRH_STRB_LDRSBpre_LDR_LDRH_LDRB_LDRSHpre(vet, registradores, CPSR);
        }

        break;

    case 6:
        if((vet[1] & 8) == 0){
            //instruçao STR  Ld, [Ln, #immed*4]
            void STR_LDR_com_Ln_immed_x4(vet, registradores, CPSR);
        }
        if((vet[1] & 8) == 8){
            //instruçao LDR Ld, [Ln, #immed*4]
            void STR_LDR_com_Ln_immed_x4(vet, registradores, CPSR);
        }

        break;

     case 7:
        if((vet[1] & 8) == 0){
           //instruçao  STRB Ld, [Ln, #immed]
           void STRB_LDRB_com_ln_imediato(vet, registradores, CPSR);
        }
        if((vet[1] & 8) == 8){
           //instruçao   LDRB Ld, [Ln, #immed]
           void STRB_LDRB_com_ln_imediato(vet, registradores, CPSR);        }
        break;

    case 8:
       if((vet[1] & 8) == 0){
           //instruçao  STRH Ld, [Ln, #immed*2]
           void STRH_LDRH_com_Ln_immed_x2(vet, registradores, CPSR);
        }
        if((vet[1] & 8) == 8){
           //instruçao LDRH Ld, [Ln, #immed*2]
           void STRH_LDRH_com_Ln_immed_x2(vet, registradores, CPSR);
        }
        break;

    case 9:
        if ((vet[1] >> 3) == 0){
            // instruçao STR Ld, [sp, #immed*4]
           void STR_LDR_ADD_com_ld_sp_pc_com_immediato8_x4(vet, registradores, CPSR);
        }
        if ((vet[1] >> 3) == 1){
            //instruçao LDR Ld, [sp, #immed*4]
           void STR_LDR_ADD_com_ld_sp_pc_com_immediato8_x4(vet, registradores, CPSR);

        }
        break;

    case 10: 
        if ((vet[1] >> 3) == 0){
            // instruçao ADD Ld, pc, #immed*4 |
           void ADD_Ld_pc_immed_x4(vet, registradores, CPSR);
        }
        if ((vet[1] >> 3) == 1){
            //instruçao ADD Ld, sp, #immed*4
            void ADD_Ld_sp_immed_x4(vet, registradores, CPSR);

        }
        break;
        

    case 11:
        if((vet[1] == 0) && ((vet[2] & 8) == 0)){
            // instruçao ADD sp, #immed*4
           void ADD_SUB_com_sp_imediato7(vet, registradores, CPSR);
        }

        if((vet[1] == 0) && ((vet[2] & 8) == 8)){
            // instruçao SUB sp, #immed*4
           void ADD_SUB_com_sp_imediato7(vet, registradores, CPSR);

    break;
    }
}

