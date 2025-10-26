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
        printf("Arquivo inicializado com 100 IDs e indices -1 (total 800 bytes).\n");
        for (int i = 0; i < 100; i++) {
            int ID=i;
            int indice = -1;
        
            size_t escrito = fwrite(&ID, sizeof(int), 1, arquivo);
            escrito += fwrite(&indice, sizeof(int), 1, arquivo);
            if (escrito != 2) {
                perror("Erro ao escrever no arquivo");
            }
        }
    }

    fflush(arquivo);
    return arquivo;
    
}

#endif