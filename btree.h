#ifndef TREE_H
#define TREE_H

#include <stdbool.h>

typedef char informacao;

struct celula
{
    informacao info;
    struct celula *fidir;
    struct celula *fidesq;
};

typedef struct celula celula;

typedef celula *TREE;

bool word(char);

TREE make_tree(char *);

void pre_ordem(TREE raiz);

void ordem_central(TREE raiz);

void pos_ordem(TREE raiz);

void nivel(TREE raiz);

void arvore_destroy(TREE raiz);

extern int cont;

#endif // TREE_H