#include <stdio.h>

int main()
{
	float valor;

	printf("Digite um valor entre R$ 0.01 e R$ 1:");
	scanf(" %f", &valor);

	if(valor==1){	
		printf("Moeda de 1 real\n");
		valor=0;
	}
	

	if(valor>=0.50){	
		printf("Moedas de 50 centavos: %d\n", (int)(valor/0.50));
		valor-=(0.50*(int)(valor/0.50));
	}
	
	if(valor>=0.25){	
		printf("Moedas de 25 centavos: %d\n", (int)(valor/0.25));
		valor-=(0.25*(int)(valor/0.25));
	}

	if(valor>=0.10){	
		printf("Moedas de 10 centavos: %d\n", (int)(valor/0.10));
		valor-=(0.10*(int)(valor/0.10));
	}

	if(valor>=0.05){	
		printf("Moedas de 5 centavos: %d\n", (int)(valor/0.05));
		valor-=(0.05*(int)(valor/0.05));
	}

	if(valor>=0.01){	
		printf("Moedas de 1 centavo: %d\n", (int)(valor/0.01));
		valor-=(0.01*(int)(valor/0.01));
	}

}
