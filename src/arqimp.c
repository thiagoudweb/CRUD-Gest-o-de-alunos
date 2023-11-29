#include "cabecalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//----------- FUNÇÃO MAIN ---------//
int tamInicial = 10;
int tamFixo = 10;
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
        puts("[2] - Inserir Aluno no fim");
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
                printf("Digite 7 notas do aluno:");
                for (int i = 0; i < 7; i++)
                {
                    scanf("%d", &cadastroAluno.aluno->notas[i]);
                }

                printf("Digite a matricula do aluno:");
                scanf("%d", &cadastroAluno.aluno->matricula);
                printf("Digite as 7 faltas do aluno:");
                for (int i = 0; i < 7; i++)
                {
                    scanf("%d", &cadastroAluno.aluno->faltas[i]);
                }

                //                 ESCREVENDO DADOS NA HEAP                 //
                inserirInicio(&vetGeral, cadastroAluno);
                continue;

            case 2:

                printf("Iinsira o ID de registro do aluno:");
                scanf("%d", &cadastroAluno.idRegistro);
                returnEndHeapAluno(&cadastroAluno.aluno);
                printf("Digite o nome do  aluno:");
                scanf("%s", &cadastroAluno.aluno->nomeAluno);
                printf("Digite 7 notas do aluno:");
                for (int i = 0; i < 7; i++)
                {
                    scanf("%d", &cadastroAluno.aluno->notas[i]);
                }

                printf("Digite a matricula do aluno:");
                scanf("%d", &cadastroAluno.aluno->matricula);
                printf("Digite as 7 faltas do aluno:");
                for (int i = 0; i < 7; i++)
                {
                    scanf("%d", &cadastroAluno.aluno->faltas[i]);
                }

                //                 ESCREVENDO DADOS NA HEAP                 //
                inserirFim(&vetGeral, cadastroAluno);
                continue;

            case 8:
                puts("Saindo!.......\n");
                bool = 0;
            }
        }
    }
}

//----------- FUNÇÕES DE ALOCAÇÃO ---------//

// -- Alocação de memória para 10 registros iniciais ( FUNÇÃO DE ALOCAÇÃO GENÉRICA > Tipagem na variavel do menu de atribuição) --
void vetEndHeapAlunos(cadAluno **vetGeral)
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

void returnEndHeapAluno(aluno **vetAlunos)
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

// ------- FUNÇÕES PARA INSERIR ALUNOS ------------ //

// -----        inserir no inicio ------- //
int inserirInicio(cadAluno **cadastroAluno, cadAluno registro)
{
    // verificando se o tamanho atual é igual ao do vetor //
    if (tamAtualVet == tamInicial)
    {
        aumentarMemoria(cadastroAluno);
        moverDireitaEinserir(cadastroAluno, registro);
    }

    else
    {
        moverDireitaEinserir(cadastroAluno, registro);
    }

    return 0;
}

// -----        inserir no fim ------- //
int inserirFim(cadAluno **cadastroAluno, cadAluno registro)
{

    if (tamAtualVet == tamInicial)
    {
        aumentarMemoria(cadastroAluno);
        moverFimEinserir(cadastroAluno, registro);
    }

    else
    {
        moverFimEinserir(cadastroAluno, registro);
    }

    return 0;
}

//  FUNÇÃO PARA AUMENTAR MEMÓRIA //
void aumentarMemoria(cadAluno **cadastroAluno)
{

    void *endTem = realloc(*cadastroAluno, tamFixo * sizeof(cadAluno));
    if (endTem == NULL)
    {
        printf("Espaço de memória insuficiente.");
    }
    else
    {
        *cadastroAluno = endTem;
        tamInicial += 10;
    }
}

// FUNÇÃO PARA  MOVER OS DADOS PARA A DIREITA

// ---- mover direita inicio  //
int moverDireitaEinserir(cadAluno **cadastroAluno, cadAluno registro)
{

    cadAluno *endComp = *cadastroAluno;
    if ((endComp + 0)->idRegistro == 0)
    {

        (endComp + 0)->idRegistro = registro.idRegistro;
        (endComp + 0)->aluno = registro.aluno;
        printf("Cadastro realizado com sucesso!");
        tamAtualVet++;
        return 1;
    }
    else
    {

        memmove(endComp + 1, endComp, tamAtualVet * sizeof(cadAluno));

        (endComp + 0)->idRegistro = registro.idRegistro;
        (endComp + 0)->aluno = registro.aluno;
        printf("Cadastro realizado com sucesso!");
        tamAtualVet++;
        return 1;
    }
}

// FUNÇÃO PARA INSERIR NO FIM //

int moverFimEinserir(cadAluno **cadastroAluno, cadAluno registro)
{
    int escolhaUser;
    cadAluno *endComp = *cadastroAluno;
    if (tamAtualVet == 0)
    {
        printf("Você ainda não possui registros. Deseja alocar no inicio?");
        printf("Digite 1 para sim ou 2 para não");
        scanf("%d", &escolhaUser);
        if (escolhaUser == 2)
        {
            printf("Você optou por sair.");
            return 0;
        }
        else
        {
            (endComp + 0)->idRegistro = registro.idRegistro;
            (endComp + 0)->aluno = registro.aluno;
            printf("Cadastro realizado com sucesso!");
            tamAtualVet++;
            return 1;
        }
    }
    else
    {
        (endComp + (tamAtualVet + 1))->idRegistro = registro.idRegistro;
        (endComp + (tamAtualVet + 1))->aluno = registro.aluno;
        printf("Cadastro realizado com sucesso!");
        tamAtualVet++;
        return 1;
    }
}

// IMPLEMENTAÇÃO DE ESCOLHAS DO USUÁRIO //