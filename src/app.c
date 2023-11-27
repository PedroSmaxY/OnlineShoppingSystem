#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

int main()
{
    setlocale(LC_ALL, "");
    float peso, valorProduto;
    int codigo, index, regiao;

    printf("Lista de produtos:\n");
    printf("Código | Nome | Preço\n");
    printf("-------+------+-------\n");
    for (index = 0; produtos[index].codigo; index++)
    {
        printf("Código: %d\nNome: %s\nPreço: R$ %.2f\n", produtos[index].codigo, produtos[index].nome, produtos[index].preco);
    }

    printf("\nInforme a região: \n");
    printf("Norte: 1\n");
    printf("Nordeste: 2\n");
    printf("Sudeste: 3\n");
    printf("Sul: 4\n");
    printf("\nDigite o código da região: ");
    scanf(" %d", &regiao);

    printf("\nDigite o peso do produto em Kg: ");
    scanf("%f", &peso);

    printf("\nDigite o valor do produto: ");
    scanf("%f", &valorProduto);

    float valorFrete = calcularFrete(regiao, peso);

    if (valorFrete == -1.0)
    {
        return 1;
    }

    float totalCompra = valorProduto + valorFrete;

    time_t t;
    struct tm *data;
    t = time(NULL);
    data = localtime(&t);

    printf("\n\n");
    printf("Resumo da Compra\n");
    printf("Data e Hora da Compra: %d/%d/%d %d:%d\n", data->tm_mday, data->tm_mon + 1, data->tm_year + 1900, data->tm_hour, data->tm_min);
    printf("\nValor do Produto: R$ %.2f\n", valorProduto);

    printf("Região: %s\n", regiao == 1 ? "Norte" : regiao == 2 ? "Nordeste" : regiao == 3 ? "Sudeste" : regiao == 4 ? "Sul" : "Região inválida");

    printf("Valor do Frete: R$ %.2f\n", valorFrete);
    printf("Valor Total da Compra: R$ %.2f\n", totalCompra);

    data->tm_mday += 7;
    mktime(data);

    printf("Data prevista para entrega: %02d/%02d/%d\n", data->tm_mday, data->tm_mon + 1, data->tm_year + 1900);

    return 0;
}