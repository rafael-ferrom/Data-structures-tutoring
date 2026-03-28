#include <stdio.h>
#include <stdlib.h>
#include "lista_dinamica.h"

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
    novo->prox = *p_l;

    *p_l = novo;
}

/* Insere no fim */
void insere_fim(Lista *p_l, elem_t e) {
    No_lista *novo = (No_lista*) malloc(sizeof(No_lista));
    novo->info = e;
    novo->prox = NULL;

    if (*p_l == NULL) {
        *p_l = novo;
        return;
    }

    No_lista *aux = *p_l;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = novo;
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

    if (*p_l == NULL || (*p_l)->info > e) {
        novo->prox = *p_l;
        *p_l = novo;
        return 1;
    }

    No_lista *aux = *p_l;

    while (aux->prox != NULL && aux->prox->info < e) {
        aux = aux->prox;
    }

    if (aux->prox != NULL && aux->prox->info == e) {
        free(novo);
        return 0;
    }

    novo->prox = aux->prox;
    aux->prox = novo;

    return 1;
}

/* Ordena (Bubble em lista) */
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

/* Remove do início */
int remove_inicio(Lista *p_l, elem_t *p_e) {
    if (*p_l == NULL) return 0;

    No_lista *rem = *p_l;
    *p_e = rem->info;

    *p_l = rem->prox;
    free(rem);

    return 1;
}

/* Remove do fim */
int remove_fim(Lista *p_l, elem_t *p_e) {
    if (*p_l == NULL) return 0;

    No_lista *aux = *p_l;

    if (aux->prox == NULL) {
        *p_e = aux->info;
        free(aux);
        *p_l = NULL;
        return 1;
    }

    while (aux->prox->prox != NULL) {
        aux = aux->prox;
    }

    No_lista *rem = aux->prox;
    *p_e = rem->info;

    aux->prox = NULL;
    free(rem);

    return 1;
}

/* Remove valor */
int remove_valor(Lista *p_l, elem_t e) {
    if (*p_l == NULL) return 0;

    No_lista *aux = *p_l;

    if (aux->info == e) {
        *p_l = aux->prox;
        free(aux);
        return 1;
    }

    while (aux->prox != NULL && aux->prox->info != e) {
        aux = aux->prox;
    }

    if (aux->prox == NULL) return 0;

    No_lista *rem = aux->prox;
    aux->prox = rem->prox;
    free(rem);

    return 1;
}

/* Inverte lista */
void inverte(Lista *p_l) {
    No_lista *ant = NULL;
    No_lista *atual = *p_l;
    No_lista *prox;

    while (atual != NULL) {
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
    }

    *p_l = ant;
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
        printf("%d -> ", aux->info);
        aux = aux->prox;
    }

    printf("NULL\n");
}
