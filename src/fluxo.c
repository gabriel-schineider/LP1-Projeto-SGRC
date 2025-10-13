#include <stdlib.h> // para limpar o terminal

// Assinatura das funções
void exibeOpcoes(void);
void limpaTerminal(void);




// Funções completas
void exibeOpcoes(void)
{
  // assume-se que as funções aqui utilizadas já foram incluídas ou criadas neste arquivo.

  puts("Opções:\n [1] Criar registro\n [2] Buscar registro\n [3] Editar registro\n [4] Remover registro\n [5] Sair");
  puts("Digite o número da opção escolhida: ");
  int escolha;
  scanf("%d", &escolha);

  switch (escolha)
  {
    case(1):
      CriarRegistro();
      break;
    
    case(2):
      BuscarRegistro();
      break;
    
    case(3):
      EditarRegistro();
      break;
    
    case(4):
      RemoverRegistro();
      break;

    case(5):
      break;

    default:
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