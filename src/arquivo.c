//Bibliotecas Nativas:
#include <stdio.h>

//Headers autorais
#include "arquivo.h"
#include "aluno.h"

void salvarDados(Aluno lista[], int totalAlunos) {
    //Abre/cria/sobrescreve o arquivo no modo "write binary" (wb).
    FILE *arquivo = fopen("banco_alunos.dat", "wb");

    //Caso o sistema operacional negue a criação do arquivo:
    if (arquivo == NULL) {
        printf("\n\033[1;31m[Erro Fatal]\033[0m Nao foi possivel acessar o disco para salvar os dados.\n");
        return;
    }

    //Grava o número total de alunos 1 bloco do tamanho de um inteiro:
    fwrite(&totalAlunos, sizeof(int), 1, arquivo);

    //Grava o vetor inteiro de alunos de uma vez (totalAlunos blocos do tamanho da struct):
    fwrite(lista, sizeof(Aluno), totalAlunos, arquivo);

    //Sempre fechamos o arquivo para liberar a memória e confirmar a gravação no disco:
    fclose(arquivo);
}

void carregarDados(Aluno **lista, int *totalAlunos) {
    //Abre o arquivo no modo "read binary" (rb).
    FILE *arquivo = fopen("banco_alunos.dat", "rb");

    //Se o arquivo retornar nulo, significa que é a primeira vez rodando o programa e ele não existe:
    if (arquivo == NULL) {
        *totalAlunos = 0; //Garante que o contador inicie zerado.
        printf("\n\033[1;36m[Info]\033[0m Nenhum banco de dados anterior encontrado. Iniciando sistema limpo.\n");
        return;
    }

    //Lê o número total de alunos salvo anteriormente e guarda no endereço do contador:
    fread(totalAlunos, sizeof(int), 1, arquivo);

    //Lê os dados dos alunos e despeja de volta para dentro do vetor:
    fread(lista, sizeof(Aluno), *totalAlunos, arquivo);

    //Fecha o arquivo de leitura:
    fclose(arquivo);
}

void resetDados()
{
    if (remove("banco_alunos.dat") == 0)
    {
        printf("\n\033[1;32m[Sucesso]\033[0m O banco de dados físico foi deletado com sucesso.\n");
    } else {
        //Se cair aqui, é porque o arquivo não existia ou o SO bloqueia o acesso
        printf("\n\033[1;33m[Aviso]\033[0m Nenhum banco de dados existente para deletar.\n");
    }
}