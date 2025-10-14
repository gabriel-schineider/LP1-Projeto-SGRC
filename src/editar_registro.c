// exibir as opções e pedir o campo a ser editado
// fornecer a opção de edição (sobre-escrita)

#include "/home/ime/aula/LP1-Projeto-SGRC/include/escrita_arq.h"
#include "/home/ime/aula/LP1-Projeto-SGRC/include/ler_arq.h"
void preencheUserMotor(struct Motorizado* ptr){
    int tipo;
    printf("Digite 0 para moto, 1 para carro, 2 para barco, 3 para barco\n");
    scanf("%d",&tipo);
    char combustivel[ESPACO];
    printf("Escreva aqui o tipo de combustivel, num max de caracteres 27\n");
    scanf("%s",combustivel);
    strncpy(ptr->combustivel,combustivel,ESPACO);
    switch (tipo){
        case moto:
            char guidom[ESPACO];
            printf("Escreva aqui o tipo de guidom da moto, max de caracteres 27\n");
            scanf("%s",guidom);
            strncpy(ptr->moto.guidom,guidom,ESPACO);

            int offroad;
            printf("A moto eh offroad? 1 para sim, 0 p nao\n");
            scanf("%d",&offroad);
            ptr->moto.offroad=offroad;

            for (int i=0;i<2;i++){
                int pressao;
                printf("Pressao ideal do pneu %d\n",i);
                scanf("%d",&pressao);
                ptr->moto.pressao_ideal[i]=pressao;
            }

            break;
        case carro:
            int tracao;
            printf("Qual e a tracao(x por x, digite um numero)\n");
            scanf("%d",tracao);
            ptr->carro.tracao=tracao;

            int portas;
            printf("Quantas portas?\n");
            scanf("%d",&portas);
            ptr->carro.portas=portas;

            int eletrico;
            printf("O carro eh eletrico? 1 para sim 0 para nao\n");
            scanf("%d",&eletrico);
            ptr->carro.eletrico=eletrico;
            for (int i=0;i<4;i++){
                int pressao;
                printf("Pressao ideal do pneu %d\n",i);
                scanf("%d",&pressao);
                ptr->carro.pressao_ideal[i]=pressao;
            }
            break;
        case barco:
            int litragem;
            printf("Qual e a litragem do barco(volume)\n");
            scanf("%d",litragem);
            ptr->barco.litragem=litragem;

            char tipo_casco[ESPACO];
            printf("Escreva tipo de casco, max de caracteres 27\n");
            scanf("%s",tipo_casco);
            strncpy(ptr->barco.tipo_casco,tipo_casco,ESPACO);

            int vel_aq_max;
            printf("Qual e a velocidade maxima em nos do barco\n");
            scanf("%d",litragem);
            ptr->barco.litragem=litragem;
            ptr->barco.vel_aq_max=vel_aq_max;

            break;
        case helicoptero:
            int pas;
            printf("Numero de pas do helicoptero\n");
            scanf("%d",pas);
            ptr->helicoptero.pas=pas;
            
            int passageiros;
            printf("Numero de passageiros max do helicoptero\n");
            scanf("%d",passageiros);
            ptr->helicoptero.passageiros=passageiros;

            int altitude_max;
            printf("Altitude maxima do helicoptero em metros\n");
            scanf("%d",altitude_max);
            ptr->helicoptero.altitude_max=altitude_max;

            break;
    }
}
preencheUserManual(struct Manual* ptr){
    int tipo;
    printf("Digite 0 para bike, 1 para skate\n");
    scanf("%d",&tipo);
    char modelo[ESPACO];
    printf("Escreva aqui o modelo, num max de caracteres 27\n");
    scanf("%s",modelo);
    strncpy(ptr->modelo,modelo,ESPACO);
    switch (tipo){
        case bike:
            char suspensao[ESPACO];
            printf("Escreva tipo de suspensao da bike, max de caracteres 27\n");
            scanf("%s",suspensao);
            strncpy(ptr->bike.suspensao,suspensao,ESPACO);

            int diam_roda;
            printf("Diametro das rodas da bike\n");
            scanf("%d",diam_roda);
            ptr->bike.diam_roda=diam_roda; 

            int marchas;
            printf("Numero de marchas da bike\n");
            scanf("%d",marchas);
            ptr->bike.marchas=marchas;
            break;
        case skate:
            int comprimento;
            printf("Comprimento do skate, em cm\n");
            scanf("%d",comprimento);
            ptr->skate.comprimento=comprimento;

            int diam_roda;
            printf("Diametro das rodas do skate\n");
            scanf("%d",diam_roda);
            ptr->skate.diam_roda=diam_roda; 

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
    printf("Escreva o nome do produto max de caracteres 27\n");
    scanf("%s",nome);
    strncpy(coisa->nome,nome,ESPACO);

    char cor[ESPACO];
    printf("Escreva a cor do produto max de caracteres 27\n");
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
    printf("Informe a ID da entrada que voce quer editar:");
    scanf("%d",id_editar);
    ENTRADA_FINAL modificado;

    leEntrada(&modificado,id_editar,arquivo);
    ModificarEntrada(&modificado);
    EscreverEntrada(modificado,arquivo);
}
