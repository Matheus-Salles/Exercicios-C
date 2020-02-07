#include<stdio.h>

int main(){
	
	int n, fat=1;
	
	printf("Digite um núemro inteiro: ");
	scanf("%d", &n);

	for(int i=n; i>=1; i--){
		fat = fat*i;	
	}
	
	printf("Fatorial = %d\n", fat);
}
