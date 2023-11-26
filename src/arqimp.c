#include "cabecalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//----------- FUNÇÃO MAIN ---------//

void menu()
{

    cadAluno cadastroAluno;
    cadAluno *vetGeral = vetEndHeapAlunos();

    while (1)
    {

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

        if (escolha < 1 || escolha > 8)
        {
            puts("Escolha uma opção válida!");
            continue;
        }
        else
        {
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
                //                 ESCREVENDO DADOS NA HEAP                 //
                inserirInicio(vetGeral, cadastroAluno);

            case 2:
                //////////////

            case 8:
                puts("Saindo!.......\n");
                break;

                ;
            }
        }
    }
}

//----------- FUNÇÕES PARA INSERIR ALUNOS ---------//

// -- Inserir registro no inicio //
void funcMainInserirInicio()
{
}
// -- Inserir registro no fim //
void funcMainInserirFim()
{
}
// -- inserir em local especifico //
void funcMainInserirPosEspec()
{
}

//----------- FUNÇÕES DE ALOCAÇÃO ---------//

// -- Alocação de memória para 10 registros iniciais --
cadAluno *vetEndHeapAlunos()
{
    cadAluno *vetEndAluno = malloc(10 * sizeof(cadAluno));
    return vetEndAluno;
}
// -- Alocando espaço para o membro >Aluno< na struct CadAluno --

aluno *returnEndHeapAluno()
{
    aluno *heapAluno = malloc(sizeof(aluno));
    return heapAluno;
}

//----------- FUNÇÕES PARA INSERÇÃO DE DADOS NO VETOR DE ALUNOS ---------//

int inserirInicio(cadAluno *cadastroAluno, cadAluno registro)
{
    memcpy(cadastroAluno, &registro, sizeof(cadAluno));

    return 0;
}