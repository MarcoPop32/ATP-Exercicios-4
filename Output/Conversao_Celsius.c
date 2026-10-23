#include <stdio.h>

//Protótipo
float CalculoConversao(float grau);
void Resultado(float grau, float celsius);

//Função Principal
int main(){
    //Declaração da variável
    float grau;

    //Entrada dos Dados
    printf("Digite o valor da temperatura em Fahrenheit para converter em Celsius: ");
    scanf("%f", &grau);

    //Chamada das funções para a main
    float Conversao = CalculoConversao(grau);

    Resultado(grau, Conversao);
  
}
//Função de conversão de temperatura
float CalculoConversao(float grau){
    float Celsius = (grau-32)*(5.0/9.0);

    return Celsius;
}

//Função resultado
void Resultado(float grau, float celsius){
    printf("O valor da temperatura %.2f°F em Celsius é igual a: %.2f°C\n", grau, celsius);
}
