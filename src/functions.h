#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura para os produtos
typedef struct 
{
    char nome[50];
    float preco;
    float peso;
} Produto;

// Definindo a estrutura para a compra
typedef struct 
{
    int regiao;
    Produto produtos[10];
    int quantidadeProdutos;
    float precoTotal;
    float precoFrete;
    char dataHoraCompra[20];
    char previsaoChegada[20];
} Compra;

// Função para calcular o preço do frete
float calcularFrete(float peso, int regiao) 
{
    float fretePadrao, fretePeso;
    switch (regiao)
    {
    case 1:
        fretePadrao = 35.00;
        fretePeso = 50.00;
        break;
    case 2:
        fretePadrao = 40.00;
        fretePeso = 60.00;
        break;
    case 3:
        fretePadrao = 30.00;
        fretePeso = 50.00;
        break;
    case 4:
        fretePadrao = 25.00;
        fretePeso = 45.00;
        break;
    default:
        printf("Região inválida\n");
        return -1;
        break;
    }
    if (peso <= 2) {
        return fretePadrao;
    } else {
        return fretePeso;
    }
}

// Função para exibir a lista de produtos disponíveis
void exibirListaProdutos(Produto listaProdutos[], int tamanho) 
{
    printf("Lista de produtos disponiveis:\n");
    for (int i = 0; i < tamanho; i++) 
    {
        printf("%d - %s - R$ %.2f\n", i + 1, listaProdutos[i].nome, listaProdutos[i].preco);
    }
}

// Função para solicitar a região ao usuário
int solicitarRegiao() 
{
    int regiao;
    printf("Selecione a regiao:\n");
    printf("1 - Nordeste\n2 - Norte\n3 - Sul\n4 - Sudeste\n");
    scanf("%d", &regiao);
    if (regiao < 1 || regiao > 4) 
    {
        printf("Região inválida. Tente novamente.\n");
        return solicitarRegiao();  // Chama recursivamente se a região for inválida
    } else 
    {
    return regiao;
    }
}

// Função para solicitar a seleção de produtos ao usuário
void selecionarProdutos(Compra *compra, Produto listaProdutos[], int tamanho) 
{
    int escolha;
    while (1) 
    {
        printf("Selecione os produtos (digite o numero do produto, -1 para encerrar): ");
        scanf("%d", &escolha);
        printf("\n");
        if (escolha == -1) 
        {
            break;
        }
        if (escolha >= 1 && escolha <= tamanho) 
        {
            compra->produtos[compra->quantidadeProdutos] = listaProdutos[escolha - 1];
            compra->precoTotal += listaProdutos[escolha - 1].preco;
            compra->quantidadeProdutos++;
        } 
        else 
        {
            printf("Escolha invalida. Tente novamente.\n");
        }
    }
}

void limparBufferEntrada() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}