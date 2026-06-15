//Bibliotecas nativas do C:
#include <stdio.h>  // Biblioteca que implementa funções básicas, em especial o printf e scanf
#include <string.h> // Contém as funções ideais para manipulação de strings, como o strcspn e strcpy

//Headers autorais:
#include "aluno.h" // <-- ESSENCIAL: Ensina para o notas.c o que é um Aluno atualizado!
#include "notas.h"

//Funções:
void lancarNotas(Aluno lista[], int totalAlunos) {
    //Verifica se há alunos para poder aplicar as notas:
    if (totalAlunos == 0) {
        printf("\n⚠️ Erro: Nenhum aluno cadastrado no sistema ainda.\n");
        return;
    }

    int matriculaBusca;
    int indiceEncontrado = -1; //-1 significa "não encontrado"

    printf("\n               LANÇAR NOTAS                    \n");
    printf("Digite a matricula do aluno: ");
    scanf("%d", &matriculaBusca);

    //Passa por todos os alunos procurando a matrícula igual
    for (int i = 0; i < totalAlunos; i++) {
        if (lista[i].matricula == matriculaBusca) {
            indiceEncontrado = i; //Guarda onde ele está
            break; //Parar o laço
        }
    }

    //Se passamos pelo vetor inteiro e continuou -1, o aluno não existe:
    if (indiceEncontrado == -1) {
        printf("\nErro: Aluno com a matricula %d não foi encontrado.\n", matriculaBusca);
        return;
    }

    //Aluno encontrado, mas atinge o seu número máximo de materias:
    if (lista[indiceEncontrado].qtdMateriasCadastradas >= MAX_MATERIAS) {
        printf("\nErro: Este aluno ja atingiu o limite de %d materias.\n", MAX_MATERIAS);
        return;
    }

    //Busca a próxima posição livre no vetor de matérias do aluno:
    int idxMat = lista[indiceEncontrado].qtdMateriasCadastradas;

    printf("\nAluno(a) selecionado(a): \033[1m%s\033[0m\n", lista[indiceEncontrado].nome);

    //Limpa o buffer do teclado (o ENTER) que sobrou do scanf da matrícula:
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    //Seleção de qual matéria as notas vão ser lançadas:
    printf("Digite o nome da matéria (ex: Matematica): ");
    fgets(lista[indiceEncontrado].materias[idxMat].nomeDisciplina, 30, stdin);
    lista[indiceEncontrado].materias[idxMat].nomeDisciplina[strcspn(lista[indiceEncontrado].materias[idxMat].nomeDisciplina, "\n")] = '\0';

    //Coleta as notas:
    float soma = 0.0f;
    for (int i = 0; i < 4; i++) {
        printf("Digite a nota %d (0.0 a 10.0): ", i + 1);
        scanf("%f", &lista[indiceEncontrado].materias[idxMat].notas[i]);
        soma += lista[indiceEncontrado].materias[idxMat].notas[i];
    }

    //Calculo de média:
    float mediaFinal = soma / 4.0f;
    lista[indiceEncontrado].materias[idxMat].media = mediaFinal;

    //Define a situação automaticamente com base na média
    if (mediaFinal >= 7.0f) {
        strcpy(lista[indiceEncontrado].materias[idxMat].situacao, "Aprovado");
    } else {
        strcpy(lista[indiceEncontrado].materias[idxMat].situacao, "Reprovado");
    }

    //Informa ao aluno que ele agora tem mais uma matéria cadastrada
    lista[indiceEncontrado].qtdMateriasCadastradas++;
    printf("\n\033[1;32mNotas lançadas e média calculada com sucesso!\033[0m\n");
}