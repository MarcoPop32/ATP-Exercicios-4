#include <stdio.h>
#include <stdlib.h> 

int horasEntreDatas(int d1, int m1, int a1, int d2, int m2, int a2) {
    int dias1 = a1 * 365 + m1 * 30 + d1;
    int dias2 = a2 * 365 + m2 * 30 + d2;
    
    // abs() garante que o resultado seja positivo idependente da ordem das datas
    return abs(dias2 - dias1) * 24;
}

int main(){
    int d1, m1, a1, d2, m2, a2;
    
    printf("Primeira data (dd mm aaaa): ");
    scanf("%d %d %d", &d1, &m1, &a1);
    
    printf("Segunda data (dd mm aaaa): ");
    scanf("%d %d %d", &d2, &m2, &a2);
    
    // O uso correto de %d garante que a exibicao suporte o sinal caso abs() nao fosse usado
    printf("Diferenca: %d horas\n", horasEntreDatas(d1, m1, a1, d2, m2, a2));
    
    return 0;
}