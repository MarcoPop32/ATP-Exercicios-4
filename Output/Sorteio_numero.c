#include <stdio.h>
#include <stdlib.h>

void Sorteio(int n1, int n2);

int main(){
    int n1, n2;

    printf("Digite um número: ");
    scanf("%d", &n1);

    printf("Digite a quantidade de números a ser sorteados entre 1 e %d: ", n1);
    scanf("%d", &n2);

    Sorteio(n1, n2);


    return 0;
}

void Sorteio(int n1, int n2){
    printf("\nNúmeros Sorteados:\n");

    for(int i = 1; i <= n2; i++){
        int numero = (rand() % n1) + 1; 
        printf("%d° - %d\n", i, numero);
    }
}