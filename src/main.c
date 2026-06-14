//Bibliotecas nativas:
#include <stdio.h> //Biblioteca que implementa funções básicas, em especial o printf e scanf
#include <locale.h> //Biblioteca para estabelecer adequações de linguagem.
#include <stdlib.h> //Biblioteca para malloc(), free(), realloc()

//Headers Autorais:
#include "aluno.h"
#include "menu.h"
#include "notas.h"
#include "relatorio.h"
#include "arquivo.h"

int main(void)
{
    setlocale(LC_ALL, "Portuguese"); //Estabelece por padrão as acentuações da língua portuguesa;

    Aluno *lista = NULL; //Lista de todos os alunos (ponteiro para a Heap).
    int totalAlunos = 0; //Contador inicial de alunos, iniciamos em zero.
    int capacidadedados = 10; // Capacidade inicial padrão do sistema
    int opcao; //Variável para capturar a resposta do Menu principal.
    int subOpcao; //Variável para capturar a escolha do submenu de relatórios.

    // CORREÇÃO 1: Alocação inicial de segurança na Heap para o programa iniciar estável
    lista = (Aluno *)malloc(capacidadedados * sizeof(Aluno));
    if (lista == NULL) {
        printf("\n\033[1;31m[Erro Fatal]\033[0m Falha crítica do Sistema Operacional ao conceder RAM.\n");
        return 1; // Encerra o programa se o computador estiver sem memória
    }

    //Chamada corrigida com os 3 parâmetros dinâmicos usando endereço (&)
    carregarDados(&lista, &totalAlunos, &capacidadedados);

    do
    {
        //Chamada para o Menu:
        opcao = exibirMenu();

        switch (opcao)
        {
        case 1:
            printf("\n\033[1;33m[Aviso]\033[0m Você escolheu a opção: Cadastrar Aluno.\n");
            cadastrarAluno(&lista, &totalAlunos, &capacidadedados);
            salvarDados(lista, totalAlunos);
            break;

        case 2:
            printf("\n\033[1;33m[Aviso]\033[0m Você escolheu a opção: Registrar Notas.\n");
            lancarNotas(lista, totalAlunos);
            salvarDados(lista, totalAlunos);
            break;

        case 3:
            printf("\n\033[1;33m[Aviso]\033[0m Você escolheu a opção: Exibir Alunos.\n");

            //Construção do submenu limpo (Removido o print duplicado):
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

            //Faz o uso das funções dentro do submenu:
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
            break; // Removido o segundo break redundante que existia aqui

        case 4:
            printf("\n\033[1;33m[Aviso]\033[0m Você escolheu a opção: Excluir Aluno.\n");
            excluirAluno(&lista, &totalAlunos, &capacidadedados);

            //Salva a nova configuração limpa imediatamente no arquivo binário
            salvarDados(lista, totalAlunos);
            break;

        case 5:
            printf("\nSaindo do sistema. Obrigado por utilizar o SGE!\n");
            break;

        default:
            printf("\n\033[1;33m[Opção inválida!]\033[0m Digite um número válido (1 ... 5).\n");
            break;
        }
    }
    while (opcao != 5);

    //Liberação obrigatória da memória RAM antes de fechar o software
    free(lista);
    lista = NULL;

    return 0;
}