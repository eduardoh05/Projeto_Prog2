#include "lib_lista.h"
#include <stdio.h>
#include <stdlib.h>

void inserir(lista*& lst, void* chave){
    lista *p; //
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
