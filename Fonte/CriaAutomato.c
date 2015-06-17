#include "Simulador.h"

//Dodos dois inteiros que representam o número de vértices e o número de arestas,
//esta função constroi um digrafo
Digraph *Constroi() {
   int i, V, origem, destino, menu;
   char cond;
   scanf("%d", &V);
   
   Digraph *G = DigraphInit(V);

   while(1) {
      printf("1 - Inserir aresta e condicao\n");
      printf("2 - Deletar aresta\n");
      printf("3 - Definir estado inicial\n");
      printf("4 - Definir estados finais| -1 p/ Sair\n");
      printf("0 - Sair\n");
      scanf("%d", &menu);
      switch(menu) {
         case 0:
            return G;
         case 1:
            scanf("%d %d %c", &origem, &destino, &cond);
            DgraphInsertA(G, origem, destino, cond);
            break;
         case 2:
            scanf("%d %d", &origem, &destino);
            DigraphRemoveA(G, origem, destino);
            break;
         case 3:
            scanf("%d", &i);
            G->Est_inicial = i;
            break;
         case 4:
            while(1) {
               scanf("%d", &i);
               if(i < 0) break;
               G->adj[i][i].final = 1;
            }
            break;
      }
   }
}
