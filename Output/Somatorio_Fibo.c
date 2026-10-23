#include <stdio.h>

int SomatorioFibonacci(int n);

int main(){
    int n;

    printf("Digite o valor de n para calcular o somatório dos n primeiros números da sequência de Fibonacci: ");
    scanf("%d", &n);

    int soma = SomatorioFibonacci(n);
    printf("O somatório dos %d primeiros números da sequência de Fibonacci é: %d\n", n, soma);

    return 0;

}

int SomatorioFibonacci(int n){
    int a = 0, b = 1, soma = 0;

    for(int i = 0; i < n; i++){
        soma += a;
        int proximo = a + b;
        a = b;
        b = proximo;
    }

    return soma;
}