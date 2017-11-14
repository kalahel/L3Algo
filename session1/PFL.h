#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED
#include <malloc.h>
#include <stdio.h>
#define  N   100
typedef int Element;
typedef struct Cellule{
        Element Valeur;
        struct Cellule *Suivant;
        }*Pile;
typedef struct{
        Element F[N];
        int Tete,Queue;
        int Taille;
}File;
typedef struct Noeud{
        Element Valeur;
        struct Noeud *Suivant, *Predecesseur;
        }*Liste;

Pile Creer_Pile(void);
Pile Empiler(Pile,Element);
Pile Depiler(Pile);
Element Sommet(Pile);
int Pile_Vide(Pile);
File Creer_File(void);
File Enfiler(File,Element);
File Defiler(File);
Element Premier(File);
int File_Vide(File);
int File_Pleine(File);
Liste Creer_Liste(void);
Liste Ajouter_Tete(Liste, Element);
Liste Ajouter_Queue(Liste,Element);
Liste Supp_Tete(Liste);
Element Tete_Liste(Liste);
int Liste_Vide(Liste);

Pile Creer_Pile(void){
    return NULL;
}
Pile Empiler(Pile P,Element e){
Pile P1=(Pile)malloc(sizeof(*P1));
     P1->Valeur=e;
     P1->Suivant=P;
     return P1;
}
Pile Depiler(Pile P){
Pile P1;
     if (!Pile_Vide(P)){
        P1=P;
        P=P->Suivant;
        free(P1);
     }
     return P;
}
Element Sommet(Pile P){
    return P->Valeur;
}
int Pile_Vide(Pile P){
    return P==NULL;
}
File Creer_File(void){
File FF;
     FF.Tete=FF.Queue=0;
     FF.Taille=0;
     return FF;
}
File Enfiler(File F,Element e){
if (!File_Pleine(F)){
    F.F[F.Queue]=e;
    F.Queue=(F.Queue +1) % N ;
    F.Taille++;
}
return (F);
}
File Defiler(File F){
if (!File_Vide(F)){
    F.Tete=(F.Tete+1) % N;
    F.Taille--;
}
return (F);
}
Element Premier(File F){
return F.F[F.Tete];
}
int File_Vide(File F){return (F.Taille==0);}
int File_Pleine(File F){return (F.Taille==N);}

Liste Creer_Liste(void){
return NULL;
}
Liste Ajouter_Tete(Liste L, Element e){
Liste L1=(Liste)malloc(sizeof(Liste));
      L1->Valeur=e;
      L1->Suivant=L;
      return L1;
}

Liste Ajouter_Queue(Liste L, Element e){
      if (Liste_Vide(L)){
        L=(Liste)malloc(sizeof(Liste));
        L->Valeur=e;
        L->Suivant=NULL;
      }
      else
        L->Suivant=Ajouter_Queue(L->Suivant,e);
    return L;
}

Liste Supp_Tete(Liste L){
Liste L1=L->Suivant;
      free(L);
      return L1;
}

Element Tete_Liste(Liste L){
return L->Valeur;
}

int Liste_Vide(Liste L){
return L==NULL;
}

int Evaluer(char tab[],int *i);
Pile Traiter(Pile p, char tab[], int *i);
Pile Operer(Pile p, char tab[], int *i);

#endif // PILE_H_INCL
