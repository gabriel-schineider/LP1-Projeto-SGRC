#include <stdio.h>
#include <stdlib.h> // para limpar o terminal

// Assinatura das funções
void exibeOpcoes(void);
void limpaTerminal(void);




// Funções completas
void exibeOpcoes(void)
{
  // assume-se que as funções aqui utilizadas já foram incluídas ou criadas neste arquivo.

  FILE* f = fopen("SGRC/informacoes.bin", "rb+"); // Se o usuário mudar o caminho, pode falhar

  // precisamos add um teste de segurança de arquivo : "perror" ou algo do tipo

  puts("Opções:\n [1] Criar registro\n [2] Buscar registro\n [3] Editar registro\n [4] Remover registro\n [5] Sair");
  puts("Digite o número da opção escolhida: ");
  int escolha;
  scanf("%d", &escolha);

  switch (escolha)
  {
    case(1):
      CriarRegistro(f);
      fclose(f);
      break;
    
    case(2):
      BuscarRegistro(f);
      fclose(f);
      break;
    
    case(3):
      EditarRegistro(f);
      fclose(f);
      break;
    
    case(4):
      RemoverRegistro(f);
      fclose(f);
      break;

    case(5):
      fclose(f); 
      break;

    default:
      fclose(f);
      limpaTerminal();
      puts("Escolha uma opção válida.");
      exibeOpcoes();  
  }
}

void limpaTerminal(void)
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}