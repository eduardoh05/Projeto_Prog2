#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

struct Tipo_pms{
    char nome_de_guerra[MAX+1];
};

int main(){
    int op;
    do{
        printf("\n1 - Viatura Login");
        printf("\n2 - Viatura em uso");
        printf("\n3 - COPOM");
        printf("\n4 - Policial Militar");
        printf("\n5 - Oficial");
        printf("\n6 - Comandante Geral");
        printf("\n0 - Encerrar Programa\n");
        printf("Opcao: ");
        scanf("%d", &op);

        if (op == 1)
        {
            int qtd_pms, cod_viatura;

            //ETAPA 1
            printf("\nPolicia Regular - 1");
            printf("\nPolicia Especializada - 2\n");
            printf("Opcao: ");
            scanf("%d", &op);
            
            //Caso essa diferenciação seja necessária, é melhor fazer desse primeiro jeito.
            
            /*
            if (op == 1)
            {
                //Necessário validar com o arquivo viaturas.txt? Acredito que seja.
                printf("Código da Viatura: ");
                scanf("%d", &cod_viatura);
                printf("Quantidade de PMs: ");
                scanf("%d", &qtd_pms);

                if (qtd_pms < 2 || qtd_pms > 4)
                {
                    printf("Solicitação de embarque negada.\n");
                }
                else{
                    //Declarando o registro com o número de PMs digitado;
                    struct Tipo_pms PMS[qtd_pms];

                    printf("Identificação dos PMs:\n");
                    
                    //For usado para digitar o nome dos PMs e armazenar no registro.
                    for (int i = 0; i < qtd_pms; i++){
                        scanf(" %[^\n]", PMS[i].nome_de_guerra);
                        printf("%s\n", PMS[i].nome_de_guerra);
                    }
                }
                
            }
            */

        
        //Essa é a opção caso não seja necessário diferenciar as viaturas.  
        //ETAPA 2
        //Necessário validar com o arquivo viaturas.txt? Acredito que seja.
        printf("Código da Viatura: ");
        scanf("%d", &cod_viatura);
        printf("Quantidade de PMs: ");
        scanf("%d", &qtd_pms);

        if (op == 1){

            if (qtd_pms < 2 || qtd_pms > 4)
            {
                printf("Solicitação de embarque negada.\n");
                break;
            }
            else
            {
                //Declarando o registro com o número de PMs digitado;
                struct Tipo_pms PMS[qtd_pms];

                printf("Identificação dos PMs:\n");
                
                //For usado para digitar o nome dos PMs e armazenar no registro.
                for (int i = 0; i < qtd_pms; i++){
                    scanf(" %[^\n]", PMS[i].nome_de_guerra);
                    printf("%s\n", PMS[i].nome_de_guerra);
                }
            }
        }

        if (op == 2){
            if (qtd_pms < 4)
            {
                printf("Solicitação de embarque negada.\n");
            }
            else
            {
                //Declarando o registro com o número de PMs digitado;
                struct Tipo_pms PMS[qtd_pms];

                printf("Identificação dos PMs:\n");
                
                //For usado para digitar o nome dos PMs e armazenar no registro.
                for (int i = 0; i < qtd_pms; i++){
                    scanf(" %[^\n]", PMS[i].nome_de_guerra);
                    printf("%s\n", PMS[i].nome_de_guerra);
                }
            }
        }
        
        //ETAPA 3
        printf("\n1 - Apto para atender ocorrência");
        printf("\n2 - Cancelar Embarcação\n");
        printf("Opcao: ");
        scanf("%d", &op);

        if (op == 1){
            
        }
        else{
            continue;
        }
        

        }
    
    }while (op != 0);
    
    
    
    
}
