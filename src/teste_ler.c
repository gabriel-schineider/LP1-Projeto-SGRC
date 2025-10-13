#include <stdio.h>
#include "C:\\LP1\\concessionaria\\repositorio\\include\\ler_arq.h"
#include "C:\\LP1\\concessionaria\\repositorio\\include\\escrita_arq.h"

int main(void){
    FILE* arquivo=fopen("C:\\LP1\\concessionaria\\repositorio\\src\\testes.bin","rb+");
    ENTRADA_FINAL teste;
    leEntrada(&teste,0,arquivo);
    ExibeEntrada(teste);
    fclose(arquivo);
    return 0;
}