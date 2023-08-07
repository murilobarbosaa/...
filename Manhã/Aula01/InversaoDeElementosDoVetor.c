// Programa de Invers�o de Elementos do vetor
#include <stdio.h>
#include <locale.h>

// Declara��o das Vari�veis
int vetorOriginal[10];
int vetorInvertido[10];
int i = 0;

// Fun��o Principal de Execu��o do Programa
int main () {
    setlocale(LC_ALL, "Portuguese");
    // Inicializa��o de Mem�ria
    for (i = 0; i < 10; i++) {
        vetorOriginal[i] = 0;
        vetorInvertido[i] = 0;
    }

    // Preenchimento do Vetor
    for (i = 0; i < 10; i++) {
        printf("Digite o valor da posi��o %d: ", i);
        scanf("%d", &vetorOriginal[i]);
    }

    // Invers�o do Vetor
    printf("\n");
    for (i = 9; i >= 0; i--) {
        vetorInvertido[9 - i] = vetorOriginal[i];
    }

    // Impress�o dos Vetores
    printf("\n");
    for (i = 0; i < 10; i++) {
        printf("vetor [%d] = %d \n", i, vetorOriginal[i]);
    }

    printf("\n");
    for (i = 0; i < 10; i++) {
        printf("vetor [%d] = %d \n", i, vetorInvertido[i]);
    }

}
