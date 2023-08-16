// Programa de Lista de Encadeamento Simples
#include <stdio.h>
#include <stdlib.h>

// Declara��o da Estrutura do N�
struct no {
    int numero;
    struct no *proximo;
};

// Declara��o de Vari�veis
struct no *cabeca = NULL;

// Fun��o que Insere um N� na Lista
void inserir(int numero) {
    // Aloca��o do Espa�o de Mem�ria
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));
    novoNo -> numero = numero;
    novoNo -> proximo = NULL;

    if (cabeca == NULL) {
        // Caso F�cil, a Lista Est� Vazia
        cabeca = novoNo;
    }
    else {
        // Caso Dif�cil a Lista N�O Est� Vazia
        struct no *ponteiro = cabeca;

        while (ponteiro -> proximo != NULL) {
            ponteiro = ponteiro -> proximo;
        }

        ponteiro -> proximo = novoNo;
    }
}

// Fun��o que Imprime os N�s da Lista
void imprimir() {
    printf("==========================\n");

    struct no *ponteiro = cabeca;

    while (ponteiro != NULL) {
        printf("%d\n", ponteiro -> numero);
        ponteiro = ponteiro -> proximo;
    }
}

// Fun��o que Exclui o N� da Lista
void remover(int numero) {
    if (cabeca != NULL) {
        if (cabeca -> numero == numero) {
            // Caso F�cil, Excluir o primeiro Elemento da Lista
            struct no *ponteiroExcluir = cabeca;
            cabeca = cabeca -> proximo;
            free (ponteiroExcluir);
        }
        else {
            // Caso Dif�cil, Excluir Algum Elemento no Meio da Lista
            struct no *ponteiroAnterior = cabeca;
            while ((ponteiroAnterior -> proximo != NULL) && (ponteiroAnterior -> proximo -> numero != numero)) {
                ponteiroAnterior = ponteiroAnterior -> proximo;
            }

            if (ponteiroAnterior -> proximo != NULL) {
                struct no *ponteiroExcluir = ponteiroAnterior -> proximo;
                ponteiroAnterior -> proximo = ponteiroExcluir -> proximo;
                free(ponteiroExcluir);
            }
        }
    }
}

// Fun��o Principal de Execu��o do Programa
int main(int argc, char *argv[]) {
    int opcao = 0;
    int numero = 0;

    while (opcao != 4) {
        printf("+----------------+\n");
        printf("| Menu de opcoes |\n");
        printf("+----------------+\n");
        printf("|  1 - Inserir   |\n");
        printf("|  2 - Remover   |\n");
        printf("|  3 - Imprimir  |\n");
        printf("|  4 - Sair      |\n");
        printf("+----------------+\n");
        printf("Digite a opcao: ")/
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("Digite o numero: ");
            scanf("%d", &numero);
            inserir(numero);
            break;
        case 2:
            printf("Digite o numero: ");
            scanf("%d", &numero);
            remover(numero);
            break;
        case 3:
            imprimir();
            break;
        }
    }
}
