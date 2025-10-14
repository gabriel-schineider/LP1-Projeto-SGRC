# include <stdio.h> // Tomar cuidado para não incluí-lo várias vezes ao adicionar os módulos dos outros arquivos neste arquivo principal
# include <entrada_struct.h> // Faz-se necessário atualizar o caminho corretamente desse header

// CRIANDO APENAS O ESQUELETO DO MAIN

int main (void)
{
  struct ENTRADA_FINAL registros[100];

  puts("Seja bem-vindo(a) ao XXXXX_nome-do-nosso-sistema_XXXXX, o Sistema de Gerenciamento de Registros para Concesionárias !");

  exibeOpcoes(); // encontra-se em "fluxo.c"

  puts("Programa finalizado.");

  return 0;
}