#include <stdio.h>
#include <unistd.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "PFL.h"

#define BUFFER_SIZE 64

typedef int Element;

// TODO Faire un programme utilisant PFL.h pour manipuler des files, sans calcul

void print_str(char *str) {
  int i = 0;
  while (str[i])
    putchar(str[i++]);
}

char* show_menu() {
  char buffer[BUFFER_SIZE];
  char *buf = malloc(sizeof(char) * BUFFER_SIZE);
  int c = 0;

  print_str("Veuillez saisir une expression a evaluer\n[Exemple : 31 195+17 3\%*]\n");
  c = read(0, buf, BUFFER_SIZE - 1);
  if (c) {
    buf[strlen(buf) - 1] = '\0';
    return buf;
  }
  else
    return NULL;
}

int main(){
  char *expr;
  expr = show_menu();
  if (!strlen(expr)) {
    perror("No expression\n");
    exit(1);
  }

  int indice = 0;
  int *i = &indice;

  Pile p = Creer_Pile();
  p = Traiter(p, expr, i);
  printf("Etape finale\nLa valeur restante dans la pile est : %d\n", Sommet(p));

  free(expr);
  return 0;
}

/**
 *   Convertit une chaine de caractère en une valeur entière
 *   et la retourne.
 */
int Evaluer(char tab[],int *i){
  int x = 0;
  while(tab[*i] >= '0' && tab[*i] <= '9'){
    x = x * 10;
    x = x + tab[*i] - '0';
    (*i)++;
  }
  return (x);
}

/**
 * Traitera un tableau statique de char
 */
Pile Traiter(Pile p, char tab[], int *i){
  while(*(i) < strlen(tab)){
    if(tab[*i] <= '9' && tab[*i] >= '0')
      p = Empiler(p, Evaluer(tab,i));
    else if (tab[*i] == ' ') {
      (*i)++;
      printf("Espace detecte, indice : %d\n",*i);
    }
    else if (tab[*i] == '+' || tab[*i] == '-'|| tab[*i] == '*'|| tab[*i] == '%')
      p = Operer(p,tab,i); // !!!!
    else {
      printf("ERREUR DE CARACTERE\n");
      exit(1);
    }
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
