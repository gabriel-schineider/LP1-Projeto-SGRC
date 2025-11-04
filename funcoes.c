#include "estruturas.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



// Preenchimento de Registro pelo Terminal

 /* Comentários pertinentes sobre a lógica nos preenchimentos

  - Os scanf possuem um espaço antes do % para evitar que o \n - que fica no buffer após a tecla Enter ser pressionada - seja consumido por essa função, pois isso impede que o usuário digite.

  - O fluxo segue uma lógica de " scanf(); getchar(); fgets();  'alteração do último byte útil'  " para que seja possível receber uma string do usuário ainda que contenha espaços. Faz-se necessário que getchar() venha entre as funções mencionadas para que a posterior à essa não receba a quebra de linha "\n" que fica no buffer proveniente da anterior à essa que acontece quando o usuário pressiona a tecla Enter ao enviar o input

 */

  // Preenchimento dos Campos de Moto

void preencheCilindradas (Moto * moto)
{
  // Usada para os seguinte tipo: Moto
  // Essa função está sendo usada na criação e na edição de registros

  printf("Número de cilindradas: ");
  scanf(" %d", &moto->Cilindradas);
}

void preencheFreio (Moto * moto)
{
  // Usada para os seguinte tipo: Moto
  // Essa função está sendo usada na criação e na edição de registros

  printf("Tipo de freio: ");
  fgets(moto->Freio, sizeof(moto->Freio), stdin);
  moto->Freio[strcspn(moto->Freio, "\n")] = '\0';
}

void preencheTransmissao (Moto * moto)
{
  // Usada para os seguinte tipo: Moto
  // Essa função está sendo usada na criação e na edição de registros

  printf("Tipo de transmissão: ");
  fgets(moto->Transmissao, sizeof(moto->Transmissao), stdin);
  moto->Transmissao[strcspn(moto->Transmissao, "\n")] = '\0';
}

  // Preenchimento de Moto

void preencheMoto (Moto * moto)
{
  preencheCilindradas(moto);
  getchar();

  preencheFreio(moto);

  preencheTransmissao(moto);
}


  // Preenchimento dos campos de Carro

void preenchePortas (Carro * carro)
{
  // Usada para os seguinte tipo: Carro
  // Essa função está sendo usada na criação e na edição de registros

  printf("Número de portas: ");
  scanf(" %d", &carro->QntPortas);
}

void preenchePassageirosCarro (Carro * carro)
{
  // Usada para os seguinte tipo: Carro
  // Essa função está sendo usada na criação e na edição de registros

  printf("Número de passageiros: ");
  scanf(" %d", &carro->Passageiros);
}

void preencheCambio (Carro * carro)
{
  // Usada para os seguinte tipo: Carro
  // Essa função está sendo usada na criação e na edição de registros

  printf("Tipo de câmbio: ");
  fgets(carro->Cambio, sizeof(carro->Cambio), stdin);
  carro->Cambio[strcspn(carro->Cambio, "\n")] = '\0';
}

void preencheTracao (Carro * carro)
{
  // Usada para os seguinte tipo: Carro
  // Essa função está sendo usada na criação e na edição de registros

  printf("Tipo de tração: ");
  fgets(carro->Tracao, sizeof(carro->Tracao), stdin);
  carro->Tracao[strcspn(carro->Tracao, "\n")] = '\0';
}

  // Preenchimento de Carro

void preencheCarro (Carro * carro)
{
  preenchePortas(carro);

  preenchePassageirosCarro(carro);
  getchar();

  preencheCambio(carro);

  preencheTracao(carro);
}


  // Preenchimento dos campos de Caminhao

void preencheCargaMax (Caminhao * caminhao)
{
  // Usada para os seguinte tipo: Caminhao
  // Essa função está sendo usada na criação e na edição de registros

  printf("Carga máxima em kg: ");
  scanf(" %d", &caminhao->CargaMax);
}

