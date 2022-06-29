
#ifndef IMOVEL
#define IMOVEL

typedef struct lista LISTA;

LISTA *imovel_create();

int imovel_comprar(int e, LISTA *o);

void imovel_venda(int e, LISTA *o);

void imovel_destroy(LISTA *o);

#endif // IMOVEL