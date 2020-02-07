#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	
	char valor[20];
	int cont, aux, teste;
	
	printf("Digite um valor até 1000: ");
	scanf("%s", valor);

	cont = strlen(valor);
	
	aux = cont;
	
	for(int i = 0; i<=cont; i++){
		
		if(aux == 4){
			printf("mil\n");
			break;
		}
	
		else if(aux == 3){

			switch(valor[i]) {

				case '1': printf("cento ");break;
				case '2': printf("duzentos ");break;
				case '3': printf("trezentos ");break;
				case '4': printf("quatrocentos ");break;
				case '5': printf("quinhentos ");break;
				case '6': printf("seiscentos ");break;
				case '7': printf("setecentos ");break;
				case '8': printf("oitocentos ");break;
				case '9': printf("novecentos ");break;
			}
			
			if((valor[i+1] != '0') || (valor[i+2] != 0)){
				printf("e ");
				aux--;
			}
			else{
				printf("\n");
				break;
			}
		}

		else if (aux == 2){

			if(valor[i] == '0'){
				aux--;
				continue;
			}

			else if((valor[i] == '1') && (valor[i+1] != '0')){
						
				switch(valor[i+1]) {

					case '1': printf("onze\n");break;
					case '2': printf("doze\n");break;
					case '3': printf("treze\n");break;
					case '4': printf("quatorze\n");break;
					case '5': printf("quinze\n");break;
					case '6': printf("dezesseis\n");break;
					case '7': printf("dezessete\n");break;
					case '8': printf("dezoito\n");break;
					case '9': printf("dezenove\n");break;
				}
				break;
			}
			else {
					
				switch(valor[i]) {

					case '1': printf("dez");break;
					case '2': printf("vinte");break;
					case '3': printf("trinta");break;
					case '4': printf("quarenta");break;
					case '5': printf("cinquenta");break;
					case '6': printf("sessenta");break;
					case '7': printf("setenta");break;
					case '8': printf("oitenta");break;
					case '9': printf("noventa");break;
				
				}
				if(valor[i+1] != '0'){
					printf(" e ");
					aux--;
				}
				else {
					printf("\n");
					break;
				}	
			}	 
		}
		
		else{

			switch(valor[i]) {

				case '1': printf("um\n");break;
				case '2': printf("dois\n");break;
				case '3': printf("três\n");break;
				case '4': printf("quatro\n");break;
				case '5': printf("cinco\n");break;
				case '6': printf("seis\n");break;
				case '7': printf("sete\n");break;
				case '8': printf("oito\n");break;
				case '9': printf("nove\n");break;
			}
	
		}
	}

}