void preencheQntEixos (Caminhao * caminhao)
{
  // Usada para os seguinte tipo: Caminhao
  // Essa função está sendo usada na criação e na edição de registros

  printf("Quantidade de eixos do caminhão: ");
  scanf(" %d", &caminhao->QntEixos);
}

void preencheCarroceria (Caminhao * caminhao)
{
  // Usada para os seguinte tipo: Caminhao
  // Essa função está sendo usada na criação e na edição de registros

  printf("Tipo de carroceria do caminhão: ");
  fgets(caminhao->Carroceria, sizeof(caminhao->Carroceria), stdin);
  caminhao->Carroceria[strcspn(caminhao->Carroceria, "\n")] = '\0';
}

  // Preenchimento de Caminhao

void preencheCaminhao (Caminhao * caminhao)
{
  preencheCargaMax(caminhao);

  preencheQntEixos(caminhao);
  getchar();

  preencheCarroceria(caminhao);
}


  // Preenchimento dos campos de Helicoptero

void preencheQntRotores (Helicoptero * helicoptero)
{
  // Usada para os seguinte tipo: Helicoptero
  // Essa função está sendo usada na criação e na edição de registros

  printf("Quantidade de rotores: ");
  scanf(" %d", &helicoptero->QntRotores);
}

void preencheAutonomiaHelicoptero (Helicoptero * helicoptero)
{
  // Usada para os seguinte tipo: Helicoptero
  // Essa função está sendo usada na criação e na edição de registros

  printf("Autonomia em km: ");
  scanf(" %f", &helicoptero->Autonomia);
}

void preenchePassageirosHelicoptero (Helicoptero * helicoptero)
{
  // Usada para os seguinte tipo: Helicoptero
  // Essa função está sendo usada na criação e na edição de registros

  printf("Quantidade máxima de passageiros: ");
  scanf(" %d", &helicoptero->Passageiros);
}

void preenchePesoMax (Helicoptero * helicoptero)
{
  // Usada para os seguinte tipo: Helicoptero
  // Essa função está sendo usada na criação e na edição de registros

  printf("Peso máximo em kg: ");
  scanf(" %d", &helicoptero->PesoMax);
}

  // Preenchimento de Helicoptero

void preencheHelicoptero (Helicoptero * helicoptero)
{
  preencheQntRotores(helicoptero);

  preencheAutonomiaHelicoptero(helicoptero);

  preenchePassageirosHelicoptero(helicoptero);

  preenchePesoMax(helicoptero);
}


  // Preenchimento dos campos de Barco

void preencheComprimento (Barco * barco)
{
  // Usada para os seguinte tipo: Barco
  // Essa função está sendo usada na criação e na edição de registros

  printf("Comprimento do barco em metros: ");
  scanf(" %d", &barco->Comprimento);
}

void preencheCasco (Barco * barco)
{
  // Usada para os seguinte tipo: Barco
  // Essa função está sendo usada na criação e na edição de registros

  printf("Material do casco: ");
  fgets(barco->Casco, sizeof(barco->Casco), stdin);
  barco->Casco[strcspn(barco->Casco, "\n")] = '\0';
}

void preenchePassageirosBarco (Barco * barco)
{
  // Usada para os seguinte tipo: Barco
  // Essa função está sendo usada na criação e na edição de registros

  printf("Quantidade máxima de passageiros: ");
  scanf(" %d", &barco->Passageiros);
}

void preencheAutonomiaBarco (Barco * barco)
{
  // Usada para os seguinte tipo: Barco
  // Essa função está sendo usada na criação e na edição de registros

  printf("Autonomia em km: ");
  scanf(" %f", &barco->Autonomia);
}

  // Preenchimento de Barco

void preencheBarco (Barco * barco)
{
  preencheComprimento(barco);
  getchar();

  preencheCasco(barco);
  
  preenchePassageirosBarco(barco);

  preencheAutonomiaBarco(barco);
}


  // Preenchimento de algum tipo específico

