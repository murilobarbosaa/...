// Problema de Ordena��o BubbleSort
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Declara��o de Vari�veis
int vetor[10000];
int i = 0;
int troquei = 1;

// Fun��o Principal de Execu��o do Programa
int main() {
    setlocale(LC_ALL, "Portuguese");

    // Inicializa��o da Mem�ria
    for (i = 0; i < 10000; i++) {
        vetor[i] = (rand() % 10000);
    }

    // Impress�o do Vetor
    for (i = 0; i < 10000; i++) {
        printf("%d\n", vetor[i]);
    }

    // Ordena��o Propriamente Dita
    while (troquei) {
        troquei = 0;
        for (i = 0; i < 9999; i++) {
            if (vetor[i] > vetor[i+1]) {
                int temp = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = temp;
                troquei = 1;
            }
        }
    }

    // Impress�o do Vetor Ordenado
    for (i = 0; i < 10000; i++) {
        printf("%d\n", vetor[i]);
    }

}
