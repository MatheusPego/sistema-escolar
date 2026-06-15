cmake_minimum_required(VERSION 4.2)

#Nome do arquivo
project(trabalho C)

#Set para utilizar a versão 17 da Linguagem C
set(CMAKE_C_STANDARD 17)

#Atualizando os arquivos, apontando para dentro da pasta 'src'
add_executable(trabalho
        src/main.c
        src/menu.c
        src/aluno.c
        src/notas.c
        src/arquivo.c
        src/relatorio.c
)

#Passando para o compilador onde vão ficar os manuais (.h)
target_include_directories(trabalho PUBLIC include)