void preencheTipo (Registro * registro)
{
  // Preenche o tipo específico por completo

  switch (registro->Tipo)
  {
  case (moto):
    preencheMoto(&registro->moto); // Essas funções auxiliares recebem um ponteiro para a estrutura do respectivo veículo
    break;

  case (carro):
    preencheCarro(&registro->carro);
    break;  

  case (caminhao):
    preencheCaminhao(&registro->caminhao); 
    break;

  case (helicoptero):
    preencheHelicoptero(&registro->helicoptero);
    break;

  case (barco):
    preencheBarco(&registro->barco); 
    break;
  }
}


  // Preenchimento dos campos em comum a todos os tipos

void preencheRevisao (Registro * registro, int i)
{
  // assume-se 0 <= i <= 9
  printf("%d° revisão: ", i+1);
  fgets(registro->Revisoes[i], sizeof(registro->Revisoes[i]), stdin); // Captura toda o texto inserido pelo usuário (sem fazer split nos espaços)
  registro->Revisoes[i][strcspn(registro->Revisoes[i], "\n")] = '\0'; // Atribuindo ao último byte capturado pela função fgets() o terminador nulo ao invés da quebra de linha advinda do Enter pressionado pelo usuário ao enviar o texto
}

void preencheRevisoes (Registro * registro)
{

  // Inicializando com todas as revisões em branco
  for (int i = 0; i < 10; i ++)
  {
    registro->Revisoes[i][0] = '\0';
  }

  puts(""); // Apenas formatando como aparece no terminal

  int revisoes;
  printf("O veículo tem histórico de revisões?\n [0] Não\n [1] Sim\nInforme com o número correspondente: ");
  scanf(" %d", &revisoes);
  getchar(); // Usado entre scanf() e fgets() para permitir o fluxo correto

  puts("");

  if (revisoes)
  {

    int i = 0; int continua = 1;
    while ( (i < 10) && (continua) )
    {
      preencheRevisao(registro, i);
      
      puts("");

      i++;
      if (i == 10)
      {
        break;
      }

      printf("Deseja adicionar mais uma revisão? \n [0] Não\n [1] Sim\nInforme com o número correspondente: ");
      scanf(" %d", &continua);
      getchar();

      puts("");
    }
  }
}

void preencheMarca (Registro * registro)
{
  // Essa função está sendo usada na criação e na edição de registros

  printf("Marca: ");
  fgets(registro->Marca, sizeof(registro->Marca), stdin);
  registro->Marca[strcspn(registro->Marca, "\n")] = '\0';
}

void preencheModelo (Registro * registro)
{
  // Essa função está sendo usada na criação e na edição de registros

  printf("Modelo: ");
  fgets(registro->Modelo, sizeof(registro->Modelo), stdin);
  registro->Modelo[strcspn(registro->Modelo, "\n")] = '\0';
}

void preencheAnoFabricacao (Registro * registro)
{
  // Essa função está sendo usada na criação e na edição de registros

  printf("Ano de fabricação: ");
  scanf(" %d", &registro->AnoFabricacao);
}

void preencheCor (Registro * registro)
{
  // Essa função está sendo usada na criação e na edição de registros

  printf("Cor: ");
  fgets(registro->Cor, sizeof(registro->Cor), stdin);
  registro->Cor[strcspn(registro->Cor, "\n")] = '\0';
} 

void preenchePreco (Registro * registro)
{
  // Essa função está sendo usada na criação e na edição de registros

  printf("Preço: ");
  scanf(" %f", &registro->Preco);
}

void preencheObservacoes (Registro * registro)
{
  // Essa função está sendo usada na criação e na edição de registros

  printf("Observações: ");
  fgets(registro->Obs, sizeof(registro->Obs), stdin);
  registro->Obs[strcspn(registro->Obs, "\n")] = '\0';
} 

