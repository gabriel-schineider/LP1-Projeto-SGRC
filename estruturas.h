#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#define TAM 32 // Tamanho da maior parte dos tipos textos. Sempre colocando-os com tamanho múltiplo de 4 para evitar incoveniências
#define ARQUIVO "RegistrosConcessionaria.bin" // Arquivo padrão que será utilizado e gerenciado pelo sistema ao longo da aplicação
#define INDICE_INICIO 800 //no maximo 100 entradas--> 100 pares de 2 ints no indice no inicio do arquivo, cada um com 4 bytes.
#define NULO -1 //referente a indices apagados

typedef enum Tipo
{
  moto,
  carro,
  caminhao,
  helicoptero,
  barco
} Tipo;

typedef struct Moto
{
  int Cilindradas;
  char Freio[TAM];
  char Transmissao[TAM];
} Moto;

typedef struct Carro
{
  int QntPortas;
  int Passageiros;
  char Cambio[TAM];
  char Tracao[TAM];
} Carro;

typedef struct Caminhao
{
  int CargaMax;
  int QntEixos;
  char Carroceria[TAM];
} Caminhao;

typedef struct Helicoptero
{
  int QntRotores;
  float Autonomia;
  int Passageiros;
  int PesoMax;
} Helicoptero;

typedef struct Barco
{
  int Comprimento;
  char Casco[TAM];
  int Passageiros;
  float Autonomia;
} Barco;

typedef struct Registro
{
  int ID; // Para ser utilizado no arquivo
  int indice; // Adicioná-lo futuramente para ser utilizado no arquivo ?
  int Ativo; // Para saber se está ativo (se Ativo == 1) ou se foi removido (se Ativo == 0)
  Tipo Tipo;
  char Marca[TAM];
  char Modelo[TAM];
  int AnoFabricacao;
  char Cor[TAM];
  float Preco;
  union // A identificação ocorre nas funções por meio do Tipo atribuído ao Registro
  {
    Moto moto;
    Carro carro;
    Caminhao caminhao;
    Helicoptero helicoptero;
    Barco barco;
  };
  char Revisoes[10][88]; // A concessionária informou que deseja ter controle apenas das primeiras 10 revisões gratuitas que ela oferece
  char Obs[88];
} Registro;



// Estruturas Enum utilizadas na função editaRegistro()

typedef enum Campos
{
  // Usado na função editaRegistro();

  nenhum,
  marca,
  modelo,
  ano_fabricacao,
  cor,
  preco,
  revisoes,
  observacoes,
  subcampo
} Campo;

typedef enum CamposMoto
{
  // Usado na função editaRegistro();

  cilindradas,
  freio,
  transmissao
} CamposMoto;

typedef enum CamposCarro
{
  // Usado na função editaRegistro();

  portas,
  passageirosCarro,
  cambio,
  tracao
} CamposCarro;

typedef enum CamposCaminhao
{
  // Usado na função editaRegistro();

  cargaMax,
  qntEixos,
  carroceria
} CamposCaminhao;

typedef enum CamposHelicoptero
{
  // Usado na função editaRegistro();

  qntRotores,
  autonomiaHelicoptero,
  passageirosHelicoptero,
  pesoMax
} CamposHelicoptero;

typedef enum CamposBarco
{
  // Usado na função editaRegistro();

  comprimento,
  casco,
  passageirosBarco,
  autonomiaBarco
} CamposBarco;



// Estrutura Enum utilizada na função exibeOpcoes()

typedef enum Acao
{
  criacao,
  busca,
  edicao,
  remocao,
  sair
} Acao;



#endif