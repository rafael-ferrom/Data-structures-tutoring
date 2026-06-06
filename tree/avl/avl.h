#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    int fb;
    struct no *esq, *dir;
} No;

typedef No* Arvore;

void cria_arvore(Arvore *p);

int altura(Arvore p);

void inorder(Arvore p);

int verifica_AVL(Arvore p);

void LL(Arvore *p);
void RR(Arvore *p);
void LR(Arvore *p);
void RL(Arvore *p);

int busca(Arvore p, int chave);

int n_rec_busca(Arvore p, int chave);

int insere(Arvore *p, int chave);

int n_rec_insere(Arvore *p, int chave);

int remove_arv(Arvore *p, int chave);

int verifica_busca(Arvore p);

#endif