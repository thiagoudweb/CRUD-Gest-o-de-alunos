#include "cabecalho.h"
#include "arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//----------- FUNÇÃO MAIN ---------//
int tamInicial = 10;
int tamFixo = 10;
int tamAtualVet = 0;
int escolha;
int escolhaUsuario;

void menu()
{
    puts("----------------- CADASTRAR ALUNO ----------------");
    puts("[1] - Inserir Aluno no Inicio");
    puts("[2] - Inserir Aluno no fim");
    puts("[3] - Inserir dados em um local especifico");
    puts("[4] - Deletar posição");
    puts("[5] - Deletar registro");
    puts("[6] - ------");
    puts("[7] - Apresentar Dados");
    puts("[8] - Deseja Sair?");
    puts("--------------------------------------------------\n");
}

void novoRegistroInicio(cadAluno *vetGeral, cadAluno cadastroAluno)
{
    printf("Iinsira o ID de registro do aluno:\n");
    scanf("%d", &cadastroAluno.idRegistro);

    returnEndHeapAluno(&cadastroAluno.aluno);

    printf("Digite o nome do  aluno:\n");
    scanf("%s", &cadastroAluno.aluno->nomeAluno);

    printf("Digite 7 notas do aluno:\n");
    for (int i = 0; i < 7; i++)
    {
        scanf("%f", &cadastroAluno.aluno->notas[i]);
    }

    printf("Digite a matricula do aluno:\n");
    scanf("%d", &cadastroAluno.aluno->matricula);

    printf("Digite as 7 faltas do aluno:\n");
    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &cadastroAluno.aluno->faltas[i]);
    }

    //                 ESCREVENDO DADOS NA HEAP                 //
    inserirInicio(&vetGeral, cadastroAluno);
}

void novoRegistroFim(cadAluno *vetGeral, cadAluno cadastroAluno)
{
    printf("Iinsira o ID de registro do aluno:\n");
    scanf("%d", &cadastroAluno.idRegistro);

    returnEndHeapAluno(&cadastroAluno.aluno);

    printf("Digite o nome do  aluno:\n");
    scanf("%s", &cadastroAluno.aluno->nomeAluno);

    printf("Digite 7 notas do aluno:\n");
    for (int i = 0; i < 7; i++)
    {
        scanf("%f", &cadastroAluno.aluno->notas[i]);
    }

    printf("Digite a matricula do aluno:\n");
    scanf("%d", &cadastroAluno.aluno->matricula);

    printf("Digite as 7 faltas do aluno:\n");
    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &cadastroAluno.aluno->faltas[i]);
    }

    //                 ESCREVENDO DADOS NA HEAP                 //
    inserirFim(&vetGeral, cadastroAluno);
}

void novoRegistroPosEspecifica(cadAluno *vetGeral, cadAluno cadastroAluno)
{
    printf("DIGITE A POSIÇÃO QUE VOCÊ QUER INSERIR O REGISTRO\n");

    int escolhaUsuario;
    scanf("%d", &escolhaUsuario);

    printf("Iinsira o ID de registro do aluno:\n");
    scanf("%d", &cadastroAluno.idRegistro);

    returnEndHeapAluno(&cadastroAluno.aluno);

    printf("Digite o nome do  aluno:\n");
    scanf("%s", &cadastroAluno.aluno->nomeAluno);

    printf("Digite 7 notas do aluno:\n");
    for (int i = 0; i < 7; i++)
    {
        scanf("%f", &cadastroAluno.aluno->notas[i]);
    }

    printf("Digite a matricula do aluno:\n");
    scanf("%d", &cadastroAluno.aluno->matricula);

    printf("Digite as 7 faltas do aluno:\n");
    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &cadastroAluno.aluno->faltas[i]);
    }

    //                 ESCREVENDO DADOS NA HEAP                 //
    inserirPosiInformada(&vetGeral, cadastroAluno, escolhaUsuario);
}

