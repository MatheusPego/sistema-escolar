#include <stdio.h> //Biblioteca que implementa funções básicas, em especial o printf e scanf
#include "menu.h"

int exibirMenu() {
    int opcao;

    printf("\n\033[1;33m---- Sistema de Gerenciamento Escolar (SGE) ----\033[0m\n");
    printf("1 - Cadastrar Aluno\n");
    printf("2 - Registrar Notas\n");
    printf("3 - Exibir Alunos/Relatórios\n");
    printf("4 - Excluir Aluno\n");
    printf("5 - Sair\n");
    printf("----------------------------------------------\n");
    printf("Escolha uma opção: ");

    if (scanf("%d", &opcao) != 1) {
        while (getchar() != '\n');
        return -1;
    }

    return opcao;
}