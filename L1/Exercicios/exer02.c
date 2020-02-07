#include<stdio.h>

int main(){
	
	int n;
	int primo = 1;

	printf("Digite um número inteiro positivo: ");
	scanf("%d", &n);

	if(n!=1){
		for(int i=2; i<n; i++){
			if(n%i==0){
			primo=0;
			break;
			}
		}
	}
	else primo = 0;

	if(primo) printf("É primo\n");
	else printf("Não é primo\n");
}
