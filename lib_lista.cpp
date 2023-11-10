#include "lib_lista.h"
#include <stdio.h>
#include <stdlib.h>

void inserir(lista*& lst, void* chave){
    lista *p; // ta certo mesmo? 
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