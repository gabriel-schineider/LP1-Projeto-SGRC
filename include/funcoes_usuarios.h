#include <stdio.h>
#include "C:\\LP1\\concessionaria\\repositorio\\include\\escrita_arq.h"
#include "C:\\LP1\\concessionaria\\repositorio\\include\\ler_arq.h"
#include "C:\\LP1\\concessionaria\\repositorio\\include\\escrita_arq.h"
#include "C:\\LP1\\concessionaria\\repositorio\\include\\remover_registro.h"
#include "C:\\LP1\\concessionaria\\repositorio\\include\\editar_cria_registro.h"
#ifndef FUNCOES_USUARIOS_H
#define FUNCOES_USUARIOS_H

void USER_INPUT(FILE* arquivo, int* termino){
    //pega um input do usuario
    puts("Opções:\n [1] Criar registro\n [2] Buscar registro\n [3] Editar registro\n [4] Remover registro\n [5] Sair");
    puts("Digite o número da opção escolhida: ");
    int escolha;
    scanf("%d", &escolha);
    int id;
    switch (escolha){
        case(1):
            CriaRegistroUSER(arquivo); //IDs sao crescentes, entao tem que ir ate o final do arquivo, pegar ultima e adicionar uma com ID+1
            break;
        case(2): //teste de busca de arquivos
            BuscarRegistro(arquivo);
            break;
        case(3):
            EditarRegistro(arquivo); //editar um dado registro, definido em outro modulo 
            break;
    
        case(4):
            printf("Qual id voce quer remover do arquivo?");
            scanf("%d",&id);
            int indice=pegaIndice(id,arquivo);
            RemoverRegistro(indice,arquivo); //estou abusando do fato que isso tambem consegue deletar
            break;

        case(5):
            *termino=1; //
            break;

        default:
            puts("Input nao reconhecido, saindo do loop de acao");
            *termino=1;
    }
}

#endif