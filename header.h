#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

//funçoes_basicas
//void execult(char buffer1 [], char buffer2[], int registradores[], char CPSR[]){
void ConvertChar(char vet[]);
void Decodifica(char vet[], int registradores[], char CPSR[]);
//instruçoes_01
void LSL(char vet[],int registradores[], char CPSR[]);
void LSR(char vet[],int registradores[], char CPSR[]);
void ASR(char vet[],int registradores[], char CPSR[]);
void ADD_com_LM(char vet[],int registradores[], char CPSR[]);
void SUB_com_LM(char vet[], int registradores[], char CPSR[]);

void ADD_com_imediato3(char vet[], int registradores[], char CPSR[]);
void SUB_com_imdeiato3(char vet[], int registradores[], char CPSR[]);
void MOV_com_imediato8(char vet[], int registradores[], char CPSR[]);
void CMP_com_imediato8(char vet[], int registradores[], char CPSR[]);
void ADD_com_imediato8(char vet[], int registradores[], char CPSR[]);
void SUB_com_imediato8(char vet[], int registradores[], char CPSR[]);
void AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(char vet[], int registradores[], char CPSR[]);
void STR_STRH_STRB_LDRSBpre_LDR_LDRH_LDRB_LDRSHpre(char vet[], int registradores[], char CPSR[]);
void STR_LDR_com_Ln_immed_x4(char vet[], int registradores[], char CPSR[]);
void STRB_LDRB_com_ln_imediato(char vet[], int registradores[], char CPSR[]);
void STRH_LDRH_com_Ln_immed_x2(char vet[], int registradores[], char CPSR[]);
void STR_LDR_ADD_com_ld_sp_pc_com_immediato8_x4(char vet[], int registradores[], char CPSR[]);
void ADD_Ld_pc_immed_x4(char vet[], int registradores[], char CPSR[]);
void ADD_Ld_sp_immed_x4(char vet[], int registradores[], char CPSR[]);
void ADD_SUB_com_sp_imediato7(char vet[], int registradores[], char CPSR[]);
//void SUB_com_LM(char vet[], int registradores[], char CPSR[]);
//Show_things
void Mostra_Registrador(int registradores[]);
void Mostra_CPSR(char CPSR[]);
void Mostra_memory_data(char buffer1[], FILE *file);
//updates_things
void Atualiza_CPSR(int registradores[],char CPSR[], int Ld);
void Copia_conteudo(char origem[], char buffer1[], char buffer2[]);


#endif // HEADER_H_INCLUDED

