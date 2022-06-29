#include "bst.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
// estrutura da célula
struct tree
{
    int elem;
    TREE *left;
    TREE *right;
};
// estrutura que guarda a raiz da arvore
struct bst
{
    TREE *root;
};
// cria a estrurua da raiz da arvore
BST *bst_create()
{
    BST *raiz;
    raiz = (BST *)malloc(sizeof(BST));
    assert(raiz != NULL);
    raiz->root = NULL;
    return raiz;
}
/// destroi as estruturas, abrindo espaço de memória
static void tree_destroy(TREE *tree)
{
    if (tree != NULL)
    {
        tree_destroy(tree->left);
        tree_destroy(tree->right);
    }
    free(tree);
}
// destroi a estrutura de referência da raiz , abrindo espaço de memória
void bst_destroy(BST *bst)
{
    tree_destroy(bst->root);
}
// cria uma estrutura da árvore , podendno ser qualquer parte(folha,galho, raiz)
static TREE *tree_create(int value)
{
    TREE *galho;
    galho = (TREE *)malloc(sizeof(TREE));
    assert(galho != NULL);
    galho->left = NULL;
    galho->right = NULL;
    galho->elem = value;
    return galho;
} // função que insere e cria o modelo da árvore binária de busca
static TREE *tree_insert(TREE *tree, int value)
{
    if (tree == NULL)
    {
        tree = tree_create(value);
    }
    if (value < tree->elem)
    {
        tree->left = tree_insert(tree->left, value);
    }
    if (value > tree->elem)
    {
        tree->right = tree_insert(tree->right, value);
    }
    return tree;
}

void bst_insert(BST *bst, int value)
{
    bst->root = tree_insert(bst->root, value);
}
// dá o filho mais a esquerda da árvore
static TREE *left_most_child(TREE *tree)
{
    TREE *o;
    o = tree;
    if (tree->left != NULL)
    {
        o = left_most_child(tree->left);
    }
    return o;
} // remove uma estrutura da arvore
static TREE *tree_remove(TREE *tree, int value)
{
    TREE *noh;
    noh = tree;
    if (tree_search(tree, value) == true) // condição para ver se existe o elmento a se removido
    {
        if (tree->elem == value) // condições para remover a raiz da arvore
        {
            if (tree->left == NULL && tree->right == NULL) // somente a raiz na estrutura como um todo
            {
                free(noh);
                noh = NULL;
                return noh;
            }
            else if (tree->left != NULL && tree->right == NULL) // só um lado da árvore cresce
            {
                TREE *aux;
                aux = noh;
                tree = noh->left;
                noh = tree;
                free(aux);
                return noh;
            }
            else if (tree->left == NULL && tree->right != NULL) // só o outro lado da árvore cresce
            {
                TREE *aux;
                aux = noh;
                tree = noh->right;
                noh = tree;
                free(aux);
                return noh;
            }
            else if (tree->left != NULL && tree->right != NULL) // há estruturas no dois lados da raiz
            {
                TREE *aux;
                aux = left_most_child(tree->right);
                aux->left = noh->left;
                tree = aux;
                free(noh);
                noh = tree;
                return noh;
            }
            return noh;
        }
        else if (tree->left != NULL && value == tree->left->elem) // para eliminar uma estrutura interna
        {
            if (noh->left->right == NULL && noh->left->left == NULL) // remover folha
            {
                free(noh->left);
                noh->left = NULL;
                return noh;
            }
            else if (noh->left->right != NULL && noh->left->left == NULL) // remover uma estrutura que tem um filho,somente
            {
                TREE *aux;
                aux = noh->left;
                noh->left = aux->right;
                free(aux);
                return noh;
            }
            else if (noh->left->right == NULL && noh->left->left != NULL) // remover uma estrutura que tem um filho,somente
            {
                TREE *aux;
                aux = noh->left;
                noh->left = aux->left;
                free(aux);
                return noh;
            }
            else if (noh->left->right != NULL && noh->left->left != NULL) // remover uma estrutura que tem os dois filhos
            {
                TREE *aux1, *aux2, *aux3;
                aux1 = noh->left;
                aux2 = left_most_child(noh->left->right);
                aux3 = Esquerdo_E(noh->left->right);
                noh->left = aux2;
                aux2->left = aux1->left;
                if (aux2 != aux3)
                {
                    aux2->right = aux1->right;
                    aux3->left = NULL;
                }
                free(aux1);
                return noh;
            }
        }

        else if (tree->right != NULL && value == tree->right->elem) // para eliminar uma estrutura interna
        {
            if (noh->right->right == NULL && noh->right->left == NULL) // remover folha
            {
                free(noh->right);
                noh->right = NULL;
                return noh;
            }
            else if (noh->right->right != NULL && noh->right->left == NULL) // remover uma estrutura que tem um filho,somente
            {
                TREE *aux;
                aux = noh->right;
                noh->right = aux->right;
                free(aux);
                return noh;
            }
            else if (noh->right->right == NULL && noh->right->left != NULL) // remover uma estrutura que tem um filho,somente
            {
                TREE *aux;
                aux = noh->right;
                noh->right = aux->left;
                free(aux);
                return noh;
            }
            else if (noh->right->right != NULL && noh->right->left != NULL) // remover uma estrutura que tem os dois filhos
            {
                TREE *aux1, *aux2, *aux3;
                aux1 = noh->right;
                aux2 = left_most_child(noh->right->right);
                aux3 = Esquerdo_E(noh->right->right);
                noh->right = aux2;
                aux2->left = aux1->left;
                if (aux2 != aux3)
                {
                    aux2->right = aux1->right;
                    aux3->left = NULL;
                }
                free(aux1);
                return noh;
            }
        }
        else if (value > tree->elem) // condição para percorrer a árvore e colocar uma referência no elemento
        {
            noh->right = tree_remove(noh->right, value);
            return (noh);
        }
        else if (value < tree->elem)
        {
            noh->left = tree_remove(noh->left, value);
            return (noh);
        }
        return noh;
    }
    return noh;
}

