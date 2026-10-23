#include <stdio.h>

#define pi 3.14

double CalculoVolume(double raio){
    double volume = (4.0/3.0)*pi*raio*raio*raio;

    return volume;
}

void Resultado(double volume){
    printf("O valor do volume é: %lf\n", volume);
}

int main(){
    double raio; 
    printf("Digite o valor do raio de uma esfera: ");
    scanf("%lf", &raio); 

    double volumeEsfera = CalculoVolume(raio);

    Resultado(volumeEsfera);
    
}