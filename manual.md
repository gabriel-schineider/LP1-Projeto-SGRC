# Manual de Uso: Projeto Sistema de Gerenciamento de Registros
1. Faça o download do diretório inteiro, seja por clonando o repositório usando git e git pull, ou instalando o ZIP e extraindo num diretório qualquer
2. Instale um compilador de C(GCC), e incorpore ele ao PATH do sistema, pois o programa usa o comando gcc.
3. Para rodar o programa, o abra o diretório no qual você instalou os arquivos e rode o comando "gcc main.c funcoes.c -o {insira nome de executavel que desejar}
4. Depois, basta invocar o executável que você criou, ./nome.exe ou ./a.out caso você não tenha escrito nenhum nome
5. O banco de dados é local a cada dispositivo, e na primeira execução, o programa fará um novo, o nome do arquivo é "RegistrosConcessionaria.bin"
    <ol type="a">
        <li>Caso queira resetar por completo os dados, apenas deletar o arquivo e executar de novo</li>
        <li>Abrir um arquivo com o mesmo nome sem nada dentro atrapalhará o programa, a primeira execução inicializa a tabela de índices</li>
    </ol>
6. Funções usadas pelo usuário:
    <ol type="a">
        <li>criaRegistro-> Ela pega o maior ID, e pergunta pro usuário preencher cada campo da nova entrada, de características gerais a específicas. No final, mostra ao usuário a ID da nova entrada e grava-a no arquivo. Essa ID é única, e sempre será 1 maior do que a maior ID existente no arquivo. Logo, a primeira entrada será a ID 1, 2, 3 .... até o máximo de 100.</li>
        <li>Busca-> Dado um ID pelo usuário, busca no arquivo a entrada correspondente. Retorna arquivo não consta caso ele ainda não tenha sido dado pelo usuário, ou removido caso tenha sido removido pelo usuário. Caso ele exista, exibe a entrada no terminal.</li>
        <li>editaRegistro-> Dado um ID pelo usuário, busca no arquivo a entrada correspondente, a exibe, e pergunta qual campo ele quer editar. Depois da edição, exibe o arquivo editado e o grava no arquivo.</li>
        <li>removeRegistro-> Dado um ID pelo usuário, remove a entrada. A remoção é feita buscando a entrada no arquivo e o marcando como inativo. </li>   
    </ol>