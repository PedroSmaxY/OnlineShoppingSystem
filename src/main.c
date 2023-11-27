#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>

int calcularFrete(char regiao, float peso)
{
    float fretePadrao, fretePeso;
    switch (regiao)
    {
    case 'N':
        fretePadrao = 35.00;
        fretePeso = 50.00;
        break;
    case 'O':
        fretePadrao = 40.00;
        fretePeso = 60.00;
        break;
    case 'S':
        fretePadrao = 30.00;
        fretePeso = 50.00;
        break;
    case 'E':
        fretePadrao = 25.00;
        fretePeso = 45.00;
        break;
    default:
        printf("Região inválida\n");
        return -1;
        break;
    }

    if (peso > 2)
    {
        return fretePeso;
    }
    else
    {
        return fretePadrao;
    }
}

int main()
{
    setlocale(LC_ALL, "");

    char regiao, regiaoString[1];
    float peso, valorProduto;
    

    printf("\nInforme a região [ S, SE, N, NE ]: ");
    scanf(" %s", regiaoString);

    for (int i = 0; i < regiaoString[i]; i++)
    {
        regiaoString[i] = toupper(regiaoString[i]);
    }

    regiao = (strcmp(regiaoString, "NE") == 0 ? 'O'
    : strcmp(regiaoString, "SE") == 0 ? 'E'
    : regiaoString[0]);

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

    printf("Região: %s\n", regiaoString);


    printf("Valor do Frete: R$ %.2f\n", valorFrete);
    printf("Valor Total da Compra: R$ %.2f\n", totalCompra);

    data->tm_mday += 7;
    mktime(data);

    printf("Data prevista para entrega: %02d/%02d/%d\n", data->tm_mday, data->tm_mon + 1, data->tm_year + 1900);

    return 0;
}