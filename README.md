# Sistema de Gerenciamento Escolar (SGE)
Trabalho de conclusão de semestre referente a disciplina Laboratório de Programação, do COLTEC-UFMG. Orientado pela professora Camille Braga, utilizando a Linguagem C. 

O intuito do trabalho é utilizar todos os conceitos já aplicados em sala de aula. Aplicando no projeto lógica de programação, estrutura de dados e boas práticas. O tema escolhido foi "Sistema de Notas Escolares", que aborda conceitos como matrizes, vetores, ponteiros, arquivos e etc. Posteriormente, adotamos o nome para 'Sistema de Gerenciamento Escolar (SGE)'. 

### Fluxo de Funcionamento:
- 1º - Devemos cadastrar alunos;
- 2° - Registrar as notas por disciplina, para cada aluno;
- 3° - Calcular a média e situação de cada aluno;
- 4° - Ter um relatório com a situação do aluno e turma;
- 5° - Salvar em arquivo;

### Ferramentas:
Ao longo do desenvolvimento do trabalho utilizamos algumas ferramentas, sendo as principais:

- **CLion:** IDE otimizada para C/C++, facilitando o desenvolvimento;
- **CMake:** Depurador também otimizado para a IDE;
- **Canva:** Utilizado na elaboração dos Slides de apresentação;
- **Git & GitHub:** Ferramentas de versionamento de código;
- **ISO/IEC 9899:** Documentação da linguagem;

### Dependência Entre Arquivos:
- **aluno.h:** A base de dados tipada do sistema. Não possui dependências externas e define as estruturas Disciplina, Turma e Aluno. 
- **arquivo.h / notas.h / relatorio.h:** Possuem dependência direta de aluno.h, pois recebem registros ou ponteiros do tipo Aluno em suas assinaturas de função. 
- **main.c:** O centro da aplicação. Inclui todos os cabeçalhos autorais para orquestrar o fluxo de execução e gerenciar o ciclo de vida do vetor principal na memória.

