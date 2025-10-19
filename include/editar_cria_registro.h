// exibir as opções e pedir o campo a ser editado
// fornecer a opção de edição (sobre-escrita)

#include "escrita_arq.h"
#include "ler_arq.h"
#ifndef EDITAR_REGISTRO_H
#define EDITAR_REGISTRO_H
void preencheUserMotor(struct Motorizado* ptr){
    int tipo;
    printf("Digite 0 para moto, 1 para carro, 2 para barco, 3 para helicoptero\n");
    scanf("%d",&tipo);

    char combustivel[ESPACO];
    printf("Escreva aqui o tipo de combustivel, num max de caracteres 27\n");
    scanf("%s",combustivel);
    strncpy(ptr->combustivel,combustivel,ESPACO);

    int numero; //sera usado para preencher parametros numericos
    switch (tipo){
        case moto_ENUM:
            char guidom[ESPACO];
            printf("Escreva aqui o tipo de guidom da moto, max de caracteres 27\n");
            scanf("%s",guidom);
            strncpy(ptr->moto.guidom,guidom,ESPACO);

            printf("A moto eh offroad? 1 para sim, 0 p nao\n");
            scanf("%d",&numero);
            ptr->moto.offroad=numero;

            for (int i=0;i<2;i++){
                printf("Pressao ideal do pneu %d\n",i);
                scanf("%d",&numero);
                ptr->moto.pressao_ideal[i]=numero;
            }

            break;
        case carro_ENUM:
            printf("Qual e a tracao(x por x, digite um numero)\n");
            scanf("%d",&numero);
            ptr->carro.tracao=numero;

            printf("Quantas portas?\n");
            scanf("%d",&numero);
            ptr->carro.portas=numero;

            printf("O carro eh eletrico? 1 para sim 0 para nao\n");
            scanf("%d",&numero);
            ptr->carro.eletrico=numero;

            for (int i=0;i<4;i++){
                printf("Pressao ideal do pneu %d\n",i);
                scanf("%d",&numero);
                ptr->carro.pressao_ideal[i]=numero;
            }
            break;
        case barco_ENUM:

            printf("Qual e a litragem do barco(volume)\n");
            scanf("%d",&numero);
            ptr->barco.litragem=numero;

            char tipo_casco[ESPACO];
            printf("Escreva tipo de casco, max de caracteres 27\n");
            scanf("%s",tipo_casco);
            strncpy(ptr->barco.tipo_casco,tipo_casco,ESPACO);

            printf("Qual e a velocidade maxima em nos do barco\n");
            scanf("%d",&numero);
            ptr->barco.vel_aq_max=numero;

            break;
        case helicoptero_ENUM:
            printf("Numero de pas do helicoptero\n");
            scanf("%d",&numero);
            ptr->helicoptero.pas=numero;
            
            printf("Numero de passageiros max do helicoptero\n");
            scanf("%d",&numero);
            ptr->helicoptero.passageiros=numero;

            printf("Altitude maxima do helicoptero em metros\n");
            scanf("%d",&numero);
            ptr->helicoptero.altitude_max=numero;

            break;
    }
}
void preencheUserManual(struct Manual* ptr){
    int tipo;
    printf("Digite 0 para bike, 1 para skate\n");
    scanf("%d",&tipo);

    char modelo[ESPACO];
    printf("Escreva aqui o modelo, num max de caracteres 27\n");
    scanf("%s",modelo);
    strncpy(ptr->modelo,modelo,ESPACO);
    int numero; //usado para preencher parametros numericos
    switch (tipo){
        case bike_ENUM:
            char suspensao[ESPACO];
            printf("Escreva tipo de suspensao da bike, max de caracteres 27\n");
            scanf("%s",suspensao);
            strncpy(ptr->bike.suspensao,suspensao,ESPACO);


            printf("Diametro das rodas da bike\n");
            scanf("%d",&numero);
            ptr->bike.diam_roda=numero; 

            printf("Numero de marchas da bike\n");
            scanf("%d",&numero);
            ptr->bike.marchas=numero;
            break;
        case skate_ENUM:
            printf("Comprimento do skate, em cm\n");
            scanf("%d",&numero);
            ptr->skate.comprimento=numero;

            printf("Diametro das rodas do skate\n");
            scanf("%d",&numero);
            ptr->skate.diam_roda=numero; 

            char tipo_roda[ESPACO];
            printf("Escreva o tipo de roda do skate, max 27 caracteres\n");
            scanf("%s",tipo_roda);
            strncpy(ptr->skate.tipo_roda,tipo_roda,ESPACO);

            break;
    }
}
void ModificarEntrada(ENTRADA_FINAL* coisa){
    printf("A ID da entrada é %d\n",coisa->ID);
    int reverter; //reverter o estado de apagado ou nao apagado 
    if (coisa->APAGADO){
        printf("Ela está marcada para ser apagada, voce quer reverter?\n");
        printf("Digite 1 para sim e 0 para nao\n");
        scanf("%d",&reverter);
        if (reverter){
            coisa->APAGADO=nao;
        }
        else{
            return; //se mantiver apagado, nem se incomodar com mudar o resto
        }
    }
    else{
        printf("Voce quer apagar a entrada? 1 para sim, 0 para nao\n");
        scanf("%d",&reverter);
        if (reverter){
            coisa->APAGADO=sim;
            return; //se ta apagado, nem se incomodar com mudar o resto 
        }
    }
    int classe;
    printf("Voce quer que a nova entrada seja motorizada ou manual?\n");
    printf("0 p motorizado, 1 manual\n");
    scanf("%d",&classe);
    coisa->classe=classe;

    char nome[ESPACO];
    printf("Escreva o nome do produto, max de caracteres 27\n");
    scanf("%s",nome);
    strncpy(coisa->nome,nome,ESPACO);

    char cor[ESPACO];
    printf("Escreva a cor do produto, max de caracteres 27\n");
    scanf("%s",cor);
    strncpy(coisa->cor,cor,ESPACO);

    int preco;
    printf("Digite o preco do produto\n");
    scanf("%d",&preco);
    coisa->preco=preco;

    if(classe==0){
        preencheUserMotor(&(coisa->motorizado));
    }
    if (classe==1){
        preencheUserManual(&(coisa->manual));
    }
}

