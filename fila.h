
#ifndef FILA
#define FILA

typedef struct fila LINE;

typedef struct mark MARK;

#include <stdbool.h>

MARK *fila_create();

void fila_deletar(MARK *fila);

void fila_destroy(MARK *fila);

void fila_inserir(MARK *fila, char value);

bool fila_vazia(MARK *fila);

int fila_value_inicio(MARK *fila);

#endif // FILA