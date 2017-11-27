#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <math.h>
#include <time.h>
#include "B-arbre.h"
#define taille_tab 25

int main()
{
    // la fonction "checksize(tab,sizeof(tab))" renvoie le nombre d'éléments du tableau tab

    printf("\t\t///////////////////////////////////////////////////\n");
    printf("\t\t/////////////////////TRI-TP4///////////////////////\n");
    printf("\t\t///////////////////////////////////////////////////\n\n\n");

    int choix;
    int tab[taille_tab];
    int compteur = 0;

    while(1){
        printf("What do you want to do?\n\n");
        printf("1 : Insert an element\n");
        printf("2 : Delete an element\n");
        printf("3 : Show the current array\n");
        printf("4 : Sort the array\n");
        printf("5 : Clean the array\n");
        printf("6 : AUTO-TAB\n");
        printf("7 : Exit\n\n");

        scanf("%d",&choix);
        switch(choix){
        case 1:
            printf("Which element do you want to add?\n");
            scanf("%d",&choix);
            InsertTab(tab,compteur,choix);
            compteur++;
            break;
        case 2:
            printf("Which element do you want to delete?\n");
            scanf("%d",&choix);
            choix = SuppressTab(tab,compteur,choix);
            if (choix == 1) compteur --;
            break;
        case 3:
            afficheTab(tab,compteur);
            break;
        case 4:
            SortMenu(tab,compteur);
            break;
        case 5:
            CleanTab(tab,compteur);
            compteur = 0;
            break;
        case 6:
            AutoTab(tab,compteur);
            compteur = taille_tab;
            break;
        case 7:
            printf("\t\t///////////////////////////////////////////////////\n");
            printf("\t\t/////////////////////////END///////////////////////\n");
            printf("\t\t///////////////////////////////////////////////////\n\n\n");
            return 0;
            break;
        }
        printf("\n-------------------------\n");
    }
}


void SortMenu(int *tab,int compteur){
        printf("Choose a sorting algorithm\n\n");
        printf("1 : Tri par insertion\n");
        printf("2 : Tri Fusion\n");
        printf("3 : Tri Rapide\n");
        printf("4 : Exit\n\n");

        int choix;
        scanf("%d",&choix);

        switch(choix){
        case 1:
            printf("Press '1' if you want the details, ortherwise press 0\n");
            scanf("%d",&choix);
            if(choix == 1) triInsert(tab,compteur,1);
            else           triInsert(tab,compteur,0);
            break;
        case 2:
            printf("Press '1' if you want the details, ortherwise press 0\n");
            scanf("%d",&choix);
            if(choix == 1) triFusion(tab,0,compteur-1,1);
            else           triFusion(tab,0,compteur-1,0);
            break;
        case 3:
            printf("Press '1' if you want the details, ortherwise press 0\n");
            scanf("%d",&choix);
            if(choix == 1) Quicksort(tab,0,compteur-1,compteur,1);
            else           Quicksort(tab,0,compteur-1,compteur,0);
            break;
        case 4:
            SortMenu(tab,compteur);
            break;
        }
}






