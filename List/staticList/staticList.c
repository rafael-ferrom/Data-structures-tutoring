#include <stdio.h>
#include "lista_estatica.h"

/* Inicializa a lista */
void cria(Lista *p_l) {
    p_l->tam = 0;
}

/* Verifica se a lista está vazia */
int vazia(Lista *p_l) {
    return (p_l->tam == 0);
}

/* Insere no início */
void insere_inicio(Lista *p_l, elem_t e) {
    if (p_l->tam == MAX) {
        printf("Lista cheia!\n");
        return;
    }

    for (int i = p_l->tam; i > 0; i--) {
        p_l->vet[i] = p_l->vet[i - 1];
    }

    p_l->vet[0] = e;
    p_l->tam++;
}

/* Insere no fim */
void insere_fim(Lista *p_l, elem_t e) {
    if (p_l->tam == MAX) {
        printf("Lista cheia!\n");
        return;
    }

    p_l->vet[p_l->tam] = e;
    p_l->tam++;
}

/* Verifica se está ordenada */
int ordenada(Lista *p_l) {
    for (int i = 0; i < p_l->tam - 1; i++) {
        if (p_l->vet[i] > p_l->vet[i + 1]) {
            return 0;
        }
    }
    return 1;
}

/* Insere ordenado */
int insere_ordenado(Lista *p_l, elem_t e) {
    if (p_l->tam == MAX) return 0;

    // verifica duplicado
    for (int i = 0; i < p_l->tam; i++) {
        if (p_l->vet[i] == e) return 0;
    }

    int i = p_l->tam - 1;
    while (i >= 0 && p_l->vet[i] > e) {
        p_l->vet[i + 1] = p_l->vet[i];
        i--;
    }

    p_l->vet[i + 1] = e;
    p_l->tam++;

    return 1;
}

/* Ordena (Bubble Sort simples) */
void ordena(Lista *p_l) {
    for (int i = 0; i < p_l->tam - 1; i++) {
        for (int j = 0; j < p_l->tam - i - 1; j++) {
            if (p_l->vet[j] > p_l->vet[j + 1]) {
                int temp = p_l->vet[j];
                p_l->vet[j] = p_l->vet[j + 1];
                p_l->vet[j + 1] = temp;
            }
        }
    }
}

/* Remove do início */
int remove_inicio(Lista *p_l, elem_t *p_e) {
    if (vazia(p_l)) return 0;

    *p_e = p_l->vet[0];

    for (int i = 0; i < p_l->tam - 1; i++) {
        p_l->vet[i] = p_l->vet[i + 1];
    }

    p_l->tam--;
    return 1;
}

/* Remove do fim */
int remove_fim(Lista *p_l, elem_t *p_e) {
    if (vazia(p_l)) return 0;

    *p_e = p_l->vet[p_l->tam - 1];
    p_l->tam--;

    return 1;
}

/* Remove valor específico */
int remove_valor(Lista *p_l, elem_t e) {
    int pos = -1;

    for (int i = 0; i < p_l->tam; i++) {
        if (p_l->vet[i] == e) {
            pos = i;
            break;
        }
    }

    if (pos == -1) return 0;

    for (int i = pos; i < p_l->tam - 1; i++) {
        p_l->vet[i] = p_l->vet[i + 1];
    }

    p_l->tam--;
    return 1;
}

/* Inverte a lista */
void inverte(Lista *p_l) {
    int i = 0, j = p_l->tam - 1;

    while (i < j) {
        int temp = p_l->vet[i];
        p_l->vet[i] = p_l->vet[j];
        p_l->vet[j] = temp;

        i++;
        j--;
    }
}

/* Libera lista */
void libera(Lista *p_l) {
    p_l->tam = 0;
}

/* Exibe lista */
void exibe(Lista *p_l) {
    for (int i = 0; i < p_l->tam; i++) {
        printf("%d ", p_l->vet[i]);
    }
    printf("\n");
}
