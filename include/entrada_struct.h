#include <stdio.h>
#include <string.h>
#ifndef ENTRADA_STRUCT_H
#define ENTRADA_STRUCT_H

#define ESPACO 28 // definindo aqui para generalizar e facilitar manutenção (caso precisemos alterar o espaço, mudamos apenas uma vez aqui e não em cada local, o que poderia estar sujeito a falhas)

enum Entidade{ motorizado, manual }; //0 e 1 respect.

enum tipo_Motorizado{  moto, carro, barco, helicoptero }; //0,1,2,3 respect.

enum tipo_Manual{ bike, skate };

enum Afirmacao{nao,sim};

struct Manual{
    int tipo;
    char modelo[ESPACO];
    union{
        struct Bike{
            int diam_roda; int marchas; char suspensao[ESPACO];
        } bike;
        struct Skate{
            int comprimento;
            int diam_roda;
            char tipo_roda[ESPACO];
        } skate;
    };
};
struct Motorizado{
    int tipo;
    char combustivel[ESPACO];
    union {
        struct Moto{
            char guidom[ESPACO]; int offroad;
            int pressao_ideal[2];
        } moto;
        struct Carro{
            int tracao; int portas; int eletrico;
            int pressao_ideal[4];
        } carro; //nome do atributo da union
        struct Barco{ //tipo ==2
            int litragem; char tipo_casco[ESPACO]; int vel_aq_max;
        } barco;
        struct Helicoptero{  //tipo ==3
            int pas; int passageiros; int altitude_max;
        } helicoptero;
    };
};

void preencheMotorizado(struct Motorizado* ptr,int tipo, int arr[], char nomes[][ESPACO]){ //funcao p preencher motorizados
    ptr->tipo=tipo; //pega vetor de numeros e vetor de strings para preencher, ordem importa! olhar os indices usados, sao arbitrarios
    strncpy(ptr->combustivel,nomes[3],ESPACO);
    switch (ptr->tipo){
        case moto: 
            strncpy(ptr->moto.guidom,nomes[3],ESPACO);
            ptr->moto.offroad=arr[1];
            for (int i=0;i<2;i++){
                ptr->moto.pressao_ideal[i]=arr[1+i];
            }
            break;
        case carro:
            ptr->carro.tracao=arr[1];
            ptr->carro.portas=arr[2];
            ptr->carro.eletrico=arr[3];
            for (int i=0;i<4;i++){
                ptr->carro.pressao_ideal[i]=arr[4+i];
            }
            break;
        case barco:
            ptr->barco.litragem=arr[1];
            strncpy(ptr->barco.tipo_casco, nomes[3], ESPACO); // ambos, a origem e o destino, já são char* (destino é apenas ponteiro para char e origem é ponteiro para array de 25 chars)
            ptr->barco.vel_aq_max=arr[2];
            break;
        case helicoptero:
            ptr->helicoptero.pas=arr[1];
            ptr->helicoptero.passageiros=arr[2];
            ptr->helicoptero.altitude_max=arr[3];
            break;
    }
}

void preencheManual(struct Manual* ptr,int tipo, int arr[],char nomes[][ESPACO]){
    ptr->tipo=tipo;
    strncpy(ptr->modelo,nomes[2],ESPACO); //nomes 1 e 2 reservado para nome e preco
    switch (ptr->tipo){
        case bike: 
            strncpy(ptr->bike.suspensao,nomes[1],ESPACO);
            ptr->bike.diam_roda=arr[1]; //olhar aqui para padrao de input p preencher skate. arr[0] reservado para preco
            ptr->bike.marchas=arr[2];
            break;
        case skate:
            ptr->skate.comprimento=arr[1];
            ptr->skate.diam_roda=arr[2];
            strncpy(ptr->skate.tipo_roda,nomes[1],ESPACO);
            break;
    }
}

typedef struct ENTRADA_FINAL{
    int ID;
    int APAGADO;
    int classe;
    char nome[ESPACO];
    char cor[ESPACO];
    int preco;
    union{
        struct Motorizado motorizado; //classe 0
        struct Manual manual;  //classe 1
    };
} ENTRADA_FINAL;

