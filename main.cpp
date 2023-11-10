#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib_lista.h"
#define MAX 30

struct Tipo_Pessoa{
    char nome[40];
    int cpf;
    char cidade[40];
    int idade;
    int passagens;
    int inadimplencias;
    char nome_inadimplencia[40];
};

//Função para pesquisar CPF
// void pesquisa_cpf (FILE *file, char *cpf){
//     char *nome, *cidade, *nome_inadimplencias;
//     int idade, passagens, inadimplencias;

   
    
//     file = fopen("pessoas.txt", "r");

//     if (file == NULL)
//     {
//         printf("Erro ao acessar o banco de dados.");
//     }
//     else
//     {
//         fscanf(file, "%s", nome);
//         fscanf(file, "%s", cidade);
//         fscanf(file, "%d", &idade);
//         fscanf(file, "%d", &passagens);
//         fscanf(file, "%d", &inadimplencias);
//         fscanf(file, "%s", nome_inadimplencias);

//         char nome[40];
//         int cpf;
//         char cidade[40];
//         int idade;
//         int passagens;
//         int inadimplencias;
//         char nome_inadimplencia[40];
//     }

//     fclose(file);
// };

void lerViaturas(lista*& lst){
    FILE* arq = fopen("./arquivosEntrada/viaturas.txt", "r");
    int id_aux;
    bool tipo_aux = 0;
    char esp[14];

    viatura* aux;
    while(feof(arq) == 0){
        fscanf(arq, "%d", &id_aux);
        fscanf(arq, " %[^\n]", esp);
        if (strcmp(esp, "regular") == 0){
            tipo_aux = 1;
        } 

        aux = (viatura*)calloc(1, sizeof(viatura));
        aux->codigo = id_aux;
        aux->tipoBool = tipo_aux;
        strcpy(aux->tipo, esp);
        inserir(lst, aux);
    }
}

void lerPoliciais(lista*& lst){
    FILE* arq = fopen("./arquivosEntrada/policiais.txt", "r");

    if(arq == NULL){
        printf("ERRO AO ABRIR\n");
        return;
    }
    char nome_aux[MAX+1];
    int cpf_aux;
    char nome_de_guerra_aux[MAX+1];
    char cidade_aux[MAX+1];
    int idade_aux;
    char cargo_aux[MAX+1];
    char senha_aux[MAX+1];

    policial* aux;
    while (feof(arq) == 0){
        fscanf(arq, " %[^\n]", nome_aux);
        fscanf(arq, "%d", &cpf_aux);
        fscanf(arq, " %[^\n]", nome_de_guerra_aux);
        fscanf(arq, " %[^\n]", cidade_aux);
        fscanf(arq, "%d", &idade_aux);
        fscanf(arq, " %[^\n]", cargo_aux);                        
        fscanf(arq, " %[^\n]", senha_aux);

        aux = (policial*) calloc(1, sizeof(policial));
        strcpy(aux->nome, nome_aux);
        aux->cpf = cpf_aux;
        strcpy(aux->nome_de_guerra, nome_de_guerra_aux);
        strcpy(aux->cidade, cidade_aux);
        aux->idade = idade_aux;
        strcpy(aux->cargo, cargo_aux);
        strcpy(aux->senha, senha_aux);
        inserir(lst, aux);
    }
}


// se for int (caso de retornar o codigo), nao é possivel acessar outros dados dessa viatura
// return ((viatura*)p->chave)->codigo;
viatura* buscaViatura(lista* lst, int cod){
    lista* p = lst;

    for(; p!=NULL; p=p->prox){
        if(((viatura*)p->chave)->codigo == cod){
            return (viatura*)p->chave;
        }
    }

    return NULL;
}

policial* buscaPolicial(lista* lst, char *nomeGuerra){
    lista *p = lst;
    for (; p != NULL; p = p->prox){
        // se nomeGuerra existir na lista de policiais
        if (strcmp(((policial*)p->chave)->codigo, nomeGuerra) == 0){
            return (policial*)p->chave;
        }
    }

    return NULL;
}

