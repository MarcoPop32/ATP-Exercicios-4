#include <stdio.h>

float somaTresMaiores(float a, float b, float c, float d);
char conceito(int nota);

int main(){
    float num, p1, p2, p3, p4, final, nota;

    for(int i = 0; i < 80; i++){
        printf("Aluno %d - numero, 4 notas mensais e prova final: ", i + 1);
        scanf("%f %f %f %f %f %f", &num, &p1, &p2, &p3, &p4, &final);
        nota = somaTresMaiores(p1, p2, p3, p4) + final;
        printf("Aluno %d - numero: %.0f, nota final: %.2f, conceito: %c\n", i + 1, num, nota, conceito(nota));
    }
}

float somaTresMaiores(float a, float b, float c, float d){
    int menor = a;

    if(b < menor){
        menor = b;
    }
    if(c < menor){
        menor = c;
    }
    if(d < menor){
        menor = d;
    }
    return a + b + c + d - menor;
}

char conceito(int nota){
    if(nota >= 90){
        return 'A';
    } else if(nota >= 80){
        return 'B';
    } else if(nota >= 70){
        return 'C';
    } else if(nota >= 60){
        return 'D';
    } else if(nota >= 40){
        return 'E';
    } else{
        return 'F';
    }
}