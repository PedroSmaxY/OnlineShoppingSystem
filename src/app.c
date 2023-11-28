#include "functions.h"

// Função principal
int main()
{
    Produto listaProdutos[] = {
        {"Produto A", 20.0, 1.5},
        {"Produto B", 30.0, 3.0},
        {"Produto C", 15.0, 0.5}};

    Compra compra;
    compra.precoTotal = 0.0;
    compra.precoFrete = 0.0;

    compra.regiao = solicitarRegiao();
    exibirListaProdutos(listaProdutos, sizeof(listaProdutos) / sizeof(listaProdutos[0]));
    selecionarProdutos(&compra, listaProdutos, sizeof(listaProdutos) / sizeof(listaProdutos[0]));

    compra.precoFrete = calcularFrete(compra.produtos[0].peso); // Supondo que o peso do primeiro produto seja representativo

    strcpy(compra.dataHoraCompra, "27/11/2023 14:30");
    strcpy(compra.previsaoChegada, "04/12/2023");

    printf("\nResumo da compra:\n");
    printf("Regiao: %d\n", compra.regiao);
    printf("Produtos selecionados:\n");
    for (int i = 0; i < compra.quantidadeProdutos; i++)
    {
        printf("- %s - R$ %.2f\n", compra.produtos[i].nome, compra.produtos[i].preco);
    }
    printf("Preco total: R$ %.2f\n", compra.precoTotal);
    printf("Frete: R$ %.2f\n", compra.precoFrete);
    printf("Data e hora da compra: %s\n", compra.dataHoraCompra);
    printf("Previsao de chegada: %s\n", compra.previsaoChegada);

    return 0;
}
