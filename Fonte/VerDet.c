#include "Simulador.h"

int VerDet(Digraph *G) {
	int i, j, k, l;
	for(i=0; i < G->V; i++) {
		for(j=0; j < G->V; j++) {
			if(G->adj[i][j].val == 1) {		//verifica se ha vertice de i para j
				for(k=0; k < G->adj[i][j].topo; k++) {		//se tiver, olha para todas as condicoes de transicao
					for(l=0; l < G->V; l++) {//anda por todos vertices adjacentes a i p/ verificar se alguma condisao se repete
						if(G->adj[i][l].val == 1 && l != j) {
							if(TestaCond(G->adj[i][l].cond, G->adj[i][j].cond[k], G->adj[i][l].topo)) return 1;
						}		//chama TestaCond() p/ comparar cond[k] de i com cond de todos vertices adjacentes
					}
				}
			}
		}
	}
	return 0;
}