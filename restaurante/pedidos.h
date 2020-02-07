#ifndef _PEDIDOS_H_
#define _PEDIDOS_H_

struct pedidos {
	int codigoPedido;
	int quantidadePedido;
};

typedef struct no_pedidos* Listapedidos;

Listapedidos* abre_lista_pedidos();
void fecha_lista_pedidos(Listapedidos* li);
int insere_pedido_novo(Listapedidos* li, int cod, int qtd);
int verifica_pedido_repetido(Listapedidos* li, int cod, int qtd);
int adiciona_pedido(Listapedidos* li, int cod, int qtd);
void recolhe_dados_pedido(Listamesas* MESAS, int* num, int* cod, int* qtd, char menu[20]);

#endif

