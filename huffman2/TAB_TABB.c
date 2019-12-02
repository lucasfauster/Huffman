#include "TAB_TABB.h"

void libera_ab(TAB* t){
  if(t){
  libera_ab(t->filho0);
  libera_ab(t->filho1);
  free(t);
  }
}

TAB* busca_abb(int e, TAB* t){
  if(!t) return NULL;
  if(e < t->letra[0]) return busca_abb(e, t->filho0);
  if(e > t->letra[0]) return busca_abb(e, t->filho1);
  return t;
}

TAB* busca_ab(int e, TAB* t){
  if((!t) || (t->letra[0] == e)) return t;
  TAB *resp = busca_ab(e, t->filho0);
  if(resp) return resp;
  return busca_ab(e, t->filho1);
}

void imprime_aux(TAB* a, int andar){
  if(a){
    int j;
    imprime_aux(a->filho0, andar + 1);
    for(j = 0; j <= andar; j++) printf("   ");
    for(int i = 0; i < a->tam; i++){
      printf("%c",(char) a->letra[i]);
    }
    printf("\n");
    imprime_aux(a->filho1, andar + 1);
  }
}

void imprime_ab(TAB* a){
  imprime_aux(a, 1);
}

TAB* cria_no(int c, int tam, float f, int v, int m, TAB* e, TAB* d){
  TAB* a = (TAB*) malloc(sizeof(TAB));
  a->letra[0] = c;
  a->tam = tam;
  a->freq = f;
  a->vogal = v;
  a->caps = m;
  a->filho0 = e;
  a->filho1 = d;
  return a;
}

TAB* insere_abb(TAB* t, int tam, int c, float f, int v, int m, TAB* e, TAB* d){
  if(!t) t = cria_no(c, tam, f, v, m, e, d);
  else if(f > t->freq) t->filho0 = insere_abb
  (t->filho0, c, tam, f,v, m , e, d);
  else if(f < t->freq) t->filho1 = insere_abb(t->filho0, c, tam, f,v, m , e, d);
  return t;
}

TAB* retira_abb(int e, TAB *t){
  if(!t) return t;
  else if(e < t->letra[0]) t->filho0 = retira_abb(e, t->filho0);
  else if(e > t->letra[0]) t->filho1 = retira_abb(e, t->filho1);
  else{
    if((!t->filho0) && (!t->filho1)){
      free(t);
      t = NULL;
    }
    else if((!t->filho0) || (!t->filho1)){
      TAB *q = t;
      if(!t->filho1) t = t->filho0;
      else t = t->filho1;
      free(q); 
    }
    else{
      TAB *f = t->filho0;
      while(f->filho1) f = f->filho1;
      t->letra[0] = f->letra[0];
      f->letra[0] = e;
      t->filho0 = retira_abb(e, t->filho0);
    }
  }
  return t;  
}
