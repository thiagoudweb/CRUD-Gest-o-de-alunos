#include <stdio.h>
#include <stdlib.h>

#include "cabecalho.h"
#include "arquivo.h"

void salvarDados(cadAluno *alunos, const char *tipoArquivo, int tamanhoAtual)
{
    FILE *salvarArquivo = fopen("alunos.txt", tipoArquivo);

    if (salvarArquivo == NULL)
    {
        puts("O arquivo pode não existir, crie um no diretorio raiz da pasta com o nome: alunos.txt");
        exit(1);
    }

    for (int k = 0; k <= tamanhoAtual; k++)
    {
        fprintf(salvarArquivo, "%d\n", alunos[k].idRegistro);
        fprintf(salvarArquivo, "%d\n", alunos[k].aluno->matricula);
        fprintf(salvarArquivo, "%s\n", alunos[k].aluno->nomeAluno);

        for (int i = 0; i < 7; i++)
        {
            fprintf(salvarArquivo, "%.2f\n", alunos[k].aluno->notas[i]);
        }

        for (int j = 0; j < 7; j++)
        {
            fprintf(salvarArquivo, "%d\n", alunos[k].aluno->faltas[j]);
        }

        fprintf(salvarArquivo, "\n");
    }

    fclose(salvarArquivo);
}

int lerDados(cadAluno *carregarAlunos) {
    FILE *lerArquivo = fopen("alunos.txt", "r");

    if (lerArquivo == NULL) {
        puts("O arquivo pode não existir, crie um no diretório raiz da pasta com o nome: alunos.txt");
        exit(1);
    } else {
        int contador = 0;

        while (fscanf(lerArquivo, "%d", &carregarAlunos[contador].idRegistro) == 1) {
            carregarAlunos[contador].aluno = malloc(sizeof(aluno));

            fscanf(lerArquivo, "%d", &carregarAlunos[contador].aluno->matricula);
            fscanf(lerArquivo, "%s", carregarAlunos[contador].aluno->nomeAluno);

            for (int i = 0; i < 7; i++) {
                fscanf(lerArquivo, "%f", &carregarAlunos[contador].aluno->notas[i]);
            }

            for (int j = 0; j < 7; j++) {
                fscanf(lerArquivo, "%d", &carregarAlunos[contador].aluno->faltas[j]);
            }

            contador++;
        }

        fclose(lerArquivo);
        return contador;
    }
}


void imprimirDados(cadAluno *carregarAlunos, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("idRegistro: %d\nmatriculaAluno: %d\nnome: %s\nnotas: ", carregarAlunos[i].idRegistro, carregarAlunos[i].aluno->matricula, carregarAlunos[i].aluno->nomeAluno);
        for (int j = 0; j < 7; j++)
        {
            printf("%.2f ", carregarAlunos[i].aluno->notas[j]);
        }
        printf("\nfaltas: ");
        for (int j = 0; j < 7; j++)
        {
            printf("%d ", carregarAlunos[i].aluno->faltas[j]);
        }
        printf("\n\n");
    }
}