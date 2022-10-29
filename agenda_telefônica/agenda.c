#include <stdlib.h>
#include <stdio.h>
#include "agenda.h"
#include <string.h>

struct elemento {
    struct contato dados;
    struct elemento *proximo;
};

typedef struct elemento Elem;


Lista* criar() {
    Lista *lde;
    lde = (Lista*)malloc(sizeof(Lista));
    if(lde != NULL) {
        *lde = NULL;
    }
    return lde;
}

void destruir(Lista *lde) {
    if(*lde == NULL) {
        free(*lde);
    }else {
        Elem *aux;
        while(*lde != NULL) {
            aux = *lde;
            *lde = (*lde)->proximo;
            free(aux);
        }
    }
}

int lista_vazia(Lista *lde){
    if(lde == NULL){
        return 1;
    }else if(*lde == NULL){
        return 1;
    }else{
        return 0;
    }
}

int insereContato(Lista* lde, struct contato ctt) {
    if(lde == NULL) return 0;
    Elem* novo = (Elem*) malloc(sizeof(Elem));
    if(novo == NULL) return 0;
    Elem* aux = *lde;
    while(aux != NULL){
        if(ctt.telefone == aux->dados.telefone){
            printf("não é possível inserir contatos com o mesmo telefone! \n");
            return 0;
        }
        aux = aux->proximo;
    }
    novo->dados = ctt;
    novo->proximo = (*lde);
    *lde = novo;
    return 1;
}

int buscaContato(Lista* lde, char nome[50], struct contato* ctt) {
    if(lista_vazia(lde)) {
        printf("Lista vazia !\n");
        return 0;
    }
    for(Elem* i = *lde; i != NULL; i = i->proximo) {
        if(!strcmp(i->dados.nome, nome)) {
            *ctt = i->dados;
            printf("--------------------------------\n");
            printf("Nome: %s\nTelefone: %d\n", i->dados.nome, i->dados.telefone);
            printf("--------------------------------\n");
            return 1;
        }
    }
    printf("esse contato não existe! \n");
    return 0;
}

int removeContato(Lista *lde, char nome[50]) {
    if(lista_vazia(lde)) {
        return 0;
    }else if(!strcmp((*lde)->dados.nome, nome)) {
        Elem *aux = *lde;
        *lde = aux->proximo;
        free(aux);
        return 1;
    } else {
        Elem *ant = *lde;
        Elem *aux = ant->proximo;
        while(aux != NULL && strcmp(aux->dados.nome, nome)) {
            ant = aux;
            aux = aux->proximo;
        }
        if(aux == NULL) {
            printf("esse contato não existe! \n");
            return 0;
        }
        ant->proximo = aux->proximo;
        free(aux);
        return 1;
    }
}


int imprimeLista(Lista *lde){
    int i = 0;
    if(lde== NULL){
        return 0;
    }else{
        Elem *aux = *lde;
        while(aux != NULL){
            printf("/////////////////////////////////\n", i);
            printf("Nome: %s\nTelefone: %d\n", aux->dados.nome, aux->dados.telefone);
            printf("//////////////////////////////////\n");
            aux = aux->proximo;
            i++;
        }
        return 1;
    }
}
