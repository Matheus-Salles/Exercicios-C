#include<stdio.h>

int main(){
	
	int n, soma=0;

	printf("Digite um número entre 1 e 32767: ");
	scanf("%d", &n);
	
	for(int i=1; i<n; i++){
	
		if(n%i==0){
			soma+=i;
		}
	}

	if(soma==n) printf("É um inteiro perfeito\n");
	else printf("Não é um inteiro perfeito\n");
}
