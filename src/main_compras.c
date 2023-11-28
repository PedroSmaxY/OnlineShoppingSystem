// Inclui o arquivo de cabeçalho que contém as bibliotecas, definições e funções necessárias
#include "../Include/dados_operacoes.h"

// Função principal do programa
int main()
{
    // Configura a localização para o português
    setlocale(LC_ALL, "Portuguese");

    // Lista de produtos disponíveis com seus códigos, nomes, preços e pesos
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

    // Limpa o console (função definida no arquivo de cabeçalho)
    limparConsole();

    // Inicializa a estrutura de Compra com valores padrão
    Compra compra = {.quantidadeProdutos = 0, .precoTotal = 0.0, .precoFrete = 0.0};

    // Exibe a lista de produtos disponíveis para o usuário
    exibirListaProdutos(listaProdutos, sizeof(listaProdutos) / sizeof(listaProdutos[0]));

    // Solicita ao usuário que selecione os produtos desejados
    selecionarProdutos(&compra, listaProdutos, sizeof(listaProdutos) / sizeof(listaProdutos[0]));

    // Limpa o buffer de entrada do teclado
    limparBufferEntrada();

    // Limpa o console novamente
    limparConsole();

    // Solicita a região ao usuário
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
    printf("Região: %s", compra.regiao == 1 ? "norte" 
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
    printf("Preço dos produtos: R$%.2f", compra.precoProdutos);
    printf("\n----------------------------------------\n");
    printf("Frete: R$%.2f", compra.precoFrete);
    printf("\nPreço total: R$%.2f", compra.precoTotal);
    printf("\n----------------------------------------\n");
    printf("Data e hora da compra: %s\n", compra.dataHoraCompra);
    printf("Previsâo de chegada: %s", compra.previsaoChegada);
    printf("\n----------------------------------------\n");
    return 0;
}
