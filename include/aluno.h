//Aqui aplico o INCLUSION GUARD, para evitar que o compilador leia a mesma coisa duas vezes.
#ifndef ALUNO_H //Se não conhecer o header.
#define ALUNO_H //Define o header com os parametros passados.

typedef struct
{
    char nome[61];
    int matricula;
    float notas, media;
    char situacao[31];
} Aluno;

//Funções:

void cadastrarAluno(Aluno lista[], int *totalAlunos); //Adiciona um aluno.
void removerAluno(Aluno lista[], int *totalAlunos); //Remove um aluno.
//O 'Aluno lista[]' é um vetor

#endif //Se já conhece o header, desconsidera os parâmetros.