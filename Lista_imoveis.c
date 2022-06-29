#include <stdio.h>
#include <stdlib.h>
#include "Lista_imoveis.h"
#include <assert.h>

struct lista
{
    int m;
    LISTA *prox;
};

LISTA *imovel_create()
{
    LISTA *imoveis, *aux;
    int i;
    imoveis = (LISTA *)malloc(sizeof(LISTA));
    assert(imoveis != NULL);
    imoveis->prox = (LISTA *)malloc(sizeof(LISTA));
    assert(imoveis->prox != NULL);
    aux = imoveis->prox;
    aux->m = 1;
    for (i = 0; i < 19; aux = aux->prox)
    {
        aux->prox = (LISTA *)malloc(sizeof(LISTA));
        assert(aux->prox != NULL);
        aux->prox->m = i + 2;
        i++;
    }
    aux->prox = NULL;
    return imoveis;
}
//e->evento e o->original
int imovel_comprar(int e, LISTA *o)
{
    LISTA *comprar;
    int numero;
    comprar = o->prox;
    while (comprar != NULL && comprar->m != e)
    {
        comprar = comprar->prox;
    }
    if (comprar == NULL)
    {
        return 0;
    }
    else
    {
        LISTA *aux;
        aux = o;
        while (aux->prox != comprar)
        {
            aux = aux->prox;
        }
        numero = comprar->m;
        aux->prox = comprar->prox;
        free(comprar);
        return numero;
    }
}

void imovel_venda(int e, LISTA *o)
{
    LISTA *venda;
    venda = (LISTA *)malloc(sizeof(LISTA));
    assert(venda != NULL);
    venda->m = e;
    venda->prox = o->prox;
    o->prox = venda;
}
void imovel_destroy(LISTA *o)
{
    LISTA *destruir, *aux;
    destruir = o->prox;
    aux = destruir->prox;
    while (aux != NULL)
    {
        free(destruir);
        destruir = aux;
        aux = destruir->prox;
    }
    free(destruir);
    free(o);
}