#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "funcoes.h"
#ifndef FUNCOESFINAL_H
#define FUNCOESFINAL_H


// Remoção de Registro no Arquivo

void removeRegistro (Registro * registro)
{
  // Assume-se que o usuário sabe o ID do registro que pretende remover

  int ID_Busca;
  printf("Informe o ID do registro que desejas remover: ");
  scanf(" %d", &ID_Busca);

  int posicaoRegistro = buscaRegistro(registro, ID_Busca);

  if (posicaoRegistro == -1)
  {
    return; // A função busca já informou a não ocorrência desse registro, então é só sair dessa função
  }

  // Caso chegue nessa parte, podemos garantir que o registro existe e está ativo
  registro->Ativo = 0;

  FILE* f = fopen(ARQUIVO, "rb+"); // Abre o arquivo em modo binário de leitura para leitura e escrita

  // Como a função busca já foi utilizada, podemos garantir que o arquivo existe. Se não existisse, a função já teria sido retornada

  fseek(f, posicaoRegistro, SEEK_SET); // Posiciona para a posição inicial do registro, agora já removido (registro->Ativo == 0)

  fwrite(registro, sizeof(Registro), 1, f);

  fclose(f);


  printf("\nRemoção de registro realizada com sucesso!\n");
}



// Fluxo do sitema

void limpaTerminal (void)
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

void exibeOpcoes (Registro * registro, int * ultimoID)
{
  int acao;
  printf("Qual ação desejas realizar?\n [%d] Criação de Registro\n [%d] Busca de Registro\n [%d] Edição de Registro\n [%d] Remoção de Registro\n [%d] Sair\nInforme com o número correspondente: ", criacao, busca, edicao, remocao, sair);
  scanf(" %d", &acao);
  puts("");

  while (acao != sair)
  {
    switch (acao)
    {
      case (criacao):
        criaRegistro(registro, ultimoID);
        break;

      case (busca):
        Busca(registro);
        break;
      
      case (edicao):
        editaRegistro(registro);
        break;

      case (remocao):
        removeRegistro(registro);
        break;
    }
    puts(""); // Apenas para fins de estética no terminal

    int retorno = -1;
    printf("Digite [0] para retornar à tela de opções: ");
    scanf(" %d", &retorno); // Congelando a tela para que o usuário possa ver o que fez até que decida voltar para a tela de opções 

    limpaTerminal();

    printf("Qual ação desejas realizar?\n [%d] Criação de Registro\n [%d] Busca de Registro\n [%d] Edição de Registro\n [%d] Remoção de Registro\n [%d] Sair\nInforme com o número correspondente: ", criacao, busca, edicao, remocao, sair);
    scanf(" %d", &acao);
    puts("");
  }

  limpaTerminal(); // Limpando o terminal antes de finalizar o programa para que apenas a mensagem de despedida apareça.
}

void Opcoes (void)
{
  // Inicializando a aplicação

  Registro registro; // Variável auxiliar que será utilizada em todas as operações, apenas de forma pontual
  int ultimoID =pegarUltimoID(); // Por mais que a função verifica_UltimoID() abaixo verifique e atribua o valor correto para essa variável, ela está sendo inicializada como -1 para evitar lixos de memória.



  // Exibindo as opções

  exibeOpcoes(&registro, &ultimoID);
}

#endif