// TAD MATRICULA //
typedef struct
{
    int matricula;
    float notas[7];
    char nomeAluno[50];
    int faltas[7];
} aluno;
// TAD ALUNO //
typedef struct
{
    aluno *aluno;
    int idRegistro;

} cadAluno;

// ASSINATURA DE FUNÇÕES: FUNÇÕES DO MAIN.

// ASSINATURA DE FUNÇÕES: ALOCAÇÃO NA MEMÓRIA HEAP - DINÂMICA - //
aluno *returnEndHeapAluno();
cadAluno *vetEndHeapAlunos();

// ASSINATURA DE FUNÇÕES: INSERÇÃO DE REGISTRO NAS POSIÇÕES ESCOLHIDAS PELO USUÁRIO //
int inserirInicio(cadAluno *cadastroAluno, cadAluno registro);
int inserirFim(cadAluno *cadastroAluno, cadAluno registro);
int inserirPosiInformada (cadAluno *cadastroAluno, cadAluno registro, int posicao);
