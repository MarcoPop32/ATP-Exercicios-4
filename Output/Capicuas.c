#include <stdio.h>

int qntdAlgarismos(int n);

void separa(int n, int alg[], int qtd);

int formaInverso(int alg[], int qtd);

int capicua(int n); 

int quadradoPerfeito(int n);

int main(void) {
    int n;
    for (n = 1; n < 5000; n++)
        if (quadradoPerfeito(n) && capicua(n)) printf("%d\n", n);
    return 0;
}


int qtdAlgarismos(int n) {
    int q = 1;
    while (n >= 10) { n /= 10; q++; }
    return q;
}

void separa(int n, int alg[], int qtd) {
    int i;
    for (i = qtd - 1; i >= 0; i--) { alg[i] = n % 10; n /= 10; }
}

int formaInverso(int alg[], int qtd) {
    int i, inv = 0;
    for (i = qtd - 1; i >= 0; i--) inv = inv * 10 + alg[i];
    return inv;
}

int capicua(int n) {
    int alg[10], qtd = qtdAlgarismos(n);
    separa(n, alg, qtd);
    return n == formaInverso(alg, qtd);
}

int quadradoPerfeito(int n) {
    int i = 1;
    while (i * i < n) i++;
    return i * i == n;
}