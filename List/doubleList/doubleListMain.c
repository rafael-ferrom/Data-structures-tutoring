#include <stdio.h>
#include "lista_dupla.h"

int main() {
    Lista l;
    elem_t x;

    cria(&l);

    insere_inicio(&l, 10);
    insere_inicio(&l, 5);
    insere_fim(&l, 20);

    exibe(&l);

    remove_fim(&l, &x);
    printf("Removido: %d\n", x);

    exibe(&l);

    inverte(&l);
    exibe(&l);

    libera(&l);

    return 0;
}
