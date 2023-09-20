// Progamaa que Implementa uma �rvore Bin�ria e suas Respectivas Navega��es

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Declara��o de Estruturas
struct no {
    int numero;
    struct no *esquerda;
    struct no *direita;
};

// Fun��o que Insere um N� na �rvore
struct no *inserir(struct no *raiz, int numero) {
    // Caso f�cil
    if (raiz == NULL) {
        raiz = (struct no *)malloc(sizeof(struct no));
        raiz -> numero = numero;
        raiz -> esquerda = NULL;
        raiz -> direita = NULL;
    }
    // Caso Dif�cil
    else {
        if ((rand() % 2) == 0) {
            raiz -> esquerda = inserir(raiz -> esquerda, numero);
        }
        else {
            raiz -> direita = inserir(raiz -> direita, numero);
        }
    }

    return raiz;
};

// Navega��o em PR�-ORDEM
void navegarPreOrdem(struct no *raiz) {
    if (raiz != NULL) {
        printf("%d\t", raiz -> numero);
        navegarPreOrdem(raiz -> esquerda);
        navegarPreOrdem(raiz -> direita);
    }
}

// Navega��o EM_ORDEM
void navegarEmOrdem(struct no *raiz) {
    if (raiz != NULL) {
        printf("%d\t", raiz -> numero);
        navegarEmOrdem(raiz -> esquerda);
        navegarEmOrdem(raiz -> direita);
    }
}

// Navega��o P�S_ORDEM
void navegarPosOrdem(struct no *raiz) {
    if (raiz != NULL) {
        navegarPosOrdem(raiz -> esquerda);
        navegarPosOrdem(raiz -> direita);
        printf("%d\t", raiz -> numero);
    }
}

// Fun��o Principal de Execu��o do Programa
int main() {
    setlocale(LC_ALL, "Portuguese");
    // Declara��o de Vari�veis
    struct no *raiz = NULL;

    // Inicializa��o da Aleatoriedade
    time_t t;
    srand((unsigned) time(&t));

    // Preenchimento da �rvore
    for (long int i = 0; i < 10; i++) {
        raiz = inserir(raiz, i);
    }

    // Navega��es
    printf("=============================== PR�-ORDEM ===============================\n");
    navegarPreOrdem(raiz);


    printf("\n================================ EM-ORDEM ===============================\n");
    navegarEmOrdem(raiz);


    printf("\n=============================== P�S-ORDEM ===============================\n");
    navegarPosOrdem(raiz);
}