void apagarPosEspecifica(cadAluno *vetGeral, cadAluno cadastroAluno)
{
    printf("DIGITE A POSIÇÃO QUE VOCÊ DESEJA REMOVER \n");
    scanf("%d", &escolhaUsuario);

    if (escolhaUsuario > tamAtualVet)
    {
        printf("Não existe bloco alocado nessa posição informada. \n");
    }
    else
    {
        deletarPosicoes(&vetGeral, escolhaUsuario);
    }
}

void chamadaPrincipal()
{
    cadAluno *vetGeral;
    vetEndHeapAlunos(&vetGeral);

    cadAluno cadastroAluno;

    while (1)
    {
        menu();

        int tam = lerDados(vetGeral);
        tamAtualVet = tam;

        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            novoRegistroInicio(vetGeral, cadastroAluno);
            break;

        case 2:
            novoRegistroFim(vetGeral, cadastroAluno);
            break;

        case 3:
            novoRegistroPosEspecifica(vetGeral, cadastroAluno);
            break;

        case 4:
            apagarPosEspecifica(vetGeral, cadastroAluno);
            break;

        case 5:
            printf("Insirida o id do registro do aluno: ");
            scanf("%d", &escolhaUsuario);

            apagarRegistro(&vetGeral, escolhaUsuario);
            break;

        case 7:
            int tam = lerDados(vetGeral);

            puts("\n------------------------ APRESENTANDO DADOS ------------------------");
            imprimirDados(vetGeral, tam);
            puts("----------------------------------------------------------------------\n");

            break;
        }

        if (escolha < 1 || escolha > 8)
        {
            puts("Escolha uma opção válida!\n");
        }
        else if (escolha == 8)
        {
            puts("Saindo!.......\n");
            break;
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
            printf("Falha ao alocar a memória! Espaço insuficiente\n");
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
        printf("A alocação de alunos falho!\n");
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
}

// ----- inserir em um local especifico  ------ //
int inserirPosiInformada(cadAluno **cadastroAluno, cadAluno registro, int posicao)
{
    if (tamAtualVet == tamInicial)
    {
        aumentarMemoria(cadastroAluno);
        moverLugarEscolhido(cadastroAluno, registro, posicao);
    }
    else
    {
        moverLugarEscolhido(cadastroAluno, registro, posicao);
    }
}

// ----- Deleltar posição  ------ //
int deletarPosicoes(cadAluno **cadastroAluno, int posicao)
{
    removerPosicao(posicao, cadastroAluno);
}

// ----- deletar registro, mas mantendo o espaço ---- //
int apagarRegistro(cadAluno **cadastroAluno, int posicao)
{
    removerRegistro(posicao, cadastroAluno);
}

//  FUNÇÃO PARA AUMENTAR MEMÓRIA //
void aumentarMemoria(cadAluno **cadastroAluno)
{
    void *endTem = realloc(*cadastroAluno, tamFixo * sizeof(cadAluno));
    if (endTem == NULL)
    {
        printf("Espaço de memória insuficiente.\n");
    }
    else
    {
        *cadastroAluno = endTem;
        tamInicial += 10;
    }
}

// FUNÇÕES PARA INSERIR CADASTROS DA LISTA //
// ---- mover direita inicio  //
int moverDireitaEinserir(cadAluno **cadastroAluno, cadAluno registro)
{
    cadAluno *endComp = *cadastroAluno;

    if ((endComp + 0)->idRegistro == 0)
    {
        (endComp + 0)->idRegistro = registro.idRegistro;
        (endComp + 0)->aluno = registro.aluno;

        salvarDados(endComp, "w", tamAtualVet);

        printf("Cadastro realizado com sucesso!\n");

        tamAtualVet++;

        return 1;
    }
    else
    {
        memmove(endComp + 1, endComp, tamAtualVet * sizeof(cadAluno));

        (endComp + 0)->idRegistro = registro.idRegistro;
        (endComp + 0)->aluno = registro.aluno;

        salvarDados(endComp, "w", tamAtualVet);

        printf("Cadastro realizado com sucesso!\n");

        tamAtualVet++;

        return 1;
    }
}

// inserir no fim da lista //
int moverFimEinserir(cadAluno **cadastroAluno, cadAluno registro)
{
    int escolhaUser;
    cadAluno *endComp = *cadastroAluno;

    if (tamAtualVet == 0)
    {
        printf("Você ainda não possui registros. Deseja alocar no inicio?\n");

        printf("Digite 1 para sim ou 2 para não\n");
        scanf("%d", &escolhaUser);

        if (escolhaUser == 2)
        {
            printf("Você optou por sair.\n");

            return 0;
        }
        else
        {
            (endComp + 0)->idRegistro = registro.idRegistro;
            (endComp + 0)->aluno = registro.aluno;

            salvarDados(endComp, "w", tamAtualVet);

            printf("Cadastro realizado com sucesso!\n");

            tamAtualVet++;

            return 1;
        }
    }
    else
    {
        (endComp + tamAtualVet)->idRegistro = registro.idRegistro;
        (endComp + tamAtualVet)->aluno = registro.aluno;

        salvarDados(endComp, "w", tamAtualVet);

        printf("Cadastro realizado com sucesso!\n");

        tamAtualVet++;

        return 1;
    }
}

// inserir em um lugar especifico //
int moverLugarEscolhido(cadAluno **cadastroAluno, cadAluno registro, int posicao)
{
    cadAluno *varTemp = *cadastroAluno;

    if ((varTemp + posicao)->idRegistro == 0)
    {
        (varTemp + posicao)->idRegistro = registro.idRegistro;
        (varTemp + posicao)->aluno = registro.aluno;

        salvarDados(varTemp, "w", tamAtualVet);

        printf("Cadastro realizado com sucesso!\n");

        tamAtualVet++;

        return 1;
    }
    else
    {
        memmove(varTemp + posicao + 1, varTemp + posicao, (tamAtualVet - posicao) * sizeof(cadAluno));

        (varTemp + posicao)->idRegistro = registro.idRegistro;
        (varTemp + posicao)->aluno = registro.aluno;

        salvarDados(varTemp, "w", tamAtualVet);

        printf("Cadastro realizado com sucesso!\n");

        tamAtualVet++;

        return 1;
    }
}

// remover de um lugar especifico //
int removerPosicao(int posicao, cadAluno **cadastroAluno)
{
    cadAluno *varTemp = *cadastroAluno;

    if ((varTemp + posicao)->idRegistro == 0)
    {
        printf("Não há nenhum registro nessa posição.\n");
        return 0;
    }
    else
    {
        (varTemp + posicao)->idRegistro = 0;

        free((varTemp + posicao)->aluno);

        (varTemp + posicao)->aluno = NULL;

        salvarDados(varTemp, "w", tamAtualVet);

        tamAtualVet--;

        return 1;
    }
}

// remover aluno por id ( identificador inicial do bloco do vetor ) //
int removerRegistro(int id, cadAluno **cadastroAluno)
{
    cadAluno *varTemp = *cadastroAluno;

    for (int i = 0; i < tamAtualVet; i++)
    {
        if ((varTemp + i)->idRegistro == id)
        {
            for (int j = i; j < tamAtualVet - 1; j++)
            {
                (varTemp + j)->idRegistro = (varTemp + j + 1)->idRegistro;
                (varTemp + j)->aluno = (varTemp + j + 1)->aluno;
            }

            (varTemp + tamAtualVet - 1)->idRegistro = 0;

            free((varTemp + tamAtualVet - 1)->aluno);

            (varTemp + tamAtualVet - 1)->aluno = NULL;

            salvarDados(varTemp, "w", tamAtualVet);

            printf("Registro removido com sucesso!");
            tamAtualVet--;

            return 1;
        }
    }

    return 0;
}