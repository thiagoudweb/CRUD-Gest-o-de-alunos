#include "cabecalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//----------- FUNÇÃO MAIN ---------//
int tamInicial = 10;
int tamAtualVet = 0;
void menu()
{
    cadAluno *vetGeral;
    vetEndHeapAlunos(&vetGeral);
    cadAluno cadastroAluno;

    int bool = 1;
    while (bool == 1)
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
                returnEndHeapAluno(&cadastroAluno.aluno);
                printf("Digite o nome do  aluno:");
                scanf("%s", &cadastroAluno.aluno->nomeAluno);
                printf("Digite a nota do aluno:");
                scanf("%d", &cadastroAluno.aluno->notas);
                printf("Digite a matricula do aluno:");
                scanf("%d", &cadastroAluno.aluno->matricula);
                printf("Digite as faltas do aluno:");
                scanf("%d", &cadastroAluno.aluno->faltas);
                //                 ESCREVENDO DADOS NA HEAP                 //
                inserirInicio(&vetGeral, cadastroAluno);

            case 2:
                //////////////

            case 8:
                puts("Saindo!.......\n");
                bool = 0;
            }
        }
    }
}

//----------- FUNÇÕES DE ALOCAÇÃO ---------//

// -- Alocação de memória para 10 registros iniciais ( FUNÇÃO DE ALOCAÇÃO GENÉRICA > Tipagem na variavel do menu de atribuição) --
void vetEndHeapAlunos(void **vetGeral)
{
    // verificando se o espaço de vetGeral na stack foi alocado com sucesso
    if (vetGeral == NULL)
    {
        printf("O ponteiro vetGeral é inválido.\n");
    }

    else
    {
        // alocando espaço na heap e atribuindo a *vetGeral no menu > tipagem integrada no *vetGeral no menu.
        void *endTemp = calloc(10, sizeof(cadAluno));

        if (endTemp == NULL)
        {
            printf("Falha ao alocar a memória! Espaço insuficiente");
        }
        else
        {
            *vetGeral = endTemp;
        }
    }
}
// -- Alocando espaço para o membro >Aluno< na struct CadAluno --

void returnEndHeapAluno(void **vetAlunos)
{
    void *endTemp = calloc(1, sizeof(aluno));
    if (endTemp == NULL)
    {
        printf("A alocação de alunos falho!");
    }
    else
    {
        *vetAlunos = endTemp;
    }
}

//----------- FUNÇÕES PARA INSERÇÃO DE DADOS NO VETOR DE ALUNOS ---------//

int inserirInicio(cadAluno **cadastroAluno, cadAluno registro)
{
    // verificando se o tamanho atual é igual ao do vetor //
    if (tamAtualVet == tamInicial)
    {
        void *endTem = realloc (*cadastroAluno, tamInicial * sizeof(cadAluno));
        if (endTem == NULL)
        {
            printf("Espaço de memória insuficiente.");
        }
        else
        {

            *cadastroAluno = endTem;
        }
    }
    
    // else if (/* condition */)
    // {
    //     /* code */
    // }
    

    return 0;
}