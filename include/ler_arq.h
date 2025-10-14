#include "/home/ime/LP1-Projeto-SGRC/include/entrada_struct.h"
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
    case moto: 
        fread(&(coisa->moto.guidom), sizeof(char), ESPACO,f);
        fread(&(coisa->moto.offroad), sizeof(int), 1, f);
        fread(&(coisa->moto.pressao_ideal), sizeof(int), 2, f);
        break;

    case carro:
        fread(&(coisa->carro.tracao), sizeof(int), 1, f);
        fread(&(coisa->carro.portas), sizeof(int), 1, f);
        fread(&(coisa->carro.eletrico), sizeof(int), 1, f);
        fread(coisa->carro.pressao_ideal, sizeof(int), 4, f);
        break;

    case barco:
        fread(&(coisa->barco.litragem), sizeof(int), 1, f); 
        fread(coisa->barco.tipo_casco, sizeof(char), ESPACO, f);
        fread(&(coisa->barco.vel_aq_max), sizeof(int), 1, f);
        break;

    case helicoptero:
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
    case bike:
        fread(coisa->bike.suspensao, sizeof(char), ESPACO, f);
        fread(&(coisa->bike.diam_roda), sizeof(int), 1, f);
        fread(&(coisa->bike.marchas), sizeof(int), 1, f);
        break;
        
    case skate:
        fread(&(coisa->skate.comprimento), sizeof(int), 1, f);
        fread(&(coisa->skate.diam_roda), sizeof(int), 1, f);
        fread(coisa->skate.tipo_roda, sizeof(char), ESPACO, f);
        break;
  }
}
void LeEntrada(ENTRADA_FINAL* teste,int id, FILE* f)
{
  //Lê a região do arquivo referente ao ID informado pela estrutura
  //Assume todas entradas de tamanho igual(144), FILE* em modo rb+ ou wb+ 
  //Esse metodo de calculo impede de tentar truncar strings com menos de 25 chars
  //Em troca, acesso de entradas fica em O(1) em vez de O(n)

  fseek(f, (long int) sizeof(ENTRADA_FINAL)*id, SEEK_SET); // Posiciona o cursor do arquivo, a partir da posição inicial, na struct referente ao ID

  fread(&(teste->ID), sizeof(int), 1, f);
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


void BuscarRegistro(FILE* f)
{
  // Assume-se a já existência do registro, cuja posição no arquivo encontra-se em (long int)sizeof(ENTRADA_FINAL) * id
  ENTRADA_FINAL registro; // Variável nova que receberá a cópia das informações do registro já existente
  long int id; // ID desse registro já existente
  puts("Informe o ID do registro que deseja buscar: ");
  scanf("%d", id);

  LeEntrada(&registro, id, f);
  ExibeEntrada(registro);
}

#endif