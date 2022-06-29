#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"
#include "btree.h"
// estrutura para uma fila em que o elemento representa o numeor tirado no dado.
struct fila
{
    LINE *prox;
    TREE dado;
};

struct mark
{
    LINE *inicio;
    LINE *final;
};
// criação da estrutura TAD para armazenar os númeors do dado para cada jogador MARK-> deuqe que tem ponteiros de início e final
MARK *fila_create()
{
    MARK *original;
    original = (MARK *)malloc(sizeof(MARK));
    assert(original != NULL);
    original->final = (LINE *)malloc(sizeof(LINE));
    assert(original->final != NULL);
    original->inicio = original->final;
    original->final->prox = NULL;
    return original;
}
// inserir o valor tirado do dado
void fila_inserir(MARK *fila, TREE raiz)
{
    LINE *n;
    if (fila->inicio->prox != NULL)
    {
        n = (LINE *)malloc(sizeof(LINE));
        assert(n != NULL);
        n->dado = raiz;
        n->prox = fila->inicio->prox;
        fila->inicio->prox = n;
    }
    else
    {
        n = (LINE *)malloc(sizeof(LINE));
        assert(n != NULL);
        n->dado = raiz;
        fila->inicio->prox = n;
        fila->final = n;
        n->prox = NULL;
    }
}
// deletar a celula depois de usado para andar
void fila_deletar(MARK *fila)
{
    LINE *aux;
    aux = fila->inicio->prox;
    if (aux != fila->final)
    {
        while (aux->prox != fila->final)
        {
            aux = aux->prox;
        }
        free(fila->final);
        fila->final = aux;
        aux->prox = NULL;
    }
    else
    {
        fila->final = fila->inicio;
        free(aux);
        fila->inicio->prox = NULL;
    }
}
// Destruir o TAD para n ter vazamento de memória
void fila_destroy(MARK *fila)
{
    free(fila->inicio);
    free(fila);
}
// verificar se a fila está vazia
bool fila_vazia(MARK *fila)
{
    if (fila->final != fila->inicio)
    {
        return false;
    }
    else
    {
        return true;
    }
}
// retorna o valor do primeiro número que entrou
TREE fila_value_inicio(MARK *fila)
{
    return (fila->final->dado);
}