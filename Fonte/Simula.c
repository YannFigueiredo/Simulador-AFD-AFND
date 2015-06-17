#include "Simulador.h"

void Simula(Digraph *G) {
	char teste[TMSTR];
	int len, i, j, k, flag;
	int *Est_atual = (int *) malloc(G->V*sizeof(int));	//Vetor de estado atuais

	if(G->Est_inicial > G->V || G->Est_inicial < 0) {
		printf("Estado Inicial indefinido!\n");
		return;
	}

	printf("Digite a string de teste:\n");
	scanf("%s", teste);

	len = strlen(teste);

	for(i=0; i < G->V; i++) Est_atual[i] = 0;	//inicializa marcando como estado nao atual

	k=0;
	Est_atual[G->Est_inicial] = 1;	//marca estado inicial
	
	while(1) {
		
		for(i=0; i < G->V; i++) {
			if(Est_atual[i] == 1 || Est_atual[i] == 3) {	//verifica se i e um estado atual
				for(j=0; j < G->V; j++) {

					if(G->adj[i][j].val == 1) {	//verifica se existe a areste
																				
						if(TestaCond(G->adj[i][j].cond, teste[k], G->adj[i][j].topo)) {	//se a condicao e satisfeita
							
							if(Est_atual[j] == 1) Est_atual[j] = 3;	//trata se o proximo estado for um estado atual
							else Est_atual[j] = 2;	//marca j como proximo estado

						}
					}

				}
				if(Est_atual[i] == 1)	Est_atual[i] = 0;	//desmarca estado atual se este nao for proximo estado
			}
		}

		for(i=0; i < G->V; i++) {
			if(Est_atual[i] == 2 || Est_atual[i] == 3) Est_atual[i] = 1;	//marca proximo estado como estado atual
		}

		k++;	//avanca na string de entrada
		if(k == len) {	//verifica se a string terminou
			flag = 0;
			for(i=0; i < G->V; i++) {
				if(Est_atual[i] == 1 && G->adj[i][i].final == 1) {
					printf("Reconheceu em %d\n", i);
					flag = 1;
				}
			}
			if(!flag) printf("Nao Reconheceu!\n");
			break;
		}
	}
}