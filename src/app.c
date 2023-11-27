#include <stdio.h>
#include "functions.h"
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    struct produto produtos[10] = {
        {1, "Arroz", 10.00},
        {2, "Feijao", 8.00},
        {3, "Macarrao", 5.00},
        {4, "Farinha", 4.00},
        {5, "Acucar", 3.00},
        {6, "Cafe", 6.00},
        {7, "Oleo", 7.00},
        {8, "Sal", 2.00},
        {9, "Leite", 3.00},
        {10, "Manteiga", 5.00},
    };

    setlocale(LC_ALL, "");
    float peso, valorProduto;
    int index, regiao;

    while (1)
    {
        printf("Lista de produtos:\n");
        printf("Codigo | Nome | Preco\n");
        printf("-------+------+-------\n");
        for (index = 0; produtos[index].codigo; index++)
        {
            printf("Codigo: %d Nome: %s Preco: R$ %.2f\n", produtos[index].codigo, produtos[index].nome, produtos[index].preco);
        }
        int codigo;
        printf("\nDigite o código do produto (0 para sair): ");
        scanf("%d", &codigo);

        int index;
        for (index = 0; produtos[index].codigo; index++)
        {
            if (produtos[index].codigo == codigo)
            {
                break;
            }
        }
        if (index == 10)
        {
            break;
        }
        else
        {
            valorProduto += produtos[index].preco;
        }

        if (codigo == 0)
        {
            break;
        }
    }

    printf("\nInforme a região: \n");
    printf("Norte: 1\n");
    printf("Nordeste: 2\n");
    printf("Sudeste: 3\n");
    printf("Sul: 4\n");
    printf("\nDigite o código da região: ");
    scanf("%d", &regiao);

    printf("\nDigite o peso do produto em Kg: ");
    scanf("%f", &peso);

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

    printf("Região: %s\n", regiao == 1   ? "Norte"
    : regiao == 2 ? "Nordeste"
    : regiao == 3 ? "Sudeste"
    : regiao == 4 ? "Sul"
    : "Região inválida");

    printf("Valor do Frete: R$ %.2f\n", valorFrete);
    printf("Valor Total da Compra: R$ %.2f\n", totalCompra);

    data->tm_mday += 7;
    mktime(data);

    printf("Data prevista para entrega: %02d/%02d/%d\n", data->tm_mday, data->tm_mon + 1, data->tm_year + 1900);

    return 0;
}