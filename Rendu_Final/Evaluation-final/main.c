#include <stdio.h>
#include <stdlib.h>
#include "b_arbre.h"
#include "tri.h"
#include "avl.h"
#include "Tas_B.h"
#include "Graphe.h"
#include <math.h>
#include <time.h>
#define taille_tab 25
#define degre (2)
#define MAX(A,B) A > B ? A : B
#define DEBUGMODE 1
#define nombre_sommet 6

void AVL();
void TAS();
void B_ARBRE();
void Tri();
void SortMenu(int *tab,int compteur);
void Graphe();
void MatriceMenu(int M[nombre_sommet][nombre_sommet]);
void GRAPHE();




int main()
{

    int selection=0;
    int choix;
    while(1){
        printf("\t\t*-------------------------------------------------*\n");
        printf("\t\t|  AROSIO         *------------*  ANNEE 2017-2018 |\n");
        printf("\t\t|  STAIANO        |Rendu de TPS|                  |\n");
        printf("\t\t|  HANNOUN        *------------*                  |\n");
        printf("\t\t|                                                 |\n");
        printf("\t\t|                                                 |\n");
        printf("\t\t|  AVL   Tri   B_Arbre   Tas_Binomiaux   Graphes  |\n");
        switch(selection){
        case 0:
            printf("\t\t|   X                                             |\n");
            break;
        case 1:
            printf("\t\t|         X                                       |\n");
            break;
        case 2:
            printf("\t\t|                 X                               |\n");
            break;
        case 3:
            printf("\t\t|                              X                  |\n");
            break;
        case 4:
            printf("\t\t|                                           X     |\n");
            break;
        }
        printf("\t\t|                                                 |\n");
        printf("\t\t|         //------              ------\\\\          |\n");
        printf("\t\t*-------------------------------------------------*\n\n\n");

        printf("Deplacez-vous a l'aide de '4' et '6' et faites votre choix avec '5'\n");
        printf("Exit avec '0'\n");
        scanf("%d",&choix);

        if((choix == 4)&&(selection != 0)){
            selection --;
        }
        else if(choix == 0){
            return 0;
        }
        else if((choix == 6)&&(selection != 4)){
            selection++;
        }
        else if(choix == 5){
            switch(selection){
            case 0:
                AVL();
                break;
            case 1:
                Tri();
                break;
            case 2:
                B_ARBRE();
                break;
            case 3:
                TAS();
                break;
            case 4:
                Graphe();
                //GRAPHE();
                break;
            }
        }
    }
}
void Graphe(){

    int exemple[nombre_sommet][nombre_sommet] = {{0, 5, 2, 0, 3, 0},
                                                 {5, 0, 7, 1, 0, 0},
                                                 {2, 7, 0, 1, 1, 0},
                                                 {0, 1, 1, 0, 0, 2},
                                                 {3, 0, 1, 0, 0, 3},
                                                 {0, 0, 0, 2, 3, 0},
                                                };

    printf("\t\t///////////////////////////////////////////////////\n");
    printf("\t\t///////////////////GRAPHE-TP7//////////////////////\n");
    printf("\t\t///////////////////////////////////////////////////\n\n\n");

    int choix;
    int M[nombre_sommet][nombre_sommet];

    while(1){
        printf("What do you want to do?\n\n");
        printf("1 : Create a Matrice\n");
        printf("2 : Clean a Matrice\n");
        printf("3 : Show the current Matrice\n");
        printf("4 : Transform the Matrice\n");
        printf("5 : take the exemple\n");
        printf("6 : Exit\n\n");

        scanf("%d",&choix);
        switch(choix){
        case 1:
            creationMatrice(M);
            break;
        case 2:
            resetMatrice(M);
            break;
        case 3:
            affichageMatrice(M);
            break;
        case 4:
            MatriceMenu(M);
            break;
        case 5:
            exempleMatrice(M,exemple);
            break;
        case 6:
            printf("\t\t///////////////////////////////////////////////////\n");
            printf("\t\t/////////////////////////END///////////////////////\n");
            printf("\t\t///////////////////////////////////////////////////\n\n\n");
            libereMatrice(M);
            return ;
            break;
        }
        printf("\n-------------------------\n");
    }
}
void MatriceMenu(int M[nombre_sommet][nombre_sommet]){

    int choix;
    while(1){
        printf("What do you want to do?\n\n");
        printf("1 : Use the Prim algorithm\n");
        printf("2 : Use the Krustal algorithm\n");
        printf("3 : exit\n");

        scanf("%d",&choix);
        switch(choix){
        case 1:
            Prim(M);
            break;
        case 2:
            GRAPHE(M);
            break;
        case 3:
            return;
            break;
        }
    }
}
void GRAPHE(int M[nombre_sommet][nombre_sommet]){

    printf("\t\t///////////////////////////////////////////////////\n");
    printf("\t\t///////////////////GRAPHE-TP7//////////////////////\n");
    printf("\t\t///////////////////////////////////////////////////\n\n\n");

    int choice;
    printf("voulez-vous les details? 1 ou 0\n");
    scanf("%d",&choice);



    n = nombre_sommet;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            cost[i][j] = M[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    printf("Les couts minimaux des aretes de l'arbre sont : \n");
    //ne est le nombre de chemins, soit n-1
    while (ne < n) {
        for (i = 1, minimum = INT_MAX; i <= n; i++)
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < minimum) {
                    minimum = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
                if(choice == 1) printf("cost[%d][%d] = %d\n",i,j,cost[i][j]);
            }
            if(choice == 1) printf("\n");
        u = Find(u);
        v = Find(v);
        if (Union(u, v)) {
            printf("chemin n:%d ; %d---%d ==> poids de %d\n", ne++, a, b, minimum);
            mincost += minimum;
        }
        cost[a][b] = cost[b][a] = INT_MAX;
    }
    printf("\nCout minimal = %d\n", mincost);
}
void TAS(){

    printf("\t\t///////////////////////////////////////////////////\n");
    printf("\t\t///////////////TAS-BINOMIAUX TP6///////////////////\n");
    printf("\t\t///////////////////////////////////////////////////\n\n\n");

    char clesString[255];
    char selection[255];


    printf("Premiere valeur de l'arbre :\n");
    scanf("%s", clesString);
    int clesValue = atoi(clesString);
    Noeud tasPrincipal = allouerNoeud(clesValue);

    while (1) {
        printf("Menu de selection\n\t1)Afficher tas\n\t2)Inserer cles\n\t3)Suppression cles\n\t4)Affichage Min cles\n\t5)Quitter\n");
        printf("Selection : \n");
        scanf("%s", selection);
        int value = atoi(selection);
        switch (value) {
            case 1:
                displayToutTas(tasPrincipal);
                break;

            case 2:
                printf("cles : \n");
                scanf("%s", clesString);
                int clesValue = atoi(clesString);
                printf("Valeur cles : %d\n", clesValue);
                tasPrincipal = insereNoeud(clesValue, tasPrincipal);
                break;
            case 3:
                /*printf("cles : \n");
                scanf("%s", clesString);
                int clesASuppr = atoi(clesString);
                printf("Valeur cles : %d\n", clesASuppr);
                arbrePrincipal = suppressioncles(arbrePrincipal, clesASuppr);
                hauteurUpdateV2(arbrePrincipal);
                equilibrageUpdate(arbrePrincipal);
                //arbrePrincipal = equilibrage(arbrePrincipal);
                arbrePrincipal = equilibrageParcours(arbrePrincipal);
                equilibrageUpdate(arbrePrincipal);*/
                break;

            case 4:
                printf("Min cles : %d\n",mincles(tasPrincipal,100000));
                break;

            case 5:
                freeTas(tasPrincipal);
                return;
            default:
                printf("Valeur non valide\n");
                break;
        }
    }
}
void AVL(){

    printf("\t\t///////////////////////////////////////////////////\n");
    printf("\t\t/////////////////////AVL-TP3///////////////////////\n");
    printf("\t\t///////////////////////////////////////////////////\n\n\n");

    char cle[255];
    char string[255];

    printf("Premiere valeur de l'arbre :\n");
    scanf("%s", cle);
    int cleValue = atoi(cle);
    Avl arbrePrincipal = creer_Value_Avl(cleValue,0,NULL);

    while (1) {
        printf("Menu de selection\n\t1)Afficher arbre\n\t2)Inserer cle\n\t3)Suppression cle\n\t4)Quitter\n");
        printf("Selection : \n");
        scanf("%s", string);
        int value = atoi(string);
        switch (value) {
            case 1:
                menuAfficheArbre(arbrePrincipal);
                break;
            case 2:

                printf("cle : \n");
                scanf("%s", cle);
                int cleValue = atoi(cle);
                printf("Valeur cle : %d\n",cleValue);
                insertion_cle_arbreBinaire(arbrePrincipal, cleValue);
                hauteurUpdateV2(arbrePrincipal);
                equilibrageUpdate(arbrePrincipal);
                //arbrePrincipal = equilibrage(arbrePrincipal);
                arbrePrincipal = equilibrageParcours(arbrePrincipal);
                equilibrageUpdate(arbrePrincipal);
                break;
            case 3:
                printf("cle : \n");
                scanf("%s", cle);
                int cleASuppr = atoi(cle);
                printf("Valeur cle : %d\n",cleASuppr);
                arbrePrincipal = suppressionCle(arbrePrincipal,cleASuppr);
                hauteurUpdateV2(arbrePrincipal);
                equilibrageUpdate(arbrePrincipal);
                //arbrePrincipal = equilibrage(arbrePrincipal);
                arbrePrincipal = equilibrageParcours(arbrePrincipal);
                equilibrageUpdate(arbrePrincipal);
                break;

            case 4:
                freeArbre(arbrePrincipal);
                return;
            default:
                printf("Valeur non valide\n");
                break;
        }
    }
}
void B_ARBRE(){
    printf("\t\t///////////////////////////////////////////////////\n");
    printf("\t\t///////////////////B_Arbre-TP5/////////////////////\n");
    printf("\t\t///////////////////////////////////////////////////\n\n\n");

    int choix;
    B_Arbre barbre;
    barbre = createTree();
    while(1){
        printf("What do you want to do?\n\n");
        printf("1 : Insert an element in the B_Arbre\n");
        printf("2 : Delete an element in the B_Arbre\n");
        printf("3 : Show the B_Arbre\n");
        printf("4 : Clean the B_Arbre\n");
        printf("5 : Search an Element in the B_Arbre\n");
        printf("6 : Exit\n\n");

        scanf("%d",&choix);
        switch(choix){
        case 1:
            printf("Which element do you want to add?\n");
            scanf("%d",&choix);
            barbre = addKey(barbre,choix);
            break;
        case 2:
            printf("Which element do you want to delete?\n");
            scanf("%d",&choix);
            DeleteKey(barbre,choix);
            break;
        case 3:
            ShowTree(barbre,0);
            break;
        case 4:
            FreeTree(barbre);
            barbre = createTree();
            break;
        case 5:
            printf("Which element do you want to Search?\n");
            scanf("%d",&choix);
            FindKey(barbre,choix);
            break;
        case 6:
            printf("\t\t///////////////////////////////////////////////////\n");
            printf("\t\t/////////////////////////END///////////////////////\n");
            printf("\t\t///////////////////////////////////////////////////\n\n\n");
            return ;
            break;
        }
        printf("\n-------------------------\n");
    }
}
void Tri(){


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
            return ;
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
