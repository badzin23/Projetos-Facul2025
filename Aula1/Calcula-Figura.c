#include <stdio.h>
#include <math.h>

int main()
{
    float base, altura, per, are;
    printf("Escreva a base da sua figura\n");
    scanf("%f", &base);
    printf("Escreva a altura da sua figura\n");
    scanf("%f", &altura);
    if (base == altura){
        printf("Sua figura é um quadrado :)\n");
    }
    else {
        per = (base * 2) + (altura *2);
        are = base * altura;
        printf("Sua figura é um retângulo segue a área e o perímetro dele\n");
        printf("Area %.2f", are);
        printf("\\Perímetro %.2f", per);
    }
    
    return 0;
} 
