#ifndef FUNCOES_H
#define FUNCOES_H


// Inclusões das bibliotecas utilizadas e arquivos utilizados no programa

#include "estruturas.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Funções de Preenchimento de Registro pelo Terminal

void preencheCilindradas (Moto * moto);
void preencheFreio (Moto * moto);
void preencheTransmissao (Moto * moto);
void preencheMoto (Moto * moto);

void preenchePortas (Carro * carro);
void preenchePassageirosCarro (Carro * carro);
void preencheCambio (Carro * carro);
void preencheTracao (Carro * carro);
void preencheCarro (Carro * carro);

void preencheCargaMax (Caminhao * caminhao);
void preencheQntEixos (Caminhao * caminhao);
void preencheCarroceria (Caminhao * caminhao);
void preencheCaminhao (Caminhao * caminhao);

void preencheQntRotores (Helicoptero * helicoptero);
void preencheAutonomiaHelicoptero (Helicoptero * helicoptero);
void preenchePassageirosHelicoptero (Helicoptero * helicoptero);
void preenchePesoMax (Helicoptero * helicoptero);
void preencheHelicoptero (Helicoptero * helicoptero);

void preencheComprimento (Barco * barco);
void preencheCasco (Barco * barco);
void preenchePassageirosBarco (Barco * barco);
void preencheAutonomiaBarco (Barco * barco);
void preencheBarco (Barco * barco);

void preencheTipo (Registro * registro);

void preencheRevisao (Registro * registro, int i);
void preencheRevisoes (Registro * registro);
void preencheMarca (Registro * registro);
void preencheModelo (Registro * registro);
void preencheAnoFabricacao (Registro * registro);
void preencheCor (Registro * registro);
void preenchePreco (Registro * registro);
void preencheObservacoes (Registro * registro);

void preencheRegistro (Registro * registro);

void preencheCampoTipo (Registro * registro, int subCampoTipo);

void preencheCampoComum (Registro * registro, int campo);



// Funções de Exibição de Registro no Terminal

void exibeMoto (Moto moto);
void exibeCarro (Carro carro);
void exibeCaminhao (Caminhao caminhao);
void exibeHelicoptero (Helicoptero helicoptero);
void exibeBarco (Barco barco);

void exibeNomeTipo (Registro registro);
void exibeTipo (Registro registro);

void exibeRevisoes (Registro registro);

void exibeRegistro (Registro registro);

void exibeCamposMoto (void);
void exibeCamposCarro (void);
void exibeCamposCaminhao (void);
void exibeCamposHelicoptero (void);
void exibeCamposBarco (void);

void exibeCamposTipo (Registro * registro);

void exibeCampos (void);



// Funções de Criação de Registro no Arquivo

int verifica_UltimoID ();
void criaRegistro (Registro * registro, int* ultimoID);
int pegarUltimoID(void);
void inicializa(void);
int IndiceMax(FILE* f);


// Funções de Busca de Registro no Arquivo

long buscaRegistro (Registro * registro, int ID_Busca);
void Busca (Registro * registro);
int indice_P_ID(FILE* f, int indice);
int pegaIndice(int ID,FILE* f);


// Funções de Edição de Registro no Arquivo

void editaRegistro (Registro * registro);



// Funções de Remoção de Registro no Arquivo

void removeRegistro (Registro * registro);



// Funções de Fluxo de Sistema

void limpaTerminal (void);
void exibeOpcoes (Registro * registro, int * ultimoID);
void Opcoes (void);



#endif