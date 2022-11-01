#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include <locale.h>


void imprimeMenu(){
    printf("Digite o numero da opcao desejada:\n");
    printf("1- Inserir aluno\n");
    printf("2- Remover aluno\n");
    printf("3- Acessa aluno no começo da fila\n");
    printf("4- Imprime a fila\n");
    printf("5- Sair do Programa\n");
}

void preencheAluno(struct aluno *dados){
    printf("Digite o nome:\n");
    fflush(stdin);
    scanf("%s", dados->nome);
    printf("Digite a matricula:\n");
    scanf("%d", &dados->matricula);
}


int main()
{
    setlocale(LC_ALL, "portuguese");
    Pilha *pilha;
    pilha = NULL;
    pilha = criar();
    Pilha* pilha_d = criar();
    int opcao;
    opcao = -1;
    struct aluno dados;
    struct aluno copia;

    while(opcao != 5){
        imprimeMenu();
        scanf("%d", &opcao);
        if(opcao == 1){
            preencheAluno(&dados);
            inserir(pilha, dados);
        }else if(opcao == 2){
            while(tamanho(pilha)> 0){
                acessar(pilha, &copia);
                inserir(pilha_d, copia);
                remover(pilha);
            }

            remover(pilha_d);

             while(tamanho(pilha_d)> 0){
                acessar(pilha_d, &copia);
                inserir(pilha, copia);
                remover(pilha_d);
            }
        }else if(opcao == 3){
             while(tamanho(pilha)> 0){
                acessar(pilha, &copia);
                inserir(pilha_d, copia);
                remover(pilha);
            }
            acessar(pilha_d,&copia);
            printf("--------------------------------\n");
            printf("Nome: %s\nMatricula: %d\n", copia.nome, copia.matricula);
            printf("--------------------------------\n");
        }else if(opcao == 4){
            while(tamanho(pilha)> 0){
                acessar(pilha, &copia);
                inserir(pilha_d, copia);
                remover(pilha);
            }
            imprimePilha(pilha_d);
        }else if(opcao == 5){
            printf("Encerrando o programa\n");
        }else{
            printf("Opcao invalida, tente novamente\n");
        }
    }

    while(tamanho(pilha)> 0){
            acessar(pilha, &copia);
            inserir(pilha_d, copia);
            remover(pilha);
    }

    imprimePilha(pilha_d);
    return 0;
}
