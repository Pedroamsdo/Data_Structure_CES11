/***************************************************/
/* Aluno: Pedro Anacleto Maritns Senna De Oliveira*/
/* CES-11: Lab 8************************** */
/**************************************************/

#include <stdio.h>
#include <assert.h>
#include "graph.h"

int main()
{
    GRAPH *graph;
    graph = read();
    Find_Articulations(graph);
    graph_destroy(graph);
    return 0;
}