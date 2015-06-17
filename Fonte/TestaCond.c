#include "Simulador.h"

int TestaCond(char *test, char str, int topo) {
	int i;

	for(i=0; i < topo; i++) {
		if(test[i] == str) return 1;
	}
	return 0;	
}