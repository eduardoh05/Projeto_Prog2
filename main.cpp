#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib_lista.h"
#define MAX 30

void lerViaturas(lista*& lst){
    FILE* arq = fopen("./arquivosEntrada/viaturas.txt", "r");
    int id_aux;
    char esp[14];

    viatura* aux;
    while(feof(arq) == 0){
        bool tipo_aux = 0;
        fscanf(arq, "%d", &id_aux);
        fscanf(arq, " %s", esp);
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

void lerPessoas(lista *&lst){
    FILE* file = fopen("./arquivosEntrada/pessoas.txt", "r");

    char nome[MAX+1]; 
    char cpf[12]; 
    char cidade[MAX+1]; 
    char inadimplencias[3][MAX+1]; 
    char passagens[3][MAX+1];
    int idade, qtdPassagens, qtdInad;
    pessoa *aux;

    if (file == NULL){
        printf("Erro ao acessar o banco de dados.");
        return;
    } else {    
        while (feof(file) == 0){
            fscanf(file, " %[^\n]", nome);
            fscanf(file, " %s", cpf);
            fscanf(file, " %[^\n]", cidade);
            fscanf(file, "%d", &idade);
            fscanf(file, "%d", &qtdPassagens);
            for (int i = 0; i < qtdPassagens; i++)
                fscanf(file, " %[^\n]", passagens[i]);
            
            fscanf(file, "%d", &qtdInad);
            for (int i = 0; i < qtdInad; i++)
                fscanf(file, " %[^\n]", inadimplencias[i]);

            aux = (pessoa*) calloc(1, sizeof(pessoa));
            strcpy(aux->nome, nome);
            strcpy(aux->cpf, cpf);
            strcpy(aux->cidade, cidade);
            aux->idade = idade;
            aux->qtdPassagens = qtdPassagens;
            aux->qtdInad = qtdInad;

            for (int i = 0; i < qtdPassagens; i++)
                strcpy(aux->passagens[i], passagens[i]);
            for (int i = 0; i < qtdInad; i++)
                strcpy(aux->inadimplencias[i], inadimplencias[i]);
            
            inserir(lst, aux);
        }
    }
    fclose(file);
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

policial* buscaPolicial(lista *lst, char *nomeGuerra){
    lista *p = lst;
    for (; p != NULL; p = p->prox){
        // se nomeGuerra existir na lista de policiais
        if (strcmp(((policial*)p->chave)->nome_de_guerra, nomeGuerra) == 0){
            return (policial*)p->chave;
        }
    }

    return NULL;
}

void buscaCPF(lista *lst, char *cpf){
    lista *p = lst;
    int qtdPassagens, qtdInad;
    for (; p != NULL; p = p->prox){
        if (strcmp(((pessoa*)p->chave)->cpf, cpf) == 0){
            printf("Nome: %s\n", ((pessoa*)p->chave)->nome);
            printf("CPF: %s\n", ((pessoa*)p->chave)->cpf);
            printf("Cidade: %s\n", ((pessoa*)p->chave)->cidade);
            printf("Idade: %d\n", ((pessoa*)p->chave)->idade);
            printf("Quantidade de passagens: %d\n", ((pessoa*)p->chave)->qtdPassagens);
            qtdPassagens = ((pessoa*)p->chave)->qtdPassagens;
            for (int i = 0; i < qtdPassagens; i++)
                printf("%s\n", ((pessoa*)p->chave)->passagens[i]);
            printf("Quantidade de inadimplencias: %d\n", ((pessoa*)p->chave)->qtdInad);

            qtdInad = ((pessoa*)p->chave)->qtdInad;
            for (int i = 0; i < qtdInad; i++)
                printf("%s\n", ((pessoa*)p->chave)->inadimplencias[i]);
            return;
        }
    }
    if (p == NULL)
        printf("CPF nao encontrado.\n");
}

char *criptografar(char *senha){
    int tam = strlen(senha);
    int inicio = 0;
    int fim = tam - 1;
    char *senhac = (char*)malloc((tam+1) * sizeof(char));

    // inverte
    while (inicio < fim) {
        char temp = senha[inicio];
        senhac[inicio] = senha[fim];
        senhac[fim] = temp;

        inicio++;
        fim--;
    }

    // substitui
    for (int i = 0; i < tam; i++) {
        if ((senhac[i] >= 'a' && senhac[i] <= 'z')) {
            senhac[i] = 'a' + (senhac[i] - 'a' + 3) % 26;
        } else if ((senhac[i] >= 'A' && senhac[i] <= 'Z')) {
            senhac[i] = 'A' + (senhac[i] - 'A' + 3) % 26;
        }
    }

    return senhac;
}

policial* loginPM(lista *lst){
    policial* temp;
    char nomeGuerra[MAX+1];
    char senha[MAX+1], senhaC[MAX+1];
    while(1){
        printf("Digite seu nome de guerra (digite 1 para sair): ");
        scanf("%s", nomeGuerra);
        if (strcmp(nomeGuerra, "1") == 0)
            break;

        temp = buscaPolicial(lst, nomeGuerra);
        if (!temp)
            printf("Nome invalido\n");
    }

    while(1){
        printf("Digite sua senha (digite 1 para sair): ");
        scanf("%s", senha);
        strcpy(senha, criptografar(senha));
        if (strcmp(nomeGuerra, "1") == 0)
            break;

        if (strcmp(senha, temp->senha)){
            printf("Login bem sucedido\n");
            return temp;
        }

        printf("Senha invalida\n");
    }
}

int main(){
    lista* listaChamadasP = NULL;
    lista* listaChamadasNP = NULL;
    lista* listaViatura = NULL;
    lista* listaPMs = NULL;
    lista* listaPessoa = NULL;
    int op;
    viatura *atual = NULL;
    lerPoliciais(listaPMs);
    lerViaturas(listaViatura);
    lerPessoas(listaPessoa);

    //Declaração do CPF para usar na função Pesquisar por CPF.
    char cpf_pessoa[12];

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
            
            if (op == 1)
            {   
                viatura* temp;
                // validar codigo da viatura regular
                while (1)
                {
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
                    if (qtd_pms >= 2 && qtd_pms <= 4)
                        break;
                    printf("Solicitação de embarque negada.\n");
                } 

                printf("Identificação dos PMs:\n");
                int i = 0;
                char nome_de_guerra[MAX+1];
                while (i < qtd_pms){
                    scanf(" %[^\n]", nome_de_guerra);
                    if(buscaPolicial(listaPMs, nome_de_guerra)){
                        strcpy(temp->policiais[i], nome_de_guerra);
                        i++;
                        printf("%d nome válido\n", i);
                    } else 
                        printf("Nome inválido\n");
                }
                atual = temp;
                op = 1;             
            }

            if (op == 2){
                viatura* temp;
                // validar codigo da viatura especializada
                while (1)
                {
                    printf("Código da Viatura: ");
                    scanf("%d", &cod_viatura);
                    temp = (buscaViatura(listaViatura, cod_viatura));
                    // se existir mas nao for especializada??
                    if(temp != NULL){
                        if (temp->tipoBool == 0) // 0 para especializada
                            break;
                    }

                    printf("Erro ao ler viatura\n");
                } 
                printf("Quantidade de PMs: 4 (especial)\n");
                qtd_pms = 4;
                printf("Identificação dos PMs:\n");
                int i = 0;
                char nome_de_guerra[MAX+1];
                while (i < qtd_pms){
                    scanf(" %[^\n]", nome_de_guerra);
                    if(buscaPolicial(listaPMs, nome_de_guerra)){
                        strcpy(temp->policiais[i], nome_de_guerra);
                        i++;
                        printf("%d nome válido\n", i);
                    } else 
                        printf("Nome inválido\n");
                }
                atual = temp;
                op = 1;
            }
            
            //ETAPA 3
            printf("\n1 - Apto para atender ocorrência");
            printf("\n2 - Cancelar Embarcação\n");
            printf("Opcao: ");
            // mesma variavel para submenu dá conflito?? nao, mas ao fim de todo caso, retornar op ao valor inicial.
            scanf("%d", &op);

            // do {} while (op != 1)
            if (op == 1){
                // Caso em que não há chamadas policiais.
                // listaChamadaP ou listaChamadaNP == NULL
                if(chamada_policial == false){    
                    printf("\nViatura direcionada para rondas, no aguardo de chamadas policiais.");
                    // temp->statusLivre = true;
                    printf("\n1 - Voltar para o Menu Principal");
                    printf("\nOpcao: ");
                    scanf("%d", &op);
                    continue;

                } else {
                    // printf("\nDescrição: %s", );
                    // printf("\nLocalização: %s\n", );
                    printf("\n1 - Confirmada Ação Policial");
                    printf(" 2 - Ação Policial Dispensada\n");
                    printf("Opcao: ");
                    scanf("%d", &op);

                    //Caso em que a Ação Policial é confirmada. Tentativa de usar SWITCH
                    do {
                        printf("\n1 - Pesquisar por CPF");
                        printf("\n2 - Solicitar Reforços");
                        printf("\n3 - Prisão em Andamento");
                        printf("\n4 - Encerrar Ocorrência\n");
                        scanf("%d", &op);

                        switch (op)
                        {
                            case 1:
                                printf("CPF: ");
                                scanf(" %s", cpf_pessoa);
                                buscaCPF(listaPessoa, cpf_pessoa);
                                printf("1- Encerrar visualizacao\n");
                                scanf("%d", &op);
                                break;
                            
                            case 2:
                                break;
                        }

                    } while (op != 4);
                }
                    op = 1;
            } 
        
        } else if (op == 2) {
            int cod_viatura;

            printf("Viatura em uso\n");
            printf("Identificador da viatura: ");
            scanf("%d", &cod_viatura);
        }

        // COPOM
        else if (op == 3){
            // 1. verificar se ha pedido de reforco

            //cadastrar chamada
            chamada *aux = (chamada*)calloc(1, sizeof(chamada)); 
            
            printf("Policia normal - 1  Especializada - 2: ");
            scanf("%d", &aux->tipo);
            printf("Viaturas necessárias: ");
            scanf("%d", &aux->qtd_viaturas);
            printf("Descrição: ");
            scanf(" %[^\n]", aux->desc);
            printf("Localização: ");
            scanf(" %[^\n]", aux->local);

            // se for policiar regular (prioritaria ou nao)
            if (aux->tipo == 1){
                printf("Prioritaria - 1 Nao prioritaria - 2:");
                scanf("%d", &op);
                // regular prioritaria
                if (op == 1)
                    inserir(listaChamadasP, aux);
                else
                    inserir(listaChamadasNP, aux);

                op = 3;
            // se for policia especializada
            } else 
                inserir(listaChamadasP, aux);
            
        } else if (op == 4) {
            policial *temp = loginPM(listaPMs);
            
            // checar ocorrencias dele e registrar b.o se faltar

        }

    }while (op != 0);

    //desalocar
    desalocar(listaChamadasP);
    desalocar(listaChamadasNP);
    desalocar(listaViatura);
    desalocar(listaPMs);
    desalocar(listaPessoa);

}