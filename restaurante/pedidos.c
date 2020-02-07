#include<stdio.h>
#include<stdlib.h>
#include"mesas.h"
#include"pedidos.h"
#include"arquivos.h"

struct no_pedidos{
	struct pedidos dados;
	struct no_pedidos *prox;
};

typedef struct no_pedidos PEDIDO;

Listapedidos* abre_lista_pedidos(){
	Listapedidos* li = (Listapedidos*) malloc(sizeof(Listapedidos));
	if(li != NULL)
		*li = NULL;
	return li;
}

void fecha_lista_pedidos(Listapedidos* li){
	if(*li != NULL){

		printf("\n ####### NOTA FISCAL #######\n\n");

		PEDIDO* no;
			

		while((*li) != NULL){
			no = *li;
			imprime_pedido(no->dados.codigoPedido);
			printf(" x %d\n",no->dados.quantidadePedido);
			*li = (*li)->prox;
			free(no);
		}
		free(li);
	}
}

int verifica_pedido_repetido(Listapedidos* li, int cod, int qtd) {
	
	if(*li == NULL) return 0;
	
	PEDIDO* aux = *li;	
	while(aux != NULL){   
		if(aux->dados.codigoPedido == cod){
			aux->dados.quantidadePedido += qtd;
			return 1;
		}
		else {
			aux = aux->prox;
		}
	}
	return 0;	
}

int insere_pedido_novo(Listapedidos* li, int cod, int qtd){

	PEDIDO *no = (PEDIDO*) malloc(sizeof(PEDIDO));// aloca nó
	if(no == NULL) return 0; // verifica se só foi alocado corretamente

	no->dados.codigoPedido = cod;
	no->dados.quantidadePedido = qtd;
	no->prox = NULL;

	if((*li) == NULL) { // lista vazia: insere no início
		*li = no;	
	}else{ // lista não vazia: insere no final
		PEDIDO* aux = *li;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = no;
    }
	return 1;
}

int adiciona_pedido(Listapedidos* li, int cod, int qtd){

	if(li == NULL) return 0; // verifica se a lista existe
	
	int achou = verifica_pedido_repetido(li, cod, qtd);

	if(!achou) insere_pedido_novo(li, cod, qtd);
	
	return 1; 
	
}

void recolhe_dados_pedido(Listamesas* MESAS, int* num, int* cod, int* qtd, char menu[20]){
	mostra_mesas_funcionando(MESAS);		
	printf("Digite o número da mesa a ser adicionado um pedido:");
	scanf("%d", num);
	
	printf("\n***** MENU *****\n");
	exibe_arquivo(menu);
	printf("\nCódigo do pedido (somento numéro(s)):");
	scanf("%d", cod);
	printf("Quantidade (somento numéros):");
	scanf("%d", qtd);
}

