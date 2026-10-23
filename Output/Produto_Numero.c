#include <stdio.h>

int Multiplicacao(int n1, int n2);

int main(){
    int n1, n2;

    for(int i = 0; i < 10; i++){ 
    printf("(Par %d)- Digite o valor de n1 e n2: ", i+1);
    scanf("%d %d", &n1, &n2);

    Multiplicacao(n1, n2);

    printf("%d x %d = %d\n", n1, n2, Multiplicacao(n1, n2));
    }
    return 0;
}

int Multiplicacao(int n1, int n2){
    int soma = 0;

    while(n1 >= 1){
        if(n1 % 2 == 1){
            soma += n2;
        }
        n1 /= 2;
        n2 *= 2;
    }
    return soma;
}