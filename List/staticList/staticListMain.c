#include <stdio.h>
#include "lista_estatica.h"

int main() {
    Lista l;
    elem_t x;

    cria(&l);

    insere_fim(&l, 10);
    insere_fim(&l, 5);
    insere_fim(&l, 20);

    exibe(&l);

    ordena(&l);
    exibe(&l);

    remove_inicio(&l, &x);
    printf("Removido: %d\n", x);

    exibe(&l);

    return 0;
}
