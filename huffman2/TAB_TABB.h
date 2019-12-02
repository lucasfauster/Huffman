#include <stdio.h>
#include <stdlib.h>

#ifndef TAB_TABB_H
#define TAB_TABB_H

typedef struct huffman{
  int letra[100];
  float freq;
  int vogal, caps, tam;
  struct huffman *filho0, *filho1;
}TAB;

TAB* cria_no(int c, int tam, float f, int v, int m, TAB* e, TAB* d);
void imprime_ab(TAB *t);
void libera_ab(TAB* t);
TAB* busca_ab(int e, TAB* t);
TAB* busca_abb(int e, TAB* t);
TAB* insere_abb(TAB* t, int tam, int c, float f, int v, int m, TAB* e, TAB* d);
TAB* retira_abb(int e, TAB *t);

#endif