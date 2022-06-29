#ifndef FILA
#define FILA

typedef struct fila LINE;

typedef struct mark MARK;

#include "btree.h"

#include <stdbool.h>

MARK *fila_create();

void fila_deletar(MARK *fila);

void fila_destroy(MARK *fila);

void fila_inserir(MARK *fila, TREE value);

bool fila_vazia(MARK *fila);

TREE fila_value_inicio(MARK *fila);

#endif // FILA