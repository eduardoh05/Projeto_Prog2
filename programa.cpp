#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

//Função para pesquisar CPF

void pesquisa_cpf (FILE *file, int cpf){
    file = fopen("pessoas.txt", "r");
};



struct Tipo_pms{
    char nome_de_guerra[MAX+1];
};

int main(){
    //Declaração usada para usar as opções.
    int op;
    
    //Declaração do CPF para usar na função Pesquisar por CPF.
    int cpf_pessoa;
    //Declaração do arquivo FILE para manipular arquivo.
    FILE *file;
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
            
            //Inicialização com true para testar a função de BUSCA DE CPF.
            bool chamada_policial = true;

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
                    continue;
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
                    continue;
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
                //Caso em que não há chamadas policiais.
                if(chamada_policial == false){    
                    printf("\nViatura direcionada para rondas, no aguardo de chamadas policiais.");
                    printf("\n1 - Voltar para o Menu Principal");
                    printf("\nOpcao: ");
                    scanf("%d", &op);

                    if (op == 1)
                        continue;
                }
                //Criação do menu, caso haja chamadas policiais. As infos devem vir de outro lugar, acredito.
                else{
                    printf("\nDescrição: ");
                    printf("\nLocalização: \n");

                    printf("\n1 - Confirmada Ação Policial");
                    printf("\n2 - Ação Policial Dispensada\n");
                    
                    printf("Opcao: ");
                    scanf("%d", &op);

                    //Caso em que a Ação Policial é confirmada. Tentativa de usar SWITCH
                    switch (op)
                    {
                    case 1:
                        printf("\n1 - Pesquisar por CPF");
                        printf("\n2 - Solicitar Reforços");
                        printf("\n3 - Prisão em Andamento");
                        printf("\n4 - Encerrar Ocorrência");

                        switch (op)
                        {
                            //Manipulação do arquivo pessoas.txt
                            case 1:
                                printf("\nCPF: ");
                                scanf("%d", &cpf_pessoa);
                                
                                //Enquanto a função não estiver pronta.
                                continue;


                        }

                    //Precisa ser consertado pois, após apertar 2, o programa deveria voltar para a etapa 3, não para o menu inicial.
                    case 2:
                        continue;
                    }
                }
            }

            else{
                continue;
            }
            

        }


    
    }while (op != 0);
    
    
    
    
}
