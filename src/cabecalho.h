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
    int idRegistro;
    aluno *aluno;
    
} cadAluno;

// ASSINATURA DE FUNÇÕES: FUNÇÕES DO MAIN.
void menu();

// ASSINATURA DE FUNÇÕES: ALOCAÇÃO NA MEMÓRIA HEAP - DINÂMICA - //
void returnEndHeapAluno( void **vetAlunos);
void vetEndHeapAlunos(void **vetGeral);
void aumentarMemoria(cadAluno **cadastroAluno);
int moverDireitaEinserir ( cadAluno **cadastroAluno, cadAluno registro);
int moverFimEinserir ( cadAluno **cadastroAluno, cadAluno registro);



// ASSINATURA DE FUNÇÕES: INSERÇÃO DE REGISTRO NAS POSIÇÕES ESCOLHIDAS PELO USUÁRIO //
int inserirInicio(cadAluno **cadastroAluno, cadAluno registro);
int inserirFim(cadAluno **cadastroAluno, cadAluno registro);
int inserirPosiInformada (cadAluno *cadastroAluno, cadAluno registro, int posicao);
