#include <stdio.h>
#include <locale.h>
#include "aluno.h"
#include "menu.h"
#include "notas.h"
#include "relatorio.h"
#include "arquivo.h"

int main(void)
{
    setlocale(LC_ALL, "Portuguese"); //Estabelece por padrão as acentuações da lingua portuguesa;
    Aluno lista[50];
    int totalAlunos = 0; //Contador inicial de alunos, inciamos em zero
    int opcao;

    do
    {
        //Chamada pro Menu:
        opcao = exibirMenu();

        switch (opcao)
        {
            case 1:
            printf("\n\033[1;33m[Aviso]\033[0m Você escolheu a opção: Cadastrar Aluno (Função será ativada na Fase 4).\n");
            break;

        case 2:
            // Na Fase 4: registrarNotas(lista, totalAlunos);
            printf("\n\033[1;33m[Aviso]\033[0m Você escolheu a opção: Registrar Notas (Função será ativada na Fase 4).\n");
            break;

        case 3:
            // Na Fase 4: exibirAlunos(lista, totalAlunos);
            printf("\n\033[1;33m[Aviso]\033[0m Você escolheu a opção: Exibir Alunos (Função será ativada na Fase 4).\n");
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
