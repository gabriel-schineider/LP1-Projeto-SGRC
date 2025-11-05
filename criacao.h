#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "funcoes.h"
#ifndef CRIACAO_H
#define CRIACAO_H

void inicializa(void) {
    //se nao existe, cria tabela de ID- Indice
    FILE* arquivo = fopen(ARQUIVO, "ab+");
    for (int i = 1; i <= 100; i++) {
        int ID=i;
        int indice = NULO;
    
        size_t escrito = fwrite(&ID, sizeof(int), 1, arquivo);
        escrito += fwrite(&indice, sizeof(int), 1, arquivo);
        if (escrito != 2) {
            perror("Erro ao escrever no arquivo");
        }
    }
        
    fflush(arquivo);
    fclose(arquivo);
}

int IndiceMax(FILE* f){
  //pega o indice maximo do arquivo. Nao passa de 99(indices vao de 0 a 99 para 100 elementos totais)
  int max=NULO;
  fseek(f,4,SEEK_SET);
  int offset=0; //o quanto andamos na leitura
  int novo;
  while(offset<INDICE_INICIO){
    offset+=8;
    fread(&novo,sizeof(int),1,f); //ler indice atual 
    if (novo>max){
      max=novo;
    }
    fseek(f,4,SEEK_CUR); //pula o ID, so queremos ler o indice agora. Eh parecido com pegar UltimoID
  }
  return max;
}

int indice_P_ID(FILE* f, int indice){
  //dado um indice, retorna seu ID respectivo
  fseek(f, 0,SEEK_SET); //comeca no inicio, vai ate o indice no inicio
  long int offset=0;
  int ID=-1;
  int indiceIterante; //usado para verificar se achamos o indice desejado
  while(offset<INDICE_INICIO){ 
    fread(&ID,sizeof(int),1,f); //ler ID primeiro porque ta escrito nessa ordem
    fread(&indiceIterante,sizeof(int),1,f);//pula de ler o indice, em relacao a posicao relativa do leitor
    offset+=8;
    if (indiceIterante==indice){ //achamos o indice, retornamos seu ID correspondente
      return ID;
    }
    //nao preciso de nenhum fseek, os dois freads ja percorrem o intervalo da forma que eu quero
  }
  return -1;

}
int pegarUltimoID(void){
    FILE* f = fopen(ARQUIVO, "rb");
    if (f == NULL) {
        inicializa();
        return 0;
    }
    fseek(f, 0, SEEK_SET);

    int ID = 0;
    int indice = 0;
    int ultID = 0;

    long int offset = 0;

    while (offset < INDICE_INICIO) {
        size_t l1 = fread(&ID, sizeof(int), 1, f);
        size_t l2 = fread(&indice, sizeof(int), 1, f);

        // Se fread falhar (EOF antes de 800 bytes), para o loop
        if (l1 != 1 || l2 != 1){
            break;
        }


        if (indice != NULO)
            ultID = ID;

        offset = ftell(f); // atualiza a posição real no arquivo
    }
    return ultID;
}


void criaRegistro (Registro * registro, int * ultimoID)
{
  FILE* f = fopen(ARQUIVO, "ab+"); // Abrindo o arquivo em modo binário append

  // Atribuindo um valor para o ID
  if (*ultimoID == 0) // Se ainda não houver registros
  {
    registro->ID = 1; // Esse é o primeiro registro
    *ultimoID = registro->ID; // Recebe o valor do último registro
  }
  else // Se esse for o próximo registro
  {
    *ultimoID += 1;
    registro->ID = *ultimoID;
  }
  // Atribuindo um valor para Ativo
  registro->Ativo = 1;
  registro->indice=IndiceMax(f)+1;
  // Atribuindo valores para os demais campos do registro
  preencheRegistro(registro); // Usuário preenche, normalmente, outros campos
  fwrite(registro, sizeof(Registro), 1, f); // Escreve (com append) esse registro para o arquivo
  fclose(f); // Fecha o arquivo para garantir que o buffer registro tenha sido gravado

  FILE* arq=fopen(ARQUIVO,"rb+");
  fseek(arq,(long int) (registro->ID-1)*8,SEEK_SET); //atualizar tabela de IDs e indices 
  fwrite(&registro->ID,sizeof(int),1,arq);
  fwrite(&registro->indice,sizeof(int),1,arq);
  fclose(arq);
  printf("\nRegistro criado com sucesso! O ID desse registro é: %d\n", registro->ID);
}





// Edição de Registro no Arquivo

void editaRegistro (Registro * registro)
{
  // Assume-se que o usuário sabe o ID do registro que pretende editar
  int ID_Busca;
  printf("Informe o ID do registro que desejas editar: ");
  scanf(" %d", &ID_Busca);
  int posicaoRegistro = buscaRegistro(registro, ID_Busca);
  if (posicaoRegistro == -1)
  {
    return; // A função busca já informou a não ocorrência desse registro, então é só sair dessa função
  }
  // Caso chegue nessa parte, podemos garantir que o registro existe e está ativo
  exibeRegistro(*registro); // A função busca já preencheu a variável registro com o registro certo 
  int campo;
  printf("\nQual campo desejas alterar?\n");
  exibeCampos();
  printf("Informe com o número correspondente: ");
  scanf(" %d", &campo);
  getchar();
  if (campo != subcampo)
  {
    preencheCampoComum(registro, campo); 
  }
  else
  {
    if (campo == subcampo)
    {
      int subCampoTipo;
      printf("\nQual campo desejas alterar?\n");
      exibeCamposTipo(registro);
      printf("Informe com o número correspondente: ");
      scanf(" %d", &subCampoTipo);
      getchar();
      preencheCampoTipo(registro, subCampoTipo);
    }
  }
  FILE* f = fopen(ARQUIVO, "rb+"); // Abre o arquivo em modo binário de leitura para leitura e escrita
  // Como a função busca já foi utilizada, podemos garantir que o arquivo existe. Se não existisse, a função já teria sido retornada
  fseek(f, posicaoRegistro, SEEK_SET); // Posiciona para a posição inicial do registro, agora já editado
  fwrite(registro, sizeof(Registro), 1, f);
  fclose(f);

  FILE* arq=fopen(ARQUIVO,"rb+");
  fseek(arq,(long int) (registro->ID-1)*8,SEEK_SET); //atualizar tabela de IDs e indices 
  fwrite(&registro->ID,sizeof(int),1,arq);
  fwrite(&registro->indice,sizeof(int),1,arq);
  fclose(arq);
  if (campo != nenhum)
  {
    printf("\nEdição de registro realizada com sucesso!\n");
  }
}
#endif