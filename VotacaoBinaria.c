//Gustavo Henrique Franzin da Silva RA: 124346

#include <stdio.h>
#include <stdlib.h>
#include "Votacao.c"

int main() {
    int op, valor;
    ArvB arv;
    arv.raiz = NULL;

    No *raiz = NULL;
//PRIMEIRA ARVORE ^^^^^^^^^^^^


    No2 *raiz2 = NULL;
    char nome[20];
    int numero;

    do {
        printf("\n0 - sair\n1 - inserir Titulo\n2 - imprimir titulos cadastrados\n3 - Buscar por titulo valido\n4 - Remover titulo\n5 - Iniciar uma nova votacao\n6 - Votar\n7 - Retirar voto\n8 - Mostrar resultado parcial\n9 - Maior numero de titulo que ja votou\n10 - Menor numero de titulo que ja votou\n11 - Listar todos os numero de titulos que ja votaram\n12 - Liberar todas as estruturas e encerrar o programa\n13 - Imprimir a arvore dois(testes)\n");
        scanf("%d", &op);

        switch(op) {
        case 0:
            printf("\nSaindo...\n");
            break;
        case 1:
            printf("Digite o numero do titulo de eleitor a ser cadastrado: ");
            scanf("%d", &valor);
            raiz = inserirNovaVersao(raiz, valor);// não precisa da estrutura ArvB
            //inserir(&arv, valor);// para utilizar esta inserção, comente a anterior
            break;
        case 2:
            printf("\nImpressao dos titulos cadastrados e válidos:\n");
            imprimir(raiz);
            printf("\n");
            printf("Tamanho: %d\n", tamanho(raiz));
            break;
        case 3:
            printf("Qual o numero do titulo? ");
            scanf("%d", &valor);
            printf("Resultado da busca: %d\n", buscar(raiz, valor));
            break;
        case 4:
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;
        case 5:
            printf("Iniciando uma nova votacao... ");
            break;
        case 6:
            //printf("Qual o numero do seu titulo?");//COMPARE O NUMERO COM O TITULO QUE ESTÁ NA PRIMEIRA ARVORE
            //scanf("%d", &numero);
            //fflush(stdin);
            //printf("Deseja votar em quem? ");
            //scanf("%s", &nome);
            //validarnasegunda(raiz, numero);
            //inserirSegunda(No2 *raiz2, int numero);
            break;
        case 7:
            printf("Deseja remover o voto de quem?");
            break;
        case 8:
            printf("Mostrando o resultado parcial:");
            break;

        case 9:
            printf("Maior titulo que votou:");
            maiortitulo(raiz);
            break;

        case 10:
            printf("Menor titulo que votou:");
            break;
        case 11:
            printf("Listando todos os titulos que votaram:");
            break;
        case 13:
            printf("\nImpressao dos titulos cadastrados e válidos:\n");
            imprimir2(raiz2);
            printf("\n");
            //printf("Tamanho: %d\n", tamanho(raiz));
            break;
        default:
            printf("\nOpcao invalida...\n");
        }
    } while(op != 0);
}
