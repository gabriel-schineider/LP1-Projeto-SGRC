# include <stdio.h> // Tomar cuidado para não incluí-lo várias vezes ao adicionar os módulos dos outros arquivos neste arquivo principal
#include "include/mestre.h" // Faz-se necessário atualizar o caminho corretamente desse header

// CRIANDO APENAS O ESQUELETO DO MAIN

int main (void)
{
  int sair=0;
  FILE* arquivo=fopen("dados.bin","rb+");
  inicializa(arquivo);
  puts("Seja bem-vindo(a) ao XXXXX_nome-do-nosso-sistema_XXXXX, o Sistema de Gerenciamento de Registros para Concesionárias !");
  while(!sair){
    USER_INPUT(arquivo,&sair); //pega input do usuario, sair indica fim de atividade
  }

  puts("Programa finalizado.");
  fclose(arquivo);
  return 0;
}