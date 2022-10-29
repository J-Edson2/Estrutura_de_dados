#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"
#include <locale.h>
/*
Voce devera implementar uma programa que simule o funcionamento de uma
agenda telefonica. Para isso, implemente um programa principal que tenha
um menu retornavel onde o usuario escolhe dentre as opcoes possíveis.

Requisitos funcionais:

-Funcoes da agenda:

1-Insere contato
2-Busca contato por nome
3-Edita contato (pode alterar o nome ou o telefone)
4-Remove contato pelo nome
5-Apagar todos os contatos
6-Encerrar o programa

-E possivel inserir contatos com o mesmo nome, porem nao e possivel inserir
contatos com o mesmo telefone
-Coloque mensagens para informar ao usuario sempre que houver erros.
Por exemplo, quando o contato nao for inserido, pois ja existe um contato
com o mesmo telefone na agenda, ou quando o contato nao for removido por nao
existir na agenda ninguem com aquele nome

Requisitos nao funcionais:

-Nao e permitido o uso de variaveis globais
-Utilize uma lista dinamica simplesmente encadeada como estrutura de dados,
 implementando as funcoes declaradas em agenda.h.
-Nao e permitido adicionar novas funcoes ou alterar a funcoes existentes em
agenda.h. Se for necessario, crie novas funcoes no programa principal

Opcional: implemente funcoes para carregar e salvar contatos em um arquivo
para nao precisar inserir contatos na mao toda vez que quiser testar o programa
*/



void preencheContato(struct contato *dados) {
    printf("Digite o nome:\n");
    fflush(stdin);
    scanf("%s", dados->nome);
    printf("Digite o numero de telefone:\n");
    scanf("%d", &dados->telefone);
}


void imprimir_Menu() {
    printf("--------------------------------------------\n");
    printf("Digite a opção que deseja usar:\n");
    printf("1- Inserir contato\n");
    printf("2- Buscar contato\n");
    printf("3- Remover contato\n");
    printf("4- Editar contato\n");
    printf("5- Apagar todos os contatos\n");
    printf("6- Sair do Programa\n");
    printf("7-(opcional)- imprimir lista de contatos\n");
    printf("--------------------------------------------\n");
}


int main()
{
    setlocale(LC_ALL,"portuguese");
    Lista *lde;
    int escolha = 0;
    char nome[50];
    struct contato *dados;
    lde = NULL;
    lde = criar();
    dados = (struct contato*)malloc(sizeof(struct contato));

    while(escolha != 6){
        imprimir_Menu();
        scanf("%d", &escolha);
        if(escolha == 1){
            preencheContato(dados);
            insereContato(lde, *dados);
        }else if(escolha == 2){
            printf("\nDigite o nome do contato: ");
            fflush(stdin);
            gets (nome);
            buscaContato(lde, nome, dados);
        }else if(escolha == 3){
            printf("Digite o nome do contato: \n ");
            fflush(stdin);
            gets (nome);
            removeContato(lde, nome);
        }else if(escolha == 4){
            printf("insira o nome do contato que deseja editar: \n");
            fflush(stdin);
            gets(nome);
            buscaContato(lde, nome, dados);
            if(buscaContato(lde, nome, dados) == 1) {
                removeContato(lde, nome);
                preencheContato(dados);
                insereContato(lde, *dados);
                printf("Contato alterado com sucesso! \n");
            }
        }else if(escolha == 5){
            destruir(lde);
            printf("Contatos removidos!\n");
        }else if(escolha== 6){
            printf("Programa encerrado !\n");
            destruir(lde);
        }else if(escolha == 7){
            if(lista_vazia(lde)) printf("Lista vazia.\n");
            imprimeLista(lde);
        } else {
            printf("opção inválida! \n");
    }
    }

    return 0;
}