void preencheRegistro (Registro * registro)
{
  // assume-se que o usuário vai colocar o tipo certo, dentro das opções apresentadas
  // o ID é atribuído automaticamente ao registro

  printf("Informe o tipo de veículo que desejas registrar:\n [0] Moto\n [1] Carro\n [2] Caminhão\n [3] Helicóptero\n [4] Barco\nDigite o número correspondente: ");
  scanf(" %d", (int*)&registro->Tipo); // Usando esse cast para que o compilador trate esse enum type como int, pois é assim que está sendo usado no programa
  getchar(); // Consome o "\n" do buffer para o uso do fgets()

  puts(""); // Apenas para fins estéticos no terminal

  // Preenchimento dos registros comuns antes da union (tendo a struct em mente como base)

  preencheMarca(registro);

  preencheModelo(registro);

  preencheAnoFabricacao(registro);
  getchar();

  preencheCor(registro);

  preenchePreco(registro);

  // Como todos os primeiros campos de cada tipo são int, não faz-se necessário o uso do getchar(), visto que não há o uso do fgets() após scanf()
  preencheTipo(registro);

  preencheRevisoes(registro);

  // getchar() já está sendo utilizado na função preencheRevisoes() logo antes de entrar nesse nessa função de fgets()
  preencheObservacoes(registro);
}


  // Preenchimento de algum campo específico de algum tipo específico numa edição de registro

void preencheCampoTipo (Registro * registro, int subCampoTipo)
{
  // Função utilizada em editaRegistro()
  printf("\nInsira o novo valor desse campo\n");
  switch (registro->Tipo)
  {
  case (moto):
    switch (subCampoTipo)
    {
      case (cilindradas):
        preencheCilindradas(&registro->moto);
        break;

      case (freio):
        preencheFreio(&registro->moto);
        break;

      case (transmissao):
        preencheTransmissao(&registro->moto);
        break;
    }
    break;
  
  case (carro):
    switch (subCampoTipo)
    {
      case (portas):
        preenchePortas(&registro->carro);
        break;

      case (passageirosCarro):
        preenchePassageirosCarro(&registro->carro);
        break;

      case (cambio):
        preencheCambio(&registro->carro);
        break;
        
      case (tracao):
        preencheTracao(&registro->carro);
        break;
    }
    break;

  case (caminhao):
    switch (subCampoTipo)
    {
      case (cargaMax):
        preencheCargaMax(&registro->caminhao);
        break;
      
      case (qntEixos):
        preencheQntEixos(&registro->caminhao);
        break;
      
      case (carroceria):
        preencheCarroceria(&registro->caminhao);
        break;
    }
    break;

  case (helicoptero):
    switch (subCampoTipo)
    {
      case (qntRotores):
        preencheQntRotores(&registro->helicoptero);
        break;

      case (autonomiaHelicoptero):
        preencheAutonomiaHelicoptero(&registro->helicoptero);
        break;

      case (passageirosHelicoptero):
        preenchePassageirosHelicoptero(&registro->helicoptero);
        break;

      case (pesoMax):
        preenchePesoMax(&registro->helicoptero);
        break;
    }
    break;
  
  case (barco):
    switch (subCampoTipo)
    {
    case (comprimento):
      preencheComprimento(&registro->barco);
      break;
    
    case (casco):
      preencheCasco(&registro->barco);
      break;

    case (passageirosBarco):
      preenchePassageirosBarco(&registro->barco);
      break;

    case (autonomiaBarco):
      preencheAutonomiaBarco(&registro->barco);
      break;
    }
    break;
  }
}


  // Preenchimento de algum campo comum numa edição de registro

