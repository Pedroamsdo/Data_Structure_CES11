#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "btree.h"
#include <string.h>
#include "queue.h"

int cont = 1;
// verifica se o caractere é uma letra.
bool word(char caracter)
{
    if ((64 < caracter && caracter < 91) || (96 < caracter && caracter < 123))
    {
        return true;
    }
    return false;
}
// cria a arvore a partir de uma string
TREE make_tree(char *cad)
{
    TREE p = NULL;
    if (word(cad[cont]))
    {
        p = (celula *)malloc(sizeof(celula));
        assert(p != NULL);
        p->fidesq = NULL;
        p->fidir = NULL;
        p->info = cad[cont];
        cont++;
    }
    if (cad[cont] == '(')
    {
        cont++;
        p->fidesq = make_tree(cad);
    }
    if (cad[cont] == '(')
    {
        cont++;
        p->fidir = make_tree(cad);
    }
    if (cad[cont] == ')')
    {
        cont++;
    }
    return p;
}
// printa os elementos da pre ordem
void pre_ordem(TREE raiz)
{
    printf("%c", raiz->info);
    if (raiz->fidesq != NULL)
    {
        pre_ordem(raiz->fidesq);
    }
    if (raiz->fidir != NULL)
    {
        pre_ordem(raiz->fidir);
    }
    return;
}
// printa os elemntos da ordem central
void ordem_central(TREE raiz)
{
    if (raiz->fidesq != NULL)
    {
        ordem_central(raiz->fidesq);
    }
    printf("%c", raiz->info);
    if (raiz->fidir != NULL)
    {
        ordem_central(raiz->fidir);
    }
}
// printa em pos ordem a arvore
void pos_ordem(TREE raiz)
{
    if (raiz->fidesq != NULL)
    {
        pos_ordem(raiz->fidesq);
    }
    if (raiz->fidir != NULL)
    {
        pos_ordem(raiz->fidir);
    }
    printf("%c", raiz->info);
}
// printa em nivelamento os elementos da arvore
void nivel(TREE raiz)
{
    MARK *fila;
    fila = fila_create();
    fila_inserir(fila, raiz);
    while (fila_vazia(fila) == false)
    {
        if (fila_value_inicio(fila)->fidesq != NULL)
            fila_inserir(fila, fila_value_inicio(fila)->fidesq);
        if (fila_value_inicio(fila)->fidir != NULL)
            fila_inserir(fila, fila_value_inicio(fila)->fidir);
        printf("%c", fila_value_inicio(fila)->info);
        fila_deletar(fila);
    }
    fila_destroy(fila);
}

void arvore_destroy(TREE raiz)
{
    if (raiz->fidesq != NULL)
    {
        arvore_destroy(raiz->fidesq);
    }
    if (raiz->fidir != NULL)
    {
        arvore_destroy(raiz->fidir);
    }
    free(raiz);
}