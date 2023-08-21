#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Produto {
    int codigo;
    char descricao[100];
    float precoCompra;
    float precoVenda;
    int quantidade;
    int estoqueMinimo;
};

void cadastrarProduto(struct Produto estoque[], int *numProdutos) {
    struct Produto novoProduto;

    printf("C�digo do produto: ");
    scanf("%d", &novoProduto.codigo);
    printf("Descri��o do produto: ");
    scanf(" %[^\n]", novoProduto.descricao);
    printf("Pre�o de compra: ");
    scanf("%f", &novoProduto.precoCompra);
    printf("Pre�o de venda: ");
    scanf("%f", &novoProduto.precoVenda);
    printf("Quantidade em estoque: ");
    scanf("%d", &novoProduto.quantidade);
    printf("Estoque m�nimo: ");
    scanf("%d", &novoProduto.estoqueMinimo);

    estoque[*numProdutos] = novoProduto;
    (*numProdutos)++;

    printf("Produto cadastrado com sucesso!\n");
}

void calcularLucro(struct Produto produto) {
    float lucro = (produto.precoVenda - produto.precoCompra) * produto.quantidade;
    float percentualLucro = (lucro / (produto.precoCompra * produto.quantidade)) * 100;

    printf("Lucro obtido: R$ %.2f\n", lucro);
    printf("Percentual de lucro: %.2f%%\n", percentualLucro);
}

void mostrarProdutosAbaixoEstoqueMinimo(struct Produto estoque[], int numProdutos) {
    printf("Produtos com estoque abaixo do m�nimo:\n");

    for (int i = 0; i < numProdutos; i++) {
        if (estoque[i].quantidade < estoque[i].estoqueMinimo) {
            printf("C�digo: %d\n", estoque[i].codigo);
            printf("Descri��o: %s\n", estoque[i].descricao);
            printf("Quantidade em estoque: %d\n", estoque[i].quantidade);
            printf("Estoque m�nimo: %d\n\n", estoque[i].estoqueMinimo);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    struct Produto estoque[100];
    int numProdutos = 0;
    int opcao;

    do {
        printf("===== Controle de Estoque =====\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Calcular Lucro de Produto\n");
        printf("3. Mostrar Produtos Abaixo do Estoque M�nimo\n");
        printf("0. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        int codigoProduto;
        switch (opcao) {
            case 1:
                cadastrarProduto(estoque, &numProdutos);
                break;
            case 2:
                printf("Digite o c�digo do produto: ");
                scanf("%d", &codigoProduto);

                for (int i = 0; i < numProdutos; i++) {
                    if (estoque[i].codigo == codigoProduto) {
                        calcularLucro(estoque[i]);
                        break;
                    }
                }
                break;
            case 3:
                mostrarProdutosAbaixoEstoqueMinimo(estoque, numProdutos);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Op��o inv�lida. Escolha novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
