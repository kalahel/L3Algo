#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "PFL.h"
typedef int Element;
/*
  typedef struct Cell{
  Element value;
  struct Cell * Next;
  }*Pile;

  Pile Creer_pile();
  Pile Empiler(Pile p, Element x);
  Pile Depiler(Pile p);
  Element Sommet(Pile p);
  int Pile_Vide(Pile p);*/
int Evaluer(char tab[],int *i);
Pile Traiter(Pile p, char tab[], int *i);
Pile Operer(Pile p, char tab[], int *i);
/*
  Pile Creer_Pile(void){
  return NULL;
  }
  Pile Empiler(Pile P,Element x){
  Pile P1=(Pile)malloc(sizeof(*P1));
  P1->value=x;
  P1->Next=P;
  return P1;
  }
  Pile Depiler(Pile P){
  Pile P1;
  if (!Pile_Vide(P)){
  P1=P;
  P=P->Next;
  free(P1);
  }
  return P;
  }*/
int main(){
  //printf("Etape 1\n");

  char expression[] = "31 195+17 3%*";
  int indice = 0;
  int *i = &indice;
  //printf("Etape 2\n");

  Pile p = Creer_Pile();
  //printf("Etape 3\n");

  p = Traiter(p, expression, i);
  printf("Etape finale\n");

  printf("la valeur restante dans la pile est : %d\n", Sommet(p));
  return 0;
}

/**
 *   Convertit une chaine de caractère en une valeur entière
 *   et la retourne.
 */
int Evaluer(char tab[],int *i){
  //printf("Etape Evaluer 1\n");
  
  int x = 0;
  while(tab[*i] >= '0' && tab[*i] <= '9'){
    //printf("Etape Evaluer 2\n");
    x = x * 10;
    x = x + tab[*i] - '0';
    (*i)++;
    //printf("Valeur de x : %d, valeur indice : %d\n",x,*i);    }
  //printf("Etape Evaluer 3\n");

  return (x);
}
/**
 *   Traitera un tableau statique de char
 */
Pile Traiter(Pile p, char tab[], int *i){
  //printf("Etape 4\n");

  while(*i <  strlen (tab)){
    //printf("Etape %d\n", 5 + *i);

    if(tab[*i] <= '9' && tab[*i] >= '0'){
      p = Empiler(p, Evaluer(tab,i));
    }
    else if (tab[*i] == ' '){            (*i)++;
      printf("Espace detecte, indice : %d\n",*i);
    }
    else if (tab[*i] == '+' || tab[*i] == '-'|| tab[*i] == '*'|| tab[*i] == '%')
      p = Operer(p,tab,i); // !!!!
    else
      printf("ERREUR DE CARACTERE");
  }
  return p;
}
Pile Operer(Pile p, char tab[], int *i){
  int val1,val2;
  val1 = Sommet(p);
  p = Depiler(p);
  val2 = Sommet(p);
  p = Depiler(p);
  printf("val1 : %d , val2 : %d \n",val1,val2);
  
  switch (tab[*i]){
  case '+':
    p = Empiler(p, val1 + val2);
    printf("%d + %d \n",val1,val2);
    break;

  case '-':
    p = Empiler(p, val2 - val1); // !!! A vérifier
    printf("%d - %d \n",val2,val1);
    break;

  case '*':
    p = Empiler(p, val1 * val2);
    printf("%d * %d \n",val1,val2);
    break;

  case '%':
    p = Empiler(p, val2 % val1);
    printf("%d /R %d \n",val2,val1);

    break;
  }
  (*i)++;
  return p;
}

