#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
 
#define ESPECIES 3
 
void zeraAcumuladores(double soma[ESPECIES][2], int qtd[ESPECIES][2]) {
    int i, j;
    for (i = 0; i < ESPECIES; i++)
        for (j = 0; j < 2; j++) {
             soma[i][j] = 0; qtd[i][j] = 0; 
            }
}
 
double mediaPeso(double soma, int qtd) {
    return qtd > 0 ? soma / qtd : 0;
}
 
int main(void) {
    double soma[ESPECIES][2], peso;
    int qtd[ESPECIES][2], n, i, esp, s;
    char sexo;
    const char *nomes[ESPECIES] = {"Bovinos", "Ovinos", "Caprinos"};
    zeraAcumuladores(soma, qtd);
    printf("Quantos animais? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Animal %d - especie (1=bovino 2=ovino 3=caprino): ", i + 1);
        scanf("%d", &esp);
        printf("  sexo (F/M): ");
        scanf(" %c", &sexo);
        printf("  peso (kg): ");
        scanf("%lf", &peso);
        sexo = toupper(sexo);
        if (esp < 1 || esp > 3 || (sexo != 'F' && sexo != 'M')) { 
            printf("  Dado invalido, animal ignorado.\n"); 
            continue; 
        }
        s = (sexo == 'F') ? 0 : 1;
        soma[esp - 1][s] += peso;
        qtd[esp - 1][s]++;
    }
    for (i = 0; i < ESPECIES; i++)
        printf("%s: femeas %.2f kg | machos %.2f kg\n", nomes[i],
               mediaPeso(soma[i][0], qtd[i][0]), mediaPeso(soma[i][1], qtd[i][1]));
    return 0;
}