void preencheCampoComum (Registro * registro, int campo)
{
  if ( (campo != nenhum) && (campo != revisoes) )
  {
    printf("\nInsira o novo valor desse campo\n");
  }
  switch (campo)
  {
    case (nenhum):
      return; // Sai da função editaRegistro()

    case (marca):
      preencheMarca(registro);
      break;

    case (modelo):
      preencheModelo(registro);
      break;

    case (ano_fabricacao):
      preencheAnoFabricacao(registro);
      break;

    case (cor):
      preencheCor(registro);
      break;

    case (preco):
      preenchePreco(registro);
      break;

    case (revisoes):
      int subcampoRevisao; // Valores de 1 a 10
      printf("\nInforme qual revisão desejas editar: ");
      scanf(" %d", &subcampoRevisao);
      getchar();
      printf("\nInforme o novo valor do campo\n");
      preencheRevisao(registro, subcampoRevisao - 1);
      break;

    case (observacoes):
      preencheObservacoes(registro);
      break;
  }
}



// Exibição de Registro no Terminal


  // Exibição de cada tipo específico

void exibeMoto (Moto moto)
{
  printf(" Cilindradas: %d\n", moto.Cilindradas);

  printf(" Freio: %s\n", moto.Freio);

  printf(" Transmissão: %s\n", moto.Transmissao);
}

void exibeCarro (Carro carro)
{
  printf(" Portas: %d\n", carro.QntPortas);

  printf(" Passageiros: %d\n", carro.Passageiros);

  printf(" Câmbio: %s\n", carro.Cambio);

  printf(" Tração: %s\n", carro.Tracao);
}

void exibeCaminhao (Caminhao caminhao)
{
  printf(" Carga máxima: %d\n", caminhao.CargaMax);

  printf(" Eixos: %d\n", caminhao.QntEixos);

  printf(" Carroceria: %s\n", caminhao.Carroceria);
}

void exibeHelicoptero (Helicoptero helicoptero)
{
  printf(" Rotores: %d\n", helicoptero.QntRotores);

  printf(" Autonomia em km: %.2f\n", helicoptero.Autonomia);

  printf(" Passageiros: %d\n", helicoptero.Passageiros);

  printf(" Peso máximo em kg: %d\n", helicoptero.PesoMax);
}

void exibeBarco (Barco barco)
{
  printf(" Comprimento em metros: %d\n", barco.Comprimento);

  printf(" Casco: %s\n", barco.Casco);

  printf(" Passageiros: %d\n", barco.Passageiros);

  printf(" Autonomia em km: %.2f\n", barco.Autonomia);
}


  // Exibição de algum tipo específico

void exibeNomeTipo (Registro registro)
{
  printf("Tipo de veículo: ");
  switch (registro.Tipo)
  {
  case (moto):
    printf("Moto\n");
    break;

  case (carro):
    printf("Carro\n");
    break;
  
  case (caminhao):
    printf("Caminhão\n");
    break;

  case (helicoptero):
    printf("Helicóptero\n");
    break;

  case (barco):
    printf("Barco\n");
    break;
  }
}

void exibeTipo (Registro registro)
{
  switch (registro.Tipo)
  {
  case (moto):
    exibeMoto(registro.moto);
    break;

  case (carro):
    exibeCarro(registro.carro);
    break;
  
  case (caminhao):
    exibeCaminhao(registro.caminhao);    
    break;

  case (helicoptero):
    exibeHelicoptero(registro.helicoptero);
    break;

  case (barco):
    exibeBarco(registro.barco);
    break;
  }
}


  // Exibição em comum a todos os tipos

void exibeRevisoes (Registro registro)
{
  printf(" Revisões\n");
  for (int i = 0; i < 10; i++)
  {
    printf("  %d° revisão: %s\n", i+1, registro.Revisoes[i]);
  }
}

