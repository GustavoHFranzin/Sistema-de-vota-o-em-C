//Nome: Gustavo Henrique Franzin da Silva RA: 124346
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "FuncaoAgenda.h"

int main()
{
    struct Agenda *elemento;
    elemento = (agenda*)malloc(sizeof(agenda));

    int decisao=0;
    setlocale(LC_ALL, "Portuguese");

    //funcao Macro para testes!
    //funcaoMACRO(elemento);

    while (decisao!=6)
    {
        printf("Qual opção deseja escolher?\n");
        printf("1 - Criar uma Agenda\n");
        printf("2 - Inserir Usuário na Agenda\n");
        printf("3 - Remover um Usuário na Agenda\n");
        printf("4 - Buscar um Usuário na Agenda\n");
        printf("5 - Imprimir Agenda\n");
        printf("6 - Sair do Programa\n");
        scanf("%i", &decisao);
        fflush(stdin);

        switch(decisao)
        {
        case 1:
            CriarAgenda(elemento);
            break;

        case 2:
            InserirUsuario(elemento);
            break;

        case 3:
            RemoverUsuario();
            break;

        case 4:
            BuscarUsuario();
            break;

        case 5:
            ImprimirAgenda(elemento);
            break;
        }

    }

    free(elemento);
    return 0;
}
