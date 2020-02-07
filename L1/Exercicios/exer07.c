#include<stdio.h>
#include<stdlib.h>

int main(){
	struct ficha_aluno{
		char nome[20];
		float nota;
	};

	struct ficha_aluno aluno[50];

	float maiores_notas[6], auxnotas;
	int maior1=-1, maior2=-1, maior3=-1, maior4=-1, maior5=-1, auxindices;	

	for(int i=0; i<6; i++){
		maiores_notas[i] = -1;
	}

	for(int i=0; i<50; i++){
		setbuf(stdin,NULL);
		
		printf("Nome do aluno: ");
    	fgets(aluno[i].nome, sizeof(aluno[i].nome), stdin);
    
		printf("Nota: ");
		scanf("%f", &aluno[i].nota);
		printf("\n");
		
		if(aluno[i].nota>maiores_notas[5]){
			maiores_notas[5] = aluno[i].nota;
			maior5=i;
			
		}
		if(aluno[i].nota>maiores_notas[4]){
			auxnotas = maiores_notas[4];
			maiores_notas[4] = aluno[i].nota;
			maiores_notas[5] = auxnotas;

			auxindices = maior4;
			maior4 = i;
			maior5 = auxindices;
		}
		if(aluno[i].nota>maiores_notas[3]){
			auxnotas = maiores_notas[3];
			maiores_notas[3] = aluno[i].nota;
			maiores_notas[4] = auxnotas;

			auxindices = maior3;
			maior3 = i;
			maior4 = auxindices;
		}
		if(aluno[i].nota>maiores_notas[2]){
			auxnotas = maiores_notas[2];
			maiores_notas[2] = aluno[i].nota;
			maiores_notas[3] = auxnotas;

			auxindices = maior2;
			maior2 = i;
			maior3 = auxindices;
		}
		if(aluno[i].nota>maiores_notas[1]){
			auxnotas = maiores_notas[1];
			maiores_notas[1] = aluno[i].nota;
			maiores_notas[2] = auxnotas;

			auxindices = maior1;
			maior1 = i;
			maior2 = auxindices;
		}
	}
	
	printf("As 5 maiores notas em ordem decrescente:\n");

	printf("%s: %.1f\n", aluno[maior1].nome, aluno[maior1].nota);
	printf("%s: %.1f\n", aluno[maior2].nome, aluno[maior2].nota);
	printf("%s: %.1f\n", aluno[maior3].nome, aluno[maior3].nota);
	printf("%s: %.1f\n", aluno[maior4].nome, aluno[maior4].nota);
	printf("%s: %.1f\n", aluno[maior5].nome, aluno[maior5].nota);
	
}
