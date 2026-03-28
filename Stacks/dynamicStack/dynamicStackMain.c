#include <stdio.h>
#include "pilhaDinamica.h"

int main() {
    Pilha p;

    cria_pilha(&p);

    insere_pilha(&p, 'A');
    insere_pilha(&p, 'B');
    insere_pilha(&p, 'C');

    printf("Topo: %c\n", elemTopo(&p));

    printf("Removido: %c\n", remove_pilha(&p));
    printf("Removido: %c\n", remove_pilha(&p));

    printf("Topo agora: %c\n", elemTopo(&p));

    libera_pilha(&p);

    return 0;
}
