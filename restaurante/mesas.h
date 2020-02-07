#ifndef _MESAS_H_
#define _MESAS_H_

struct mesa{
	int num_mesa;
	int cod_garcom;
	float total_conta;
};

typedef struct no_mesa* Listamesas;

int mostra_mesas_disponiveis(Listamesas* li);
Listamesas* cria_mesa();
int tamanho_lista(Listamesas* li);
int abre_conta(Listamesas* li, int nmesa, int cgarcom, float tconta);
void mostra_mesas_funcionando(Listamesas* li);
void atualiza_pedidos(Listamesas* li,int num, int cdg, int qtd, float valor);
void exibe_nota_fiscal(Listamesas* lin, int num_m);
int libera_mesa(Listamesas* li, int num);
void recolhe_dados_mesa(int* n, int* g);

#endif
