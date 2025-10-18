#include <stdio.h>
#include "C:\\LP1\\concessionaria\\repositorio\\include\\escrita_arq.h"
#include "C:\\LP1\\concessionaria\\repositorio\\include\\ler_arq.h"
#include "C:\\LP1\\concessionaria\\repositorio\\include\\escrita_arq.h"
#include "C:\LP1\concessionaria\repositorio\include\remover_registro.h"

void CriarRegistro(arquivo){
    puts("Entre 0 p moto, 1 p carro, 2 p barco, 3 p helicoptero, 4 p bike, 5 p skate ? ");
    int entrada_USER;
    scanf("%d", &entrada_USER);

    int ID=pegarUltimoID(arquivo)+1; //pega o ultimo ID do arquivo, e adiciona um a mais para criar um novo registro
    int indice=IndiceMax(arquivo)+1; //pega o maior indice do arquivo, e adiciona +1
    ENTRADA_FINAL moto;
    int ARR_TIPOS[] = {ID,indice,0, 0, 0}; // ID ; indice; APAGADO ; classe ; subclasse 
    int nomes[4][ESPACO];
    strncpy(nomes[0], "Motinha", ESPACO); // nome
    strncpy(nomes[1], "Preta", ESPACO); // cor
    strncpy(nomes[2], "Gasolina", ESPACO); // combustivel
    strncpy(nomes[3], "Couro", ESPACO); // guidom
    int arr[] =  {8500, 1, {8, 12}}; // preco ; offroad ; pressao_ideal[2]
    PreencheEntrada(&moto,ARR_TIPOS,arr,nomes);
    ExibeEntrada(moto); //mostra a entrada a ser escrita

    ENTRADA_FINAL carro;
    int ARR_TIPOS[] = {ID, indice,0, motorizado_ENUM, carro_ENUM}; // ID ; APAGADO ; classe ; subclasse 
    int nomes[3][ESPACO];
    strncpy(nomes[0], "Carrinho", ESPACO); // nome
    strncpy(nomes[1], "Cinza", ESPACO); // cor
    strncpy(nomes[2], "Gasolina", ESPACO); // combustivel
    int arr[] =  {18500, 4, 4, 1, {8, 8, 12, 12}}; // preco ; tracao ; portas ; eletrico ; pressao_ideal[4]
    PreencheEntrada(&carro,ARR_TIPOS,arr,nomes);
    ExibeEntrada(carro);

    ENTRADA_FINAL barco;
    int ARR_TIPOS[] = {ID, indice,0, 0, 2}; // ID ; APAGADO ; classe ; subclasse 
    int nomes[4][ESPACO];
    strncpy(nomes[0], "Barquinho", ESPACO); // nome
    strncpy(nomes[1], "Branco", ESPACO); // cor
    strncpy(nomes[2], "Gasolina", ESPACO); // combustivel
    strncpy(nomes[3], "Amadeirado", ESPACO); // tipo_casco
    int arr[] =  {958500, 250, 320}; // preco ; litragem ; vel_aq_max
    PreencheEntrada(&barco,ARR_TIPOS,arr,nomes);
    
    ENTRADA_FINAL helicoptero;
    int ARR_TIPOS[] = {ID, indice,0, 0, 3}; // ID ; APAGADO ; classe ; subclasse 
    int nomes[4][ESPACO];
    strncpy(nomes[0], "Helicopterozinho", ESPACO); // nome
    strncpy(nomes[1], "Preto", ESPACO); // cor
    strncpy(nomes[2], "Gasolina", ESPACO); // combustivel
    int arr[] =  {1518500, 6, 6, 6000}; // preco ; pas ; passageiros ; altitude_max
    PreencheEntrada(&helicoptero,ARR_TIPOS,arr,nomes);

    ENTRADA_FINAL bike;
    int ARR_TIPOS[] = {ID,indice, 0, 1, 0}; // ID ; APAGADO ; classe ; subclasse 
    int nomes[4][ESPACO];
    strncpy(nomes[0], "Bikezinha", ESPACO); // nome
    strncpy(nomes[1], "Vermelha", ESPACO); // cor
    strncpy(nomes[2], "Vintage", ESPACO); // modelo
    strncpy(nomes[3], "Alta", ESPACO); // suspensao
    int arr[] =  {1200, 50, 6};  // preco ; diam_roda ; marchas
    PreencheEntrada(&bike,ARR_TIPOS,arr,nomes);


    ENTRADA_FINAL skate;
    int ARR_TIPOS[] = {ID, indice, 0, 1, 1}; // ID ; APAGADO ; classe ; subclasse 
    int nomes[4][ESPACO];
    strncpy(nomes[0], "Skatezinho", ESPACO); // nome
    strncpy(nomes[1], "Preto", ESPACO); // cor
    strncpy(nomes[2], "Street", ESPACO);// modelo
    strncpy(nomes[3], "Borracha", ESPACO); // tipo_roda
    int arr[] =  {1200, 110, 10}; // preco ; comprimento ; diam_roda
    PreencheEntrada(&skate,ARR_TIPOS,arr,nomes);
    
    switch (entrada_USER){
        case 0:
            EscreverEntrada(moto,arquivo);
            break;
        case 1:
            EscreverEntrada(carro, arquivo);
            break;
        case 2:
            EscreverEntrada(barco,arquivo);
            break;
        case 3:
            EscreverEntrada(bike,arquivo);
            break;
        case 4:
            EscreverEntrada(skate,arquivo);
            break;
        default:
            printf("Deu errado(provavelmente input errado)\n");
    }


}

int main ()
{
    ENTRADA_FINAL registros_teste[6];
    FILE* arquivo=fopen("C:\\LP1\\concessionaria\\repositorio\\src\\testes.bin","rb+");

    // vou criar um loop para add cada registro à uma posição

    //Loop infinito de acao, tirado diretamente do fluxo, so que com funcoes em sua forma bruta
    int termino=0;
    while(!termino){
        puts("Opções:\n [1] Criar registro\n [2] Buscar registro\n [3] Editar registro\n [4] Remover registro\n [5] Sair");
        puts("Digite o número da opção escolhida: ");
        int escolha;
        scanf("%d", &escolha);

        switch (escolha)
        {
            case(1):
                CriarRegistro(arquivo); //IDs sao crescentes, entao tem que ir ate o final do arquivo, pegar ultima e adicionar uma com ID+1
                break;
            case(2): //teste de busca de arquivos
                int id;
                printf("Qual id voce quer procurar no arquivo?");
                scanf("%d",&id);
                ENTRADA_FINAL amostra;
                leEntrada(&amostra,id,arquivo);
                ExibeEntrada(amostra);
                break;
            case(3):
                EditarRegistro(arquivo); //editar um dado registro, definido em outro modulo 
                break;
            
            case(4):
                int id;
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
