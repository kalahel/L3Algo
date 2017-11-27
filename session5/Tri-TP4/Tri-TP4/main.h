#include <stdio.h>
#include <stdlib.h>
#define taille_tab 25
#include <time.h>

//Fonctions de base

void switch_number(int *a,int *b);
void switch_number(int *a,int *b){
    int echange = *a;
    *a = *b;
    *b = echange;
}

int checksize(int *tab,int sizetab);
int checksize(int tab[],int siz){
    return  siz / sizeof tab;
}

void afficheTab(int *tab,int sizetab);
void afficheTab(int *tab,int sizetab){
    int i=0;
    printf("Tableau de %d Elements : ",sizetab);
    for(i=0;i<sizetab;i++){
        if(i==sizetab-1){
            printf("%d",tab[i]);
        }

        else{
            printf("%d -- ",tab[i]);
        }
    }
    printf("\n");
}

void InsertTab(int *tab,int sizetab,int key){
    if(sizetab != taille_tab){
        tab[sizetab]=key;
        printf("The element '%d' has been add to the array\n",key);
    }
    else{
        printf("The array is full");
    }
}

int SuppressTab(int *tab,int sizetab,int key){
    if(sizetab == 0){
        printf("The array is already empty !\n");
        return 0;
    }

    int i;
    for(i=0;i<sizetab;i++){
        if(key == tab[i]){
                printf("The element '%d' has been delete of the array\n",key);
                for(i;i<sizetab-1;i++){
                    tab[i] = tab[i+1];
                }
                free(tab[i]);
                return 1;
        }
    }

    printf("The element '%d' was not in the array\n",key);
    return 0;
}

void CleanTab(int *tab,int sizetab){
   int i;
    for(i=sizetab-1;i<=0;i--){
        printf("The element '%d' has been delete of the array\n",tab[i]);
        free(tab[i]);
    }
    printf("\nThe Array is now empty\n");
}

void AutoTab(int *tab,int sizetab){
    if(sizetab == taille_tab) printf("The array is already full !\n");
    else{
        int i;
        int random;
        srand(time(NULL));
        for(i=sizetab;i<taille_tab;i++){
            random = rand();
            tab[i] = random;
            printf("The element '%d' has been add of the array\n",tab[i]);
        }
    }
}



/////////////////////////////////////////////////////////////////////
/////////////////////TRI INSERTION///////////////////////////////////
/////////////////////////////////////////////////////////////////////







/**
    tab : le tableau
    sizetab : la taille du tableau
    on : boolean, 1 pour afficher les etapes
*/
void triInsert(int *tab,int sizetab,int on);
void triInsert(int *tab,int sizetab,int on){
    int i;
    for(i=0;i<sizetab-1;i++){

        if(on == 1)printf("Emplacements %d <-> %d  ;  %d --- %d\n",i,i+1,tab[i],tab[i+1]);

        if(tab[i]>tab[i+1]){
            switch_number(&tab[i],&tab[i+1]);
            i=-1;
        }
    }
}




//////////////////////////////////////////////////////////////////
/////////////////////TRI FUSION///////////////////////////////////
//////////////////////////////////////////////////////////////////





/**
    tab : le tableau
    start : debut de l'endroit où l'on veut trier (souvent égal à 0)
    sizetab : la taille du tableau - 1 pour eviter l'overflow
    on : boolean, 1 pour afficher les etapes
*/

void fusion(int *tab,int start,int milieu,int sizetab,int on);
void triFusion(int *tab,int start,int sizetab,int on);
void triFusion(int *tab,int start,int sizetab,int on){
    if(start<sizetab){
        int milieu = start+(sizetab - start)/2;
        //printf("tableau de gauche : ");
        //afficheTab(tab,sizetab+1);
        triFusion(tab,start,milieu,on);

        //printf("tableau de droite : ");
        //afficheTab(tab,sizetab);

        triFusion(tab,milieu+1,sizetab,on);
        fusion(tab,start,milieu,sizetab,on);
    }
}

void fusion(int *tab,int start,int milieu,int sizetab,int on){

    /**
        i : parseur gauche
        j : parseur droite
        k : parseur tableau initial
    */

    int i,j,k;

    int dim_gauche=milieu-start+1;
    int dim_droite=sizetab-milieu;

    int left[dim_gauche],right[dim_droite];

    for(i=0;i<dim_gauche;i++){
        left[i]=tab[start+i];
    }
    for(j=0;j<dim_droite;j++){
        right[j]=tab[milieu+1+j];
    }

    if(on == 1){
        printf("tableau de gauche : \n");
        afficheTab(left,i);

        printf("tableau de droite : \n");
        afficheTab(right,j);
    }

    i=0;
    j=0;
    k=start;

    while(i<dim_gauche && j<dim_droite){
        if(on ==1)printf ("min(%d,%d)? ==>",left[i],right[j]);
        if(left[i] <= right[j]){
            tab[k] = left[i];
            i++;
        }
        else{
            tab[k]=right[j];
            j++;
        }
        if(on==1)printf("%d\n",tab[k]);
        k++;
    }

    while(i<dim_gauche){
        tab[k]=left[i];
        i++;
        k++;
    }

    while(j<dim_droite){
        tab[k]=right[j];
        j++;
        k++;
    }
}



//////////////////////////////////////////////////////////////////
/////////////////////TRI RAPIDE///////////////////////////////////
//////////////////////////////////////////////////////////////////



/**
    tab : tableau voulant etre trie
    start : indice du debut du tableau
    sizetab: indice de la fin du tableau (donc la taille -1)
    sizetab2 : nombre d'elements dans le tableau
    on : boolean, 1 pour afficher les details, 0 pour juste trier et afficher le resultat
*/

int partitio(int *tab,int start,int sizetab,int sizetab2,int on);
void Quicksort(int *tab,int start,int sizetab,int sizetab2,int on);
void Quicksort(int *tab,int start,int sizetab,int sizetab2,int on){

    if(start<sizetab){
        int index_pivot = partitio(tab,start,sizetab,sizetab2,on);

        Quicksort(tab,start,index_pivot-1,sizetab2,on);
        Quicksort(tab,index_pivot+1,sizetab,sizetab2,on);
    }
}

int partitio(int *tab,int start,int sizetab,int sizetab2,int on){
    int i=start-1;
    int j=start;

    int index_pivot = sizetab;
    int pivot = tab[index_pivot];

    if(on == 1){
        printf("-----------------------------------------------------------");
        printf("\npivot  : %d\n",pivot);
    }

    while(j != index_pivot){
            if(on == 1)printf("%d < %d ? ===>",tab[j],pivot);
        if(tab[j] < pivot){
            i++;
            if(on == 1)printf("Oui donc : Emplacements %d <-> %d  ;  %d <---> %d\n",i,j,tab[i],tab[j]);
            switch_number(&tab[i],&tab[j]);
        }
        else{
             if(on == 1)printf(" Non\n");
        }
        j++;
    }
    if(on == 1)printf("donc : Emplacements %d <-> %d  ;  %d <---> %d\n\n",i+1,j,tab[i+1],tab[j]);

    switch_number(&tab[i+1],&tab[index_pivot]);

    if(on == 1){
        printf("index trouve pour le pivot : %d\n",i+1);
        printf("tableau actuel trie : ");
        afficheTab(tab+start,sizetab);
        printf("tableau complet : ");
        afficheTab(tab,sizetab2);
    }
    return i+1;
}

//////////////////////////////////////////////////////////////////
/////////////////////TRI PAR TAS//////////////////////////////////
//////////////////////////////////////////////////////////////////
