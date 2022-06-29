/***************************************************/
/* Aluno: Pedro Anacleto Maritns Senna De Oliveira*/
/* CES-11: Lista Linear************************** */
/**************************************************/

#include "list.h"

#include <assert.h>
#include <stdio.h>

int main()
{
  unsigned int max; // máximo de elementos no TAD

  // Auxiliares para a interface com o usuário
  char cmd = 0;     // comando do usuário
  int valor;        // parâmetros do comando
  unsigned int idx; // parâmetros do comando

  assert(scanf("%u", &max) == 1); // de acordo com 'https://en.cppreference.com/w/c/io/fscanf'
  assert(max > 0);

  // Criar o TAD com o número máximo solicitado
  LIST *list = list_create(max);
  assert(list != NULL);

  // Interface com o usuário
  while (cmd != '0' && scanf(" %c", &cmd) != EOF)
  {
    switch (cmd)
    {
    case 'q':
      printf("%u\n", list_size(list));
      break;

    case '0':
      break;

    case 'a': // a <valor> <idx>
      assert(scanf(" %d %u", &valor, &idx) == 2);
      list_change(list, valor, idx);
      break;

    case 'i': // i <valor> <idx>
      assert(scanf(" %d %u", &valor, &idx) == 2);
      list_insert(list, valor, idx);
      break;

    case 'd': // d <idx>
      assert(scanf(" %u", &idx) == 1);
      list_delete(list, idx);
      break;

    case 'p': // p <idx>
      assert(scanf(" %u", &idx) == 1);
      list_print(list, idx);
      break;

    default:
      printf("Operação inválida\n"); // pode ser incluido uma mensagem de operação inválida
      break;
    }
  }
  return 0;
}
