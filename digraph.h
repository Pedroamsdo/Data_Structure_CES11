#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <stdbool.h>

typedef struct digraph DIGRAPH;

DIGRAPH *digraph_read();

DIGRAPH *digraph_create(int order);
void digraph_destroy(DIGRAPH *digraph);

void digraph_add_edge(DIGRAPH *digraph, int u, int v);
bool digraph_has_edge(const DIGRAPH *digraph, int u, int v);

void topological_sort(const DIGRAPH *digraph);

#endif // DIGRAPH_H
