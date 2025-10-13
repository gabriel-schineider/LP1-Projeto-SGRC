#include <stdio.h>
#include "ler_arq.h"
#include "escrita_arq.h"

int main(void){
    char nomes[3][ESPACO];
    int tipo=moto;
    char guidom[]="Borracha legal";
    
}


void preencheMotorizado(struct Motorizado* ptr,int tipo, int arr[], char nomes[][ESPACO]){ //funcao p preencher motorizados
    ptr->tipo=tipo; //pega vetor de numeros e vetor de strings para preencher, ordem importa! olhar os indices usados, sao arbitrarios
    strncpy(ptr->combustivel,nomes[3],ESPACO);
    switch (ptr->tipo){
        case moto: 
            strncpy(ptr->moto.guidom,nomes[3],ESPACO);
            ptr->moto.offroad=arr[1];
            for (int i=0;i<2;i++){
                ptr->moto.pressao_ideal[i]=arr[1+i];
            }
            break;
        case carro:
            ptr->carro.tracao=arr[1];
            ptr->carro.portas=arr[2];
            ptr->carro.eletrico=arr[3];
            for (int i=0;i<4;i++){
                ptr->carro.pressao_ideal[i]=arr[4+i];
            }
            break;
        case barco:
            ptr->barco.litragem=arr[1];
            strncpy(ptr->barco.tipo_casco, nomes[3], ESPACO); // ambos, a origem e o destino, já são char* (destino é apenas ponteiro para char e origem é ponteiro para array de 25 chars)
            ptr->barco.vel_aq_max=arr[2];
            break;
        case helicoptero:
            ptr->helicoptero.pas=arr[1];
            ptr->helicoptero.passageiros=arr[2];
            ptr->helicoptero.altitude_max=arr[3];
            break;
    }
}