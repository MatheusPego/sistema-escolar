//Aqui aplico o INCLUDE GUARDS, para evitar que o compilador leia a mesma coisa duas vezes.
#ifndef RELATORIO_H //Se não conhecer o header.
#define RELATORIO_H //Define o header com os parametros passados.
#include "aluno.h"//É nescessária a adição desse .h por possuir dependência direta com o relatorio.h

//Funções:
void exibirAlunosPorTurma(Aluno lista[], int totalAlunos);
void exibirAlunoPorMatricula(Aluno lista[], int totalAlunos);
void exibirTurmas(Aluno lista[], int totalAlunos);

#endif //Se já conhece o header, desconsidera os parâmetros.