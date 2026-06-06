#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H

#define MAX 10

typedef struct {

    int n;
    int mat[MAX][MAX];

} GrafoMatriz;

/* Operações básicas */
void initGrafoMatriz(GrafoMatriz *g, int n);
void adicionaArestaMatriz(GrafoMatriz *g, int v1, int v2);
void imprimeMatriz(GrafoMatriz *g);

/* Algoritmos */
void dfsMatriz(GrafoMatriz *g, int v, int visitado[]);
void bfsMatriz(GrafoMatriz *g, int inicio);

#endif