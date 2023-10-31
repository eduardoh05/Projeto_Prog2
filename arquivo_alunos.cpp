/*
 
 PROGRAMA PARA ABRIR UM ARQUIVO TEXTO CONTENDO VARIOS DADOS DE ALUNOS 
 (PRIMEIRO NOME E DUAS NOTAS),
 LER OS DADOS E CALCULAR A MEDIA ARITMETICA DAS DUAS NOTAS DO ALUNO,
 IMPRIMIR NOME E MEDIA NA TELA
 
 */

#include<stdio.h>  /*FILE, printf, scanf*/
#define MAX 30


int main()
{
    
    FILE*  arq;         /* variavel para acessar um arquivo */
    char nome[MAX];     /* nome do arquivo a ser aberto*/
    char nomeA[MAX];    /* nome do aluno */
    float n1, n2, media;
    
    
    scanf(" %s", nome);
    
    /*abertura de um arquivo*/
    arq = fopen(nome, "r");
    
    /* verificando se arquivo foi aberto */
    if( arq == NULL )
    {
        printf("\n\n Arquivo %s nao pode ser aberto.\n\n", nome);
    }
    else
    {
        printf("Arquivo foi aberto!\n\n");
        
        /*JOAO  2.5 7.5*/
        
        /*leitura dos dados do arquivo*/
        fscanf(arq, "%s %f %f", nomeA, &n1, &n2);
        /*
         fscanf(arq, "%s", nomeA)
         fscanf(arq, "%f", &n1)
         fscanf(arq, "%f", &n2);
         */
        while( feof(arq) == 0 )    /*CHEGOU AO FINAL DO ARQUIVO??? verificando se chegou ao fim do arquivo*/
        {
            /*calcula da media e impressao na tela*/
            media = (n1+n2)/2;
            printf("%s %.2f\n", nomeA, media);
        
            /*leitura dos proximos dados do arquivo*/
            fscanf(arq, "%s %f %f", nomeA, &n1, &n2);
        }
        
        /*fechamento do arquivo*/
        fclose(arq);
        
    }
    printf("\n");    
    return 0;
}


    // fscanf();
    // while(    feof(arquivo) == 0)         - chegou ao final do arquivo?
    // {
        /*operacao com o dado lido*/
    
    
    
    
        /*leitura do proximo dado*/
    //    fscanf();
    
    
    
    // }
     