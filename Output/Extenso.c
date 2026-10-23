#include <stdio.h>
#include <string.h>

const char *unidades[] = {
    "zero", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove",
    "dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"
};

const char *dezenas[] = {
    "", "", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"
};

const char *centenas[] = {
    "", "cento", "duzentos", "trezentos", "quatrocentos", "quinhentos",
    "seiscentos", "setecentos", "oitocentos", "novecentos"
};

void converterGrupo(int valor, char *resultado){
    int c = valor / 100;
    int d = (valor % 100) / 10;
    int u = valor % 10;

    resultado[0] = '\0';

    if(c > 0){
        strcat(resultado, centenas[c]);
        strcat(resultado, " ");
    }

    if(valor % 100 < 20){
        strcat(resultado, unidades[valor % 100]);
    } else {
        strcat(resultado, dezenas[d]);
        if(u > 0){
            strcat(resultado, " e ");
            strcat(resultado, unidades[u]);
        }
    }
}

void porExtenso(long long numero){
    int bilhoes  = (int)(numero / 1000000000LL);
    int milhoes  = (int)((numero / 1000000LL) % 1000);
    int milhares = (int)((numero / 1000LL) % 1000);
    int resto    = (int)(numero % 1000);

    char grupo[100];

    if(bilhoes > 0){
        converterGrupo(bilhoes, grupo);
        printf("%s bilhões ", grupo);
    }

    if(milhoes > 0){
        converterGrupo(milhoes, grupo);
        printf("%s milhões ", grupo);
    }

    if(milhares > 0){
        converterGrupo(milhares, grupo);
        printf("%s mil ", grupo);
    }

    if(resto > 0 || numero == 0){
        converterGrupo(resto, grupo);
        printf("%s", grupo);
    }

    printf("\n");
}

int main(){
    long long numero;

    printf("Digite um número inteiro (até 10 dígitos): ");
    scanf("%lld", &numero);

    porExtenso(numero);

    return 0;
}