#include "Simulador.h"

void SimulaAFND(Digraph *G, char teste[100], int len) {

	int i, j, k, flag;
	int *Est_atualND = (int *) malloc(G->V*sizeof(int));	//Vetor de estado atuais

	for(i=0; i < G->V; i++) Est_atualND[i] = 0;	//inicializa marcando como estado nao atual

	k=0;
	Est_atualND[G->Est_inicial] = 1;	//marca estado inicial

	while(1) {

		for(i=0; i < G->V; i++) {
			if(Est_atualND[i] == 1 || Est_atualND[i] == 3) {	//verifica se i e um estado atual
				for(j=0; j < G->V; j++) {

					if((G->adj[i][j].val == 1) && (G->adj[i][j].cond == teste[k])) { //verifica se existe a areste e
																								//se a condicao e satisfeita
						if(Est_atualND[j] == 1) Est_atualND[j] = 3;	//trata se o proximo estado for um estado atual
						else Est_atualND[j] = 2;	//marca j como proximo estado
					}

				}
				if(Est_atualND[i] == 1)	Est_atualND[i] = 0;	//desmarca estado atual se este nao for proximo estado
			}
		}

		for(i=0; i < G->V; i++) {
			if(Est_atualND[i] == 2 || Est_atualND[i] == 3) Est_atualND[i] = 1;	//marca proximo estado como estado atual
		}

		k++;	//avanca na string de entrada
		if(k == len) {	//verifica se a string terminou
			flag = 0;
			for(i=0; i < G->V; i++) {
				if(Est_atualND[i] == 1 && G->adj[i][i].final == 1) {
					printf("Reconheceu em %d\n", i);
					flag = 1;
				}
			}
			if(!flag) printf("Nao Reconheceu!\n");
			break;
		}
	}
}
