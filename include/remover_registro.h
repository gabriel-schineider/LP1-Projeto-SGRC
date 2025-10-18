#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "entrada_struct.h"
#ifndef REMOVER_REGISTRO_H
#define REMOVER_REGISTRO_H

void RemoverRegistro(int indice, FILE *f) //só muda o campo APAGADO pra 1, não remove realmente do arquivo
{
    int removido = 1;
    
    long int PosicaoDoRegistro = INDICE_INICIO+sizeof(ENTRADA_FINAL) * indice;
    long int PosicaoParaRemover = (PosicaoDoRegistro + sizeof(int)); //pula o ID

    fseek(f,PosicaoParaRemover, SEEK_SET);
    fwrite(&removido, sizeof(int), 1, f);

    fflush(f); //só pra garantir que o dado foi escrito no arquivo.
}

#endif