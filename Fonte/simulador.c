/*
 * Project name:
   Simulador de AFD e AFND e Conversor de AFND para AFD
     
 * Autor:
   Igor Beilner

 * Revision History:
   Versão 1.0
   20/04/2015

 * Description:
   Representação de automatos com grafos por Matriz de adjacência

* Test configuration:
      Cada estado do automato e um vertice do grafo, o atributo `cond´ sobre
   as arestas e a condicao de  transicao da aresta origem para a aresta des-
   tino.
   1 - Definir o tamanho do automato
   2 - Definir as transisoes
   3 - Definir o estado inicial
   4 - Definir o(s) estado(s) final(is)
   5 - Simular automato conforme desejado

 * NOTES:
*/

#include "Simulador.h"

int main() {
   Digraph *G;
   int menu, flag=0;
      
   while(1) {
      printf("Escolha uma opcao:\n");
      printf("1 - Criar Automato\n");
      printf("2 - Simular\n");
      printf("3 - Converter AFND p/ AFD\n");
      printf("4 - Imprimir Automato\n");
      printf("0 - Sair\n");
      scanf("%d", &menu);
      switch(menu) {
         case 0:
            return 0;
         case 1:
            G = Constroi();
            flag = 1;
            break;
         case 2:
            if(flag) Simula(G);
            break;
         case 3:
            if(flag) Converte(G);
            break;
         case 4:
            if(flag) Imprime(G);
         break;
      }
   }
}