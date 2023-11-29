#include <stdio.h>
#include <stdlib.h>

#include "cabecalho.h"
#include "arquivo.h"

void salvarDados(cadAluno *alunos, const char *tipoArquivo) {
    FILE *salvarArquivo = fopen("alunos.txt", tipoArquivo);

    fprintf(salvarArquivo, "%d\n", alunos->idRegistro);
    fprintf(salvarArquivo, "%d\n", alunos->aluno->matricula);
    fprintf(salvarArquivo, "%s\n", alunos->aluno->nomeAluno);

    for (int i = 0; i < 7; i++) {
        fprintf(salvarArquivo, "%.2f\n", alunos->aluno->notas[i]);
    }

    for (int j = 0; j < 7; j++) {
        fprintf(salvarArquivo, "%d\n", alunos->aluno->faltas[j]);
    }

    fprintf(salvarArquivo, "\n");

    fclose(salvarArquivo);
}

void lerDados() {

}