//Bibliotecas nativas:
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Header autoral:
#include "aluno.h"

void cadastrarAluno(Aluno **lista, int *totalAlunos, int *capacidade) {
    //Verifica se o vetor está lotado:
    if (*totalAlunos >= *capacidade) {
        //Dobra a capacidade atual para evitar chamadas excessivas ao realloc
        int novaCapacidade = (*capacidade) * 2;

        //Alocação em ponteiro temporário por segurança, evitando ocupação de memória desnecessária:
        Aluno *temp = (Aluno *)realloc(*lista, novaCapacidade * sizeof(Aluno));

        if (temp == NULL) {
            printf("\n\033[1;31m[Erro]\033[0m Memória RAM cheia! Não foi possível expandir o sistema.\n");
            return; //Aborta o cadastro mantendo os dados antigos intactos
        }

        //Se der certo, as variáveis reais da main recebem o update
        *lista = temp;
        *capacidade = novaCapacidade;
        printf("\n\033[1;32m[Sistema Expandido]\033[0m Capacidade aumentada para até %d alunos.\n", *capacidade);
    }

    //Acessos a memória usando a precedência de ponteiros: (*lista)[indice]
    printf("\n    Cadastro de Aluno    \n");
    printf("Digite a matrícula: ");
    scanf("%d", &((*lista)[*totalAlunos].matricula));

    //Limpa o buffer antes de ler strings
    while (getchar() != '\n');

    //Recebe nome para o Aluno:
    printf("Digite o nome do aluno: ");
    fgets((*lista)[*totalAlunos].nome, 50, stdin);
    //Remove o '\n' gerado pelo fgets
    (*lista)[*totalAlunos].nome[strcspn((*lista)[*totalAlunos].nome, "\n")] = '\0';

    //Recebe a turma para o Aluno:
    printf("Digite o código da turma: ");
    fgets((*lista)[*totalAlunos].turma.codigoTurma, 15, stdin);
    (*lista)[*totalAlunos].turma.codigoTurma[strcspn((*lista)[*totalAlunos].turma.codigoTurma, "\n")] = '\0';

    //Recebe o número da turma do Aluno:
    printf("Digite o número da sala: ");
    fgets((*lista)[*totalAlunos].turma.numeroSala, 10, stdin);
    (*lista)[*totalAlunos].turma.numeroSala[strcspn((*lista)[*totalAlunos].turma.numeroSala, "\n")] = '\0';

    //Inicializa campos vazios de matérias
    (*lista)[*totalAlunos].qtdMateriasCadastradas = 0;

    //Incrementa o contador de registros cadastrados
    (*totalAlunos)++;
    printf("\n\033[1;32m[Sucesso]\033[0m Aluno cadastrado com sucesso!\n");
}

void excluirAluno(Aluno **lista, int *totalAlunos, int *capacidade) {
    //Se não há alunos, não há o que excluir. Retonando o print com a mensagem referente a falta de alunos
    if (*totalAlunos == 0) {
        printf("\n\033[1;33m[Aviso]\033[0m Nenhum aluno cadastrado para exclusão.\n");
        return;
    }

    int matriculaBusca;
    int indiceEncontrado = -1;

    printf("\n    Exclusão de Aluno    \n");
    printf("Digite a matrícula do aluno que deseja EXCLUIR: ");
    scanf("%d", &matriculaBusca);

    //Procura na memória a matrícula informada
    for (int i = 0; i < *totalAlunos; i++) {
        //obrigatório os parênteses (*lista)[i] devido à precedência de operadores
        if ((*lista)[i].matricula == matriculaBusca) {
            indiceEncontrado = i;
            break; //Interrompe o laço assim que encontra
        }
    }

    //Se o ponteiro de busca percorreu tudo e o índice continuou -1, o aluno não existe
    if (indiceEncontrado == -1) {
        printf("\n\033[1;31m[Erro]\033[0m Aluno com a matrícula %d não foi encontrado.\n", matriculaBusca);
        return;
    }

    //Evita exclusões acidentais pedindo a confirmação
    char confirmacao;
    printf("Tem certeza que deseja excluir o aluno %s? (S/N): ", (*lista)[indiceEncontrado].nome);
    while (getchar() != '\n'); //Limpa o buffer do teclado
    scanf("%c", &confirmacao);

    if (confirmacao == 'S' || confirmacao == 's') {

        //"SHIFT" (Deslocamento): Puxa todos os alunos subsequentes uma posição para trás
        for (int i = indiceEncontrado; i < (*totalAlunos) - 1; i++) {
            (*lista)[i] = (*lista)[i + 1];
        }

        //Atualiza a contagem de alunos:
        (*totalAlunos)--;
        printf("\n\033[1;32m[Sucesso]\033[0m Aluno removido da memória com sucesso!\n");

        /*Redução física do vetor na Heap. Se o total de alunos cair para 1/4 (25%) ou menos da capacidade total,
        e a capacidade atual for maior que o piso mínimo inicial de 10 espaços.*/
        if (*totalAlunos <= (*capacidade) / 4 && *capacidade > 10) {
            int novaCapacidade = (*capacidade) / 2; //Corta a capacidade pela metade

            if (novaCapacidade < 10) {
                novaCapacidade = 10; //Garante que nunca fique menor que o piso inicial estabelecido
            }

            //Realoca para um tamanho menor, liberando o excesso de RAM de volta para o SO
            Aluno *temp = (Aluno *)realloc(*lista, novaCapacidade * sizeof(Aluno));
            if (temp != NULL) {
                *lista = temp;       //Atualiza o endereço real da main
                *capacidade = novaCapacidade; //Atualiza a nova capacidade reduzida
                printf("\033[1;36m[Otimização]\033[0m Memória RAM desalocada. Capacidade reduzida para %d espacos.\n", *capacidade);
            }
        }
    } else {
        printf("\nExclusão cancelada pelo usuário.\n");
    }
}