void exibeRegistro (Registro registro)
{
  // Assume-se que o registro existe e está ativo
  printf("\nInformações do Registro de ID-%d\n", registro.ID);
  
  exibeNomeTipo(registro);

  printf(" Marca: %s\n", registro.Marca);

  printf(" Modelo: %s\n", registro.Modelo);

  printf(" Ano de fabricação: %d\n", registro.AnoFabricacao);

  printf(" Cor: %s\n", registro.Cor);

  printf(" Preço: %.2f\n", registro.Preco);
  
  exibeTipo(registro);

  exibeRevisoes(registro);

  printf(" Observações: %s\n", registro.Obs);
}


  // Exibição dos campos específicos de cada tipo para a função de edição de registro

void exibeCamposMoto (void)
{
  // Essa função está sendo usada na edição de registros

  printf (" [%d] Cilindradas\n", cilindradas);
  printf (" [%d] Freio\n", freio);
  printf (" [%d] Transmissão\n", transmissao);
}

void exibeCamposCarro (void)
{
  // Essa função está sendo usada na edição de registros

  printf (" [%d] Portas\n", portas);
  printf (" [%d] Passageiros\n", passageirosCarro);
  printf (" [%d] Câmbio\n", cambio);
  printf (" [%d] Tração\n", tracao);
}

void exibeCamposCaminhao (void)
{
  // Essa função está sendo usada na edição de registros

  printf (" [%d] Carga Máxima\n", cargaMax);
  printf (" [%d] Eixos\n", qntEixos);
  printf (" [%d] Carroceria\n", carroceria);
}

void exibeCamposHelicoptero (void)
{
  // Essa função está sendo usada na edição de registros

  printf (" [%d] Rotores\n", qntRotores);
  printf (" [%d] Autonomia\n", autonomiaHelicoptero);
  printf (" [%d] Passageiros\n", passageirosHelicoptero);
  printf (" [%d] PesoMax\n", pesoMax);
}

void exibeCamposBarco (void)
{
  // Essa função está sendo usada na edição de registros

  printf (" [%d] Comprimento\n", comprimento);
  printf (" [%d] Casco\n", casco);
  printf (" [%d] Passageiros\n", passageirosBarco);
  printf (" [%d] Autonomia\n", autonomiaBarco);
}


  // Exibição dos campos de algum tipo específico para a função de edição de registro

void exibeCamposTipo (Registro * registro)
{
  // Verifica qual é o tipo do registro para exibir apenas os campos específicos de cada tipo

  switch (registro->Tipo)
  {
    case (moto):
      exibeCamposMoto();
      break;
    
    case (carro):
      exibeCamposCarro();
      break;

    case (caminhao):
      exibeCamposCaminhao();
      break;

    case (helicoptero):
      exibeCamposHelicoptero();
      break;

    case (barco):
      exibeCamposBarco();
      break;
  }
}


  // Exibição dos campos em comum a todos os tipo

void exibeCampos (void)
{
  printf(" [%d] Nenhum\n", nenhum);
  printf(" [%d] Marca\n", marca);
  printf(" [%d] Modelo\n", modelo);
  printf(" [%d] Ano de fabricação\n", ano_fabricacao);
  printf(" [%d] Cor\n", cor);
  printf(" [%d] Preço\n", preco);
  printf(" [%d] Revisões\n", revisoes); //Se revisões, perguntar qual revisão
  printf(" [%d] Observações\n", observacoes);
  printf(" [%d] Algum campo específico do tipo de veículo\n", subcampo);
}



// Criação de Registro no Arquivo

void verifica_UltimoID (int * ultimoID) // Função necessária para receber o último ID do arquivo
{
  FILE* f = fopen(ARQUIVO, "rb");
  
  if (f == NULL) // Se não existir o arquivo, ou seja, se não houver registros
  {
    *ultimoID = 0;
    return;
  }
  else // Se existir, pode ou estar vazio ou realmente com registros
  {
    // Verificando o tamanho do arquivo
    rewind(f); // Garantindo que nenhuma flag esteja ativa
    fseek(f, 0, SEEK_END); // Movendo o cursor do arquivo para o final
    long tamanhoArquivo = ftell(f);
   
    if (tamanhoArquivo == 0) // Se existe, mas com tamanho 0
    {
      *ultimoID = 0;
    }
    else // Se realmente existem registros nele
    {
      Registro ultimoRegistro; // Usando uma variável para evitar que aconteça segmentation fault ao usar fread
      fseek(f, (long int) -sizeof(Registro), SEEK_END);
      fread(&ultimoRegistro, sizeof(Registro), 1, f);
      *ultimoID = ultimoRegistro.ID;
    }
  
    fclose(f); // Fechando o arquivo apenas para f != NULL
  }
}

