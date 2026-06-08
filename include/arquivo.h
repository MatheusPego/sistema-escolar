//Aqui aplico o INCLUSION GUARD, para evitar que o compilador leia a mesma coisa duas vezes.
#ifndef ARQUIVO_H //Se não conhecer o header.
#define ARQUIVO_H //Define o header com os parametros passados.
#include "aluno.h" //É nescessária a adição desse .h por possuir dependência direta com o arquivo.h

typedef struct
{

} Arquivo;

//Funções:
void salvarDados(Aluno lista[], int totalAlunos);
void carregarDados(Aluno lista[], int *totalAlunos);
void removerDados(Aluno lista[], int *totalAlunos);


#endif //Se já conhece o header, desconsidera os parâmetros.