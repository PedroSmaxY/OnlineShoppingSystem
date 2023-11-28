// Inclui o arquivo de cabeçalho que contém as bibliotecas, definições e funções necessárias
#include "../Include/dados_operacoes.h"

// Função principal do programa
int main()
{
    // Configura as acentuações para o português
    setlocale(LC_ALL, "Portuguese");

    // Lista de produtos disponíveis com seus códigos, nomes, preços e pesos
    Produto listaProdutos[] = {
        {1, "Arroz", 10.00, 1},
        {2, "Feijao", 8.00, 1},
        {3, "Macarrao", 5.00, 0.5},
        {4, "Farinha", 4.00, 0.5},
        {5, "Peixe", 3.00, 2.1},
        {6, "Cafe", 6.00, 0.6},
        {7, "Oleo", 7.00, 1},
        {8, "Sal", 2.00, 2.5},
        {9, "Leit e", 3.00, 1},
        {10, "Manteiga", 5.00, 0.3}};

    // Limpa o console
    limparConsole();

    // Inicializa a estrutura de Compra
    Compra compra = {.quantidadeProdutos = 0, .precoTotal = 0.0, .precoFrete = 0.0};

    // Exibe a lista de produtos disponíveis
    exibirListaProdutos(listaProdutos, sizeof(listaProdutos) / sizeof(listaProdutos[0]));

    // Solicita ao cliente que selecione os produtos desejados
    selecionarProdutos(&compra, listaProdutos, sizeof(listaProdutos) / sizeof(listaProdutos[0]));

    // Limpa o buffer de entrada do teclado
    limparBufferEntrada();

    // Limpa o console
    limparConsole();

    // Solicita a região ao cliente
    compra.regiao = solicitarRegiao();

    // Calcula o preço do frete com base no peso do produto e região do cliente
    compra.precoFrete = calcularFrete(compra);

    // Adiciona o preço do frete ao preço total da compra
    compra.precoTotal += compra.precoFrete;

    // Obtém a data e hora atuais
    time_t t;
    struct tm *data;
    t = time(NULL);
    data = localtime(&t);

    // Formata a data e hora da compra
    sprintf(compra.dataHoraCompra, "%02d/%02d/%d %02d:%02d", data->tm_mday, data->tm_mon + 1, data->tm_year + 1900, data->tm_hour, data->tm_min);

    // Adiciona 7 dias à data atual para obter a previsão de chegada
    data->tm_mday += 7;
    mktime(data);

    // Formata a previsão de chegada
    sprintf(compra.previsaoChegada, "%02d/%02d/%d", data->tm_mday, data->tm_mon + 1, data->tm_year + 1900);

    // Limpa o console mais uma vez
    limparConsole();

    // Exibe um resumo da compra
    printf("\n----------------------------------------\n");
    printf("Resumo da Compra");
    printf("\n----------------------------------------\n");
    printf("Região: %s", compra.regiao == 1 ? "Norte" 
    : compra.regiao == 2 ? "Nordeste"
    : compra.regiao == 3 ? "Sul" 
    : "Sudeste");

    printf("\n----------------------------------------\n");
    printf("Produtos selecionados:\n\n");

    // Exibe os produtos selecionados
    for (int i = 0; i < compra.quantidadeProdutos; i++)
    {
        printf("id:%d - %s - R$%.2f\n", compra.produtos[i].codigo,compra.produtos[i].nome, compra.produtos[i].preco);
    }
    printf("----------------------------------------\n");
    printf("Valor dos produtos: R$%.2f", compra.precoProdutos);
    printf("\n----------------------------------------\n");
    printf("Valor do frete: R$%.2f", compra.precoFrete);
    printf("\nValor total: R$%.2f", compra.precoTotal);
    printf("\n----------------------------------------\n");
    printf("Data e hora da compra: %s\n", compra.dataHoraCompra);
    printf("Previsao de chegada: %s", compra.previsaoChegada);
    printf("\n----------------------------------------\n");
    return 0;
}