void preenche_ENTRADA(ENTRADA_FINAL* ptr,int ARR_TIPOS[], int arr[],char nomes[][ESPACO]){
    //arr de inputs numericos, olhar preenche de cada subtipo para olhar ordem certa
    //nomes array 2d com strings usados para preencher campos com string, olhar preencher p ordem
    //tamanho maximo de 24 caracteres para cada string, escolhido arbitrariamente
    //ARR_TIPOS se refere ao ID, se esta apagado, se e manual ou n, e qual seu tipo dentro de manual/nao nessa ordem
    ptr->ID=ARR_TIPOS[0];
    ptr->APAGADO=ARR_TIPOS[1];
    ptr->classe=ARR_TIPOS[2]; 
    strncpy(ptr->nome,nomes[0],ESPACO);
    strncpy(ptr->cor,nomes[1],ESPACO);
    ptr->preco=arr[0];
    if(ptr->classe==0){
        preencheMotorizado(&(ptr->motorizado),ARR_TIPOS[3],arr,nomes);
    }
    if (ptr->classe==1){
        preencheManual(&(ptr->manual),ARR_TIPOS[3],arr,nomes);
    }
}

void ExibeMotorizado(struct Motorizado coisa){ 
    printf("Seu combustivel usado eh %s \n",coisa.combustivel);
    switch (coisa.tipo){
        case moto: //exibir a moto 
            printf("Tipo de guidom: %s \n",coisa.moto.guidom);
            if (coisa.moto.offroad){
                printf("Essa moto eh offroad \n");
            }
            else{
                printf("Essa moto nao eh offroad\n");
            }
            for (int i=0;i<2;i++){
                printf("Pressao ideal do pneu %d: %d PSI", i,coisa.moto.pressao_ideal[i]);
            }
            break;
        case carro: //exibir carro
            printf("A tracao desse carro eh %d x %d \n",coisa.carro.tracao, coisa.carro.tracao);
            printf("Numero de portas%d \n",coisa.carro.portas);
            if (coisa.moto.offroad){
                printf("Essa carro eh eletrico\n");
            }
            else{
                printf("Essa moto nao eh eletrico\n");
            }
            for (int i=0;i<4;i++){
                printf("Pressao ideal do pneu %d: %d PSI", i,coisa.carro.pressao_ideal[i]);
            }
            break;
        case barco:
            printf("Quantos litros este barco desloca: %d \n",coisa.barco.litragem);
            printf("Velocidade maxima (em nos ):%d \n",coisa.barco.vel_aq_max);
            break;
        case helicoptero:
            printf("Numero de pas: %d \n",coisa.helicoptero.pas);
            printf("Numero de passageiros:%d \n",coisa.helicoptero.passageiros);
            printf("Altitude maxima:%d \n",coisa.helicoptero.altitude_max);
            break;
    }
}
void ExibeManual(struct Manual coisa){
    switch (coisa.tipo){
        case bike: 
            printf("Suspensao : %s \n",coisa.bike.suspensao);
            printf("Diametro da roda: %d\n",coisa.bike.diam_roda); //olhar aqui para padrao de input p preencher skate. arr[0] reservado para preco
            printf("Numero de marchas: %d\n",coisa.bike.marchas);
            break;
        case skate:
            printf("Comprimento do skate: %d\n",coisa.skate.comprimento);
            printf("Diametro da rodinha: %d\n",coisa.skate.diam_roda);
            printf("Tipo de rodinha: %s\n",coisa.skate.tipo_roda);
            break;
    }
}
void ExibeEntrada(ENTRADA_FINAL coisa){
    printf("ID: %d\n",coisa.ID);
    if (coisa.APAGADO){
        printf("Foi apagado/deve ser apagado \n");
    }
    else{
        printf("Nao foi apagado \n");
    }
    printf("Nome do produto:  %s \n",coisa.nome);
    printf("Cor:  %s \n",coisa.cor);
    printf("Preco:  %d \n",coisa.preco);
    if (coisa.classe){
        ExibeManual(coisa.manual);
    }
    else {
        ExibeMotorizado(coisa.motorizado);
    }
}

#endif