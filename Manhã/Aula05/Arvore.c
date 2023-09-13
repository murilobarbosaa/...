// Programa que Implementa uma �rvore de Ordem 5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

// Declara��o de Estruturas
struct no {
    int numero;
    struct no *filho1;
    struct no *filho2;
    struct no *filho3;
    struct no *filho4;
    struct no *filho5;
};

// Fun��o que Insere um N�
struct no *inserir(struct no *raiz, int numero) {
    if (raiz == NULL) {
        // Caso F�cil: A �rvore Est� Vazia
        raiz = (struct no *)malloc(sizeof(struct no));
        raiz -> numero = numero;
        raiz -> filho1 = NULL;
        raiz -> filho2 = NULL;
        raiz -> filho3 = NULL;
        raiz -> filho4 = NULL;
        raiz -> filho5 = NULL;
    }
    else {
        // Caso Dif�cil : A �rvore n�o Est� vazia
        int sorteio = (rand() % 5);

        if (sorteio == 0) {
            raiz -> filho1 = inserir(raiz -> filho1, numero);
        }
        else if (sorteio == 1) {
            raiz -> filho2 = inserir(raiz -> filho2, numero);
        }
        else if (sorteio == 2) {
            raiz -> filho3 = inserir(raiz -> filho3, numero);
        }
        else if (sorteio == 3) {
            raiz -> filho4 = inserir(raiz -> filho4, numero);
        }
        else if (sorteio == 4) {
            raiz -> filho5 = inserir(raiz -> filho5, numero);
        }
    }
    return raiz;
};

// Fun��o que Imprime a �rvore
void imprimir(struct no *raiz, char *endentacao) {
    if (raiz != NULL) {
        printf("%s %d\n", endentacao, raiz -> numero);

        char *temp = (char *)malloc(1024 * sizeof(char));
        strcpy(temp, " --- ");
        strcat(temp, endentacao);

        imprimir(raiz -> filho1, temp);
        imprimir(raiz -> filho2, temp);
        imprimir(raiz -> filho3, temp);
        imprimir(raiz -> filho4, temp);
        imprimir(raiz -> filho5, temp);
    }
}

// Fun��o Principal de Execu��o do Programa
int main() {
    setlocale(LC_ALL, "Portuguese");
    // Inicializa��o da Aleatoriedade
    time_t t;
    srand((unsigned) time(&t));

    // Declara��o da Raiz
    struct no *raiz = NULL;

    // Declara��o do Endentador
    char *endentador = (char *)malloc(1024 * sizeof(char));
    strcpy(endentador, "");

    // Menu de Op��es
    int opcao = 0;
    while (opcao != 3) {
        printf("+================+\n");
        printf("| Menu de op��es |\n");
        printf("+================+\n");
        printf("|  1 - Inserir   |\n");
        printf("|  2 - Imprimir  |\n");
        printf("|  3 - Sair      |\n");
        printf("+================+\n");
        printf("\n");
        printf("Digite sua op��o: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int numero = 0;
            printf("Digite o n�mero:");
            scanf("%d", &numero);
            printf("\n");
            raiz = inserir(raiz, numero);
        }
        else if (opcao == 2) {
            printf("\n");
            imprimir(raiz, endentador);
            printf("\n");
        }
    }
}
