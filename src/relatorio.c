//Bibliotecas nativas do C:
#include <stdio.h>  // Biblioteca que implementa funções básicas, em especial o printf e scanf

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