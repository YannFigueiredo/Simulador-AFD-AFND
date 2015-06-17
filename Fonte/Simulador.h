//matriz de adjacencia
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Vertex int
#define TMSTR 100
#define TMCOND 50

//--------------------------------------------
//----Representacao de cada vertice/estato----
typedef struct Estado {
	int topo;
   	char val;
   	char cond[TMCOND];
   	char inicial;
   	char final;
}Estado;
//--------------------------------------------

//--------------------------------------
typedef struct Digraph {
   int V;
   int Est_inicial;
   Estado **adj;
}Digraph;
//--------------------------------------

//--------------------------------------------------------
//---------------Protótipos das funções-------------------
void DigraphRemoveA(Digraph *G, Vertex v, Vertex w);
void DgraphInsertA(Digraph *G, Vertex v, Vertex w, char p);
void Imprime(Digraph *G);
Estado **MatrixInt(int r, int c, int val);
Digraph *DigraphInit(int V);
Digraph *Constroi();
void DigraphDFS(Digraph *G);
void Converte(Digraph *G);
int VerDet(Digraph *G);
void Simula(Digraph *G);
int TestaCond(char *test, char str, int topo);
//--------------------------------------------------------