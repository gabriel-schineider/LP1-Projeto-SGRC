#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<io.h>
#include<assert.h>
#include "estruturas.h"
#include "funcoes.h"
#include "criacao.h"
#ifndef PERM_REMOVE
#define PERM_REMOVE

void perm_rm(FILE *f, int index)
{
    if (f == NULL)
    {
        perror("ponteiro inválido");
        return;
    }

    Registro aux;
    long int size = sizeof(Registro);
    fseek(f, (size * (-1)), SEEK_END);
    if(fread(&aux, size, 1, f) != 1)
    {
        perror("falha ao copiar ultimo arquivo para o auxiliar");
        return;
    }

    fseek(f, size * (index), SEEK_SET);
    if (fwrite(&aux, size, 1, f) != 1)
    {
        perror("falha ao escrever o auxiliar.");
        return;
    }
    fflush(f);

    fseek(f, (size * (-1)), SEEK_END);
    int file_descr = fileno(f); //aparentemente isso é necessário para o parâmetro do ftruncate abaixo, uma chatice.
    
    #ifdef _WIN32   //acho que só vai ser necessário rodar no linux, mas, caso seja necessário, está aí.
        _chsize_s(file_descr, ftell(f));
    #else
        ftruncate(file_descr, ftell(f));
    #endif

    return;
}
    
#endif