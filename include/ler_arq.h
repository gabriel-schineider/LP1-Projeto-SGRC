#include "C:\LP1\concessionaria\repositorio\include\entrada_struct.h"
#include <stdio.h>
#ifndef LER_ARQ_H
#define LER_ARQ_H

void leMotorizado(struct Motorizado* coisa,FILE* f)
{ 
  // Lê um tipo motorizado do arquivo 
  // Assume-se offset certo, ou seja, que o cursor do arquivo esteja na posição desejada
  
  fread(&(coisa->tipo), sizeof(int), 1, f);
  fread(coisa->combustivel, sizeof(char), ESPACO, f);
  switch (coisa->tipo)
  {
    case moto_ENUM: 
        fread(coisa->moto.guidom, sizeof(char), ESPACO,f);
        fread(&(coisa->moto.offroad), sizeof(int), 1, f);
        fread(&(coisa->moto.pressao_ideal), sizeof(int), 2, f);
        break;

    case carro_ENUM:
        fread(&(coisa->carro.tracao), sizeof(int), 1, f);
        fread(&(coisa->carro.portas), sizeof(int), 1, f);
        fread(&(coisa->carro.eletrico), sizeof(int), 1, f);
        fread(coisa->carro.pressao_ideal, sizeof(int), 4, f);
        break;

    case barco_ENUM:
        fread(&(coisa->barco.litragem), sizeof(int), 1, f); 
        fread(coisa->barco.tipo_casco, sizeof(char), ESPACO, f);
        fread(&(coisa->barco.vel_aq_max), sizeof(int), 1, f);
        break;

    case helicoptero_ENUM:
        fread(&(coisa->helicoptero.pas), sizeof(int), 1, f);
        fread(&(coisa->helicoptero.passageiros), sizeof(int), 1, f);
        fread(&(coisa->helicoptero.altitude_max), sizeof(int), 1, f);
        break;
  }
}
void leManual(struct Manual* coisa,FILE* f)
{
  // Lê um tipo manual do arquivo 
  // Assume-se offset certo, ou seja, que o cursor do arquivo esteja na posição desejada
  
  fread(&(coisa->tipo), sizeof(int), 1, f);
  fread(coisa->modelo, sizeof(char), ESPACO, f);
  switch (coisa->tipo)
  {
    case bike_ENUM:
        fread(coisa->bike.suspensao, sizeof(char), ESPACO, f);
        fread(&(coisa->bike.diam_roda), sizeof(int), 1, f);
        fread(&(coisa->bike.marchas), sizeof(int), 1, f);
        break;
        
    case skate_ENUM:
        fread(&(coisa->skate.comprimento), sizeof(int), 1, f);
        fread(&(coisa->skate.diam_roda), sizeof(int), 1, f);
        fread(coisa->skate.tipo_roda, sizeof(char), ESPACO, f);
        break;
  }
}

int pegaIndice(int ID,FILE* f){
  //dado um ID, pega o indice correspondente
  //O(1) pois indices estao arranjados de forma crescente e sempre igual
  int indice;
  fseek(f,(long int) 2*sizeof(int)*(ID-1)+4,SEEK_SET); //2 vezes pares de int vezes ID-1 p/ achar o indice(ID nao mutavel e crescente, indice mutavel)
  fread(&indice, sizeof(int), 1, f);
  return indice;
}


int IndiceMax(FILE* f){
  //pega o indice maximo do arquivo. Nao passa de 99(indices vao de 0 a 99 para 100 elementos totais)
  int max=0;
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
int pegarUltimoID(FILE* f){
    if (f == NULL) {
      return 1;
    }
    fseek(f, 0, SEEK_SET);

    int ID = 1;
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


void LeEntrada(ENTRADA_FINAL* teste,int id, FILE* f) 
{
  //Lê a região do arquivo referente ao ID informado pela estrutura
  //Assume todas entradas de tamanho igual(144), FILE* em modo rb+ ou wb+ 
  //Esse metodo de calculo impede de tentar truncar strings com menos de 28 chars
  //Em troca, acesso de entradas fica em O(1) em vez de O(n)

  int indice=pegaIndice(id,f);
  if (indice==NULO){
    teste->ID=id;
    teste->indice=indice;
    teste->APAGADO=sim;
  }
  else{
    fseek(f, (long int) INDICE_INICIO+sizeof(ENTRADA_FINAL)*indice, SEEK_SET);// Posiciona o cursor do arquivo, a partir da posição inicial, na struct referente ao indice

    

    fread(&(teste->ID), sizeof(int), 1, f);
    fread(&(teste->indice), sizeof(int), 1, f);
    fread(&(teste->APAGADO), sizeof(int), 1, f);
    fread(&(teste->classe), sizeof(int), 1, f);
    fread(teste->nome, sizeof(char), ESPACO, f);
    fread(teste->cor, sizeof(char), ESPACO, f);
    fread(&(teste->preco), sizeof(int), 1, f);
    if (teste->classe)
    {
      leManual(&(teste->manual),f);
    }
    else
    {
      leMotorizado(&(teste->motorizado),f);
    }
  }
}


void BuscarRegistro(FILE* f)
{
  // Assume-se a já existência do registro, cuja posição no arquivo encontra-se em (long int) INDICE_INICIO+sizeof(ENTRADA_FINAL)*indice
  ENTRADA_FINAL registro; // Variável nova que receberá a cópia das informações do registro já existente
  int id; // ID desse registro já existente
  puts("Informe o ID do registro que deseja buscar: ");
  scanf("%d", &id);

  LeEntrada(&registro, id, f);
  ExibeEntrada(registro);
  fflush(f);
}

#endif