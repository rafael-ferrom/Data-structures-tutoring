/* 
 * Esqueleto para implementações do tipo abstrato de dados fila.
 */

#include <stdlib.h>
#include <stdio.h>
#include "esqueleto_fila.h"

void cria_fila(Fila* fila) {
  
}

int fila_vazia(Fila* fila) {
  return 0; /* A ser alterado... */
}
	  
void insere_fila(Fila* fila, elem_t elem) {
  
}

elem_t remove_fila(Fila* fila) {
  if (fila_vazia(fila)) {
    printf("Erro: fila vazia!\n");
    exit(0);
  }
  return 0;  /* A ser alterado... */
}

void libera_fila(Fila* fila) {
  
}
