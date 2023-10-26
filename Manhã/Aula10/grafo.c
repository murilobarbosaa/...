// Programa que Implementa um Grafo
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defini��o de constantes
const int TAMANHO = 10;

// Fun��o que Cria o Grafo
void criar(int grafo[TAMANHO][TAMANHO], int aleatorio) {
    // Declara��o de Vari�veis
    int i = 0;
    int j = 0;
    int amigo = 0;

    // Inicializa��o do Grafo
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            grafo[i][j] = 0;
        }
    }

    // Defini��o das Conex�es do Grafo

    for (i = 0; i < TAMANHO - 1; i++) {
        for (j = i + 1; j < TAMANHO; j++) {
            if (!aleatorio) {
                printf("Digite 1 caso %d seja amigo de %d: ", i, j);
                scanf("%d", &amigo);
            }
            else {
                amigo = (rand() % 2);
            }

            grafo[i][j] = amigo;
            grafo[j][i] = amigo;
        }
    }

}

// Fun��o que Imprime o Grafo
void imprimir(int grafo[TAMANHO][TAMANHO]) {
    // Declara��o de Vari�veis
    int i = 0;
    int j = 0;

    // Impress�o Propriamente Dita
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            printf("%d\t", grafo[i][j]);
        }
        printf("\n");
    }
}

// Fun��o que Descobre o V�rtice de Maior Grau
int descobrirVerticeMaiorGrau(int grafo[TAMANHO][TAMANHO]) {
    // Declara��o de Vari�veis
    int i = 0;
    int j = 0;
    int contador = 0;
    int maior = 0;
    int vertice = 0;

    // Navega��o do Grafo
    for (i = 0; i < TAMANHO; i++) {
        contador = 0;
        for (j = 0; j < TAMANHO; j++) {
            if (grafo[i][j]) {
                contador++;
            }
        }
        if (contador > maior) {
            maior = contador;
            vertice = i;
        }
    }

    // Retorno
    return vertice;
}

// Fun��o Principal de Execu��o do C�digo
int main() {
    time_t t;
    srand((unsigned) time(&t));
    // Declara��o de Vari�veis
    int grafo[TAMANHO][TAMANHO];

    criar(grafo, 1);

    imprimir(grafo);

    printf("Vertice mais popular : %d\n", descobrirVerticeMaiorGrau(grafo));

    return 0;
}

