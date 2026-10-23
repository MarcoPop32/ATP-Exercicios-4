#include <stdio.h>

int primo(int n){
    if(n <= 1) return 0; // Números menores ou iguais a 1 não são primos
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return 0; // Se n for divisível por algum número, não é primo
    }
    return 1; // Se não encontrou divisores, é primo
}

int main(){
    int n;

    printf("Digite um número: ");
    scanf("%d", &n);

    if(primo(n)){
        printf("%d é primo.\n", n);
    } else {
        printf("%d não é primo.\n", n);
    }

    return 0;
}