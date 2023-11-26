#include "cabecalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    cadAluno cadastroAluno;
    cadAluno *vetGeral = vetEndHeapAlunos();

    puts("----------------- CADASTRAR ALUNO ----------------");
    puts("[1] - Inserir Aluno no Inicio");
    puts("[2] - Cadastrar Aluno");
    puts("[3] - Cadastrar Aluno");
    puts("[4] - Cadastrar Aluno");
    puts("[5] - Cadastrar Aluno");
    puts("[6] - Cadastrar Aluno");
    puts("[7] - Cadastrar Aluno");
    puts("[8] - Deseja Sair?");

    int escolha;
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:

        printf("Iinsira o ID de registro do aluno:");
        scanf("%d", &cadastroAluno.idRegistro);
        cadastroAluno.aluno = returnEndHeapAluno(&cadastroAluno.aluno);
        printf("Digite o nome do  aluno:");
        scanf("%s", &cadastroAluno.aluno->nomeAluno);
        printf("Digite a nota do aluno:");
        scanf("%d", &cadastroAluno.aluno->notas);
        printf("Digite a matricula do aluno:");
        scanf("%d", &cadastroAluno.aluno->matricula);
        printf("Digite as faltas do aluno:");
        scanf("%d", &cadastroAluno.aluno->faltas);
        
        

        inserirInicio(vetGeral, cadastroAluno);

        break;

    case 2:
        //////////////
        break;

    case 8:
        puts("Saindo!.......\n");
        break;

    default:
        puts("Digite escolha valida!\n");
        
    }

    return 0;
}