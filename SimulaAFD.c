#include "Simulador.h"

void SimulaAFD(Digraph *G, char teste[100], int len) {
	int i, j, k;

	k=0;
	i = G->Est_inicial;
	while(1) {
		for(j=0; j<G->V; j++) {
			if((G->adj[i][j].val == 1) && (G->adj[i][j].cond == teste[k])) {
				i = j;
				k++;
				break;
			}
		}
		if(i != j) {
			printf("Nao reconheceu!\n");
			break;
		} else if(k == len  && G->adj[j][j].final == 1) {
			printf("Reconheceu!\n");
			break;
		}
	}
}