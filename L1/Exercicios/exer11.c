#include<stdio.h>
#include<string.h>

int main(){
	
	int cc = 0, jj = 0, tot = 0, inicio = 0, fim = 0;
	char frase[101]; 

	printf("Digite uma frase que contenha até 100 letras: ");
	fgets(frase, sizeof(frase), stdin);

	printf("\n");

	for (cc = 0; cc<50; cc++){

		if(frase[cc] == 'a' || frase[cc] == 'e' || frase[cc] == 'i' || frase[cc] == 'o' || frase[cc] == 'u'){
			tot++;	
		}

		else if(frase[cc] == ' ' || frase[cc] == '\0'){
			if(tot>=3){S
				fim = cc-1;

				for(jj=inicio; jj<=fim; jj++){
					printf("%c", frase[jj]);
				}
				
				tot=0;
				inicio = cc+1;
				printf("\n");
			}
			else {
			
				tot = 0;
				inicio = cc+1;
			}
		}
	}
}
