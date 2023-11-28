#include "functions.h"
#include <time.h>
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

    exibirListaProdutos(listaProdutos, sizeof(listaProdutos) / sizeof(listaProdutos[0]));
    selecionarProdutos(&compra, listaProdutos, sizeof(listaProdutos) / sizeof(listaProdutos[0]));

    limparBufferEntrada();

    compra.regiao = solicitarRegiao();
    compra.precoFrete = calcularFrete(compra.produtos[0].peso, compra.regiao); // Supondo que o peso do primeiro produto seja representativo

    time_t t;
    struct tm *data;
    t = time(NULL);
    data = localtime(&t);

    sprintf(compra.dataHoraCompra, "%02d/%02d/%d", data->tm_mday, data->tm_mon + 1, data->tm_year + 1900);

    data->tm_mday += 7;
    mktime(data);

    sprintf(compra.previsaoChegada, "%02d/%02d/%d", data->tm_mday, data->tm_mon + 1, data->tm_year + 1900);

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
