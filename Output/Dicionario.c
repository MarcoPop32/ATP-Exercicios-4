#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N_PALAVRAS 1000
#define TAM 100


int formatoLetra(const char *s1, const char *s2);

const char *traducao(char ing[][TAM], char por[][TAM], int n, char letra, const char *palavra);

void lerDicionario(char ing[][TAM], char por[][TAM], int n);

void consultarDicionario(char ing[][TAM], char por[][TAM], int n);

int main(){
    static char ing[N_PALAVRAS][TAM], por[N_PALAVRAS][TAM];

    lerDicionario(ing, por, N_PALAVRAS);
    consultarDicionario(ing, por, N_PALAVRAS);

    return 0;
}


int formatoLetra(const char *s1, const char *s2){
    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0'){
        if(tolower(s1[i]) != tolower(s2[i])){
            return 0; //Escrita diferente
        }
        i++;
    }
    if(s1[i] == '\0' && s2[i] == '\0'){
        return 1; //Escrita igual
    }
    return 0; //Tamanho diferente
}
const char *traducao(char ing[][TAM], char por[][TAM], int n, char letra, const char *palavra){
    for(int i = 0; i < n; i++){
        if(letra == 'I' && formatoLetra(ing[i], palavra)){
            return por[i];
        }
        if(letra == 'P' && formatoLetra(por[i], palavra)){
            return ing[i];
        }
    }
    return "(não encontrado)";
}

void lerDicionario(char ing[][TAM], char por[][TAM], int n){
    for(int i = 0; i < n; i++){
        printf("Par %d - 1° Inglês, 2° Português: ", i + 1);
        scanf("%29s %29s", ing[i], por[i]);
    }
}

void consultarDicionario(char ing[][TAM], char por[][TAM], int n){
    char letra, palavra[TAM];

    do{
        printf("Consultar palavra (I - Inglês, P - Português + Palavra - Outra letra encerra): ");
        scanf(" %c", &letra);
        letra = toupper(letra);

        if(letra != 'I' && letra != 'P'){
            break;
        }
        scanf("%29s", palavra);

        printf("%s -> %s\n", palavra, traducao(ing, por, n, letra, palavra));
    }while(letra == 'I' || letra == 'P');
}

