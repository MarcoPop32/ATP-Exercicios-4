#include <stdio.h>

void ImprimirDia(int dia){
    const char *dias[] = {
        "", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove",
        "dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove",
        "vinte", "vinte e um", "vinte e dois", "vinte e três", "vinte e quatro", "vinte e cinco", "vinte e seis", "vinte e sete", "vinte e oito", "vinte e nove",
        "trinta", "trinta e um"
    };
    if(dia >= 1 && dia <= 31){
        printf("%s", dias[dia]);
    }else{
        printf("Dia inválido");
    }
}

void imprimirAno(int ano) {
    int m = ano / 1000;
    int c = (ano % 1000) / 100;
    int d = (ano % 100) / 10;
    int u = ano % 10;
    int dezenas_unidades = ano % 100;

    const char *unidades[] = {"", "um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove"};
    const char *especiais[] = {"dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};
    const char *dezenas[] = {"", "", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
    const char *centenas[] = {"", "cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"};

    // Milhar
    if (m > 0) {
        if (m == 1) printf("mil");
        else printf("%s mil", unidades[m]);
    }

    // Centena
    if (c > 0) {
        if (m > 0) {
            if (dezenas_unidades == 0) printf(" e ");
            else printf(" ");
        }
        
        if (c == 1 && dezenas_unidades == 0) printf("cem");
        else printf("%s", centenas[c]);
    } else if (m > 0 && dezenas_unidades > 0) {
        printf(" e ");
    }

    // Dezena e Unidade
    if (dezenas_unidades > 0) {
        if (c > 0) printf(" e ");

        if (dezenas_unidades < 10) {
            printf("%s", unidades[u]);
        } else if (dezenas_unidades < 20) {
            printf("%s", especiais[dezenas_unidades - 10]);
        } else {
            printf("%s", dezenas[d]);
            if (u > 0) printf(" e %s", unidades[u]);
        }
    }
}

void Dataporextenso(int dia, int mes, int ano){
    const char *meses[] = {
        "", "janeiro", "fevereiro", "março", "abril", "maio", "junho",
        "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"
    };
    if(dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 0) {
        printf("Data inválida\n");
        return;
    }

    ImprimirDia(dia);
    printf(" de %s de ", meses[mes]);
    imprimirAno(ano);
    printf("\n");
}

int main(){
    int d, m, a;

    printf("Digite a data abreviada (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &d, &m, &a);
    Dataporextenso(d, m, a);

    return 0;
}