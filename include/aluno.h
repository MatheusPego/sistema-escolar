//Aqui aplico o INCLUSION GUARD, para evitar que o compilador leia a mesma coisa duas vezes.
#ifndef ALUNO_H //Se não conhecer o header.
#define ALUNO_H //Define o header com os parametros passados.

#define MAX_ALUNOS 50 //Limite de alunos totais.
#define MAX_MATERIAS 5 //Limite de matérias que um aluno pode ter.

//Struct para cada matéria:
typedef struct {
    char nomeDisciplina[30];
    float notas[4];
    float media;
    char situacao[15]; //Aprovado ou Reprovado.
} Disciplina;

//Struct aluno:
typedef struct
{
    char nome[61];
    int matricula;
    Disciplina materias[MAX_MATERIAS];
    float notas[4];
    float media;
    int qtdMateriasCadastradas;
} Aluno;

//Funções:
void cadastrarAluno(Aluno lista[], int *totalAlunos); //Adiciona um aluno.
void removerAluno(Aluno lista[], int *totalAlunos); //Remove um aluno.
//O 'Aluno lista[]' é um vetor declarado na main

#endif //Se já conhece o header, desconsidera os parâmetros.