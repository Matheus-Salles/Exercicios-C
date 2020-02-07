#include<stdio.h>

int main(){

	int achou = 0;
	int n = 0;

	do{
		n++;

		if((n%3 == 2) && (n%5 == 3) && (n%7 == 4)){
			printf("O número é: %d\n", n);
			achou = 1;
		}
		
	
	}while(!achou);	

}
