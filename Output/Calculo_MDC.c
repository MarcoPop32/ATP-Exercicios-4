#include <stdio.h>

int CalculoMDC(int n1, int n2);
void Resultado(int mdc);

int main(){
    int n1, n2;

    printf("Digite o 1° número: ");
    scanf("%d", &n1);
    printf("Digite o 2° número: ");
    scanf("%d", &n2);
    
    int mdc = CalculoMDC(n1, n2);
    Resultado(mdc);

    return 0;
}

int CalculoMDC(int n1, int n2){
    int resto;
    while(n2 != 0){
        resto = n1 % n2;
        n1 = n2;
        n2 = resto;
    }
    return n1;
}

void Resultado(int mdc){
    printf("O MDC é: %d\n", mdc);
}