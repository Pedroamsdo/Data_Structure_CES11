#ifndef GRAPH_H
#define GRAPH_H

typedef struct noh NOH;

typedef struct graph GRAPH;

GRAPH *graph_create(int order);

GRAPH *read();

void graph_destroy(GRAPH *graph);

void Find_Articulations(GRAPH *graph);

void Find_ArticulationsR(GRAPH *graph, int u, int *m, int *p, int *dt, int *t);

void color_points_Articulations(GRAPH *graph, int *m, int *p, int *dt, int *color);

void Print_Articulations(GRAPH *graph, int *color);

void graph_add_edge(GRAPH *graph, int u, int v);

#endif // GRAPH_H