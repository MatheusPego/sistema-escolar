//Aqui aplico o INCLUSION GUARD, para evitar que o compilador leia a mesma coisa duas vezes.
#ifndef NOTAS_H //Se não conhecer o header.
#define NOTAS_H //Define o header com os parametros passados.
#include "aluno.h" //É nescessária a adição desse .h por possuir dependência direta com o notas.h

typedef struct
{
    //Mesmo que por serem de mesmo tipo, eu as declarei linha a linha, para melhor leitura do código.
    float prova_1;
    float prova_2;
    float atividade_1;
    float atividade_2;
    float trabalho_Final;
} Notas;

//Funções:

void registrarNotas(Aluno lista[], int totalAlunos);

#endif //Se já conhece o header, desconsidera os parâmetros.