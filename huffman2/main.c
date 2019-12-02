#include <stdio.h>
#include <stdlib.h>
#include "TLSE.h"
#include <string.h>

void menu(){
  printf("\nAperte 1 para codificar uma mensagem");
  printf("\nAperte 2 para decodificar uma mensagem");
  printf("\nAperte 3 para remover as vogais");
}

TLSE* insere_ord(TLSE* lista, TLSE *no){
  if (lista){
  TLSE *L = lista, *aux = NULL;
  if (no->no->freq < lista->no->freq){
    lista = inserel(lista, no);
    return lista;
  }else{
    while (no->no->freq > L->no->freq){
      if (L->prox == NULL){
        L->prox = no;
        return lista;
      }else{
      aux = L;
      L = L->prox;
      }
    } 
    aux->prox = no;
    no->prox = L;
    return lista;
  }
  }else{
  return no;
  }
}

/*void codifica_mensagem(TAB* arvore){
  char frase[80];
  scanf("%s", frase);
  int cont = 0;
  while(frase[cont]!= '\0'){}
      char letra = frase[cont];
      int ascii = letra;
      if (((97 <= ascii) && (ascii<= 122)) || ((65 <= ascii)&& (ascii <= 90))){   //verifica se é caractere, vou conferir se isso ta certo//
        printf("49");
        codifica_caractere2(arvore, frase[cont]);
      }else{
        printf("?");
      }
}

void decodifica_mensagem(TAB* estrutura){
    char *frase;
    scanf("%s", frase);
    TAB *aux = estrutura;
    int tam = strlen(frase);
    for(int i=0; i<strlen(frase); i++){
        if (frase[i] == '?')
            printf("?");
        else if(!aux->filho0 && !aux->filho1){
            printf("%ls", aux->letra);
            aux = estrutura;
        }else{
            if (frase[i] == '0'){
                aux = aux->filho0;
            }else{
                aux = aux->filho1;
            }
        }
    }
    printf("\n");
}

void remove_vogais(TAB* estrutura, TLSE* lista){
  if(estrutura){
    if (estrutura->filho0->vogal == 1){
      if (!estrutura->filho0->filho0 && !estrutura->filho0->filho1){
        TLSE* no = (TLSE*)malloc(sizeof(TLSE));
        no->no = estrutura->filho0;
        estrutura->filho0 = NULL;
        lista = insere_ord(lista, no);
      }
    }
    if (estrutura->filho1->vogal == 1){
      if (!estrutura->filho1->filho0 && !estrutura->filho1->filho1){
        TLSE* no = (TLSE*)malloc(sizeof(TLSE));
        no->no = estrutura->filho1;
        estrutura->filho0 = NULL;
        lista = insere_ord(lista, no);
      }
    }
    remove_vogais(estrutura->filho0, lista);
    remove_vogais(estrutura->filho1, lista);
  }
}

void remove_maiusculas(TAB* estrutura, TLSE* lista){
  if(estrutura){
    if (estrutura->filho0->caps == 1){
      if (!estrutura->filho0->filho0 && !estrutura->filho0->filho1){
        TLSE* no = (TLSE*)malloc(sizeof(TLSE));
        no->no = estrutura->filho0;
        estrutura->filho0 = NULL;
        lista = insere_ord(lista, no);
        
      }
    }
    if (estrutura->filho1->caps == 1){
      if (!estrutura->filho1->filho0 && !estrutura->filho1->filho1){
        TLSE* no = (TLSE*)malloc(sizeof(TLSE));
        no->no = estrutura->filho1;
        estrutura->filho0 = NULL;
        lista = insere_ord(lista, no);
      }
    }
    remove_vogais(estrutura->filho0, lista);
    remove_vogais(estrutura->filho1, lista);
  }
}

TAB* busca_elemento_aux(TAB* estrutura){
  if(estrutura){
    if (!estrutura->filho0 && !estrutura->filho1){
        return estrutura;
    }else{
    busca_elemento_aux(estrutura->filho0);
    busca_elemento_aux(estrutura->filho1);
    }
  }
}

TAB* busca_elemento(TAB* a){
  return busca_elemento_aux(a);
}

void altera_frequencia(TAB* estrutura){
    char elemento = scanf("%c", &elemento);
    float valor = scanf("%f", &valor);
    TAB *aux = busca_elemento(estrutura);
    aux->freq = valor;
}

TAB *Busca(TAB* arvore, char ch){
    if (strcmp(arvore -> letra, &ch) != 0){
        int tam = strlen(arvore->filho0->letra);
        int flag = 0;
        //supondo que os mais frequentes estarao em filho0 //
        for (int i=0; i<tam; i++){
            if (arvore-> filho0 -> letra[i] == ch){
                flag = 1;
                i = tam;
            }
        }
        if (flag == 1){
            Busca(arvore->filho0, ch);
        }else{
            Busca(arvore->filho1, ch);
        }
    }
}

void busca_caracteristica_aux(TAB* estrutura){
  if(estrutura){
    int j;
    if (!estrutura->filho0 && !estrutura->filho1)
        printf("%s ",estrutura->letra);
    }else{
    busca_caracteristica_aux(estrutura->filho0);
    busca_caracteristica_aux(estrutura->filho1);
    }
}

void busca_caracteristica(TAB* a){
  busca_caracteristica_aux(a);
}*/

