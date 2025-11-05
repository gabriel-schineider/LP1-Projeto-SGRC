#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "funcoes.h"
#ifndef BUSCA_H
#define BUSCA_H
// Busca de Registro no Arquivo

long buscaRegistro (Registro*  registro, int ID_Busca)
{
  // User informa ID
  // variável paraRemocao --> exibir o registro caso seja com o intuito de removê-lo
  // Retorna offset para chegar ate inicio do registro no arquivo e preenche a variavel registro, -1 em caso de erro/nao ativo

  long posicaoRegistro = -1; 
  FILE* f = fopen(ARQUIVO, "rb"); // Abrindo o arquivo em modo binário de leitura
  if (f == NULL){    // Verificando se o arquivo pode ser aberto. Caso não possa, sai da função.
    perror("Erro ao abrir o arquivo de registros.");
    return posicaoRegistro; // Retornando -1
  }
  fseek(f,0,SEEK_END);
  long int tamanho_arquivo=ftell(f); //descobrir tamanho do arquivo

  if((ID_Busca-1)*sizeof(Registro)>=tamanho_arquivo){ //checa se ta fora do arquivo
    printf("\nEsse registro não consta na base de dados.\n");
    return posicaoRegistro;
  }
  else{
    posicaoRegistro= (long int) sizeof(Registro)*(ID_Busca-1);
    fseek(f,posicaoRegistro,SEEK_SET);
    fread(registro,sizeof(Registro),1,f);
  }
  fclose(f);
  return posicaoRegistro; // Retorna a posição correta apenas se o registro for encontrado e estiver ativo, Caso contrário retorna -1
}

void Busca (Registro* registro)
{
  int ID_Busca;
  printf("Informe o ID do registro que desejas acessar: ");
  scanf(" %d", &ID_Busca);

  long posicaoRegistro = buscaRegistro(registro, ID_Busca);
  
  if (posicaoRegistro == -1)
  {
    return;
  }
  if (registro->Ativo){
    exibeRegistro(*registro);
  }
  else{
    printf("\nEsse registro foi apagado.\n");
  }
  
}


#endif