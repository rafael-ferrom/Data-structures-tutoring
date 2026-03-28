#include <stdio.h>
#include "pilha.h"

/* Inicializa a pilha */
void cria_pilha(Pilha *ps) {
    ps->topo = -1;
}

/* Verifica se está vazia */
int pilha_vazia(Pilha *ps) {
    return (ps->topo == -1);
}

/* Verifica se está cheia */
int pilha_cheia(Pilha *ps) {
    return (ps->topo == MAXPILHA - 1);
}

/* Insere (push) */
int insere_pilha(Pilha *ps, elem_t x) {
    if (pilha_cheia(ps)) {
        printf("Erro: pilha cheia!\n");
        return 0;
    }

    ps->topo++;
    ps->item[ps->topo] = x;

    return 1;
}

/* Remove (pop) */
elem_t remove_pilha(Pilha *ps) {
    if (pilha_vazia(ps)) {
        printf("Erro: pilha vazia!\n");
        return -1; // valor de erro
    }

    elem_t valor = ps->item[ps->topo];
    ps->topo--;

    return valor;
}

/* Libera pilha */
void libera_pilha(Pilha *ps) {
    ps->topo = -1;
}

/* Retorna topo (sem remover) */
elem_t elemTopo(Pilha *ps) {
    if (pilha_vazia(ps)) {
        printf("Erro: pilha vazia!\n");
        return -1;
    }

    return ps->item[ps->topo];
}
