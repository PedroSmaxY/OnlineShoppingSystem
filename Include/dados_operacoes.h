// Evita que o arquivo de cabeçalho seja incluído múltiplas vezes durante a compilação
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

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
    Produto produtos[10]; // Array de produtos
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
        printf("Região inválida\n");
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
    printf("Lista de produtos disponiveis:\n\n");
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
    printf("1 - Norte\n2 - Nordeste\n3 - Sul\n4 - Sudeste\n");
    printf("\nRegiao: ");
    scanf("%d", &regiao);
    limparBufferEntrada();
    if (regiao < 1 || regiao > 4)
    {
        printf("Região inválida. Tente novamente.\n");
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
    printf("\nSelecione os produtos (digite o numero do produto, -1 para encerrar)\n");
    while (1)
    {
        printf("Produto: ");
        int resultado = scanf("%d", &escolha);
        if (resultado == 1)
        {
            if (escolha == -1)
            {
                break;
            }
            else if (escolha < 1 || escolha > tamanho)
            {
                printf("Número de produto inválido. Tente novamente.\n");
            }
            else
            {
                compra->produtos[compra->quantidadeProdutos] = listaProdutos[escolha - 1];
                compra->precoTotal += listaProdutos[escolha - 1].preco;
                compra->precoProdutos += listaProdutos[escolha - 1].preco;
                compra->quantidadeProdutos++;
            }
        }
        limparBufferEntrada();
    }
}

// Função para limpar o console (dependente do sistema operacional)
void limparConsole()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Finaliza o pré-processamento condicional
#endif