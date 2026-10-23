#include <stdio.h>

double arredondamento(double n1);
void Resultado(int n1);

int main(){
    double n1;

    printf("Digite um número decimal, para verificar seu arredondamento: ");
    scanf("%lf", &n1);

    int resultado = arredondamento(n1);

    Resultado(resultado);

    return 0;
}

double arredondamento(double n1){
    int inteiro = (int)n1;

    return inteiro;
}

void Resultado(int n1){
    printf("Resultado: %d\n", n1);
}