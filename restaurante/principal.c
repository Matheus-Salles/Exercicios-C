#include<stdio.h>
#include<stdlib.h>
#include"mesas.h"
#include"pedidos.h"
#include"arquivos.h"

Listamesas* MESAS;

int main (){

	MESAS = cria_mesa();

	int encerrou = 0;
	
 	 while(!encerrou){

		char acao = abertura(); 	
		 
		switch(acao){

			case 'M': {
				int numero_mesa, codigo_garcom;
				float totalconta = 0;

				int disponivel = mostra_mesas_disponiveis(MESAS); // retorna 0 se as 12 mesas ja estão ocupadas

				if(disponivel){

					recolhe_dados_mesa(&numero_mesa, &codigo_garcom);	

					int abriu = abre_conta(MESAS, numero_mesa, codigo_garcom, totalconta);
	
					if(abriu) printf("MESA *%d* ABERTA COM SUCESSO!\n\n", numero_mesa);
	
				}
				else continue;
				
				break;
			}
			
			case 'P': {	
				if(*MESAS != NULL){ // verifica se lista não está vazia
				
					int numero_mesa, codigo_pedido, qtd_pedido;
					float valor;
					char menu[20] = "menu.txt";

					recolhe_dados_pedido(MESAS, &numero_mesa, &codigo_pedido, &qtd_pedido,menu);		
					
					valor = procura_preco(codigo_pedido) * qtd_pedido;

					atualiza_pedidos(MESAS, numero_mesa, codigo_pedido, qtd_pedido, valor);
					
				}
				else printf("NÃO HÁ MESAS ABERTAS\n\n");
					
				break;			
			}

			case 'F': {
				if(*MESAS != NULL){
					mostra_mesas_funcionando(MESAS);
					
					int num;
					printf("\nNúmero da mesa a ser fechada:");
					scanf("%d", &num);

					exibe_nota_fiscal(MESAS, num);

					libera_mesa(MESAS, num);
				}
				else printf("NÃO HÁ MESAS ABERTAS\n\n");
				
				break;
			}

			case 'E':
				printf("Programa interrompido\n");
				exit(1);
		}
	} 
}

			

