// Problema de Ordena��o Direta
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Declara��o de Vari�veis
int vetor[10000];
int i = 0;
int j = 0;

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
    for (i = 0; i < 9999; i++) { // Do Primeiro ao Pen�ltimo
        for (j = (i + 1) ; j < 10000; j++) { // Do Pr�ximo ao �ltimo
            if (vetor[i] > vetor[j]) {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }

    // Impress�o do Vetor Ordenado
    for (i = 0; i < 10000; i++) {
        printf("%d\n", vetor[i]);
    }

}
