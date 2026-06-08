//Aqui aplico o INCLUSION GUARD, para evitar que o compilador leia a mesma coisa duas vezes.
#ifndef ALUNOS_H //Se não conhecer o header.
#define ALUNOS_H //Define o header com os parametros passados.

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

#endif //Se já conhece o header, desconsidera os parâmetros.