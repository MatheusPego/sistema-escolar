//Bibliotecas nativas do C:
#include <stdio.h>
#include <string.h>

//Headers autorais:
#include "relatorio.h"
#include "aluno.h"

void exibirTurmas(Aluno lista[], int totalAlunos) {
    //Verificando se está vazio:
    if (totalAlunos == 0) {
        printf("\n⚠️ Nenhum aluno cadastrado no sistema ainda.\n");
        return; //Sai da função.
    }

    printf("         LISTA DE ALUNOS CADASTRADOS            \n");

    //Vai de 0 até o total de alunos cadastrados:
    for (int i = 0; i < totalAlunos; i++) {
        printf("\nMatrícula: %d | Nome: %s\n", lista[i].matricula, lista[i].nome);
        printf("Turma: %s | Sala: %s\n", lista[i].turma.codigoTurma, lista[i].turma.numeroSala);

        //Verificando se o aluno possui matérias cadastradas:
        if (lista[i].qtdMateriasCadastradas == 0) {
            printf("   [Nenhuma matéria ou nota lançada para este aluno]\n");
        } else {
            //Percorre cada matéria do aluno:
            for (int m = 0; m < lista[i].qtdMateriasCadastradas; m++) {
                printf("   📚 Matéria: %s\n", lista[i].materias[m].nomeDisciplina);

                //Exibe as notas:
                printf("      Notas: [ ");
                for (int j = 0; j < 4; j++) {
                    printf("%.1f ", lista[i].materias[m].notas[j]);
                }

                //Exibe a média e a situação:
                printf("] | Média: %.1f | Situação: %s\n",
                       lista[i].materias[m].media,
                       lista[i].materias[m].situacao);
            }
        }
    }
}

void exibirAlunoPorMatricula(Aluno lista[], int totalAlunos) {
    //Verificando se está vazio:
    if (totalAlunos == 0) {
        printf("\n⚠️ Nenhum aluno cadastrado no sistema ainda.\n");
        return; //Sai da função.
    }

    int matriculaBusca;
    int encontrado = 0;

    printf("Digite a matrícula do aluno para busca: ");
    scanf("%d", &matriculaBusca);

    //Percorre a lista procurando a matricula:
    for (int i = 0; i < totalAlunos; i++) {
        if (lista[i].matricula == matriculaBusca) {
            printf("\nMatrícula: %d | Nome: %s\n", lista[i].matricula, lista[i].nome);
            printf("Turma: %s | Sala: %s\n", lista[i].turma.codigoTurma, lista[i].turma.numeroSala);

            //Verificando se o aluno possui matérias cadastradas:
            if (lista[i].qtdMateriasCadastradas == 0) {
                printf("   [Nenhuma matéria ou nota lançada para este aluno]\n");
            } else {
                //Percorre cada matéria do aluno:
                for (int m = 0; m < lista[i].qtdMateriasCadastradas; m++) {
                    printf("   📚 Matéria: %s\n", lista[i].materias[m].nomeDisciplina);

                    //Exibe as notas:
                    printf("      Notas: [ ");
                    for (int j = 0; j < 4; j++) {
                        printf("%.1f ", lista[i].materias[m].notas[j]);
                    }

                    //Exibe a média e a situação:
                    printf("] | Média: %.1f | Situação: %s\n",
                           lista[i].materias[m].media,
                           lista[i].materias[m].situacao);
                }
            }
            encontrado = 1;
            break; //Sai do laço pois a matrícula é única.
        }
    }

    //Se não encontrar o aluno:
    if (encontrado == 0) {
        printf("\n⚠️ Matrícula não encontrada no sistema.\n");
    }
}

void exibirAlunosPorTurma(Aluno lista[], int totalAlunos) {
    //Verificando se está vazio:
    if (totalAlunos == 0) {
        printf("\n⚠️ Nenhum aluno cadastrado no sistema ainda.\n");
        return; //Sai da função.
    }

    char turmaBusca[15];
    int contagem = 0;

    printf("Digite o código da turma para listagem: ");
    int c;
    while ((c = getchar()) != '\n' && c != EOF); //Limpa o buffer do teclado.
    fgets(turmaBusca, 15, stdin);
    turmaBusca[strcspn(turmaBusca, "\n")] = '\0';

    printf("         LISTA DE ALUNOS DA TURMA %s            \n", turmaBusca);

    //Percorre os alunos procurando pela turma informada:
    for (int i = 0; i < totalAlunos; i++) {
        if (strcmp(lista[i].turma.codigoTurma, turmaBusca) == 0) {
            printf("\nMatrícula: %d | Nome: %s | Sala: %s\n", lista[i].matricula, lista[i].nome, lista[i].turma.numeroSala);

            //Verificando se o aluno possui matérias cadastradas:
            if (lista[i].qtdMateriasCadastradas == 0) {
                printf("   [Nenhuma matéria ou nota lançada para este aluno]\n");
            } else {
                //Percorre cada matéria do aluno:
                for (int m = 0; m < lista[i].qtdMateriasCadastradas; m++) {
                    printf("   📚 Matéria: %s\n", lista[i].materias[m].nomeDisciplina);

                    //Exibe as notas:
                    printf("      Notas: [ ");
                    for (int j = 0; j < 4; j++) {
                        printf("%.1f ", lista[i].materias[m].notas[j]);
                    }

                    //Exibe a média e a situação:
                    printf("] | Média: %.1f | Situação: %s\n",
                           lista[i].materias[m].media,
                           lista[i].materias[m].situacao);
                }
            }
            contagem++;
        }
    }

    //Se nenhuma correspondência for encontrada:
    if (contagem == 0) {
        printf("   [Nenhum aluno alocado nesta turma ainda]\n");
    }
}