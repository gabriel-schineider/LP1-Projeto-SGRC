#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "entrada_struct.h"
#include "ler_arq.h"

void RemoverRegistro(int indice, FILE *f) //só muda o campo APAGADO pra 1, não remove realmente do arquivo
{
    int removido = 1;
    
    long int PosicaoDoRegistro = INDICE_INICIO+sizeof(ENTRADA_FINAL) * indice;
    long int PosicaoParaRemover = (PosicaoDoRegistro + sizeof(int)); //pula o ID

    fseek(f,PosicaoParaRemover, SEEK_SET);
    fwrite(&removido, sizeof(int), 1, f);

    fflush(f); //só pra garantir que o dado foi escrito no arquivo.
}

//apenas uma ideia, ainda posso alterar algo depois.
//realmente remove o registro do arquivp, e muda o indice dos que vem em seguida
/*não consegui pensar num jeito muito bom pra remover os registros dentro do próprio arquivo,
então aqui eu passo de um arquivo pra outro somente se a flag apagado for igual a 0.
e depois eu apago o arquivo anterior e renomeio o novo pra ficar igual o anterior*/
FILE *fTemporario Permanent_RM_Regist(int indice, char Caminho_Do_Arquivo[])
{
    FILE *fOriginal = fopen(Caminho_Do_Arquivo, "rb");  
    if(!fOriginal)
    {
        perror("Falha ao abrir o arquivo original.");
        return;
    }
    FILE *fTemporario = fopen("temporário.bin", "wb");
    if(!fTemporario)
    {
        perror("falha ao criar arquivo temporário");
        return;
    }

    ENTRADA_FINAL registro;
    int NovoIndice = 0;

    while(fread(&registro, sizeof(ENTRADA_FINAL), 1, fOriginal ) == 1)  //pra verificar se obteve sucesso
    {
        if(registro.APAGADO == 0)
        {
            registro.indice = Novoindice;   //assumoindo que o primeiro indice seja 0.
            fwrite(&registro, sizeof(ENTRADA_FINAL), 1, fTemporario);
            NovoIndice++;
        }
    }
    
    if(feof(fOriginal) != 0)
    {
        fclose(fTemporario);
        fclose(fOriginal);
        
        remove(Caminho_Do_Arquivo);
        rename("temporário.bin", Caminho_Do_Arquivo);
    }
    else if (ferror(fOriginal) != 0)
    {
        fclose(fTemporario);
        fclose(fOriginal);

        remove("temporário.bin");
    }

    return fTemporario;
}

void RemoveExtra(int ID, FILE* f){
    int indice_remover= pegarIndice(ID,f);
    int ult_indice=IndiceMax(f); //poderia ter mudado a funcao de leitura p/ indice? sim, porem, 
    int ultID=indice_P_ID(f,ult_indice);  //o objetivo e relacionar ID com posicao para o usuario, e nao indice, por isso essa volta
    ENTRADA_FINAL ult_elemento;
    leEntrada(&ult_elemento,ultID,f);
    ult_elemento.indice=indice_remover; //trocando o indice do ultimo elemento para o elemento a ser removido 
    EscreverEntrada(ult_elemento); //escrever o ultimo sobre o que eh para ser apagado 
    fseek(f,(long int) (ID-1)*8 +4,SEEK_SET);//atualizar indice do removido agora para ser -1, ou seja, nulo
    int nulo=NULO;
    fwrite(&nulo,sizeof(int),1,f);
}