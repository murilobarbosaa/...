// Programa de Preenchimento de Vetor
#include <stdio.h>
#include <locale.h>

// Declara��o das Vari�veis
int vetor[10];
int i = 0;

// Fun��o Principal de Execu��o do Programa
int main() {
    setlocale(LC_ALL, "Portuguese");
    // Inicializa��o da Mem�ria
    for (i = 0; i < 10; i++) {
        vetor[i] = 0;
    }

    // Preenchimento do Vetor
    for (i = 0; i < 10; i++) {
        printf("Digite o valor da posi��o %d: ", i);
        scanf("%d", &vetor[i]);
    }

    // Impress�o do Vetor
    printf("\n");
    for (i = 0; i < 10; i++) {
        printf("vetor[%d] = %d \n", i, vetor[i]);
    }

}
