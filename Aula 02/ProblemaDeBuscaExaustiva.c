// Problema de Busca Exaustiva
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Declara��o de Vari�veis
int vetor[10000];
int i = 0;
int busca = 0;
int achei = -1;

// Fun��o Principal de Execu��o do Programa
int main() {
    setlocale(LC_ALL, "Portuguese");

    // Inicializa��o da Mem�ria
    for (i = 0; i < 10000; i++) {
        vetor[i] = (rand() % 10000);
    }

    // Perguntar o Par�metro de busca
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &busca);

    // Busca Propriamente Dita
    for (i = 0; i < 10000; i++) {
        if (vetor[i] == busca) {
            achei = i;
        }
        else {

        }
    }

    if (achei == -1) {
        printf("N�o Existe!");
    }
    else {
        printf("Achei na posi��o %d", achei);
    }
}
