#include <stdio.h>
#define TAMANHO 100

void DigitarValor(int vetor[], int tamanho);
void MostrarVetor(int vetor[], int tamanho);
int Somatorio(int vetor[], int tamanho);
float CalculoMedia(int vetor[], int tamanho);
void SubstituirNegativo(int vetor[], int tamanho);
void SubstituirRepetido(int vetor[], int tamanho);
void Menu();

int main(){
    int vetor[TAMANHO] = {0};
    int opcoes;

    do{
    Menu();
    scanf("%d", &opcoes);

    switch(opcoes){
        case 1:
        DigitarValor(vetor, TAMANHO);
        break;

        case 2:
        printf("\nSomatório dos itens: %d\n", Somatorio(vetor, TAMANHO));
        break;

        case 3:
        printf("\nMédia dos valores: %.2f", CalculoMedia(vetor, TAMANHO));
        break;

        case 4:
        SubstituirNegativo(vetor, TAMANHO);
        printf("\nValores negativos substituídos por zero!\n");
        break;

        case 5:
        SubstituirRepetido(vetor, TAMANHO);
        printf("\nValores repetidos substituídos por zero!\n");
        break;

        case 6:
        MostrarVetor(vetor, TAMANHO);
        break;

        case 0:
        printf("\nEncerrando Programa\n");
        break;

        default:
        printf("\nOpção inválida\n");
        break;
    }
    }while(opcoes != 0);
    
    return 0; 
}

void DigitarValor(int vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("Digite o valor da posição %d: ", i+1);
        scanf("%d", &vetor[i]);
    }
}

void MostrarVetor(int vetor[], int tamanho){
    printf("\nValores do vetor:\n");
    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
        if((i+1) % 10 == 0){
            printf("\n");
        }
    }
    printf("\n");
}

int Somatorio(int vetor[], int tamanho){
    int soma = 0;

    for(int i = 0; i < tamanho; i++){
        soma += vetor[i];
    }
    return soma;
}

float CalculoMedia(int vetor[], int tamanho){
    int soma = Somatorio(vetor, tamanho);

    return (float)soma / tamanho;
}

void SubstituirNegativo(int vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        if(vetor[i] < 0){
            vetor[i] = 0; 
        }
    }
}

void SubstituirRepetido(int vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        if(vetor[i] > 0){
            for(int j = i + 1; j < tamanho; j++){
                if(vetor[j] == vetor[i]){
                    vetor[j] = 0; 
                }
            }
        }
    }
}

void Menu(){
    printf("----------MENU----------\n");
    printf("1 - Digite os 100 valores do vetor\n");
    printf("2 - Exibir o somatório dos itens\n");
    printf("3 - Exibir a média dos valores\n");
    printf("4 - Substituir negativos por zero\n");
    printf("5 - Substituir repetidos por zero\n");
    printf("6 - Exibir vetor atual\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}