/* Não modifique este arquivo. */

#ifndef BST_H
#define BST_H

#include <stdbool.h>

typedef struct bst BST;

typedef struct tree TREE;

#include <stdbool.h>

bool tree_search(TREE *tree, int value);

BST *bst_create();

TREE *Esquerdo_E(TREE *tree);

void bst_destroy(BST *bst);

void bst_insert(BST *bst, int value);

void bst_remove(BST *bst, int value);

bool bst_search(const BST *bst, int value);

int bst_height(const BST *bst);

void bst_print(const BST *bst);

#endif // BST_H
