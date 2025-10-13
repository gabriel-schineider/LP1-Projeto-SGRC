#include <stdio.h>
#include "C:\\LP1\\concessionaria\\repositorio\\include\\ler_arq.h"
#include "C:\\LP1\\concessionaria\\repositorio\\include\\escrita_arq.h"

int main(void){
    FILE* arquivo=fopen("C:\\LP1\\concessionaria\\repositorio\\src\\testes.bin","rb+");
    char nomes[4][ESPACO];
    int tipo=moto;
    char guidom[]="Borracha legal";
    int pressao[]={3000,30,28};
    char cor[]="Vermelho";
    char nome[]="Moto Bukowski";
    char combustivel[]="Gasolina normal";
    strncpy(nomes[0],nome,ESPACO);
    strncpy(nomes[1],cor,ESPACO);
    strncpy(nomes[2],combustivel,ESPACO);
    strncpy(nomes[3],guidom,ESPACO);
    int ARR_TIPOS[]={0,nao,motorizado,tipo};
    ENTRADA_FINAL teste;
    preenche_ENTRADA(&teste,ARR_TIPOS,pressao,nomes);
    ExibeEntrada(teste);
    EscreverEntrada(teste,arquivo);
    fclose(arquivo);
    return 0;
}