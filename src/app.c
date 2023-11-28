#include <stdio.h>
#include "functions.h"
#include <stdlib.h>
#include <locale.h>
#include <time.h>

struct produto
{
    int codigo;
    char nome[50];
    float preco;
    float peso;
};

void imprimir_produtos(struct produto produtos[], int num_produtos)
{
    printf("Lista de produtos:\n");
    printf("Codigo | Nome | Preco\n");
    printf("-------+------+-------\n");
    for (int i = 0; i < num_produtos; i++)
    {
        printf("Codigo: %d Nome: %s Preco: R$ %.2f\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco);
    }
}

int encontrar_produto(struct produto produtos[], int num_produtos, int codigo)
{
    for (int i = 0; i < num_produtos; i++)
    {
        if (produtos[i].codigo == codigo)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    setlocale(LC_ALL, "");
    struct produto produtos[NUM_PRODUTOS] = {
        {1, "Arroz", 10.00, 0.2},
        {2, "Feijao", 8.00, 1},
        {3, "Macarrao", 5.00, 0.5},
        {4, "Farinha", 4.00, 0.5},
        {5, "Acucar", 3.00, 0.5},
        {6, "Cafe", 6.00, 0.5},
        {7, "Oleo", 7.00, 0.5},
        {8, "Sal", 2.00, 0.5},
        {9, "Leite", 3.00, 0.5},
        {10, "Manteiga", 5.00, 0.5},
    };

    float peso, valorProduto;
    int index, regiao, codigo;

    while (1)
    {
        while (1)
        {
            imprimir_produtos(produtos, NUM_PRODUTOS);

            printf("\nDigite o código do produto (0 para sair): ");
            scanf("%d", &codigo);

            if (codigo == 0)
            {
                break;
            }

            if (index == -1)
            {
                printf("Produto não encontrado.\n");
            }
            else
            {
                return produtos[index].preco;
            }

            if (codigo == 0)
            {
                break;
            }
        }

        printf("\nInforme a região: \n");
        printf("Norte: 1\n");
        printf("Nordeste: 2\n");
        printf("Sul: 3\n");
        printf("Sudeste: 4\n");
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
                               : regiao == 3 ? "Sul"
                               : regiao == 4 ? "Sudeste"
                                             : "Região inválida");

        printf("Valor do Frete: R$ %.2f\n", valorFrete);
        printf("Valor Total da Compra: R$ %.2f\n", totalCompra);

        data->tm_mday += 7;
        mktime(data);

        printf("Data prevista para entrega: %02d/%02d/%d\n", data->tm_mday, data->tm_mon + 1, data->tm_year + 1900);

        return 0;
    }
}