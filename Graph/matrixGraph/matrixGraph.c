#include <stdio.h>
#include "matrixGraph.h"

void initGrafoMatriz(GrafoMatriz *g, int n) {

    g->n = n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            g->mat[i][j] = 0;
}

void adicionaArestaMatriz(GrafoMatriz *g, int v1, int v2) {

    g->mat[v1][v2] = 1;
    g->mat[v2][v1] = 1;
}

void imprimeMatriz(GrafoMatriz *g) {

    printf("Matriz de Adjacencia:\n");

    for(int i = 0; i < g->n; i++) {

        for(int j = 0; j < g->n; j++) {
            printf("%d ", g->mat[i][j]);
        }

        printf("\n");
    }
}

void dfsMatriz(GrafoMatriz *g, int v, int visitado[]) {

    visitado[v] = 1;

    printf("%d ", v);

    for(int i = 0; i < g->n; i++) {

        if(g->mat[v][i] && !visitado[i]) {
            dfsMatriz(g, i, visitado);
        }
    }
}

void bfsMatriz(GrafoMatriz *g, int inicio) {

    int fila[MAX];
    int ini = 0;
    int fim = 0;

    int visitado[MAX] = {0};

    fila[fim++] = inicio;
    visitado[inicio] = 1;

    while(ini < fim) {

        int v = fila[ini++];

        printf("%d ", v);

        for(int i = 0; i < g->n; i++) {

            if(g->mat[v][i] && !visitado[i]) {

                visitado[i] = 1;
                fila[fim++] = i;
            }
        }
    }
}