//Aqui aplico o INCLUSION GUARD, para evitar que o compilador leia a mesma coisa duas vezes.
#ifndef RELATORIO_H //Se não conhecer o header.
#define RELATORIO_H //Define o header com os parametros passados.
#include "aluno.h"//É nescessária a adição desse .h por possuir dependência direta com o relatorio.h

typedef struct
{

} Relatorio;

//Funções:

void exibirAlunos(Aluno lista[], int totalAlunos);
voi exibirTurmas(Aluno lista[]);

#endif //Se já conhece o header, desconsidera os parâmetros.