# Manual de Uso
<img width="432" height="151" alt="SisCon" src="https://github.com/user-attachments/assets/71ded3bc-7a62-4ce3-ad8a-bce1c4951b7b" />

## Guia de como usar a aplicação SisCon, o Sistema de Gerenciamento de Registros para Concessionárias.


### 1. Como ter acesso
1. Faça o download do diretório inteiro, seja por clonando o repositório usando git e git pull, ou instalando o ZIP e extraindo num diretório qualquer
2. Instale um compilador de C(GCC), e incorpore ele ao PATH do sistema, pois o programa usa o comando gcc.
3. Para rodar o programa, o abra o diretório no qual você instalou os arquivos e rode o comando "gcc main.c funcoes.c -o {insira nome de executavel que desejar}
4. Depois, basta invocar o executável que você criou, ./nome.exe ou ./a.out caso você não tenha escrito nenhum nome
5. O banco de dados é local a cada dispositivo, e na primeira execução, o programa fará um novo, o nome do arquivo é "RegistrosConcessionaria.bin"
    <ol type="a">
        <li>Caso queira resetar por completo os dados, apenas deletar o arquivo e executar de novo</li>
        <li>Abrir um arquivo com o mesmo nome sem nada dentro atrapalhará o programa, a primeira execução inicializa a tabela de índices</li>
    </ol>

---

### 2. Formas de utilização

### Criação de Registros:
Consiste na escrita de um registro em memória para o documento criado e gerenciado pela aplicação. Sendo assim, possível armazenar o registro de forma permanente. Com um limite de 100 registros

O usuário vai respondendo conforme a aplicação faz as requisições.

<img width="638" height="623" alt="criacao" src="https://github.com/user-attachments/assets/81482ce8-c989-4080-8536-7e38ebbde26f" />



### Busca de Registros:
Consiste na procura de um registro, informando o ID dele, no documento gerenciado pela aplicação.

Caso o registro exista:

<img width="486" height="640" alt="busca-existente" src="https://github.com/user-attachments/assets/b4a9b2bc-3dfd-47dc-a309-3355d71ac6c1" />


Caso o registro tenha sido removido:

<img width="519" height="293" alt="busca-removido" src="https://github.com/user-attachments/assets/a3b1d6b5-d9ff-4523-a546-366136b734c3" />


Caso o registro não exista:

<img width="511" height="308" alt="busca-inexistente" src="https://github.com/user-attachments/assets/a3d02158-fcba-42bb-8f04-e422fa4ece6b" />


### Edição de Registros:
Consiste na alteração de algum campo de algum registro. Faz-se necessário passar o ID do registro para que a aplicação possa buscá-lo no documento gerenciado por ela.

Primeiro mostra-se o registro:

<img width="461" height="597" alt="edicao-pt1" src="https://github.com/user-attachments/assets/db7d47db-da21-4dd0-b53a-2d5c27475385" />

E, então, pergunta qual alteração o usuário deseja fazer:

<img width="485" height="219" alt="edicao-pt2" src="https://github.com/user-attachments/assets/4ae72502-4579-4d9e-978f-cadee65e15f5" />



### Remoção de Registros:
Consiste em retirar do documento algum registro específico. Faz-se necessário passar o ID do registro para que a aplicação possa buscá-lo no documento por ela gerenciado para, então, removê-lo.

<img width="489" height="310" alt="removido" src="https://github.com/user-attachments/assets/f6fd6204-d66d-4f04-ac04-58c088d53588" />

