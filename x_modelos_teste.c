#include <stdio.h>
#include "include/escrita_arq.h"
#include "include/ler_arq.h"
#include "include/escrita_arq.h"
#include "include/remover_registro.h"
#include "include/editar_cria_registro.h"

void CriarRegistro(FILE* arquivo){
    puts("Entre 0 p moto, 1 p carro, 2 p barco, 3 p helicoptero, 4 p bike, 5 p skate ? ");
    int entrada_USER;
    scanf("%d", &entrada_USER);

    int ID=pegarUltimoID(arquivo)+1; //pega o ultimo ID do arquivo, e adiciona um a mais para criar um novo registro
    int indice=IndiceMax(arquivo)+1; //pega o maior indice do arquivo, e adiciona +1
    ENTRADA_FINAL moto;
    int ARR_TIPOS[] = {ID,indice,0, 0, 0}; // ID ; indice; APAGADO ; classe ; subclasse 
    char nomes[4][ESPACO];
    strncpy(nomes[0], "Motinha", ESPACO); // nome
    strncpy(nomes[1], "Preta", ESPACO); // cor
    strncpy(nomes[2], "Gasolina", ESPACO); // combustivel
    strncpy(nomes[3], "Couro", ESPACO); // guidom
    int arr[] =  {8500, 1, 8, 12}; // preco ; offroad ; pressao_ideal[2]
    PreencheEntrada(&moto,ARR_TIPOS,arr,nomes);

    ENTRADA_FINAL carro;
    int ARR_TIPOS_1[] = {ID, indice,0, motorizado_ENUM, carro_ENUM}; // ID ; APAGADO ; classe ; subclasse 
    char nomes_1[3][ESPACO];
    strncpy(nomes_1[0], "Carrinho", ESPACO); // nome
    strncpy(nomes_1[1], "Cinza", ESPACO); // cor
    strncpy(nomes_1[2], "Gasolina", ESPACO); // combustivel
    int arr_1[] =  {18500, 4, 4, 1, 8, 8, 12, 12}; // preco ; tracao ; portas ; eletrico ; pressao_ideal[4]
    PreencheEntrada(&carro,ARR_TIPOS_1,arr_1,nomes_1);

    ENTRADA_FINAL barco;
    int ARR_TIPOS_2[] = {ID, indice,0, 0, 2}; // ID ; APAGADO ; classe ; subclasse 
    char nomes_2[4][ESPACO];
    strncpy(nomes_2[0], "Barquinho", ESPACO); // nome
    strncpy(nomes_2[1], "Branco", ESPACO); // cor
    strncpy(nomes_2[2], "Gasolina", ESPACO); // combustivel
    strncpy(nomes_2[3], "Amadeirado", ESPACO); // tipo_casco
    int arr_2[] =  {958500, 250, 320}; // preco ; litragem ; vel_aq_max
    PreencheEntrada(&barco,ARR_TIPOS_2,arr_2,nomes_2);
    
    ENTRADA_FINAL helicoptero;
    int ARR_TIPOS_3[] = {ID, indice,0, 0, 3}; // ID ; APAGADO ; classe ; subclasse 
    char nomes_3[4][ESPACO];
    strncpy(nomes_3[0], "Helicopterozinho", ESPACO); // nome
    strncpy(nomes_3[1], "Preto", ESPACO); // cor
    strncpy(nomes_3[2], "Gasolina", ESPACO); // combustivel
    int arr_3[] =  {1518500, 6, 6, 6000}; // preco ; pas ; passageiros ; altitude_max
    PreencheEntrada(&helicoptero,ARR_TIPOS_3,arr_3,nomes_3);

    ENTRADA_FINAL bike;
    int ARR_TIPOS_4[] = {ID,indice, 0, 1, 0}; // ID ; APAGADO ; classe ; subclasse 
    char nomes_4[4][ESPACO];
    strncpy(nomes_4[0], "Bikezinha", ESPACO); // nome
    strncpy(nomes_4[1], "Vermelha", ESPACO); // cor
    strncpy(nomes_4[2], "Vintage", ESPACO); // modelo
    strncpy(nomes_4[3], "Alta", ESPACO); // suspensao
    int arr_4[] =  {1200, 50, 6};  // preco ; diam_roda ; marchas
    PreencheEntrada(&bike,ARR_TIPOS_4,arr_4,nomes_4);


    ENTRADA_FINAL skate;
    int ARR_TIPOS_5[] = {ID, indice, 0, 1, 1}; // ID ; APAGADO ; classe ; subclasse 
    char nomes_5[4][ESPACO];
    strncpy(nomes_5[0], "Skatezinho", ESPACO); // nome
    strncpy(nomes_5[1], "Preto", ESPACO); // cor
    strncpy(nomes_5[2], "Street", ESPACO);// modelo
    strncpy(nomes_5[3], "Borracha", ESPACO); // tipo_roda
    int arr_5[] =  {1200, 110, 10}; // preco ; comprimento ; diam_roda
    PreencheEntrada(&skate,ARR_TIPOS_5,arr_5,nomes_5);
    
    switch (entrada_USER){
        case 0:
            EscreverEntrada(moto,arquivo);
            ExibeEntrada(moto);
            break;
        case 1:
            EscreverEntrada(carro, arquivo);
            ExibeEntrada(carro);
            break;
        case 2:
            EscreverEntrada(barco,arquivo);
            ExibeEntrada(barco);
            break;
        case 3:
            EscreverEntrada(bike,arquivo);
            ExibeEntrada(moto);
            break;
        case 4:
            EscreverEntrada(skate,arquivo);
            ExibeEntrada(moto);
            break;
        default:
            printf("Deu errado(provavelmente input errado)\n");
    }


}

int main ()
{
    ENTRADA_FINAL registros_teste[6];
    FILE* arquivo=fopen("C:\\LP1\\concessionaria\\repositorio\\testes.bin","rb+");

    // vou criar um loop para add cada registro à uma posição

    //Loop infinito de acao, tirado diretamente do fluxo, so que com funcoes em sua forma bruta
    int termino=0;
    while(!termino){
        puts("Opções:\n [1] Criar registro\n [2] Buscar registro\n [3] Editar registro\n [4] Remover registro\n [5] Sair");
        puts("Digite o número da opção escolhida: ");
        int escolha;
        scanf("%d", &escolha);
        int id;
        switch (escolha)
        {
            case(1):
                CriarRegistro(arquivo); //IDs sao crescentes, entao tem que ir ate o final do arquivo, pegar ultima e adicionar uma com ID+1
                break;
            case(2): //teste de busca de arquivos
                printf("Qual id voce quer procurar no arquivo?");
                scanf("%d",&id);
                ENTRADA_FINAL amostra;
                LeEntrada(&amostra,id,arquivo);
                ExibeEntrada(amostra);
                break;
            case(3):
                EditarRegistro(arquivo); //editar um dado registro, definido em outro modulo 
                break;
            
            case(4):
                printf("Qual id voce quer remover do arquivo?");
                scanf("%d",&id);
                int indice=pegaIndice(id,arquivo);
                RemoverRegistro(indice,arquivo); //estou abusando do fato que isso tambem consegue deletar
                break;

            case(5):
                termino=1; //
                break;

            default:
                puts("Input nao reconhecido, saindo do loop de acao");
                termino=1;
        }
    }
    fclose(arquivo);
    // vou usar esses registros para testar as funções

    return 0;
}
