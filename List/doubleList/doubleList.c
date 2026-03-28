#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"

/* Inicializa */
void cria(Lista *p_l) {
    *p_l = NULL;
}

/* Verifica se está vazia */
int vazia(Lista *p_l) {
    return (*p_l == NULL);
}

/* Insere no início */
void insere_inicio(Lista *p_l, elem_t e) {
    No_lista *novo = (No_lista*) malloc(sizeof(No_lista));

    novo->info = e;
    novo->ant = NULL;
    novo->prox = *p_l;

    if (*p_l != NULL) {
        (*p_l)->ant = novo;
    }

    *p_l = novo;
}

/* Insere no fim */
void insere_fim(Lista *p_l, elem_t e) {
    No_lista *novo = (No_lista*) malloc(sizeof(No_lista));
    novo->info = e;
    novo->prox = NULL;

    if (*p_l == NULL) {
        novo->ant = NULL;
        *p_l = novo;
        return;
    }

    No_lista *aux = *p_l;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = novo;
    novo->ant = aux;
}

/* Verifica se ordenada */
int ordenada(Lista *p_l) {
    if (*p_l == NULL) return 1;

    No_lista *aux = *p_l;

    while (aux->prox != NULL) {
        if (aux->info > aux->prox->info) return 0;
        aux = aux->prox;
    }

    return 1;
}

/* Insere ordenado */
int insere_ordenado(Lista *p_l, elem_t e) {
    No_lista *novo = (No_lista*) malloc(sizeof(No_lista));
    novo->info = e;

    if (*p_l == NULL) {
        novo->prox = NULL;
        novo->ant = NULL;
        *p_l = novo;
        return 1;
    }

    No_lista *aux = *p_l;

    while (aux != NULL && aux->info < e) {
        aux = aux->prox;
    }

    // duplicado
    if (aux != NULL && aux->info == e) {
        free(novo);
        return 0;
    }

    // inserir no início
    if (aux == *p_l) {
        novo->ant = NULL;
        novo->prox = *p_l;
        (*p_l)->ant = novo;
        *p_l = novo;
        return 1;
    }

    // inserir no fim
    if (aux == NULL) {
        No_lista *ultimo = *p_l;
        while (ultimo->prox != NULL) {
            ultimo = ultimo->prox;
        }

        ultimo->prox = novo;
        novo->ant = ultimo;
        novo->prox = NULL;
        return 1;
    }

    // inserir no meio
    novo->prox = aux;
    novo->ant = aux->ant;

    aux->ant->prox = novo;
    aux->ant = novo;

    return 1;
}

/* Ordena (Bubble simples) */
void ordena(Lista *p_l) {
    if (*p_l == NULL) return;

    int trocou;
    do {
        trocou = 0;
        No_lista *aux = *p_l;

        while (aux->prox != NULL) {
            if (aux->info > aux->prox->info) {
                int temp = aux->info;
                aux->info = aux->prox->info;
                aux->prox->info = temp;
                trocou = 1;
            }
            aux = aux->prox;
        }
    } while (trocou);
}

/* Remove início */
int remove_inicio(Lista *p_l, elem_t *p_e) {
    if (*p_l == NULL) return 0;

    No_lista *rem = *p_l;
    *p_e = rem->info;

    *p_l = rem->prox;

    if (*p_l != NULL) {
        (*p_l)->ant = NULL;
    }

    free(rem);
    return 1;
}

/* Remove fim */
int remove_fim(Lista *p_l, elem_t *p_e) {
    if (*p_l == NULL) return 0;

    No_lista *aux = *p_l;

    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    *p_e = aux->info;

    if (aux->ant != NULL) {
        aux->ant->prox = NULL;
    } else {
        *p_l = NULL;
    }

    free(aux);
    return 1;
}

/* Remove valor */
int remove_valor(Lista *p_l, elem_t e) {
    No_lista *aux = *p_l;

    while (aux != NULL && aux->info != e) {
        aux = aux->prox;
    }

    if (aux == NULL) return 0;

    if (aux->ant != NULL) {
        aux->ant->prox = aux->prox;
    } else {
        *p_l = aux->prox;
    }

    if (aux->prox != NULL) {
        aux->prox->ant = aux->ant;
    }

    free(aux);
    return 1;
}

/* Inverte lista */
void inverte(Lista *p_l) {
    No_lista *aux = *p_l;
    No_lista *temp = NULL;

    while (aux != NULL) {
        temp = aux->ant;
        aux->ant = aux->prox;
        aux->prox = temp;
        aux = aux->ant;
    }

    if (temp != NULL) {
        *p_l = temp->ant;
    }
}

/* Libera lista */
void libera(Lista *p_l) {
    No_lista *aux = *p_l;

    while (aux != NULL) {
        No_lista *temp = aux;
        aux = aux->prox;
        free(temp);
    }

    *p_l = NULL;
}

/* Exibe lista */
void exibe(Lista *p_l) {
    No_lista *aux = *p_l;

    while (aux != NULL) {
        printf("%d <-> ", aux->info);
        aux = aux->prox;
    }

    printf("NULL\n");
}
