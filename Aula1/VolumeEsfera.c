#include <stdio.h>
#include <math.h>

int main()
{
    float raio, volume;
    printf("Escreva o raio da esfera\n");
    scanf("%f", &raio);
    if (raio < 0){
        printf("O valor do raio deve ser um número não negativo\n");
    }
    else {
        volume = (4.0/3.0) * 3.14159265358979323846 * pow(raio, 3);
        printf("O volume da esfera é\n %f", volume);
    }
    
    return 0;
}
