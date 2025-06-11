#include <stdio.h>      
#include <stdlib.h>     // Biblioteca para usar system() e manipulações gerais
#include <string.h>     // Biblioteca para manipulação de strings (usada em sprintf)

// Função que limpa a tela dependendo do sistema operacional
void limpar_tela() {
#ifdef _WIN32            // Se estiver compilando no Windows
    system("cls");       // Limpa a tela com comando do Windows
#else                    // Caso contrário (Linux, Mac, etc.)
    system("clear");     // Limpa a tela com comando do Linux
#endif
}

int main() {
    float num1 = 0, num2 = 0, resultado = 0;  // Números e resultado da operação
    char operacao = '+';                      // Operador aritmético (padrão: '+')
    int continuar = 1;                        // Controla o laço principal

    // Histórico: vetor de strings (100 posições, 100 caracteres cada)
    char historico[100][100];
    int total_operacoes = 0;                 // Conta quantas operações foram salvas

    while (continuar) {
        limpar_tela(); // Limpa a tela a cada repetição

        // Interface do menu da calculadora
        printf("=================================\n");
        printf("         CALCULADORA SIMPLES     \n");
        printf("=================================\n");
        printf(" Operação atual: %.2f %c %.2f = %.2f\n", num1, operacao, num2, resultado);
        printf("=================================\n");
        printf("1 - Digitar primeiro número\n");
        printf("2 - Digitar segundo número\n");
        printf("3 - Escolher operação (+ - * /)\n");
        printf("4 - Calcular\n");
        printf("5 - Ver histórico\n");
        printf("6 - Sair\n");
        printf("=================================\n");
        printf("Escolha uma opção: ");

        int opcao;
        scanf("%d", &opcao); // Lê a escolha do usuário

        switch (opcao) {
            case 1:
                printf("Digite o primeiro número: ");
                scanf("%f", &num1); // Lê o primeiro número
                break;

            case 2:
                printf("Digite o segundo número: ");
                scanf("%f", &num2); // Lê o segundo número
                break;

            case 3:
                printf("Digite a operação (+, -, *, /): ");
                scanf(" %c", &operacao); // Lê o operador
                break;

            case 4:
                // Executa a operação aritmética com base no operador
                switch (operacao) {
                    case '+':
                        resultado = num1 + num2;
                        break;
                    case '-':
                        resultado = num1 - num2;
                        break;
                    case '*':
                        resultado = num1 * num2;
                        break;
                    case '/':
                        if (num2 != 0) {
                            resultado = num1 / num2;
                        } else {
                            // Mensagem de erro para divisão por zero
                            printf("Erro: divisão por zero!\n");
                            resultado = 0;
                            break;
                        }
                        break;
                    default:
                        // Se o operador for inválido
                        printf("Operação inválida!\n");
                        break;
                }

                // Adiciona a operação ao histórico (se ainda houver espaço)
                if (total_operacoes < 100) {
                    // Salva uma string com a operação formatada
                    sprintf(historico[total_operacoes], "%.2f %c %.2f = %.2f", num1, operacao, num2, resultado);
                    total_operacoes++; // Incrementa o contador de histórico
                } else {
                    printf("Histórico cheio. Não é possível salvar mais operações.\n");
                }

                // Exibe o resultado e espera o usuário apertar Enter
                printf("Resultado: %.2f\n", resultado);
                printf("Pressione Enter para continuar...");
                getchar(); getchar(); // Pausa (espera outro enter)
                break;

            case 5:
                limpar_tela(); // Limpa a tela antes de mostrar o histórico
                printf("======= HISTÓRICO DE OPERAÇÕES =======\n");
                if (total_operacoes == 0) {
                    printf("Nenhuma operação realizada ainda.\n");
                } else {
                    // Exibe todas as operações salvas
                    for (int i = 0; i < total_operacoes; i++) {
                        printf("%d) %s\n", i + 1, historico[i]);
                    }
                }
                printf("======================================\n");
                printf("Pressione Enter para voltar...");
                getchar(); getchar(); // Pausa para visualização
                break;

            case 6:
                continuar = 0; // Sai do laço principal
                break;

            default:
                // Mensagem de opção inválida
                printf("Opção inválida!\n");
                printf("Pressione Enter para continuar...");
                getchar(); getchar();
        }
    }

    printf("Calculadora encerrada. Até logo!\n");
    return 0;
}
