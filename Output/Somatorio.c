#include <Stdio.h>

int somatorio(int n){
    int soma = 0;
    for(int i = 1; i <= n; i++){
        soma += i;
    }
    return soma;
}

int main(){
    int n;

    printf("Digite um número: ");
    scanf("%d", &n);

    int resultado = somatorio(n);
    printf("A soma dos %d primeiros números é: %d\n", n, resultado);

    return 0;
}