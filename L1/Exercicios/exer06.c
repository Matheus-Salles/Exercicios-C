#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int paradastotais;
	float odoparcial, odototal=0, gasparcial, gastotal=0, dinparcial, dintotal=0;
	
	printf("Numero total de abastecimentos: ");
	scanf("%d", &paradastotais);

	for(int i=1; i<=paradastotais; i++){
		
		printf("Parada %d\n", i);
		
		printf("Odômetro parcial (km): ");
		scanf("%f", &odoparcial);

		printf("Gasolina comprada (litros): ");
		scanf("%f", &gasparcial);

		printf("Dinheiro gasto (real): ");
		scanf("%f", &dinparcial);

		odototal += odoparcial;
		gastotal += gasparcial;
		dintotal += dinparcial;

		if(i%2==0){
			float kmlitro = odototal / gastotal;
			printf("Km/litro: %.2f\n", kmlitro);	
		}
		printf("\n");			
	}	
	
	float kmlitrototal = odototal / gastotal;
	printf("Km/litro total: %.2f\n", kmlitrototal);

	float custolitrototal = dintotal / odototal;
	printf("Custo/Km total: %.2f\n", custolitrototal);	
}
