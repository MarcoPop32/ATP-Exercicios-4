#include <stdio.h>

void Divisao(int n1, int n2);

int main(){
    int n1, n2;

    printf("Digite o 1° número: ");
    scanf("%d", &n1);

    printf("Digite o 2° número: ");
    scanf("%d", &n2);

    Divisao(n1, n2);

    return 0;
} 

void Divisao(int n1, int n2){
    if(n1 == 0 || n2 == 0){
        printf("Não é possível fazer divisão por zero!\n");
        return; 
    }
    if(n1 % n2 == 0){
        printf("%d é divisível por %d\n", n1, n2);
    }
    if(n2 % n1 ==0){
        printf("%d é divisível por %d\n", n2, n1);
    }
    if(n1 % n2 != 0 && n2 % n1 != 0){
        printf("Nenhum dos números é divisível pelo outro\n");
    }
}