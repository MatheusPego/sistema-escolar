#include <stdio.h> //Biblioteca que implementa funções básicas, em especial o printf e scanf
#include "menu.h"

int exibirMenu() {
    int opcao;

    printf("\033[1;33m---- Sistema de Gerenciamento Escolar (SGE) ----\033[0m\n");
    printf("1 - Cadastrar Aluno\n");
    printf("2 - Registrar Notas\n");
    printf("3 - Exibir Alunos\n");
    printf("4 - Sair\n");
    printf("----------------------------------------------\n");
    printf("Escolha uma opcao: ");

    //Validação contra o uso de letras no menu, o scanf devolve '1' se conseguir ler um número.
    if (scanf("%d", &opcao) != 1) {
        //Se o usuário digitar uma letra, limpamos o buffer do teclado para o caractere inválido não travar o nosso loop.
        while (getchar() != '\n');
        return -1; //Retorna um código de erro para o switch saber que foi inválido
    }

    return opcao;
}