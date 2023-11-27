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

struct produto
{
    int codigo;
    char nome[50];
    float preco;
};

struct produto produtos[10] = {
    {1, "Arroz", 10.00},
    {2, "Feijão", 8.00},
    {3, "Macarrão", 5.00},
    {4, "Farinha", 4.00},
    {5, "Açúcar", 3.00},
    {6, "Café", 6.00},
    {7, "Óleo", 7.00},
    {8, "Sal", 2.00},
    {9, "Leite", 3.00},
    {10, "Manteiga", 5.00},
};

void escolherProdutos(struct produto produtos[], int *quantidade)
{
    int index, codigo;

    // Inicializa a quantidade de produtos selecionados
    *quantidade = 0;

    // Exibe a lista de produtos
    printf("Lista de produtos:\n");
    for (index = 0; index < 10; index++)
    {
        if (produtos[index].codigo != -1)
        {
            printf("Código: %d\nNome: %s\nPreço: R$ %.2f\n", produtos[index].codigo, produtos[index].nome, produtos[index].preco);
        }
    }

    // Solicita o código do produto
    printf("\nDigite o código do produto ou -1 para parar: ");
    scanf("%d", &codigo);

    // Adiciona o produto à lista
    while (codigo != -1)
    {
        for (index = 0; index < 10; index++)
        {
            if (produtos[index].codigo == -1)
            {
                produtos[index].codigo = codigo;
                (*quantidade)++;
                break;
            }
        }

        // Exibe a lista de produtos atualizados
    }
}