/*void codifica_caractere2(TAB* estrutura, char elemento){
  if(estrutura){
    if (*estrutura->letra != elemento){
      printf("%ls", estrutura->letra);
          int tam = strlen(estrutura->filho0->letra);
          int flag = 0;
          for (int i=0; i<tam; i++){
            char compara = estrutura->filho0->letra[i];
            if (compara == elemento){  //supondo que os mais frequentes estarao em filho0 //
            flag = 1;
            i = tam;
          }
        }
        if (flag == 1){
            printf("0");
            codifica_caractere2(estrutura->filho0, elemento);
        }else{
            printf("1");
            codifica_caractere2(estrutura->filho1, elemento);
        }
    }
  }
}*/

char * codifica_caractere_aux(TAB * estrutura, char elemento, char * caminho){
  if(estrutura->filho0 != NULL || estrutura->filho1 != NULL){
    int tam = estrutura->filho0->tam;
    int flag = 1;
    //Compara os caracteres do nó com o char a ser codificado
    for (int i=0; i<tam; i++){
      char c[1];
      c[0] = estrutura->letra[i];
      if (c[0] == elemento){
          flag = 0;
          i = tam;
      }
    }
    //Concatena o bit do caminho a ser seguido
    int t = strlen(caminho);
    if (flag == 0){
      caminho = codifica_caractere_aux(estrutura->filho0, elemento, caminho);
      strcat(caminho, "0");
      return caminho;
    }
    caminho = codifica_caractere_aux(estrutura->filho1, elemento, caminho);
    strcat(caminho, "1");
    return caminho;
  }
  return caminho;
}


char * codifica_caractere(TAB* estrutura, char elemento){
  char * caminho = (char *) malloc(100*sizeof(char));
  caminho = codifica_caractere_aux(estrutura, elemento, caminho);
  return caminho;
}

void criptografa(char * entranome, char * sainome, TAB * arv){
  FILE * fi = fopen(entranome, "r");
  FILE * fo = fopen(sainome, "w");
  if(!fi||!fo) exit(1);
  //Jogando as letras numa lista
  int c = fgetc(fi);
  char * codigo;
  while(c != EOF){
    if ((65 <= c && c <= 90) || (97 <= c && c <= 122)){
      char k = (char)c;
      codigo = codifica_caractere(arv, k);
      //joga o código da letra no arquivo de saida
      fprintf(fo, "%s", codigo);
    }else{
      fprintf(fo, "%s", "?");
    }
    c = fgetc(fi);
  }
  free(codigo);
  fclose(fi);
  fclose(fo);
}

TLSE* alfabeto(TLSE *plst, TAB* pn){
       TLSE *aux;
       aux = (TLSE*)malloc(sizeof(TLSE));
       aux -> no = pn;
       aux -> prox = plst;
       return aux;
}

TAB* cria_arvore(TLSE* lista){
  while (lista->prox != NULL){
    TAB *menor1 = lista->no;
    TAB *menor2 = lista->prox->no;
    TAB *acima = (TAB*)malloc(sizeof(TAB));
    int tam = menor1->tam;
    for(int i = 0; i < tam; i++){
      acima->letra[i] = menor1->letra[i];
    }
    for(int i = 0; i < menor2->tam; i++){
      acima->letra[tam] = menor2->letra[i];
      tam++;
    }
    acima->tam = tam;
    acima->freq = menor1->freq + menor2->freq;
    if ((menor1->caps == 1) || (menor2->caps == 1)){
      acima->caps = 1;
    }else{ 
      acima->caps = 0;
    }
    if ((menor1->vogal == 1) || (menor2->vogal == 1)){
      acima->vogal = 1;
    }else{
      acima->vogal = 0;
    }
    acima->filho0 = menor1;
    acima->filho1 = menor2;
    lista = removeprimeiro(lista);
    lista = removeprimeiro(lista);
    TLSE* novomenor = (TLSE*)malloc(sizeof(TLSE));
    novomenor->no = acima;
    novomenor->prox = NULL;
    lista = insere_ord(lista, novomenor);
  }
  return lista->no;
}

