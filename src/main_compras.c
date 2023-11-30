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
        {9, "Leite", 3.00, 1},
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
    solicitarRegiao(&compra);

    // Calcula o preço do frete com base no peso do produto e região do cliente
    calcularFrete(&compra);

    // Limpa o console mais uma vez
    limparConsole();

    // Exibe o resumo da compra
    ResumoDaCompra(&compra);
    return 0;
}