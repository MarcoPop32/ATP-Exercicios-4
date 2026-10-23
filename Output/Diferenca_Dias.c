#include <stdio.h>
#include <stdlib.h>

int bissexto(int ano);

int diasMes(int mes, int ano);

int quantosDias(int dia, int mes, int ano);

int dataValida(int d, int m, int a);

int main(){
    int d1, m1, a1, d2, m2, a2;

    do{
        printf("Digite duas datas (d1 m1 a1 d2 m2 a2): - 0 0 0 0 0 0 para encerrar\n");
        scanf("%d %d %d %d %d %d", &d1, &m1, &a1, &d2, &m2, &a2);
        if(d1 == 0 && m1 == 0 && a1 == 0 && d2 == 0 && m2 == 0 && a2 == 0){
            break;
        }
        if(!dataValida(d1, m1, a1) || !dataValida(d2, m2, a2)){
            printf("Data incorreta: %d/%d/%d ou %d/%d/%d\n", d1, m1, a1, d2, m2, a2);
        }else{
            printf("Diferença entre %d/%d/%d e %d/%d/%d: %d dias\n", d1, m1, a1, d2, m2, a2, abs(quantosDias(d1, m1, a1) - quantosDias(d2, m2, a2)));
        }
    }while(d1 != 0 || m1 != 0 || a1 != 0 || d2 != 0 || m2 != 0 || a2 != 0);
}

int bissexto(int ano){
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int diasMes(int mes, int ano){
    int dia[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(mes == 2 && bissexto(ano)){
        return 29;
    }
    return dia[mes - 1];
}

int quantosDias(int dia, int mes, int ano){
    int n = dia, m;
    for(m = 1; m < mes; m++){
        n += diasMes(m, ano);
    }
    return n;
}

int dataValida(int d, int m, int a){
    return m >= 1 && m <= 12 && d >= 1 && d <= diasMes(m, a);
}