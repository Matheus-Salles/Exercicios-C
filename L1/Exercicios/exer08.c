#include <stdio.h>

int main()
{
	int vetor[50], aux;
	int maior = -99999999, smaior = -9999999;
	
	for(int i = 0; i<50; i++){
		printf("Valor em vetor[%d]: ", i);
		scanf("%d", &vetor[i]);
	}
	for(int i = 0; i<50; i++){
		if (vetor[i] > smaior) {
			smaior = vetor[i];
		}
		if (smaior > maior){
			aux = maior;
			maior = smaior;
			smaior = aux;
		}
	}
	printf("Maior valor: %d\n", maior);
	printf("Segundo maior valor: %d\n", smaior);
}

