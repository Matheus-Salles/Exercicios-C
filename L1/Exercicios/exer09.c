#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char cadeia[81], letrasdiferentes[81];
	int naotem, aux=0, cont=0;
	
	printf("Digite uma cadeia de caracteres: ");
	fgets(cadeia, sizeof(cadeia), stdin);
	
	printf("O cadeia armazenada foi: %s", cadeia);
	setbuf(stdin,NULL);

	for(int i=0; i<strlen(cadeia); i++){
		naotem = 1;
		for(int j=0; j<strlen(cadeia); j++){
			
			if((cadeia[i]==letrasdiferentes[j]) || (cadeia[i] == ' ')){
				naotem = 0;
				break;		
			}
		}
		if(naotem){
			letrasdiferentes[aux] = cadeia[i];
			aux++;
			cont++;
		}
	}
	printf("Número de letras diferentes: %d\n", cont);
}

