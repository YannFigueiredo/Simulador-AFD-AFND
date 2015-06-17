#include "Simulador.h"

//Remove um arco do digrafo
void DigraphRemoveA(Digraph *G, Vertex v, Vertex w) { 
   if (G->adj[v][w].val == 1) {
      G->adj[w][w].topo--;
      if(G->adj[w][w].topo == 0) G->adj[v][w].val = 0;
   }
}

//Insere um arco no digrafo
void DgraphInsertA(Digraph *G, Vertex v, Vertex w, char p) {
   
   G->adj[v][w].val = 1;
   G->adj[v][w].cond[G->adj[v][w].topo] = p;
   G->adj[v][w].topo++;

}

//Inicializa a mareis de adjacência
Estado **MatrixInt(int r, int c, int val) { 
   Vertex i, j;
   Estado **m = malloc(r * sizeof(Estado*));
   for (i = 0; i < r; i++)
      m[i] = malloc(c * sizeof(Estado));
   for (i = 0; i < r; i++) {
      for (j = 0; j < c; j++) {
         m[i][j].val = val;
         m[i][j].inicial = val;
         m[i][j].final = val;
         m[i][j].topo = 0;
      }
   }
   return m;
}

//Inicializa o digrafo
Digraph *DigraphInit(int V) { 
   Digraph *G = malloc(sizeof*G);
   G->V = V;
   G->Est_inicial = -1;
   G->adj = MatrixInt(V, V, 0);
   return G;
}

//imprime o digrafo de maneira que os vértices não se repitam
void Imprime(Digraph *G) {
   int i, j, k;
   for(i=0; i<G->V; i++) {
      for(j=0; j<G->V; j++) {
         if(G->adj[i][j].val == 1) {
            printf("%d %d", i, j);
            for(k=0; k < G->adj[i][j].topo; k++) printf(" %c", G->adj[i][j].cond[k]);
            printf("\n");
         }
      }
   }
}
