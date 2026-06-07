#include <stdio.h>

int menu(int respostaMenu)
{
    do
    {
        printf(printf("\033[1;33m---- Sistema de Gerenciamento Escolar (SGE) ----\033[0m\n");
        printf("1 - Cadastrar Aluno\n");
        printf("2 - Registrar Notas\n");
        printf("3 - Exibir Alunos\n");
        printf("4 - Sair\n");
        fgets()

        //O switch chama as respectivas funções para cada ação desejada:
        switch(respostaMenu)
        {
            case 1:
                cadatrarAluno();
                break;
            case 2:
                registrarNotas();
                break;
            case 3:
                exibirAlunos();
                break;
            case 4:
                sair();
                break;
            default:
                printf("Saindo Inválido\n");
            break;
        }
    }
    while (respostaMenu != 4);

}

