#ifndef LIST_H
#define LIST_H

typedef struct list LIST;

LIST *list_create(int max);

void list_destroy(LIST *list);

void list_insert(LIST *list, int value, int idx);

int list_value(LIST *list, int idx);

#endif // LIST_H