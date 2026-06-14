#include <stdio.h> //Biblioteca que implementa funções básicas, em especial o printf e scanf
#include <locale.h> //Biblioteca para estabelecer adequações de linguagem.

//Headers Autorais:
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
    int opcao; //Variável para capturar a resposta do Menu principal.
    int subOpcao; //Variável para capturar a escolha do submenu de relatórios.

    //Carrega os dados do arquivo para a memória logo ao abrir o programa:
    carregarDados(lista, &totalAlunos);

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

            //Salva os dados no disco rígido imediatamente após o cadastro:
            salvarDados(lista, totalAlunos);
            break;

        case 2:
            printf("\n\033[1;33m[Aviso]\033[0m Você escolheu a opção: Registrar Notas.\n");
            lancarNotas(lista, totalAlunos); //Passa totalAlunos por valor

            //Salva os dados no disco rígido para não perder as notas recém-lançadas:
            salvarDados(lista, totalAlunos);
            break;

        case 3:
            printf("\n\033[1;33m[Aviso]\033[0m Você escolheu a opção: Exibir Alunos.\n");

            //Construção do submenu limpo:
            printf("\n   Submenu de Relatórios    \n");
            printf("1 - Listar todos os alunos cadastrados\n");
            printf("2 - Buscar aluno específico por matrícula\n");
            printf("3 - Listar alunos filtrados por turma\n");
            printf("-----------------------------\n");
            printf("Escolha uma opção de relatório: ");

            //Validação contra letras:
            if (scanf("%d", &subOpcao) != 1) {
                while (getchar() != '\n');
                subOpcao = -1;
            }

            //Direcionamento das rotinas de exibição que criamos juntas:
            switch(subOpcao) {
                case 1:
                    exibirTurmas(lista, totalAlunos);
                    break;
                case 2:
                    exibirAlunoPorMatricula(lista, totalAlunos);
                    break;
                case 3:
                    exibirAlunosPorTurma(lista, totalAlunos);
                    break;
                default:
                    printf("\n\033[1;33m[Opção inválida!]\033[0m Voltando ao menu principal.\n");
                    break;
            }
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