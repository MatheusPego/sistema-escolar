// Bibliotecas nativas do C:
#include <stdio.h>  //Biblioteca que implementa funções básicas, em especial o printf e scanf
#include <string.h> //Contém as funções ideais para manipulação de strings, como o strcspn

//Header Autoral (Módulo do Sistema):
#include "aluno.h"

void cadastrarAluno(Aluno lista[], int *totalAlunos)
{
    //Verificação de espaço para armazenar mais alunos:
    if (*totalAlunos >= MAX_ALUNOS)
    {
        printf("O número máximo de alunos foi atingido.\n");
        return; //Sai da função e retorna para o Menu, caso esteja cheio.
    }

    int indice = *totalAlunos;

    printf("              CADASTRAR NOVO ALUNO              \n");

    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Limpa o buffer do Menu.

    //Recebe o nome do aluno:
    printf("Digite o nome do aluno: ");
    fgets(lista[indice].nome, 50, stdin);

    //O fgets captura o 'enter' do usuário. Substituo por um terminador de texto:
    lista[indice].nome[strcspn(lista[indice].nome, "\n")] = '\0';

    //Recebe a matrícula:
    printf("Digite a matrícula do aluno: ");
    scanf("%d", &lista[indice].matricula);

    //O aluno começa com zero matérias cadastradas.
    lista[indice].qtdMateriasCadastradas = 0;

    //Recebe a turma:
    printf("Digite o código da turma: ");
    int turmaAluno;
    while ((turmaAluno = getchar()) != '\n' && turmaAluno != EOF); //Limpa o buffer do teclado.
    fgets(lista[*totalAlunos].turma.codigoTurma, 15, stdin);
    lista[*totalAlunos].turma.codigoTurma[strcspn(lista[*totalAlunos].turma.codigoTurma, "\n")] = '\0';

    printf("Digite o número da sala: ");
    fgets(lista[*totalAlunos].turma.numeroSala, 10, stdin);
    lista[*totalAlunos].turma.numeroSala[strcspn(lista[*totalAlunos].turma.numeroSala, "\n")] = '\0';

    //Passa para a main.c que agora há +1 aluno na estante.
    (*totalAlunos)++;

    printf("\n\033[1;32mAluno cadastrado com sucesso!\033[0m\n");
}