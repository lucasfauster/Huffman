#include "TLSE.h"

TLSE* inserel(TLSE *l, TLSE *novo){
  novo->prox = l;
  return novo;
}

TLSE * ins(TLSE * l,TLSE * novo){
  TLSE * new = (TLSE *) malloc(sizeof(TLSE));
  new->no = novo->no;
  new->prox = l;
  return new;
}

TLSE * insere(TLSE * l, TLSE * novo){
  TLSE * p = l;
  while(l->prox){
    l = l->prox;
  }
  l->prox = novo;
  return p;
}

TLSE* removeprimeiro(TLSE *l){
  TLSE *lixo = (TLSE*)malloc(sizeof(TLSE));
  lixo = l;
  l = l->prox;
  free(lixo);
  return l;
}

void imprimel(TLSE *l){
  TLSE *p = l;
  while(p){
    printf("%c\n", p->no->letra[0]);
    p = p->prox;
  } 
}

void liberal(TLSE *l){
  TLSE *p = l, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
  } 
}

TLSE *inverte( TLSE *l) {
  TLSE *nova = NULL;
  TLSE *p = l;
  while(p){
    nova = ins(nova, p);
    p = p->prox;
  }
  return nova;
}

TLSE* retiral(TLSE *l, TLSE * elem){
  TLSE *p = l, *ant = NULL;
  while((p) && (p->no != elem->no)){
    ant = p;
    p = p->prox;
  }
  if(!p) return l;
  if(!ant) l = l->prox;
  else ant->prox = p->prox;
  free(p);
  return l;
}

TLSE* buscal(TLSE *l, int elem){
  TLSE *p = l;
  while((p) && (*p->no->letra != elem)) p = p->prox; 
  return p;
}