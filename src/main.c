#include "cabecalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    
    int entradaUsuario;
    int bool = 1;
    cadAluno *vetGeral;
    vetEndHeapAlunos(&vetGeral);

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
            inserirFimMain(&vetGeral);
            continue;
        
        case 3:
            inserirLocalEscolhidoMain(&vetGeral);
            continue;
        
        case 4:
            moverLugarEscolhidoMain(&vetGeral);
            continue;
       
        case 5: 
            apagarRegistroMain(&vetGeral);


        //.....
        
        
        
        
        
        case 8:
            printf("Saindo....\n");
            bool = 0;


        }
    }
    
    














    return 0;
}