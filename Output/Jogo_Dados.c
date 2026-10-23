#include <stdio.h>

#define DIAS 30
#define JOGOS 40

int maisVezes(int n[], int o);

int main(){
    int dia[JOGOS], meses[DIAS*JOGOS], a, b;
    for(a = 0; a < DIAS; a++){
        printf("Dia %d - digite os %d resultados (1 a 6): ", a+1, JOGOS);
        for(b = 0; b < JOGOS; b++){
            do{
                scanf("%d", &dia[b]);
            }while(dia[b] < 1 || dia[b] > 6);
            meses[a * JOGOS + b] = dia[b]; 
        }
        printf(" %d- Resultado Diário\n", maisVezes(dia, JOGOS)); 
    }
    printf("%d - Resultado mensal do jogo\n", maisVezes(meses, DIAS*JOGOS));
    return 0;
}

int maisVezes(int n[], int o){
    int cont[7] = {0, 0, 0, 0, 0, 0, 0};
    int melhor = 1;

    for(int i = 0; i < o; i++){
        cont[n[i]]++;
    }
    for(int i = 2; i <= 6; i++){
        if(cont[i] > cont[melhor]){
            melhor = i;
            return melhor;
        }
    }
    
}