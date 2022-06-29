#include <stdio.h>
#include <assert.h>
#include "graph.h"
#include <stdlib.h>

#define infinito 9999;
// estrutura do grafo
struct noh
{
    NOH *prox;
    int index;
};

struct graph
{
    int order;
    NOH **vertex;
};
// criação do grafo
GRAPH *graph_create(int order)
{
    GRAPH *graph;
    graph = (GRAPH *)malloc(sizeof(GRAPH));
    assert(graph != NULL);
    graph->order = order;
    graph->vertex = (NOH **)malloc(order * sizeof(NOH *));
    assert(graph->vertex != NULL);
    for (int i = 0; i < order; i++)
    {
        graph->vertex[i] = (NOH *)malloc(sizeof(NOH));
        assert(graph->vertex[i] != NULL);
        graph->vertex[i]->index = i;
        graph->vertex[i]->prox = NULL;
    }
    return graph;
}

GRAPH *read()
{
    GRAPH *graph;
    int u, v, order;
    assert(scanf("%d", &order) == 1);
    graph = graph_create(order);
    while (scanf("%d%d", &u, &v) != EOF)
    {
        graph_add_edge(graph, u, v);
        graph_add_edge(graph, v, u);
    }
    return graph;
}
void graph_add_edge(GRAPH *graph, int u, int v)
{
    NOH *aux1;
    aux1 = graph->vertex[u];
    for (; aux1->prox != NULL; aux1 = aux1->prox)
        ;
    aux1->prox = (NOH *)malloc(sizeof(NOH));
    assert(aux1->prox != NULL);
    aux1->prox->index = v;
    aux1->prox->prox = NULL;
}
// para destruir a estrutura
void graph_destroy(GRAPH *graph)
{
    for (int i = 0; i < graph->order; i++)
    {
        for (NOH *aux1 = graph->vertex[i]; aux1 != NULL;)
        {
            NOH *aux2 = aux1->prox;
            free(aux1);
            aux1 = aux2;
        }
    }
    free(graph->vertex);
    free(graph);
}
typedef enum
{
    GREEN,
    RED,
} COLOR;
// criação do algoritmo para identificar pontos de articulação
void Find_Articulations(GRAPH *graph)
{
    int *m, *p, *dt, *color, t;
    m = (int *)malloc(graph->order * sizeof(int));
    assert(m != NULL);
    p = (int *)malloc(graph->order * sizeof(int));
    assert(p != NULL);
    dt = (int *)malloc(graph->order * sizeof(int));
    assert(dt != NULL);
    color = (int *)malloc(graph->order * sizeof(int));
    assert(color != NULL);
    for (int i = 0; i < graph->order; i++)
    {
        color[i] = RED;
        m[i] = infinito;
        p[i] = infinito;
        dt[i] = infinito;
    }
    t = 0;
    Find_ArticulationsR(graph, 0, m, p, dt, &t);
    color_points_Articulations(graph, m, p, dt, color);
    Print_Articulations(graph, color);
    free(color); // destruir estruturas
    free(m);
    free(p);
    free(dt);
}
// algoritmo para achar vetores que auxilirão para achar os pontos de articulação
void Find_ArticulationsR(GRAPH *graph, int u, int *m, int *p, int *dt, int *t)
{
    m[u] = *t;
    dt[u] = *t;
    *t = *t + 1;
    NOH *aux;
    int inf = infinito;
    aux = graph->vertex[u]->prox;
    for (; aux != NULL; aux = aux->prox)
    {
        if (p[u] != aux->index)
        {
            if (m[aux->index] == inf)
            {
                p[aux->index] = u;
                Find_ArticulationsR(graph, aux->index, m, p, dt, t);
            }
            if (m[aux->index] < m[u])
            {
                m[u] = m[aux->index];
            }
        }
    }
}
// função que compara vetores de descoberta e colore aqueles que são pontos de articulação
void color_points_Articulations(GRAPH *graph, int *m, int *p, int *dt, int *color)
{
    int cont = 0, i;
    for (i = 1; i < graph->order; i++)
    {
        if (p[i] == 0)
        {
            cont++;
        }
    }
    if (cont > 1)
    {
        color[0] = GREEN;
    }
    for (i = 1; i < graph->order; i++)
    {
        if (m[i] >= dt[p[i]] && p[i] != 0)
        {
            color[p[i]] = GREEN;
        }
    }
}
// funçao que imprime pontos de articulação
void Print_Articulations(GRAPH *graph, int *color)
{
    for (int i = 0; i < graph->order; i++)
    {
        if (color[i] == GREEN)
        {
            printf("%d\n", i);
        }
    }
};