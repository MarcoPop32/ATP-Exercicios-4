#include <stdio.h>
#include <string.h>

int DigitoVerificador(long long n);
int cpfValido(long long cpf);



int main(){
    char nome[50];
    long long cpf;

    do{
        printf("Digite o nome do cliente(fim para encerrar): ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = 0;
        if(strcmp(nome, "fim") == 0){
            break;
        }
        printf("Digite o CPF do cliente: ");
        scanf("%lld", &cpf);
        getchar();
        printf("CPF %011lld do cliente %s é %s\n", cpf, nome, cpfValido(cpf) ? "válido" : "inválido");
    }while(strcmp(nome, "fim") != 0);
}

int DigitoVerificador(long long n){
    int soma = 0, peso = 2, r;
    while(n > 0){
        soma += (int)(n % 10) * peso;
        peso++;
        n /= 10;
    }
    r = (soma * 10) % 11;
    if(r == 10){
        r = 0;
    }
    return r;
}

int cpfValido(long long cpf){
    long long base = cpf / 100;
    int d1 = DigitoVerificador(base);
    int d2 = DigitoVerificador(base * 10 + d1);
    return cpf % 100 == d1 * 10 + d2;
}