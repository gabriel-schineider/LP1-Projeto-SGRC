#include <stdio.h>
#include <stdlib.h>
#ifndef INICALIZA_H
#define INICIALIZA_H

FILE* inicializa(FILE* arquivo) {
    if (arquivo == NULL) {
        //se nao existe, 
        arquivo = fopen("dados.bin", "wb+");
        if (arquivo == NULL) {
            perror("Erro ao criar o arquivo");
        }
    }
    int primeiro_indice;
    fseek(arquivo,4,SEEK_SET);
    fread(&primeiro_indice,sizeof(int),1,arquivo);

    if(primeiro_indice!=-1){
        for (int i = 0; i < 100; i++) {
            int ID=i;
            int indice = -1;

            // Escrevendo os dois sequencialmente
            size_t escrito = fwrite(&ID, sizeof(int), 1, arquivo);
            escrito += fwrite(&indice, sizeof(int), 1, arquivo);

            if (escrito != 2) {
                perror("Erro ao escrever no arquivo");
            }
        }
    }

    // Cada entrada sao 8 Bytes


    fflush(arquivo);


    printf("Arquivo inicializado com 100 IDs e indices -1 (total 800 bytes).\n");
    return arquivo;
}

#endif