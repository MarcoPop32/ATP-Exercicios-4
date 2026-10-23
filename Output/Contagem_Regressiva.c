#include <stdio.h>
#include <windows.h>

void contador(int n2);
int tempo(int n, int intervalo);
void pausa(int segundos);

int main(){
    int n, intervalo;

    printf("Digite um número para fazer a contagem regressiva: ");
    scanf("%d", &n);
    
    printf("Digite o intervalo de tempo entre o contador: ");
    scanf("%d", &intervalo);

    tempo(n, intervalo);

    printf("Fim da contagem.\n");

    return 0;
}
void contador(int n2){
    printf("%ds\n", n2);
}

void pausa(int segundos){
    Sleep(segundos * 1000); //Sleep faz a contagem em milissegundos, por isso 1000ms -> 1s
}
int tempo (int n, int intervalo){
    for(int i = n; i != 0; i--){
        contador(i);
        pausa(intervalo);
    }
    
    return 0;
}