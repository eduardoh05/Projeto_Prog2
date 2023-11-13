#include "lib_lista.h"
#include <stdio.h>
#include <stdlib.h>

void inserir(lista*& lst, void* chave){
    lista *p; 
    lista* novo = (lista*)calloc(1, sizeof(lista));
    novo->chave = chave;
    novo->prox = NULL;

    if(lst == NULL){
        lst = novo;
    }
    else{
        // for(lista *p = lst; p->prox!=NULL; p = p->prox);
        for(p = lst; p->prox!=NULL; p = p->prox);
        p->prox = novo;
    }
}

void inserirComeco(lista*& lst, void* chave){
    lista* novo = (lista*)calloc(1, sizeof(lista));
    novo->chave = chave;
    if (lst == NULL){
        lst = novo;
        lst->prox = NULL;
    } else {
        novo->prox = lst;
        lst = novo;
    }
}

void desalocar(lista*& lst){
    lista *aux;
    while (lst != NULL){
        aux = lst;
        lst = lst->prox;
        free(aux->chave);
        free(aux);
    }
}

chamada* removerChamada(lista *&lst, int tipo){
    lista *p = NULL;
    lista *q = lst;

    while(q != NULL && ((chamada*)q->chave)->tipo != tipo){
        p = q;
        q = q->prox;
    }
    if (q == NULL)
        return NULL;
    else {
        if (p == NULL)
            p->prox = q->prox;
        else
            lst = q->prox;
    }
    chamada *chamado = (chamada*)malloc(sizeof(chamada));
    chamado = (chamada*)q;
    free(q);
    return chamado; // posso fazer isso?
}
