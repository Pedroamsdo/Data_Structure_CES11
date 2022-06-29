/***************************************************/
/* Aluno: Pedro Anacleto Maritns Senna De Oliveira*/
/* CES-11: Lab 7:Ordenação topológica************ */
/**************************************************/
#include "digraph.h"
#include "stack.h"

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct edge EDGE;

struct edge
{
    int indice;
    EDGE *prox;
};

struct digraph
{
    int order;
    EDGE **vertex;
};

DIGRAPH *digraph_read()
{
    DIGRAPH *digraph;
    int u, v, order;
    assert(scanf("%d", &order) == 1);
    digraph = digraph_create(order);
    while (scanf("%d %d", &u, &v) != EOF)
    {
        digraph_add_edge(digraph, u, v);
    }
    return digraph;
}

DIGRAPH *digraph_create(int order)
{
    DIGRAPH *reference;
    reference = (DIGRAPH *)malloc(sizeof(DIGRAPH));
    assert(reference != NULL);
    reference->order = order;
    reference->vertex = (EDGE **)malloc(order * sizeof(EDGE *));
    assert(reference->vertex != NULL);
    for (int i = 0; i < order; i++)
    {
        reference->vertex[i] = (EDGE *)malloc(sizeof(EDGE));
        assert(reference->vertex[i] != NULL);
        reference->vertex[i]->indice = i;
        reference->vertex[i]->prox = NULL;
    }
    return reference;
}

void digraph_destroy(DIGRAPH *digraph)
{
    for (int i = 0; i < digraph->order; i++)
    {
        for (EDGE *aux1 = digraph->vertex[i]; aux1 != NULL;)
        {
            EDGE *aux2 = aux1->prox;
            free(aux1);
            aux1 = aux2;
        }
    }
    free(digraph->vertex);
    free(digraph);
}

void digraph_add_edge(DIGRAPH *digraph, int u, int v)
{
    EDGE *aux1, *aux2;
    aux1 = digraph->vertex[u]->prox;
    aux2 = (EDGE *)malloc(sizeof(EDGE));
    assert(aux2 != NULL);
    aux2->indice = v;
    digraph->vertex[u]->prox = aux2;
    aux2->prox = aux1;
}

bool digraph_has_edge(const DIGRAPH *digraph, int u, int v)
{
    EDGE *aux;
    aux = digraph->vertex[u]->prox;
    while (aux != NULL && aux->indice != v)
    {
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

typedef enum
{
    WHITE,
    GRAY,
    BLACK
} COLOR;

// Returns false if is not dag
static bool topological_sort_dfs(const DIGRAPH *digraph, int u, COLOR *color, STACK *stack)
{
    int i;
    color[u] = GRAY;
    bool aux = true;
    for (i = 0; i < digraph->order && aux == true; i++)
    {
        if (digraph_has_edge(digraph, u, i) == true)
        {
            if (color[i] == WHITE)
            {
                aux = topological_sort_dfs(digraph, i, color, stack);
            }
            if (color[i] == GRAY)
            {
                aux = false;
            }
        }
    }
    color[u] = BLACK;
    stack_push(stack, u);
    return aux;
}

void topological_sort(const DIGRAPH *digraph)
{
    bool isdag = true;
    int i;
    STACK *pilha;
    pilha = stack_create();
    COLOR *color = (COLOR *)malloc(digraph->order * sizeof(COLOR));
    assert(color != NULL);
    for (i = 0; i < digraph->order; i++)
    {
        color[i] = WHITE;
    }
    for (i = 0; i < digraph->order && isdag == true; i++)
    {
        if (color[i] == WHITE)
        {
            isdag = topological_sort_dfs(digraph, i, color, pilha);
        }
    }
    if (isdag != true)
    {
        printf("\n");
    }
    else
    {
        while (stack_isEmpty(pilha) == false)
        {
            printf("%d ", stack_top(pilha));
            stack_pop(pilha);
        }
    }
    stack_destroy(pilha);
    free(color);
}