int main(){
    //Declaração usada para usar as opções.
    lista* listaChamadasP = NULL;
    lista* listaChamadasNP = NULL;
    lista* listaViatura = NULL;
    lista* listaPMs = NULL;
    //lista* listaPessoa = NULL;
    int op;
    
    lerPoliciais(listaPMs);
    lerViaturas(listaViatura);
    //lerPessoas(listaPessoa);

    //Declaração do CPF para usar na função Pesquisar por CPF.
    int cpf_pessoa;

    do
    {
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
            
            if (op == 1)
            {   
                viatura* temp;
                // validar codigo da viatura regular
                while (1)
                {
                    //Necessário validar com o arquivo viaturas.txt? Acredito que seja. -sim
                    printf("Código da Viatura: ");
                    scanf("%d", &cod_viatura);
                    temp = (buscaViatura(listaViatura, cod_viatura));
                    // se existir mas nao for regular??
                    
                    if(temp != NULL){
                        if (temp->tipoBool == 1) // 1 para regular
                            break;
                    }

                    printf("Erro ao ler viatura\n");
                } 
                
                //validar quantidade da viatura regular
                while (1)
                {
                    printf("Quantidade de PMs: ");
                    scanf("%d", &qtd_pms);   
                    if (qtd_pms > 2 && qtd_pms < 4)
                        break;
                    printf("Solicitação de embarque negada.\n");
                } 

                printf("Identificação dos PMs:\n");
                //ponteiro da lista geral aponta para a listaPolicial ou para a geral?
                //tarefa: fazer verificacao com o banco de dados em .txt (nao eh certeza)
                int i = 0;
                char nome_de_guerra[MAX+1];
                while (i < qtd_pms){
                    scanf(" %[^\n]", nome_de_guerra);
                    if(buscaPolicial(listaPolicial, nome_de_guerra)){
                        strcpy(temp->policiais[i], nome_de_guerra);
                        i++;
                        printf("%d nome válido\n", i);
                    } else 
                        printf("Nome inválido\n");
                }

                op = 1;             
            }

            if (op == 2){
                printf("Quantidade de PMs: 4 (especial)\n");
                qtd_pms = 4;
                printf("Identificação dos PMs:\n");
                int i = 0;
                char nome_de_guerra[MAX+1];
                while (i < qtd_pms){
                    scanf(" %[^\n]", nome_de_guerra);
                    if(buscaPolicial(listaPolicial, nome_de_guerra)){
                        strcpy(temp->policiais[i], nome_de_guerra)
                        i++;
                        printf("%d nome válido\n", i);
                    } else 
                        printf("Nome inválido\n");
                }
                op = 2;
            }
            
            //ETAPA 3
            printf("\n1 - Apto para atender ocorrência");
            printf("\n2 - Cancelar Embarcação\n");
            printf("Opcao: ");
            // mesma variavel para submenu dá conflito?? nao, mas ao fim de todo caso, retornar op ao valor inicial.
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

            op = 1;

        // COPOM
        } else if (op == 3){
            // 1. verificar se ha pedido de reforco

            //cadastrar chamada
            chamada aux; 
            
            printf("Policia normal - 1  Especializada - 2: ");
            scanf("%d", &aux.tipo);
            printf("Viaturas necessárias: ");
            scanf("%d", &aux.qtd_viaturas);
            printf("Descrição: ");
            scanf(" %[^\n]", aux.desc);
            printf("Localização: ");
            scanf(" %[^\n]", aux.local);

            // se for policiar regular (prioritaria ou nao)
            if (aux.tipo == 1){
                printf("Prioritaria - 1 Nao prioritaria - 2:")
                scanf("%d", &op);
                // regular prioritaria
                if (op == 1)
                    inserir(listaChamadasP, aux);
                else
                    inserir(listaChamadaNP, aux);

                op = 3;
            // se for policia especializada
            } else {
                inserir(listaChamadasP, aux);
            }
            
        }

    }while (op != 0);

    //desalocar

}