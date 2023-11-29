#include <stdio.h>
#include <stdlib.h>

#include "cabecalho.h"
#include "arquivo.h"

void salvarDados(cadAluno *alunos, const char *tipoArquivo, int tamanhoAtual) {
    FILE *salvarArquivo = fopen("alunos.txt", tipoArquivo);

    if (salvarArquivo == NULL) {
        puts("O arquivo pode não existir, crie um no diretorio raiz da pasta com o nome: alunos.txt");
        exit(1);
    }

    for (int k = 0; k <= tamanhoAtual; k++) {
        fprintf(salvarArquivo, "%d\n", alunos[k].idRegistro);
        fprintf(salvarArquivo, "%d\n", alunos[k].aluno->matricula);
        fprintf(salvarArquivo, "%s\n", alunos[k].aluno->nomeAluno);

        for (int i = 0; i < 7; i++) {
            fprintf(salvarArquivo, "%.2f\n", alunos[k].aluno->notas[i]);
        }

        for (int j = 0; j < 7; j++) {
            fprintf(salvarArquivo, "%d\n", alunos[k].aluno->faltas[j]);
        }

        fprintf(salvarArquivo, "\n");    
    }

    fclose(salvarArquivo);
}

void lerDados(cadAluno *carregarAlunos) {
    FILE *lerArquivo = fopen("alunos.txt", "rb");

    if (lerArquivo == NULL) {
        puts("O arquivo pode não existir, crie um no diretorio raiz da pasta com o nome: alunos.txt");
        exit(1);
    } else {
        fread(carregarAlunos, sizeof(cadAluno), 1, lerArquivo);
        printf("id registro: %d\n", carregarAlunos->idRegistro);
        fclose(lerArquivo);
    }
}