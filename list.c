#include "list.h"
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct list
{
  int *elemento;
  int max, size;
};

LIST *list_create(int maximo)
{
  LIST *L;
  L = (LIST *)malloc(sizeof(LIST));
  L->elemento = (int *)malloc(maximo * sizeof(int));
  L->max = maximo;
  L->size = 0;
  return L;
}

void list_destroy(LIST *list)
{
  free(list->elemento);
  free(list);
}

void list_insert(LIST *list, int value, int idx)
{
  list->elemento[idx] = value;
}

int list_value(LIST *list, int idx)
{
  return (list->elemento[idx]);
}