void bst_remove(BST *bst, int value)
{
    bst->root = tree_remove(bst->root, value);
}

bool tree_search(TREE *tree, int value) // função para identificar se o elemento está na árvore
{
    if (tree != NULL)
    {
        if (tree->elem == value)
        {
            return true;
        }
        else if (value > tree->elem)
        {
            return (tree_search(tree->right, value));
        }
        else if (value < tree->elem)
        {
            return (tree_search(tree->left, value));
        }
    }
    return false;
}
bool bst_search(const BST *bst, int value)
{
    return (tree_search(bst->root, value));
}

static int tree_height(const TREE *tree) // função para nos dizer qual a altura da árvore
{
    if (tree != NULL)
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            return 0;
        }
        int he = 0;
        int hd = 0;
        if (tree->left != NULL)
        {
            he = tree_height(tree->left) + 1;
        }
        if (tree->right != NULL)
        {
            hd = tree_height(tree->right) + 1;
        }
        if (he > hd)
        {
            return he;
        }
        else
            return hd;
    }
    else
    {
        return -1;
    }
}

int bst_height(const BST *bst)
{
    return (tree_height(bst->root));
}

static void tree_print(const TREE *tree) // função para printar a árvore na forma parentética
{
    if (tree == NULL)
    {
        printf("()");
    }
    else
    {
        printf("(");
        printf("%d", tree->elem);
        tree_print(tree->left);
        tree_print(tree->right);
        printf(")");
    }
}

void bst_print(const BST *bst)
{
    tree_print(bst->root);
}

TREE *Esquerdo_E(TREE *tree)
{
    TREE *p;
    p = tree;
    if (p->left != NULL)
    {
        if (left_most_child(tree)->elem != p->left->elem)
        {
            p->left = Esquerdo_E(p->left);
            return p;
        }
        return p;
    }
    return p;
}