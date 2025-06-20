#include <stdio.h>      
#include <stdlib.h>     // Biblioteca para funções gerais (system, etc)
#include <string.h>     // Biblioteca para manipulação de strings (usada no histórico)
#include <math.h>       // Biblioteca para funções matemáticas como pow()

// Define comando de limpar tela dependendo do sistema operacional
#ifdef _WIN32
#define LIMPAR "cls"    // Windows usa "cls"
#else
#define LIMPAR "clear"  // Linux/Mac usam "clear"
#endif

// Função que exibe uma animação de "Calculando..."
void animarCarregamento() {
    printf("\nCalculando");
    for (int i = 0; i < 3; i++) {
        fflush(stdout); // Garante que o texto seja exibido imediatamente
        sleep(1);       // Espera 1 segundo
        printf(".");
    }
    printf("\n");
}

int main() {
    float num1 = 0, num2 = 0, resultado = 0;
    char operacao = '+';             // Armazena a operação (ex: +, -, *, /, etc)
    char operacao_f_char = '?';      // Armazena o símbolo da operação de fração

    // Controle do loop principal
    int continuar = 1;

    // Variáveis para operações com frações (numerador e denominador)
    int num1_n = 0, num1_d = 1, num2_n = 0, num2_d = 1;

    // Histórico de até 100 operações, cada uma com até 100 caracteres
    char historico[100][100];
    int total_operacoes = 0; // Contador de operações realizadas

    // Início do loop principal da calculadora
    while (continuar) {
        system(LIMPAR); // Limpa a tela (Windows ou Linux)

        // Interface visual da calculadora
        printf("==================================\n");
        printf("|         CALCULADORA            |\n");
        printf("|--------------------------------|\n");

        // Mostra o formato do cálculo, dependendo do tipo da operação
        if (operacao == 'r') { // Raiz
            printf("|   %.0f√%.2f = %.2f               |\n", num1, num2, resultado);
        } else if (operacao == 'f') { // Fração
            printf("|  (%d/%d) %c (%d/%d) = %.2f        |\n", num1_n, num1_d, operacao_f_char, num2_n, num2_d, resultado);
        } else { // Operações comuns
            printf("|   %.2f %c %.2f = %.2f             |\n", num1, operacao, num2, resultado);
        }

        // Menu principal de opções
        printf("==================================\n");
        printf("| # ESCOLHA UMA OPÇÃO #          |\n");
        printf("==================================\n");
        printf("| 1 - Adição                     |\n");
        printf("| 2 - Subtração                  |\n");
        printf("| 3 - Multiplicação              |\n");
        printf("| 4 - Divisão                    |\n");
        printf("| 5 - Raiz com índice            |\n");
        printf("| 6 - Operações com frações      |\n");
        printf("| 7 - Ver histórico              |\n");
        printf("| 0 - Encerrar                   |\n");
        printf("==================================\n");
        printf("Opção: ");

        int opcao;
        scanf("%d", &opcao); // Lê a opção escolhida

        // Verifica a opção e executa a operação correspondente
        switch (opcao) {
            case 1: // Adição
                printf("Digite os valores (ex: 5 5): ");
                scanf("%f %f", &num1, &num2);
                animarCarregamento();
                resultado = num1 + num2;
                operacao = '+';
                // Salva no histórico
                if (total_operacoes < 100) {
                    sprintf(historico[total_operacoes++], "%.2f + %.2f = %.2f", num1, num2, resultado);
                }
                break;

            case 2: // Subtração
                printf("Digite os valores (ex: 5 5): ");
                scanf("%f %f", &num1, &num2);
                animarCarregamento();
                resultado = num1 - num2;
                operacao = '-';
                if (total_operacoes < 100) {
                    sprintf(historico[total_operacoes++], "%.2f - %.2f = %.2f", num1, num2, resultado);
                }
                break;

            case 3: // Multiplicação
                printf("Digite os valores (ex: 5 5): ");
                scanf("%f %f", &num1, &num2);
                animarCarregamento();
                resultado = num1 * num2;
                operacao = '*';
                if (total_operacoes < 100) {
                    sprintf(historico[total_operacoes++], "%.2f * %.2f = %.2f", num1, num2, resultado);
                }
                break;

            case 4: // Divisão
                printf("Digite os valores (ex: 5 5): ");
                scanf("%f %f", &num1, &num2);
                if (num2 == 0) {
                    // Tratamento de erro para divisão por zero
                    printf("Erro: divisão por zero!\n");
                    sleep(2);
                    break;
                }
                animarCarregamento();
                resultado = num1 / num2;
                operacao = '/';
                if (total_operacoes < 100) {
                    sprintf(historico[total_operacoes++], "%.2f / %.2f = %.2f", num1, num2, resultado);
                }
                break;

            case 5: { // Raiz com índice
                float indice, radicando;
                printf("Índice da raiz: ");
                scanf("%f", &indice);
                if (indice == 0) {
                    printf("Índice inválido!\n");
                    sleep(2);
                    break;
                }
                printf("Valor radicado: ");
                scanf("%f", &radicando);
                animarCarregamento();
                resultado = pow(radicando, 1.0 / indice);
                operacao = 'r';
                num1 = indice;
                num2 = radicando;
                if (total_operacoes < 100) {
                    sprintf(historico[total_operacoes++], "%.0f√%.2f = %.2f", num1, num2, resultado);
                }
                break;
            }

            case 6: { // Operações com frações
                int tipo;
                float frac1, frac2;
                printf("Operações com frações:\n1 - Soma\n2 - Subtração\n3 - Multiplicação\n4 - Divisão\nEscolha: ");
                scanf("%d", &tipo);

                printf("Digite as frações (ex: 1/2 3/4): ");
                scanf("%d/%d %d/%d", &num1_n, &num1_d, &num2_n, &num2_d);

                frac1 = (float)num1_n / num1_d;
                frac2 = (float)num2_n / num2_d;
                animarCarregamento();

                // Calcula conforme o tipo
                switch (tipo) {
                    case 1:
                        resultado = frac1 + frac2;
                        operacao_f_char = '+';
                        break;
                    case 2:
                        resultado = frac1 - frac2;
                        operacao_f_char = '-';
                        break;
                    case 3:
                        resultado = frac1 * frac2;
                        operacao_f_char = '*';
                        break;
                    case 4:
                        if (frac2 == 0) {
                            printf("Erro: divisão por zero!\n");
                            sleep(2);
                            continue;
                        }
                        resultado = frac1 / frac2;
                        operacao_f_char = '/';
                        break;
                    default:
                        printf("Operação inválida!\n");
                        continue;
                }

                operacao = 'f';
                num1 = frac1;
                num2 = frac2;
                if (total_operacoes < 100) {
                    sprintf(historico[total_operacoes++], "(%d/%d) %c (%d/%d) = %.2f", num1_n, num1_d, operacao_f_char, num2_n, num2_d, resultado);
                }
                break;
            }

            case 7: // Ver histórico
                system(LIMPAR);
                printf("======= HISTÓRICO DE OPERAÇÕES =======\n");
                if (total_operacoes == 0) {
                    printf("Nenhuma operação realizada.\n");
                } else {
                    // Imprime todas as operações salvas
                    for (int i = 0; i < total_operacoes; i++) {
                        printf("%d) %s\n", i + 1, historico[i]);
                    }
                }
                printf("======================================\n");
                printf("Pressione Enter para voltar...");
                getchar(); getchar(); // Aguarda o usuário
                break;

            case 0: // Encerrar programa
                continuar = 0;
                break;

            default: // Opção inválida
                printf("Opção inválida!\n");
                sleep(2);
        }
    }

    // Mensagem final
    printf("Calculadora encerrada. Até logo!\n");
    return 0;
}
