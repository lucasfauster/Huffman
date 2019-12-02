#include <stdio.h>
#include <stdlib.h>
#include "TAB_TABB.h"

#ifndef TLSE_H
#define TLSE_H

typedef struct lse{
  TAB *no;
  struct lse *prox;
} TLSE;

TLSE * inverte(TLSE * l);
TLSE * insere(TLSE * l, TLSE * novo);
TLSE* inserel(TLSE *l, TLSE *novo);
void imprimel(TLSE *l);
void liberal(TLSE *l);
TLSE* retiral(TLSE *l, TLSE *elem);
TLSE* buscal(TLSE *l, int elem);
TLSE* removeprimeiro(TLSE *l);

#endif