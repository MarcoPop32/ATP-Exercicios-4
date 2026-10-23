#include <stdio.h>

int primo(int n) {
    if (n <= 1) return 0; 
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0; 
    }
    return 1; 
}

int somatorioPrimos(int n) {
    int soma = 0;
    int contagem = 0; // Controla quantos primos já foram encontrados
    int num = 2;      // Começamos a testar a partir do primeiro primo (2)

    while (contagem < n) {
        if (primo(num)) {
            soma += num;
            contagem++; // Só incrementa quando acha um primo válido
        }
        num++; // Passa para o próximo número para ser testado
    }
    return soma;
}

int main() {
    int n;

    printf("Digite a quantidade de elementos (n): ");
    scanf("%d", &n);

    int soma = somatorioPrimos(n);
    printf("A soma dos %d primeiros numeros primos e: %d\n", n, soma);

    return 0;
}