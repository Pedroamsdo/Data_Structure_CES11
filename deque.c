
/* Aluno: Pedro Anacleto Maritns Senna De Oliveira*/
/* CES-11: Deques************************** */
/**************************************************/
#include "deque.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct noh noh;
struct noh
{
    int x;
    noh *prox, *prev;
};
struct deque
{
    noh *s, *f;
};
/*perguntar o porque dessa srtuct*/
DEQUE *deque_create()
{
    DEQUE *o;
    o = (DEQUE *)malloc(sizeof(DEQUE));
    assert(o != NULL);
    o->s = (noh *)malloc(sizeof(noh));
    assert(o->s != NULL);
    o->f = o->s;
    o->s->prev = NULL;
    o->f->prox = NULL;
    return o;
}
void deque_destroy(DEQUE *deque)
{
    if (deque->s == deque->f)
    {
        free(deque->s);
        free(deque);
    }
    else if (deque->s != deque->f)
    {
        noh *p, *q;
        do
        {
            q = deque->f;
            p = deque->f->prev;
            deque->f = p;
            p->prox = NULL;
            free(q);
        } while (deque->s != deque->f);
        free(deque->s);
        free(deque);
    }
    return;
}
void deque_empty(DEQUE *deque)
{
    if (deque->f == deque->s)
    {
    }
    else
    {
        do
        {
            noh *p, *q;
            q = deque->f;
            p = deque->f->prev;
            deque->f = p;
            p->prox = NULL;
            free(q);
        } while (deque->s != deque->f);
    }
}
void deque_print(const DEQUE *deque)
{
    if (deque->f == deque->s)
    {
        printf("            \n");
    }
    else
    {
        noh *pos;
        pos = deque->s->prox;
        while (pos->prox != NULL)
        {
            printf("%d ", pos->x);
            pos = pos->prox;
        }
        printf("%d\n", pos->x);
    }
}
int deque_first(const DEQUE *deque)
{
    return (deque->s->prox->x);
}
int deque_last(const DEQUE *deque)
{
    return (deque->f->x);
}
void deque_insertFirst(DEQUE *deque, int element)
{
    noh *n;
    if (deque->s == deque->f)
    {
        n = (noh *)malloc(sizeof(noh));
        assert(n != NULL);
        n->x = element;
        n->prev = deque->s;
        deque->s->prox = n;
        n->prox = NULL;
        deque->f = n;
    }
    else
    {
        n = (noh *)malloc(sizeof(noh));
        assert(n != NULL);
        n->x = element;
        deque->s->prox->prev = n;
        n->prox = deque->s->prox;
        n->prev = deque->s;
        deque->s->prox = n;
    }
    return;
}
void deque_insertLast(DEQUE *deque, int element)
{
    noh *n;
    n = (noh *)malloc(sizeof(noh));
    assert(n != NULL);
    n->x = element;
    n->prev = deque->f;
    deque->f->prox = n;
    n->prox = NULL;
    deque->f = n;
}
void deque_removeFirst(DEQUE *deque)
{
    if (deque->s == deque->f)
    {
        printf("        \n");
    }
    else if (deque->s->prox->prox != NULL)
    {
        noh *r;
        r = deque->s->prox;
        r->prox->prev = deque->s;
        deque->s->prox = r->prox;
        free(r);
    }
    else if (deque->s->prox->prox == NULL)
    {
        deque->f = deque->s;
        free(deque->s->prox);
        deque->s->prox = NULL;
    }
}
void deque_removeLast(DEQUE *deque)
{
    if (deque->s == deque->f)
    {
        printf("        \n");
    }
    else
    {
        noh *r, *aux;
        r = deque->f->prev;
        aux = deque->f;
        deque->f = r;
        r->prox = NULL;
        free(aux);
    }
}
int deque_size(const DEQUE *deque)
{
    int cont;
    if (deque->s == deque->f)
    {
        cont = 0;
    }
    else
    {
        noh *c;
        c = deque->s->prox;
        for (cont = 1; c->prox != NULL; c = c->prox)
        {
            cont++;
        }
    }
    return cont;
}