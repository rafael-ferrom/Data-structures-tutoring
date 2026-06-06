#ifndef GRAFOLISTA_H
#define GRAFOLISTA_H

#define MAX 10

typedef struct No {
    int vertice;
    struct No *prox;
} No;

typedef struct {
    int n;
    No *lista[MAX];
} GrafoLista;

/* Operações básicas */
void initGrafoLista(GrafoLista *g, int n);
void adicionaArestaLista(GrafoLista *g, int v1, int v2);
void imprimeLista(GrafoLista *g);

/* Algoritmos */
void dfsLista(GrafoLista *g, int v, int visitado[]);
void bfsLista(GrafoLista *g, int inicio);

#endif