void criaRegistro (Registro * registro, int * ultimoID)
{
  FILE* f = fopen(ARQUIVO, "ab+"); // Abrindo o arquivo em modo binário appen
  
  if (f == NULL) // Verificando se o arquivo pode ser aberto.
  {
    perror("Erro ao abrir o arquivo de registros.");
    return;
  }

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
  // Atribuindo valores para os demais campos do registro
  preencheRegistro(registro); // Usuário preenche, normalmente, outros campos
  fwrite(registro, sizeof(Registro), 1, f); // Escreve (com append) esse registro para o arquivo
  fclose(f); // Fecha o arquivo para garantir que o buffer registro tenha sido gravado
  printf("\nRegistro criado com sucesso! O ID desse registro é: %d\n", registro->ID);
}



// Busca de Registro no Arquivo

long buscaRegistro (Registro * registro, int ID_Busca)
{
  // Assume-se que o usuário já informou o ID do registro antes de entrar nessa função
  // variável paraRemocao serve para não exibir o registro caso seja com o intuito de removê-lo
  // Retorna o ponteiro do cursor do arquivo para a posição do registro encontrado caso ele exista e esteja ativo ou -1 caso não exista ou não esteja mais ativo
  // && Preenche a variável registro passada para função com o registro obtido pela busca (estando ativa ou não) ou sai da função com uma mensagem de erro
  // Fazendo dessa maneira para utilizá-la tanto na própria busca de registro quanto na edição ou remoção de registro
  long posicaoRegistro = -1; // Variável que vai ser retornada pela função, pois representa a posição inicial do arquivo encontrado ou NULL
  registro->ID = -1; // "Garantindo" que não ocorra nenhum mal entendido entre os IDs que o usuário passou e o que está gravado na variável passada para função
  FILE* f = fopen(ARQUIVO, "rb"); // Abrindo o arquivo em modo binário de leitura apenas para leitura
  if (f == NULL) // Verificando se o arquivo pode ser aberto. Caso não possa, sai da função.
  {
    perror("Erro ao abrir o arquivo de registros.");
    return posicaoRegistro; // Retornando -1
  }
  int encontrado = 0; // Para saber se o registro foi encontrado
  while (fread(registro, sizeof(Registro), 1, f) == 1) // Enquanto não há erros de leituras (fread() != 0), procura um registro que tenha ID igual ao que foi passado pelo usuário
  {
    if (registro->ID == ID_Busca)
    {
      encontrado = 1;
      break; // Saindo do loop, visto que encontrou o registro
    }
  }
  if (encontrado)
  {
    if (registro->Ativo == 0)
    {
      printf("\nEsse registro não está mais ativo na base de dados.\n");
      return posicaoRegistro;
    }
    else
    {
      if (registro->Ativo == 1)
      {
        // Cursor do arquivo encontra-se na última posição do registro obtido pela busca
        fseek(f, (long int) -sizeof(Registro), SEEK_CUR); // Voltando para a posição inicial desse registro 
        posicaoRegistro = ftell(f); // Atribuindo essa posição para a variável que será retornada
      }
    }
  }
  else // Caso tenha ido até o final sem êxito
  {
    printf("\nEsse registro não consta na base de dados.\n");
  }

  fclose(f);
  return posicaoRegistro; // Retorna a posição correta apenas se o registro for encontrado e estiver ativo, Caso contrário retorna -1 Se não tenha sido possível abrir o arquivo OU Se o registro não existir na base de dados OU Se o registro não estiver mais ativo na base de dados
}

