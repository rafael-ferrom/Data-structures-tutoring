#include <stdio.h>
#include <stdlib.h>
#include "graphList.h"

void initGrafoLista(GrafoLista *g, int n) {
    g->n = n;

    for (int i = 0; i < n; i++)
        g->lista[i] = NULL;
}

void adicionaArestaLista(GrafoLista *g, int v1, int v2) {

    No *novo = (No*) malloc(sizeof(No));

    novo->vertice = v2;
    novo->prox = g->lista[v1];
    g->lista[v1] = novo;

    novo = (No*) malloc(sizeof(No));

    novo->vertice = v1;
    novo->prox = g->lista[v2];
    g->lista[v2] = novo;
}

void imprimeLista(GrafoLista *g) {

    printf("Lista de Adjacencia:\n");

    for(int i = 0; i < g->n; i++) {

        printf("%d -> ", i);

        No *aux = g->lista[i];

        while(aux != NULL) {
            printf("%d ", aux->vertice);
            aux = aux->prox;
        }

        printf("\n");
    }
}

void dfsLista(GrafoLista *g, int v, int visitado[]) {

    visitado[v] = 1;

    printf("%d ", v);

    No *aux = g->lista[v];

    while(aux != NULL) {

        if(!visitado[aux->vertice])
            dfsLista(g, aux->vertice, visitado);

        aux = aux->prox;
    }
}

void bfsLista(GrafoLista *g, int inicio) {

    int fila[MAX];
    int ini = 0;
    int fim = 0;

    int visitado[MAX] = {0};

    fila[fim++] = inicio;
    visitado[inicio] = 1;

    while(ini < fim) {

        int v = fila[ini++];

        printf("%d ", v);

        No *aux = g->lista[v];

        while(aux != NULL) {

            if(!visitado[aux->vertice]) {

                visitado[aux->vertice] = 1;
                fila[fim++] = aux->vertice;
            }

            aux = aux->prox;
        }
    }
}