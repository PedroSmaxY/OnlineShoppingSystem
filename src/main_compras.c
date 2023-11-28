#include "../include/dados_operacoes.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Produto listaProdutos[] = {
        {1, "Arroz", 10.00, 1},
        {2, "Feijão", 8.00, 1},
        {3, "Macarrão", 5.00, 0.5},
        {4, "Farinha", 4.00, 0.5},
        {5, "Açúcar", 3.00, 2.1},
        {6, "Café", 6.00, 0.6},
        {7, "Óleo", 7.00, 1},
        {8, "Sal", 2.00, 2.5},
        {9, "Leite", 3.00, 1},
        {10, "Manteiga", 5.00, 0.3}};

    limparConsole();

    Compra compra = {.quantidadeProdutos = 0, .precoTotal = 0.0, .precoFrete = 0.0};

    exibirListaProdutos(listaProdutos, sizeof(listaProdutos) / sizeof(listaProdutos[0]));
    selecionarProdutos(&compra, listaProdutos, sizeof(listaProdutos) / sizeof(listaProdutos[0]));

    limparBufferEntrada();
    limparConsole();

    compra.regiao = solicitarRegiao();
    compra.precoFrete = calcularFrete(compra.produtos[0].peso, compra.regiao); // Supondo que o peso do primeiro produto seja representativo
    compra.precoTotal += compra.precoFrete;

    time_t t;
    struct tm *data;
    t = time(NULL);
    data = localtime(&t);

    sprintf(compra.dataHoraCompra, "%02d/%02d/%d %02d:%02d", data->tm_mday, data->tm_mon + 1, data->tm_year + 1900, data->tm_hour, data->tm_min);

    data->tm_mday += 7;
    mktime(data);

    sprintf(compra.previsaoChegada, "%02d/%02d/%d", data->tm_mday, data->tm_mon + 1, data->tm_year + 1900);

    limparConsole();

    printf("\n----------------------------------------\n");
    printf("Resumo da Compra");
    printf("\n----------------------------------------\n");
    printf("Regiao: %s", compra.regiao == 1 ? "norte" 
    : compra.regiao == 2 ? "Nordeste"
    : compra.regiao == 3 ? "Sul" 
    : "Sudeste");

    printf("\n----------------------------------------\n");
    printf("Produtos selecionados:\n\n");

    for (int i = 0; i < compra.quantidadeProdutos; i++)
    {
        printf("id:%d - %s - R$%.2f\n", compra.produtos[i].codigo,compra.produtos[i].nome, compra.produtos[i].preco);
    }
    printf("\n----------------------------------------\n");
    printf("Preço dos produtos: R$ %.2f\n", compra.precoProdutos);
    printf("Frete: R$ %.2f\n", compra.precoFrete);
    printf("Preco total: R$ %.2f", compra.precoTotal);
    printf("\n----------------------------------------\n");
    printf("Data e hora da compra: %s\n", compra.dataHoraCompra);
    printf("Previsâo de chegada: %s", compra.previsaoChegada);
    printf("\n----------------------------------------\n");
    return 0;
}
