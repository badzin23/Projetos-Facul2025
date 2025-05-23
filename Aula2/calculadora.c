#include <stdio.h>
#include <math.h>

int main(){
    char operador;
    float resultado, a, b;
    
    printf("Escreva o primeiro número \n");
    scanf("%f", &a);
    
    printf("Escreva o segundo número \n");
    scanf("%f", &b);
    
    printf("Digite + para SOMAR\n");
    printf("Digite - para SUBTRAIR\n");
    printf("Digite * para MULTIPLICAR\n");
    printf("Digite / para DIVIDIR\n");
    scanf(" %c", &operador);
    
    switch(operador){
    
    case '+':
    resultado = a + b;
    printf("O resultado da sua operação é: %.2f", resultado);
    break;
    
    case '-':
    resultado = a - b;
    printf("O resultado da sua operação é: %.2f", resultado);
    break;
    
    case '*':
    resultado = a * b;
    printf("O resultado da sua operação é: %.2f", resultado);
    break;
    
    case '/':
    if(b != 0){
       resultado = a / b;
       printf("O resultado da sua operação é: %.2f", resultado);
    } else{
        printf("Erro: divisão por zero");
    }
    break;
    
    default:
    printf("Operador inválido");
    }
}
