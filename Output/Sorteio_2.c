#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sorteia(int cont[], int qtd) {
    int i;
    for (i = 0; i <= 100; i++) cont[i] = 0;
    for (i = 0; i < qtd; i++) cont[rand() % 101]++;
}
 
int maisSorteado(int cont[]) {
    int i, melhor = 0;
    for (i = 1; i <= 100; i++) if (cont[i] > cont[melhor]) melhor = i;
    return melhor;
}
 
int menosSorteado(int cont[]) {
    int i, melhor = -1;
    for (i = 0; i <= 100; i++)
        if (cont[i] > 0 && (melhor == -1 || cont[i] < cont[melhor])) melhor = i;
    return melhor;
}
 
int maiorNumero(int cont[]) {
    int i;
    for (i = 100; i >= 0; i--) if (cont[i] > 0) return i;
    return -1;
}
 
int menorNumero(int cont[]) {
    int i;
    for (i = 0; i <= 100; i++) if (cont[i] > 0) return i;
    return -1;
}
 
int main(void) {
    int cont[101];
    srand((unsigned)time(NULL));
    sorteia(cont, 1000);
    printf("Mais sorteado: %d (%d vezes)\n", maisSorteado(cont), cont[maisSorteado(cont)]);
    printf("Menos sorteado (entre os que sairam): %d (%d vezes)\n", menosSorteado(cont), cont[menosSorteado(cont)]);
    printf("Maior numero: %d\n", maiorNumero(cont));
    printf("Menor numero: %d\n", menorNumero(cont));
    return 0;
}