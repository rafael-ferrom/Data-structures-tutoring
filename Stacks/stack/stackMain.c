#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha p;

    cria_pilha(&p);

    insere_pilha(&p, 10);
    insere_pilha(&p, 20);
    insere_pilha(&p, 30);

    printf("Topo: %d\n", elemTopo(&p));

    printf("Removido: %d\n", remove_pilha(&p));
    printf("Removido: %d\n", remove_pilha(&p));

    printf("Topo agora: %d\n", elemTopo(&p));

    libera_pilha(&p);

    return 0;
}
