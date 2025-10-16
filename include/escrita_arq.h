#include <stdio.h>
#include "entrada_struct.h"
#ifndef ESCRITA_ARQ_H
#define ESCRITA_ARQ_H

void escreveMotorizado( Motorizado coisa,FILE* f){ 
    //escreve um motorizado no arquivo, ja assume offset certo
    fwrite(&coisa.tipo,sizeof(int),1,f);
    fwrite(coisa.combustivel,sizeof(char),ESPACO,f);//atentar ao '\0' na hr de ler isso p C de volta, isso vai escrever lixo
    switch (coisa.tipo){
        case moto_ENUM: 
            fwrite(coisa.moto.guidom,sizeof(char),ESPACO,f);
            fwrite(&coisa.moto.offroad,sizeof(int),1,f);
            fwrite(&coisa.moto.pressao_ideal,sizeof(int),2,f);
            break;
        case carro_ENUM:
            fwrite(&coisa.carro.tracao,sizeof(int),1,f);
            fwrite(&coisa.carro.portas,sizeof(int),1,f);
            fwrite(&coisa.carro.eletrico,sizeof(int),1,f);
            fwrite(coisa.carro.pressao_ideal,sizeof(int),4,f);
            break;
        case barco_ENUM:
            fwrite(&coisa.barco.litragem,sizeof(int),1,f);
            fwrite(&coisa.barco.tipo_casco, sizeof(char), ESPACO, f);
            fwrite(&coisa.barco.vel_aq_max,sizeof(int),1,f);
            break;
        case helicoptero_ENUM:
            fwrite(&coisa.helicoptero.pas,sizeof(int),1,f);
            fwrite(&coisa.helicoptero.passageiros,sizeof(int),1,f);
            fwrite(&coisa.helicoptero.altitude_max,sizeof(int),1,f);
            break;
    }
}
void escreveManual(Manual coisa,FILE* f){
    //escreve um tipo manual no arquivo, assume que ja esta no offset certo
    fwrite(&coisa.tipo,sizeof(int),1,f);
    fwrite(coisa.modelo,sizeof(char),ESPACO,f);
    switch (coisa.tipo){
        case bike_ENUM:
            fwrite(coisa.bike.suspensao,sizeof(char),ESPACO,f);
            fwrite(&coisa.bike.diam_roda,sizeof(int),1,f);
            fwrite(&coisa.bike.marchas,sizeof(int),1,f);
            break;
        case skate_ENUM:
            fwrite(&coisa.skate.comprimento,sizeof(int),1,f);
            fwrite(&coisa.skate.diam_roda,sizeof(int),1,f);
            fwrite(coisa.skate.tipo_roda,sizeof(char),ESPACO,f);
            break;
    }
}
void EscreverEntrada(ENTRADA_FINAL teste, FILE* f){
    //Escreve uma entrada na ID informada
    //Assume todas entradas de tamanho igual(144), FILE* em modo rb+ ou wb+ 
    //Esse metodo de calculo impede de tentar truncar strings com menos de 25 chars
    //Em troca, acesso de entradas fica  em O(1) em vez de O(n)

    fseek(f,(long int) sizeof(ENTRADA_FINAL)*teste.indice,SEEK_SET); 
    fwrite(&teste.ID,sizeof(int),1,f);
    fwrite(&teste.APAGADO,sizeof(int),1,f);
    fwrite(&teste.classe,sizeof(int),1,f);
    fwrite(&teste.nome,sizeof(char),ESPACO,f); //se atentar ao '\0' na hora de ler de volta para um programa em C, isso vai escrever lixo
    fwrite(&teste.cor,sizeof(char),ESPACO,f);
    fwrite(&teste.preco,sizeof(int),1,f);    
    if (teste.classe){
        escreveManual(teste.manual,f);
    }
    else {
        escreveMotorizado(teste.motorizado,f);
    }

}
#endif