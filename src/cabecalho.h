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
void returnEndHeapAluno( aluno **vetAlunos);
void vetEndHeapAlunos(cadAluno **vetGeral);
void aumentarMemoria(cadAluno **cadastroAluno);
int moverDireitaEinserir ( cadAluno **cadastroAluno, cadAluno registro);
int moverFimEinserir ( cadAluno **cadastroAluno, cadAluno registro);
int removerPosicao(int posicao, cadAluno **cadastroAluno);
int removerRegistro ( int id, cadAluno **cadastroAluno);



// ASSINATURA DE FUNÇÕES: INSERÇÃO DE REGISTRO NAS POSIÇÕES ESCOLHIDAS PELO USUÁRIO //
int inserirInicio(cadAluno **cadastroAluno, cadAluno registro);
int inserirFim(cadAluno **cadastroAluno, cadAluno registro);
int inserirPosiInformada (cadAluno **cadastroAluno, cadAluno registro, int posicao);
int moverLugarEscolhido (cadAluno **cadastroAluno, cadAluno registro, int posicao);
int apagarRegistro ( cadAluno **cadastroAluno, int posicao);