#include <stdio.h> //Biblioteca que implementa funções básicas, em especial o printf e scanf
#include <locale.h>
#include "aluno.h"
#include "menu.h"
#include "notas.h"
#include "relatorio.h"
#include "arquivo.h"

int main(void)
{
    setlocale(LC_ALL, "Portuguese"); //Estabelece por padrão as acentuações da lingua portuguesa;
    Aluno lista[50]; //Lista de todos os alunos.
    int totalAlunos = 0; //Contador inicial de alunos, iniciamos em zero.
    int opcao;

    do
    {
        //Chamada para o Menu:
        opcao = exibirMenu();

        switch (opcao)
        {
            case 1:
            printf("\n\033[1;33m[Aviso]\033[0m Você escolheu a opção: Cadastrar Aluno.\n");
            // Passa a lista e o ENDEREÇO da variável totalAlunos por referência (&).
            cadastrarAluno(lista, &totalAlunos);
            break;

        case 2:
            printf("\n\033[1;33m[Aviso]\033[0m Você escolheu a opção: Registrar Notas.\n");
            lancarNotas(lista, totalAlunos); //Passa totalAlunos por valor
            break;

        case 3:
            printf("\n\033[1;33m[Aviso]\033[0m Você escolheu a opção: Exibir Alunos.\n");
            //Aqui não é nescessário o uso do '&' porque não vamos alterar o total, só queremos ler o valor
            exibirTurmas(lista, totalAlunos);
            break;

        case 4:
            printf("\nSaindo do sistema. Obrigado por utilizar o SGE!\n");
            break;

        default:
            printf("\n\033[1;33m[Opção inválida!]\033[0m Digite um número válido entre as opções (1 ... 4).\n");
            break;
        }
    }
    while (opcao != 4);


    return 0;
}
