#include<stdio.h>
#include<entrada_struct.h>
#include<string.h>
#include<stdlib.h>

void RemoverRegistro(int indice, FILE *f) //só muda o campo APAGADO pra 1, não remove realmente do arquivo
{
    int removido = 1;
    
    long int PosicaoDoRegistro = sizeof(ENTRADA_FINAL) * indice;
    long int PosicaoParaRemover = (PosicaoDoRegistro + sizeof(int)); //pula o indice

    fseek(f,PosicaoParaRemover, SEEK_SET);
    fwrite(&removido, sizeof(int), 1, f);

    fflush(f); //só pra garantir que o dado foi escrito no arquivo.
}

//apenas uma ideia, ainda posso alterar algo depois.
//realmente remove o registro do arquivp, e muda o indice dos que vem em seguida
/*não consegui pensar num jeito muito bom pra remover os registros dentro do próprio arquivo,
então aqui eu passo de um arquivo pra outro somente se a flag apagado for igual a 0.
e depois eu apago o arquivo anterior e renomeio o novo pra ficar igual o anterior*/
void Permanent_RM_Regist(int indice, char Caminho_Do_Arquivo[]) 
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
}
