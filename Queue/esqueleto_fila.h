/* 
 * Esqueleto para implementações do tipo abstrato de dados fila.
 */


typedef int elem_t; /* Tipo do elemento */

typedef void* Fila; /* Tipo da fila (a ser redefinido) */

void cria_fila(Fila* fila);

int fila_vazia(Fila* fila);
	  
void insere_fila(Fila* fila, elem_t elem);

elem_t remove_fila(Fila* fila);

void libera_fila(Fila* fila);


