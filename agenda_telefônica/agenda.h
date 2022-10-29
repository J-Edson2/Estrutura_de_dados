#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

struct contato{
    char nome[50];
    int telefone;
};

typedef struct elemento *Lista;

Lista* criar();

void destruir(Lista *);

int insereContato(Lista*, struct contato);

int buscaContato(Lista*, char nome[50], struct contato*);

int removeContato(Lista*, char nome[50]);

#endif // AGENDA_H_INCLUDED
