#include <stdio.h>
#include "esqueleto_fila.h"

int main() {
    Fila fila;

    cria_fila(&fila);

    printf("Fila vazia? %d\n", fila_vazia(&fila));

    insere_fila(&fila, 10);
    insere_fila(&fila, 20);

    printf("Fila vazia? %d\n", fila_vazia(&fila));

    printf("Removido: %d\n", remove_fila(&fila));

    libera_fila(&fila);

    return 0;
}
