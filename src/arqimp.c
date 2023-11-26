#include "cabecalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//----------- FUNÇÕES DO MAIN ---------//

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

//----------- FUNÇÕES PARA INSERÇÃO DE DADOS ---------//

int inserirInicio(cadAluno *cadastroAluno, cadAluno registro)
{
    memcpy(cadastroAluno, &registro, sizeof(cadAluno));

    return 0;
}