/*IMPLEMENTAÇÃO EM LISTA
TLSE * decod(TLSE * lista, TAB * arv){
  if(!lista) return NULL;
  TLSE * li = NULL;
  while(lista){
    TAB * aux = arv;
    while(aux->filho0 != NULL && aux->filho1 != NULL){
      if(lista->no->letra[0] == '1') aux = aux->filho1;
      else if(lista->no->letra[0] == '0') aux = aux->filho0;
      else{
        TLSE * novo = (TLSE *)malloc(sizeof(TLSE));
        novo->no = cria_no('?', 1, 0,0,0,NULL,NULL);
        li = inserel(li, novo);
      }
      lista = lista->prox;
    }
    TLSE * novo = (TLSE *)malloc(sizeof(TLSE));
    novo->no = cria_no(aux->letra[0], 1, 0,0,0,NULL,NULL);
    li = inserel(li, novo);
    lista = lista->prox;
    imprimel(li);
    printf("   \n");
  }
  return li;
}*/

//IMPLEMENTAÇÃO COM PONTEIRO
char * decod(char * vet, TAB * arv, int tam){
  char * saida = (char *) malloc(sizeof(char));
  for(int i = 0; i<tam;){
    TAB * aux = arv;
    while(aux->filho0 != NULL && aux->filho1 != NULL){
      if(vet[i] == '1') aux = aux->filho1;
      else if(vet[i] == '0') aux = aux->filho0;
      else{
        strcat(saida, "?");
      }
      i = i+2;
    }
    char z = (char) arv->letra[0];
    char * p = (char *)malloc(sizeof(char));
    p = &z;
    strcat(saida, p);
    i = i+2;
  }
  printf("%s", saida);
  return saida;
}

void decriptografa(char * entranome, char * sainome, TAB * arv){
  FILE * fi = fopen(entranome, "r");
  FILE * fo = fopen(sainome, "w");
  if(!fi||!fo) exit(1);
  //Jogando as letras numa lista
  int c = fgetc(fi);
  /* IMPLEMENTAÇÃO EM LISTA
  TLSE * codigo = NULL;
  while(c != EOF){
    TLSE * novo = (TLSE *)malloc(sizeof(TLSE));
    novo->no = cria_no(c, 1, 0,0,0,NULL,NULL);
    novo->prox = NULL;
    codigo = inserel(codigo, novo);
    c =fgetc(fi);
  }
  codigo = inverte(codigo);*/
  //IMPLEMENTAÇÃO COM PONTEIRO
  char * vet = (char *)malloc(sizeof(char));
  while(c != EOF){
    char z = (char) c;
    char * p = (char *)malloc(sizeof(char));
    p = &z;
    strcat(vet, p);
    c =fgetc(fi);
  }
  char* dec = decod(vet, arv, strlen(vet));
  for(int v = 0; v<strlen(dec); v++){
    fprintf(fo, "%c", dec[v]);
  }
  fclose(fi);
  fclose(fo);
}

TLSE * remove_vogais (TLSE* lista){
  if(!lista) return NULL;
  TLSE * t = lista;
  while(t){
    if(t->no->vogal == 1){
      //retiral(lista,t);
      t = t->prox;
    }
    else t = t->prox;
  }
  return lista;
}

int main(void){
  int exec = 9;
  FILE *lf = fopen("lfreq.txt", "r");
  TLSE* lista = NULL;
  TAB* no = NULL;
  char l;
  float f;
  int v, m;
  while(!feof(lf)){
    fscanf(lf,"%c %f %d %d\n", &l, &f, &v, &m);
    no = cria_no(l, 1, f, v, m, NULL, NULL);
    lista = alfabeto(lista, no);
  }
  fclose(lf);
  no = cria_arvore(lista);
  imprime_ab(no);
  while (exec != 0){
    if (exec == 9){
      menu();
      printf("\n");
      scanf("%d", &exec);
    }
    if (exec == 1){
      criptografa("texto.txt", "saida.txt", no);
      printf("Criptografou!\n");
      exec = 0;
    }
    if(exec == 2){
      decriptografa("saida.txt", "dec.txt", no);
      printf("Decriptografou!\n");
      exec = 0;
    }
  }
}