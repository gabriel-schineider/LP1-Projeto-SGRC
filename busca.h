#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "funcoes.h"
#include "criacao.h"
#ifndef BUSCA_H
#define BUSCA_H

int pegaIndice(int ID,FILE* f){
  //dado um ID, pega o indice correspondente
  //O(1) pois indices estao arranjados de forma crescente e sempre igual
  int indice;
  fseek(f,(long int) 2*sizeof(int)*(ID-1)+4,SEEK_SET); //2 vezes pares de int vezes ID-1 p/ achar o indice(ID nao mutavel e crescente, indice mutavel)
  fread(&indice, sizeof(int), 1, f);
  return indice;
}

long buscaRegistro (Registro*  registro, int ID_Busca)
{
  // User informa ID
  // variável paraRemocao --> exibir o registro caso seja com o intuito de removê-lo
  // Retorna offset para chegar ate inicio do registro no arquivo e preenche a variavel registro, -1 em caso de erro/nao ativo
  
  long posicaoRegistro = -1; 
  FILE* f = fopen(ARQUIVO, "rb"); // Abrindo o arquivo em modo binário de leitura
  int indiceBusca=pegaIndice(ID_Busca,f);

  if (f == NULL){    // Verificando se o arquivo pode ser aberto. Caso não possa, sai da função.
    perror("Erro ao abrir o arquivo de registros.");
    return posicaoRegistro; // Retornando -1
  }

  fseek(f,0,SEEK_END);
  long int tamanho_arquivo=ftell(f); //descobrir tamanho do arquivo

  if((INDICE_INICIO+(indiceBusca)*sizeof(Registro))>=tamanho_arquivo){ //checa se ta fora do arquivo
    printf("\nEsse registro não consta na base de dados.\n");
    return posicaoRegistro;
  }
  else{
    posicaoRegistro= (long int) sizeof(Registro)*(indiceBusca) +INDICE_INICIO;
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