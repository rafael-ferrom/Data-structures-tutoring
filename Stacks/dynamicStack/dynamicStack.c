#include <stdio.h>
#include <stdlib.h>
#include "pilhaDinamica.h"

/* Inicializa */
void cria_pilha(Pilha *ps) {
    *ps = NULL;
}

/* Verifica se vazia */
int pilha_vazia(Pilha *ps) {
    return (*ps == NULL);
}

/* Pilha dinâmica NÃO tem limite fixo */
int pilha_cheia(Pilha *ps) {
    return 0; // nunca "cheia" (a menos que acabe memória)
}

/* Push */
int insere_pilha(Pilha *ps, elem_t x) {
    No_lista *novo = (No_lista*) malloc(sizeof(No_lista));

    if (novo == NULL) {
        printf("Erro: falta de memória!\n");
        return 0;
    }

    novo->info = x;
    novo->prox = *ps;

    *ps = novo;

    return 1;
}

/* Pop */
elem_t remove_pilha(Pilha *ps) {
    if (pilha_vazia(ps)) {
        printf("Erro: pilha vazia!\n");
        return '\0'; // valor de erro
    }

    No_lista *rem = *ps;
    elem_t valor = rem->info;

    *ps = rem->prox;

    free(rem);

    return valor;
}

/* Libera pilha */
void libera_pilha(Pilha *ps) {
    No_lista *aux = *ps;

    while (aux != NULL) {
        No_lista *temp = aux;
        aux = aux->prox;
        free(temp);
    }

    *ps = NULL;
}

/* Topo */
elem_t elemTopo(Pilha *ps) {
    if (pilha_vazia(ps)) {
        printf("Erro: pilha vazia!\n");
        return '\0';
    }

    return (*ps)->info;
}