void Busca (Registro * registro)
{
  int ID_Busca;
  printf("Informe o ID do registro que desejas acessar: ");
  scanf(" %d", &ID_Busca);

  long posicaoRegistro = buscaRegistro(registro, ID_Busca);
  
  if (posicaoRegistro == -1)
  {
    return;
  }
  
  exibeRegistro(*registro);
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
  if (campo != nenhum)
  {
    printf("\nEdição de registro realizada com sucesso!\n");
  }
}



// Remoção de Registro no Arquivo

void removeRegistro (Registro * registro)
{
  // Assume-se que o usuário sabe o ID do registro que pretende remover

  int ID_Busca;
  printf("Informe o ID do registro que desejas remover: ");
  scanf(" %d", &ID_Busca);

  int posicaoRegistro = buscaRegistro(registro, ID_Busca);

  if (posicaoRegistro == -1)
  {
    return; // A função busca já informou a não ocorrência desse registro, então é só sair dessa função
  }

  // Caso chegue nessa parte, podemos garantir que o registro existe e está ativo
  registro->Ativo = 0;

  FILE* f = fopen(ARQUIVO, "rb+"); // Abre o arquivo em modo binário de leitura para leitura e escrita

  // Como a função busca já foi utilizada, podemos garantir que o arquivo existe. Se não existisse, a função já teria sido retornada

  fseek(f, posicaoRegistro, SEEK_SET); // Posiciona para a posição inicial do registro, agora já removido (registro->Ativo == 0)

  fwrite(registro, sizeof(Registro), 1, f);

  fclose(f);


  printf("\nRemoção de registro realizada com sucesso!\n");
}



// Fluxo do sitema

void limpaTerminal (void)
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

void exibeOpcoes (Registro * registro, int * ultimoID)
{
  int acao;
  printf("Qual ação desejas realizar?\n [%d] Criação de Registro\n [%d] Busca de Registro\n [%d] Edição de Registro\n [%d] Remoção de Registro\n [%d] Sair\nInforme com o número correspondente: ", criacao, busca, edicao, remocao, sair);
  scanf(" %d", &acao);
  puts("");

  while (acao != sair)
  {
    switch (acao)
    {
      case (criacao):
        criaRegistro(registro, ultimoID);
        break;

      case (busca):
        Busca(registro);
        break;
      
      case (edicao):
        editaRegistro(registro);
        break;

      case (remocao):
        removeRegistro(registro);
        break;
    }
    puts(""); // Apenas para fins de estética no terminal

    int retorno = -1;
    printf("Digite [0] para retornar à tela de opções: ");
    scanf(" %d", &retorno); // Congelando a tela para que o usuário possa ver o que fez até que decida voltar para a tela de opções 

    limpaTerminal();

    printf("Qual ação desejas realizar?\n [%d] Criação de Registro\n [%d] Busca de Registro\n [%d] Edição de Registro\n [%d] Remoção de Registro\n [%d] Sair\nInforme com o número correspondente: ", criacao, busca, edicao, remocao, sair);
    scanf(" %d", &acao);
    puts("");
  }

  limpaTerminal(); // Limpando o terminal antes de finalizar o programa para que apenas a mensagem de despedida apareça.
}

void Opcoes (void)
{
  // Inicializando a aplicação

  Registro registro; // Variável auxiliar que será utilizada em todas as operações, apenas de forma pontual
  int ultimoID = -1; // Por mais que a função verifica_UltimoID() abaixo verifique e atribua o valor correto para essa variável, ela está sendo inicializada como -1 para evitar lixos de memória.

  verifica_UltimoID(&ultimoID);


  // Exibindo as opções

  exibeOpcoes(&registro, &ultimoID);
}

