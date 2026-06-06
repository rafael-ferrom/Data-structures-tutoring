#include <stdio.h>
#include "listGraph/graphList.h"
#include "matrixGraph/matrixGraph.h"

int main(void) {

    int visitado[MAX] = {0};

    /* ===============================
       MATRIZ DE ADJACÊNCIA
       =============================== */

    GrafoMatriz gm;
    initGrafoMatriz(&gm, 6);

    adicionaArestaMatriz(&gm, 0, 1);
    adicionaArestaMatriz(&gm, 0, 2);
    adicionaArestaMatriz(&gm, 1, 3);
    adicionaArestaMatriz(&gm, 2, 3);
    adicionaArestaMatriz(&gm, 3, 4);
    adicionaArestaMatriz(&gm, 4, 5);

    imprimeMatriz(&gm);

    printf("\nDFS (matriz): ");
    dfsMatriz(&gm, 0, visitado);

    printf("\nBFS (matriz): ");
    bfsMatriz(&gm, 0);

    printf("\n\n");

    /* ===============================
       LISTA DE ADJACÊNCIA
       =============================== */

    GrafoLista gl;
    initGrafoLista(&gl, 6);

    adicionaArestaLista(&gl, 0, 1);
    adicionaArestaLista(&gl, 0, 2);
    adicionaArestaLista(&gl, 1, 3);
    adicionaArestaLista(&gl, 2, 3);
    adicionaArestaLista(&gl, 3, 4);
    adicionaArestaLista(&gl, 4, 5);

    imprimeLista(&gl);

    for (int i = 0; i < MAX; i++) visitado[i] = 0;

    printf("\nDFS (lista): ");
    dfsLista(&gl, 0, visitado);

    printf("\nBFS (lista): ");
    bfsLista(&gl, 0);

    return 0;
}