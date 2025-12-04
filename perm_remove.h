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
    fseek(f, 0, SEEK_SET);
    beginf = ftell(f)
    if ((size * (-1)) < beginf) // assume que tem pelo menos um registro
    {
        printf("ainda não existem registros, para remover um registro, cire um primeiro. \n");
        return;
    }

    fseek(f, (size * (-1)), SEEK_END); // pega o ID que possui último 
    int ID_do_ultimo_indice;
    fread(&, sizeof(int), 1, f)// guarda o ID do registro de último indice 
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

    int ID = indice_P_ID(f, index); //pego o id associado ao indice do apagado
    fseek(f, (((2* sizeof(int)) * (ID -1)) + 4), SEEK_SET); // pulando para o index associado ao id apagado
    int deleted = NULO;
    fwrite(&deleted, sizeof(int, 1, f)); // tornando o index inválido.

    fseek(f, (((2* sizeof(int)) * (ID_do_ultimo_indice -1)) + 4), SEEK_SET) // vai na posição do índice associado ao último ID
    fwrite(&index, sizeof(int); 1, f); // coloca o indice do arquivo que foi removido como o novo indice do último ID.

    return;
}

#endif