// Evita que o arquivo de cabeçalho seja incluído múltiplas vezes durante a compilação
#ifndef DADOS_OPERACOES_H
#define DADOS_OPERACOES_H

// Inclui as bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

// Definindo a estrutura para os produtos
typedef struct
{
    int codigo;
    char nome[50];
    float preco;
    float peso;
} Produto;

// Definindo a estrutura para a compra
typedef struct
{
    Produto produtos[50]; // Array de produtos
    int quantidadeProdutos;
    double precoProdutos;
    double precoTotal;
    double precoFrete;
    int regiao;
    char dataHoraCompra[20];
    char previsaoChegada[20];
} Compra;

// Função para limpar o buffer de entrada do teclado
void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para limpar o console
void limparConsole()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Função para calcular o preço do frete
float calcularFrete(Compra compra)
{
    float fretePadrao, fretePeso;

    // Calcula os valores do frete com base na região
    switch (compra.regiao)
    {
    case 1: // Norte
        fretePadrao = 35.00;
        fretePeso = 50.00;
        break;
    case 2: // Nordeste
        fretePadrao = 40.00;
        fretePeso = 60.00;
        break;
    case 3: // Sul
        fretePadrao = 30.00;
        fretePeso = 50.00;
        break;
    case 4: // Sudeste
        fretePadrao = 25.00;
        fretePeso = 45.00;
        break;
    default:
        printf("Regiao invalida\n");
        return -1; // Retorna -1 se a região for inválida
        break;
    }

    // Retorna o valor do frete com base no peso
    for (int i = 0; i < compra.quantidadeProdutos; i++)
    {
        if (compra.produtos[i].peso > 2)
        {
            return fretePeso;
        }
    }
    return fretePadrao;
}

// Função para exibir a lista de produtos disponíveis
void exibirListaProdutos(Produto listaProdutos[], int tamanho)
{
    printf("\n----------------------------------------\n");
    printf("Lista de produtos disponiveis:");
    printf("\n----------------------------------------\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d - %s - %.02fkg - R$%.2f\n", i + 1, listaProdutos[i].nome, listaProdutos[i].peso, listaProdutos[i].preco);
    }
    printf("\n----------------------------------------\n");
}

// Função para solicitar a região ao usuário
int solicitarRegiao()
{
    int regiao;
    printf("\n----------------------------------------\n");
    printf("Selecione a regiao:");
    printf("\n----------------------------------------\n");
    printf("1 - Norte\n");
    printf("frete padrao: R$35.00\n");
    printf("frete por peso: R$50.00");
    printf("\n----------------------------------------\n");
    printf("2 - Nordeste\n");
    printf("frete padrao: R$40.00\n");
    printf("frete por peso: R$60.00");
    printf("\n----------------------------------------\n");
    printf("3 - Sul\n");
    printf("frete padrao: R$30.00\n");
    printf("frete por peso: R$50.00");
    printf("\n----------------------------------------\n");
    printf("4 - Sudeste\n");
    printf("frete padrao: R$25.00\n");
    printf("frete por peso: R$45.00");
    printf("\n----------------------------------------\n");
    printf("\nRegiao: ");
    scanf("%d", &regiao);
    limparBufferEntrada();
    if (regiao < 1 || regiao > 4)
    {
        limparConsole();
        printf("Regiao invalida. Tente novamente.\n");
        return solicitarRegiao(); // Chama recursivamente se a região for inválida
    }
    else
    {
        return regiao;
    }
}

// Função para solicitar a seleção de produtos ao usuário
void selecionarProdutos(Compra *compra, Produto listaProdutos[], int tamanho)
{
    int escolha;
    printf("\nSelecione os produtos (digite o numero do produto, -1 para finalizar compra)\n");
    while (1)
    {
        printf("Produto: ");
        int resultado = scanf("%d", &escolha);

        if (resultado == 1)
        {
            if (escolha == -1)
            {
                if (compra->quantidadeProdutos == 0)
                {
                    printf("Nenhum produto selecionado.\n");
                    continue;
                }
                else
                {
                    break;
                }
            }
            else if (escolha < 1 || escolha > tamanho)
            {
                printf("Numero de produto invalido. Tente novamente.\n");
            }
            else if (compra->quantidadeProdutos == 50)
            {
                printf("Limite de produtos atingido.\n");
                break;
            }
            else
            {
                compra->produtos[compra->quantidadeProdutos] = listaProdutos[escolha - 1];
                compra->precoProdutos += listaProdutos[escolha - 1].preco;
                compra->quantidadeProdutos++;
                compra->precoTotal += listaProdutos[escolha - 1].preco;
                printf("Produto %s adicionado, Valor do Carrinho: R$%.02f.\n", listaProdutos[escolha - 1].nome, compra->precoProdutos);
            }
        }
        else
        {
            printf("Numero de produto invalido. Tente novamente.\n");
        }
        limparBufferEntrada();
    }
}

// Finaliza o pré-processamento condicional
#endif