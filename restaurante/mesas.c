#include<stdio.h>
#include<stdlib.h>
#include"mesas.h"
#include"pedidos.h"
#include"arquivos.h"

struct no_mesa{
	struct mesa dados;
	struct no_mesa *ant;
	struct no_mesa *prox;
	struct no_pedidos** elo_pedidos;
};

typedef struct no_mesa MESA;

Listamesas* cria_mesa(){
	Listamesas* li = (Listamesas*) malloc(sizeof(Listamesas));
	if(li != NULL)
		*li = NULL;
	return li;
}

int abre_conta(Listamesas* li, int nmesa, int cgarcom, float tconta) {	

	if(li == NULL) return 0;
	MESA *no = (MESA*) malloc(sizeof(MESA));
	if(no == NULL) return 0;

	no->dados.num_mesa = nmesa;
	no->dados.cod_garcom = cgarcom;
	no->dados.total_conta = tconta;
	no->prox = NULL;

	Listapedidos* li_p = abre_lista_pedidos();
	
	no->elo_pedidos = li_p; // vinculação da mesa com uma lista de pedidos
	
	
	if((*li) == NULL){ //lista vazia: insere no início
		no->ant = NULL;
		*li = no;
	}else{
		MESA *aux = *li;
		while(aux->prox != NULL)
			aux = aux->prox;
		aux->prox = no;
		no->ant = aux;
	}
	return 1;
}

int tamanho_lista(Listamesas* li){
	if(li == NULL) return 0;
	int cont = 0;
	MESA* no = *li;
	while(no != NULL) {
		cont++;
		no = no->prox;
	}
	return cont;
}

int mostra_mesas_disponiveis(Listamesas* li){

	if(*li == NULL){ // LISTA VAZIA
		printf("***** MESAS DISPÍVEIS *****\n");
		for(int i=1; i<=12; i++){
			printf("#%d\n",i);
		}
		printf("\n");
		return 1;
	}
	else if(tamanho_lista(li) >= 12){
		printf("NÃO HÁ MESAS DISPONÍVEIS\n");
		return 0;	
	}
	else{
		printf("***** MESAS DISPÍVEIS *****\n\n");
		MESA* aux;
		for(int i=1; i<=12; i++){
			aux = *li;
			int achou = 0;
			while(aux != NULL){
				if(aux->dados.num_mesa == i){
					achou = 1;
					break;
				}
				aux = aux->prox;
			}
			if(!achou) printf("#%d\n",i);
		}
		return 1;
	}	
}

void mostra_mesas_funcionando(Listamesas* li){
	
	printf("***** MESAS JÁ ABERTAS *****\n");
	MESA* aux = *li;
	while(aux != NULL){
		printf("#%d\n", aux->dados.num_mesa);
		aux = aux->prox;
	}
}

void atualiza_pedidos(Listamesas* li, int num, int cdg, int qtd, float valor){

	MESA* aux = *li;
	
	while(aux->dados.num_mesa != num){ // procura mesa pelo número
		aux = aux->prox;
	}

	aux->dados.total_conta += valor; // atualiza parcial do valor da conta

	printf("%f\n\n", aux->dados.total_conta);

	adiciona_pedido(aux->elo_pedidos, cdg, qtd);
}


void exibe_nota_fiscal(Listamesas* li, int num_m){

	MESA* aux = *li;
	while(aux->dados.num_mesa != num_m){
		aux = aux->prox;
	}
										
	fecha_lista_pedidos(aux->elo_pedidos);

	printf("-------------------------\n");
	printf("Total a pagar: R$ %.2f\n", aux->dados.total_conta);
	imprime_nome_garcom(aux->dados.cod_garcom);
	printf("############################\n\n");
	
}

int libera_mesa(Listamesas* li, int num){

	MESA* no = *li;
	
	while(no != NULL && no->dados.num_mesa != num){
		no = no->prox;
	}
	if(no->ant == NULL) // remove o primeiro
		*li = no->prox;
	else
		no->ant->prox = no->prox;

	//não é o ultimo?
	if(no->prox != NULL)
		no->prox->ant = no->ant;

	free(no);	
}

void recolhe_dados_mesa(int* n, int* g){	
	printf("Escolha uma mesa disponível (somento numéro(s)):");
	scanf("%d", n);
	printf("\n");

	printf("****** GARÇONS DISPONÍVEIS ******\n\n");
	char garcons[20] = "garcons.txt";
	exibe_arquivo(garcons);
	printf("Digite o código do garçom (somento numéro(s)):");
	scanf("%d", g);
	printf("\n");
}


	

