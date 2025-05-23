#include <stdio.h>
#include <math.h>

int main(){
    float preco;
    int cod;
    
    printf("Informe o preço do produto: \n");
    scanf("%f", &preco);
    
    printf("Informe o código do produto: \n");
    scanf("%d", &cod);
    
    switch(cod){
        
        case 1:
        printf("Produto do Sul - Preço R$%.2f", preco);
        break;
        
        case 2:
        printf("Produto do Norte - Preço R$%.2f", preco);
        break;
        
        case 3:
        printf("Produto do Leste - Preço R$%.2f", preco);
        break;
        
        case 4:
        printf("Produto do Oeste - Preço R$%.2f", preco);
        break;
        
        case 5:
        case 6:
        case 25 ... 30:
        printf("Produto do Nordeste - Preço R$%.2f", preco);
        break;
        
        case 7 ... 9:
        printf("Produto do Sudeste - Preço R$%.2f", preco);
        break;
        
        case 10 ... 20:
        printf("Produto do Centro Oeste - Preço R$%.2f", preco);
        break;
        
        default:
        printf("Produto Importado - Preço R$%.2f", preco);
    }
    
    return 0;
}
