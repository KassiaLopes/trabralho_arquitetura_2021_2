#include <stdio.h>
#include <stdlib.h>
#include "heade.h"

void ConvertChar(char vet[]){
    int i;
    for (i = 0; i < 8; i++){ // NOTA mental: Erick tu mudou o valor do indice de um codigo para outro
        //caso seja de 0 a 9
        if((vet[i] >= '0') && (vet[i] <= '9')){
            vet[i] = vet[i] - '0'; //operacao para trasforma de char p/ int
            printf("%d", vet[i]);
        }
        //caso seja de a - f
        if((vet[i] >= 'a') && (vet[i] <= 'f')){
            vet[i] = vet[i] - 'W'; //operacao para trasforma de char p/ int
            printf("%d", vet[i]);
        }
        else if (vet[i] > 'f'){ //corrigir tal caso
            printf("O digito invalido, digite um digito em hexadecimal\n");
        }
    

    }

}


//parametros: vetor de char, arquivo de destino
void Decodifica(char vet[], FILE *file2){

    //primeiro digito = 4bits primeiros da instruçao thumb
    switch (vet[0]){
    case 0:
        if((vet[1] >> 3) == 0){
            //caso LSL
            LSL(vet, file2);
            
        }
        if((vet[1] >> 3) == 1){
            //caso LSR
            LSR(vet, file2);
            
        }     
        break;
        
    }
}
