#include<stdio.h>
#include<stdlib.h>
#include"mesas.h"
#include"pedidos.h"
#include"arquivos.h"

void exibe_arquivo(char nome_arquivo[20]){

	FILE* f;
	char menu[100];

	f = fopen(nome_arquivo, "r");
	if(f == NULL){
		printf("Erro ao abrir arquivo menu");	
		exit(1);
	}
	while(fgets(menu, 100, f) != NULL){
		printf("%s", menu);
	}	
	fclose(f);
}

char abertura(){
	printf(" -- -- -- AÇÕES DISPONÍVEIS -- -- -- \n");
	printf("(M) Adicionar Mesa    (P) Adicionar Pedido\n");
	printf("(F) Fechar Conta      (E) Encerrar Programa\n\n");
	printf("Escolha uma das ações pela letra:");
	char acao;
	scanf(" %c", &acao);
	printf("\n");
	return acao;
}


float procura_preco(int codigo_pedido){

	FILE* f;
	char lixo1[20], lixo2[20], valor[20];

	f = fopen("menu.txt", "r");
	if(f == NULL){
		printf("Erro ao abrir arquivo menu");	
		exit(1);
	}
	for(int i=0; i<=codigo_pedido; i++){
		fscanf(f, "%s %s %s", lixo1, lixo2, valor); 
	}
	fclose(f);

	return atof(valor); // função atof: converte string para float
}

void imprime_pedido(int codigo_pedido){

	FILE* f;
	char lixo1[20], lixo2[20], prato[20];

	f = fopen("menu.txt", "r");
	if(f == NULL){
		printf("Erro ao abrir arquivo menu");	
		exit(1);
	}
	for(int i=0; i<=codigo_pedido; i++){
		fscanf(f, "%s %s %s", lixo1, prato, lixo2); 
	}
	printf("%s", prato);
	
	fclose(f);
}

void imprime_nome_garcom(int codigo_garcom){

	FILE* f;
	char lixo1[20], nome[20];

	f = fopen("garcons.txt", "r");
	if(f == NULL){
		printf("Erro ao abrir arquivo menu");	
		exit(1);
	}
	for(int i=0; i<=codigo_garcom; i++){
		fscanf(f, "%s %s", lixo1, nome); 
	}
	fclose(f);

	printf("GARÇOM %s\n\n", nome);
}
