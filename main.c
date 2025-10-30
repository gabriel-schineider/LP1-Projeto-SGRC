
// Para usar o sistema, tenha todos os arquivos no mesmo diretório e compile-os pelo terminal assim: "gcc main.c funcoes.c"
// Depois de já compilado, apenas digite: "a.out" sempre que quiser usar o sistema

#include "funcoes.h"

int main (void)
{
  puts("Boas vindas ao Sistema de Gerenciamento de Registros da sua Concessionária!");

  puts(""); // Apenas para fins de estética no terminal

  Opcoes();

  puts("Programa finalizado com sucesso!");
  
  return 0;
}