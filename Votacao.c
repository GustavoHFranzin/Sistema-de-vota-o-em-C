//Gustavo Henrique Franzin da Silva RA: 124346

#include <stdio.h>
#include <stdlib.h>

// estrutura nó
typedef struct no {
    int conteudo;
    struct no *esquerda, *direita;
} No;

// estrutura árvore com um ponteiro para um nó
typedef struct {
    No *raiz;
    int tam;
} ArvB;
//^^^^^^^^^^^^ PRIMEIRA ARVORE, A QUE ARMAZENA OS NUMEROS DOS TITULOS; ^^^^^^^^^^^^

typedef struct no2 {
    int conteudo2;
    struct no *esq, *dir;
} No2;

typedef struct ar2{//STRUCT PARA A SEGUNDA ARVORE, A QUE ARMAZENA números de todos os títulos que já votaram e o nome da pessoa votada associada a cada título.
    int conteudo2;
    char nome;
    int numero;
    No2 *raiz2;
    struct no2 *esq, *dir;
} segunda;


/*segunda *criar_arvore()
{
    segunda *arv;
    arv = (segunda *)malloc(sizeof(segunda));

    if(segunda != NULL)
    {
        arv->raiz2 = NULL;
    }
    return arv;
}*/

int buscarsegunda(No2 *raiz2, int chave2) {
    if(raiz2 == NULL) {
        return 0;
    } else {
        if(raiz2->conteudo2 == chave2)
            return 1;
        else {
            if(chave2 < raiz2->conteudo2)
                return buscarsegunda(raiz2->esq, chave2);
            else
                return buscarsegunda(raiz2->dir, chave2);
        }
    }
}


int validarnasegunda(No *raiz, int numero){//valida o numero do titulo, confere se ele está na primeira arvore, onde fica os titulos válidos

    if(raiz == NULL) {
        return 0;
    } else {
        if(raiz->conteudo == numero)
            return printf("temmmmmm");
        else {
            if(numero < raiz->conteudo)
                return validarnasegunda(raiz->esquerda, numero);
            else
                return validarnasegunda(raiz->direita, numero);
        }
    }
    printf("tem");


    //armazene o numero e o nome do voto na arvore dois
    //inserirSegunda(No2 *raiz2, int numero);
}

/*No2* funcaovotar(ar2 segunda){
        printf("Qual o numero do seu titulo?");//COMPARE O NUMERO COM O TITULO QUE ESTÁ NA PRIMEIRA ARVORE
        scanf("%d", &numero);
        fflush(stdin);
        printf("Deseja votar em quem? ");
        scanf("%s", &nome);
}*/



No2* inserirSegunda(No2 *raiz2, int valor2) {
    if(raiz2 == NULL) {
        No2 *novo = (No2*)malloc(sizeof(No2));
        novo->conteudo2 = valor2;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    } else {
        if(valor2 < raiz2->conteudo2)
            raiz2->esq = inserirSegunda(raiz2->esq, valor2);
        if(valor2 > raiz2->conteudo2)
            raiz2->dir = inserirSegunda(raiz2->dir, valor2);
        return raiz2;
    }
}

int maiortitulo(No *raiz){
    No *navegacao = raiz;
    while (navegacao->direita != NULL){
        navegacao = navegacao->direita;
    }
    return navegacao->conteudo;
}


void imprimir2(No2 *raiz2) {
    if(raiz2 != NULL) {
        imprimir2(raiz2->esq);
        printf("%d ", raiz2->conteudo2);
        imprimir2(raiz2->dir);
    }
    else {
        printf("A arvore esta vazia");
    }
}

//(***********************DAQUI PRA BAIXO É DA SEGUNDA ARVORE *************************************



No* inserirNovaVersao(No *raiz, int valor) {
    if(raiz == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    } else {
        if(valor < raiz->conteudo)
            raiz->esquerda = inserirNovaVersao(raiz->esquerda, valor);
        if(valor > raiz->conteudo)
            raiz->direita = inserirNovaVersao(raiz->direita, valor);
        return raiz;
    }
}

// função que retorna o tamanho de uma árvore
int tamanho(No *raiz) {
    if(raiz == NULL)
        return 0;
    else
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
}

// função para buscar um elemento na árvore
int buscar(No *raiz, int chave) {
    if(raiz == NULL) {
        return 0;
    } else {
        if(raiz->conteudo == chave)
            return 1;
        else {
            if(chave < raiz->conteudo)
                return buscar(raiz->esquerda, chave);
            else
                return buscar(raiz->direita, chave);
        }
    }
}
/*  faz a impressão da árvore em ordem crescente
    esquerda - raiz - direita
*/
void imprimir(No *raiz) {
    if(raiz != NULL) {
        imprimir(raiz->esquerda);
        printf("%d ", raiz->conteudo);
        imprimir(raiz->direita);
    }
}

// função para a remoção de um nó
No* remover(No *raiz, int chave) {
    if(raiz == NULL) {
        printf("Valor nao encontrado!\n");
        return NULL;
    } else {
        if(raiz->conteudo == chave) {
            // remove nós folhas (nós sem filhos)
            if(raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                return NULL;
            }
            else{
                // remover nós que possuem apenas 1 filho
                if(raiz->esquerda == NULL || raiz->direita == NULL){
                    No *aux;
                    if(raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free(raiz);
                    return aux;
                }
                else{
                    No *aux = raiz->esquerda;
                    while(aux->direita != NULL)
                        aux = aux->direita;
                    raiz->conteudo = aux->conteudo;
                    aux->conteudo = chave;
                    raiz->esquerda = remover(raiz->esquerda, chave);
                    return raiz;
                }
            }
        } else {
            if(chave < raiz->conteudo)
                raiz->esquerda = remover(raiz->esquerda, chave);
            else
                raiz->direita = remover(raiz->direita, chave);
            return raiz;
        }
    }
}

