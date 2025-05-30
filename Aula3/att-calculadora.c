#include <stdio.h>
#include <math.h>
#include <stdlib.h>



int main() {
	char operador, resposta;
	float resultado, a, b;

	do { //Serve para usar junto com o while
		printf("\e[H\e[2J"); //Serve para limpar a tela pq e assim eu sla kk
		printf("-------------------CALCULADORA-------------------\n");
		printf("Escreva o primeiro numero \n");
		scanf("%f", &a);

		printf("Escreva o segundo numero \n");
		scanf("%f", &b);

		printf("Digite + para SOMAR\n");
		printf("Digite - para SUBTRAIR\n");
		printf("Digite * para MULTIPLICAR\n");
		printf("Digite / para DIVIDIR\n");
		scanf(" %c", &operador);

		switch(operador) { //Vai entrar no switch para escolher a operacao baseado no simbolo que o user digitou

		case '+':
			resultado = a + b;
			printf("O resultado da sua operacao C): %.2f", resultado);
			break;

		case '-':
			resultado = a - b;
			printf("O resultado da sua operacao C): %.2f", resultado);
			break;

		case '*':
			resultado = a * b;
			printf("O resultado da sua operacao C): %.2f", resultado);
			break;

		case '/':
			if(b != 0) {
				resultado = a / b;
				printf("O resultado da sua operacao C): %.2f", resultado);
			} else {
				printf("Erro: divisC#o por zero");
			}
			break;

		default:
			printf("Operador invalido");
		}

		printf("\n Deseja fazer outra operacao? (s/n)"); //Pergunta se quer continuar ou nC#o
		setbuf(stdin,NULL); //Limpa a memoria para nao bugar com o scanf abaixo
		scanf("%c", &resposta);
	}

	while(resposta == 's' || resposta == 'S');

	printf("\n Calculadora encerrada");

	return 0;

}
