#include "cabecalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    
    int entradaUsuario;
    int bool = 1;
    cadAluno *vetGeral = vetEndHeapAlunos(&vetGeral);
    

    while (bool = 1)
    {
        telaMenu();
        scanf("%d", &entradaUsuario);

        switch (entradaUsuario)
        {
        case 1:
            inserirInicioMain(&vetGeral);
            continue;
        
        case 2:
        continue;
        }
    }
    
    














    return 0;
}