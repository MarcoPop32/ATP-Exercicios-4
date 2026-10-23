#include <stdio.h>

int aposta(int sorteado[], int dezenas[], int qntd);

int main(){
    int sorteadas[5], dezenas[10], numero, qtd, pontos;
    int ternos = 0, quadras = 0, quinas = 0;

    printf("Digite as 5 dezenas sorteadas: ");

    for(int i = 0; i < 5; i++){
        scanf("%d", &sorteadas[i]);
    }
    do{
        printf("Número da aposta (0 para sair): ");
        scanf("%d", &numero);

        if(numero == 0){
            break;
        }
        printf("Quantidade de dezenas apostadas (máx 10): ");
        scanf("%d", &qtd);
        if(qtd < 1 || qtd > 10){
            printf("Quantidade inválida. Tente novamente.\n");
            continue;
        }
        printf("Dezenas: ");
        for(int i = 0; i < qtd; i++){
            scanf("%d", &dezenas[i]);
        }
        pontos = aposta(sorteadas, dezenas, qtd);

        if(pontos >= 3){
            printf("Aposta %d acertou %d dezenas\n", numero, pontos);
            if(pontos == 3){
                ternos++;
            }else if(pontos == 4){
                quadras++;
            }else{
                quinas++;
            }
        }
        printf("Terno: %d | Quadra: %d | Quina: %d\n", ternos, quadras, quinas);
    }while(numero != 0);

    return 0;
}

int aposta(int sorteado[], int dezenas[], int qntd){
    int pontos = 0;
    for(int i = 0; i < qntd; i++){
        for(int j = 0; j < 5; j++){
            if(dezenas[i] == sorteado[j]){
                pontos++;
            }
        }
    }
    return pontos;
}