void EditarRegistro(FILE* arquivo){
    int id_editar;
    printf("Informe a ID da entrada que voce quer editar:\n");
    scanf("%d",&id_editar);
    ENTRADA_FINAL modificado;

    LeEntrada(&modificado,id_editar,arquivo);
    ModificarEntrada(&modificado);
    EscreverEntrada(modificado,arquivo);
    printf("Entrada modificada:\n");
    ExibeEntrada(modificado);
}

void CriaRegistroUSER(FILE* arquivo){
    int ID=pegarUltimoID(arquivo)+1; //pega o ultimo ID do arquivo, e adiciona um a mais para criar um novo registro
    int indice=IndiceMax(arquivo)+1; //pega o maior indice do arquivo, e adiciona +1
    ENTRADA_FINAL novo;
    novo.ID=ID;
    novo.indice=indice;
    novo.APAGADO=nao;
    int classe;
    printf("Voce quer que a nova entrada seja motorizada ou manual?\n"); //reparando que isso ta repetido no Editar, da pra inventar uma sub funcao aqui
    printf("0 p motorizado, 1 manual\n"); //economizaria algumas linhas, mas por legibilidade vou deixar assim por enquanto
    scanf("%d",&classe);
    novo.classe=classe;

    char nome[ESPACO];
    printf("Escreva o nome do produto, max de caracteres 27\n");
    scanf("%s",nome);
    strncpy(novo.nome,nome,ESPACO);

    char cor[ESPACO];
    printf("Escreva a cor do produto, max de caracteres 27\n");
    scanf("%s",cor);
    strncpy(novo.cor,cor,ESPACO);

    int preco;
    printf("Digite o preco do produto\n");
    scanf("%d",&preco);
    novo.preco=preco;

    if(classe==0){
        preencheUserMotor(&(novo.motorizado));
    }
    if (classe==1){
        preencheUserManual(&(novo.manual));
    }
    EscreverEntrada(novo,arquivo);
    printf("Entrada modificada:\n");
    ExibeEntrada(novo);
}


#endif