#include <stdio.h>
#include "/home/ime/LP1-Projeto-SGRC/include/entrada_struct.h"
#include "/home/ime/LP1-Projeto-SGRC/include/ler_arq.h"
#include "/home/ime/LP1-Projeto-SGRC/include/escrita_arq.h"

int main ()
{
    ENTRADA_FINAL registros_teste[6];

    // vou criar um loop para add cada registro à uma posição

    puts("Qual é a entrada ? ");
    char entrada[12];
    scanf("%11s", entrada);

    if (entrada == "moto")
    {
    ENTRADA_FINAL moto;
    int ARR_TIPOS[] = {100, 0, 0, 0}; // ID ; APAGADO ; classe ; subclasse 
    int nomes[4][ESPACO];
    strncpy(nomes[0], "Motinha", ESPACO); // nome
    strncpy(nomes[1], "Preta", ESPACO); // cor
    strncpy(nomes[2], "Gasolina", ESPACO); // combustivel
    strncpy(nomes[3], "Couro", ESPACO); // guidom
    int arr[] =  {8500, 1, {8, 12}}; // preco ; offroad ; pressao_ideal[2]
    }

    if (entrada == "carro")
    {
    ENTRADA_FINAL carro;
    int ARR_TIPOS[] = {101, 0, 0, 1}; // ID ; APAGADO ; classe ; subclasse 
    int nomes[3][ESPACO];
    strncpy(nomes[0], "Carrinho", ESPACO); // nome
    strncpy(nomes[1], "Cinza", ESPACO); // cor
    strncpy(nomes[2], "Gasolina", ESPACO); // combustivel
    int arr[] =  {18500, 4, 4, 1, {8, 8, 12, 12}}; // preco ; tracao ; portas ; eletrico ; pressao_ideal[4]
    }

    if (entrada == "barco")
    {
    ENTRADA_FINAL barco;
    int ARR_TIPOS[] = {102, 0, 0, 2}; // ID ; APAGADO ; classe ; subclasse 
    int nomes[4][ESPACO];
    strncpy(nomes[0], "Barquinho", ESPACO); // nome
    strncpy(nomes[1], "Branco", ESPACO); // cor
    strncpy(nomes[2], "Gasolina", ESPACO); // combustivel
    strncpy(nomes[3], "Amadeirado", ESPACO); // tipo_casco
    int arr[] =  {958500, 250, 320}; // preco ; litragem ; vel_aq_max
    }

    if (entrada == "helicoptero")
    {
    ENTRADA_FINAL helicoptero;
    int ARR_TIPOS[] = {103, 0, 0, 3}; // ID ; APAGADO ; classe ; subclasse 
    int nomes[4][ESPACO];
    strncpy(nomes[0], "Helicopterozinho", ESPACO); // nome
    strncpy(nomes[1], "Preto", ESPACO); // cor
    strncpy(nomes[2], "Gasolina", ESPACO); // combustivel
    int arr[] =  {1518500, 6, 6, 6000}; // preco ; pas ; passageiros ; altitude_max
    }

    if ("entrada" == "bike")
    {
    ENTRADA_FINAL bike;
    int ARR_TIPOS[] = {200, 0, 1, 0}; // ID ; APAGADO ; classe ; subclasse 
    int nomes[4][ESPACO];
    strncpy(nomes[0], "Bikezinha", ESPACO); // nome
    strncpy(nomes[1], "Vermelha", ESPACO); // cor
    strncpy(nomes[2], "Vintage", ESPACO); // modelo
    strncpy(nomes[3], "Alta", ESPACO); // suspensao
    int arr[] =  {1200, 50, 6};  // preco ; diam_roda ; marchas
    }

    if ("entrada" == "skate")
    {
    ENTRADA_FINAL skate;
    int ARR_TIPOS[] = {201, 0, 1, 1}; // ID ; APAGADO ; classe ; subclasse 
    int nomes[4][ESPACO];
    strncpy(nomes[0], "Skatezinho", ESPACO); // nome
    strncpy(nomes[1], "Preto", ESPACO); // cor
    strncpy(nomes[2], "Street", ESPACO);// modelo
    strncpy(nomes[3], "Borracha", ESPACO); // tipo_roda
    int arr[] =  {1200, 110, 10}; // preco ; comprimento ; diam_roda
    }

    // vou usar esses registros para testas as funções

    return 0;
}
