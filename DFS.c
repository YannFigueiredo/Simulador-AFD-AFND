#include "Simulador.h"

/* A função DigraphDFS visita todos os vértices e todos os arcos do digrafo G. 
A função atribui um número de ordem pre[x] a cada vértice x:  o k-ésimo vértice visitado recebe número de ordem k.  
(Código inspirado no programa 18.3 de Sedgewick.) */

void DigraphDFS(Digraph *G) {
   int *pre = (int *) malloc(G->V*sizeof(int));
   int conta;
   Vertex v;
   conta = 0;
   for (v = 0; v < G->V; v++) 
      pre[v] = -1;
   for (v = 0; v < G->V; v++)
      if (pre[v] == -1) 
         DFS(G, v, conta, pre);
}
/* A função DFS supõe que o digrafo G é representado por uma matriz de adjacência.  
(Inspirado no programas 18.1 de Sedgewick.) */

void DFS(Digraph *G, Vertex v, int conta, int *pre) {
   Vertex w;
   pre[v] = conta++; 
   for (w = 0; w < G->V; w++)
      if (G->adj[v][w].val != 0 && pre[w] == -1)
         DFS(G, w, conta, pre); 
}
