#include <stdio.h>
#include <stdlib.h>
#ifndef INICALIZA_H
#define INICIALIZA_H

/// @brief 
/// @param arquivo 
/// @return 
FILE* inicializa(FILE* arquivo) {
    if (arquivo == NULL) {
        //se nao existe, 
        arquivo = fopen("dados.bin", "wb+");
        if (arquivo == NULL) {
            perror("Erro ao criar o arquivo");
        }
        
        for (int i = 0; i < 100; i++) {
            int ID=i;
            int indice = -1;
        
            size_t escrito = fwrite(&ID, sizeof(int), 1, arquivo);
            escrito += fwrite(&indice, sizeof(int), 1, arquivo);
            if (escrito != 2) {
                perror("Erro ao escrever no arquivo");
            }
        }
        
    fflush(arquivo);
    return arquivo;
    }
}
#endif