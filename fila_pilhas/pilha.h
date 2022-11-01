#ifndef PILHADINAMICA_H_INCLUDED
#define PILHADINAMICA_H_INCLUDED
struct aluno{
    int matricula;
    char nome[50];
    float av1;
    float av2;
    float pr;
};

typedef struct elemento* Pilha;

Pilha* criar();
int vazia(Pilha *);
int inserir(Pilha *, struct aluno);
int remover(Pilha *);
int acessar(Pilha*, struct aluno *);
void destruir(Pilha *);
int imprimePilha(Pilha* pd);


#endif // PILHADINAMICA_H_INCLUDED

