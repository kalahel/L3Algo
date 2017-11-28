#include <stdio.h>
#include <stdlib.h>

#define DEBUGMODE 1
typedef struct Node {
    int cles, degres;
    struct Node *fils, *frere, *pere;
} *Noeud;

Noeud allouerNoeud(int cles);
Noeud fusionTas(Noeud noeud1, Noeud noeud2);
void displayNode(Noeud noeud);
void displayTouteTete(Noeud noeud);
void displayToutTas(Noeud noeud);
int checkdegresTas(Noeud noeud, int validiteTas);
Noeud insereNoeud(int cles, Noeud teteTas);
Noeud equilibreTas(Noeud noeud);
void freeTas(Noeud noeud);
int mincles(Noeud noeud, int clesMin);


Noeud allouerNoeud(int cles) {
    Noeud noeud = malloc(sizeof(struct Node));
    noeud->degres = 0;
    noeud->cles = cles;
    noeud->fils = NULL;
    noeud->frere = NULL;
    noeud->pere = NULL;
    return noeud;
}

/**
 * On ajoute au noeud à la clé la plus petite un sous arbre.
 * @param noeud1
 * @param noeud2
 * @return
 */
Noeud fusionTas(Noeud noeud1, Noeud noeud2) {
    Noeud tempFrere;
    // On conserve le lien avec le prochain frere
    if (noeud1->frere == noeud2) {
        tempFrere = noeud2->frere;
    } else {
        tempFrere = noeud1->frere;
    }

    // Si noeud1 est plus grand
    if (noeud1->cles > noeud2->cles) {

        noeud1->pere = noeud2;
        noeud1->frere = noeud2->fils;
        noeud2->fils = noeud1;
        noeud2->degres++;
        noeud2->frere = tempFrere;

        return noeud2;

    } else {

        noeud2->pere = noeud1;
        noeud2->frere = noeud1->fils;
        noeud1->fils = noeud2;
        noeud1->degres++;
        noeud1->frere = tempFrere;
        return noeud1;
    }
}

/**
 * Affiche toute les informations d'un
 * @param noeud
 */
void displayNode(Noeud noeud) {
    printf("cles : %d, degres : %d", noeud->cles, noeud->degres);
    if (DEBUGMODE) {
        if (noeud->fils != NULL)
            printf(", Fils : %d", noeud->fils->cles);
        if (noeud->frere != NULL)
            printf(" ,Frere : %d", noeud->frere->cles);
        if (noeud->pere != NULL)
            printf(" ,Pere : %d", noeud->pere->cles);
    }
    printf("\n");
}

/**
 * Va parcourir toute les racines des tas, si deux tas on le meme degré renverra 1 sinon 0.
 * @param noeud
 * @return
 */
int checkdegresTas(Noeud noeud, int validiteTas) {
    if (noeud->frere != NULL) {
        if (noeud->frere->degres == noeud->degres) {
            validiteTas = 1;
        } else {
            checkdegresTas(noeud->frere, validiteTas);
        }
    }
    return validiteTas;
}

/**
 * Va inserer la nouvelle clé au début de la liste de tete de tas
 * Tant qu'il reste des  déséquilibré, les rééquilibres
 * @param cles
 * @param teteTas
 * @return
 */
Noeud insereNoeud(int cles, Noeud teteTas) {
    Noeud noeud = allouerNoeud(cles);
    noeud->frere = teteTas;

    while (checkdegresTas(noeud, 0)) {
        noeud = equilibreTas(noeud);
    }

    return noeud;
}

/**
 * Affiche toute les tetes des tas
 * @param noeud
 */
void displayTouteTete(Noeud noeud) {
    displayNode(noeud);
    if (noeud->frere != NULL)
        displayTouteTete(noeud->frere);
}

/**
 * Parcours l'arbre jusqu'a rencontrer deux noeud de même degré, une fois rencontré, fais une union des deux et retourne le resultat.
 * @param noeud
 * @return
 */
Noeud equilibreTas(Noeud noeud) {
    if (noeud->frere != NULL) {
        if (noeud->degres == noeud->frere->degres) {
            return fusionTas(noeud, noeud->frere);
        } else {
            noeud->frere = equilibreTas(noeud->frere);
        }
    }
    return noeud;
}

/**
 * Affiche récurisvement, l'élément, son fils puis son frere.
 * @param noeud
 */
void displayToutTas(Noeud noeud) {
    displayNode(noeud);
    if (noeud->fils != NULL)
        displayToutTas(noeud->fils);
    if (noeud->frere != NULL)
        displayToutTas(noeud->frere);
}


/**
 * Supprime récursivement tout le tas
 * @param noeud
 */
void freeTas(Noeud noeud) {
    if (noeud != NULL) {
        freeTas(noeud->fils);
        freeTas(noeud->frere);
        free(noeud);
    }
}
/**
 * Parcours la tete des tas pour trouver la plus petite clé
 * @param noeud
 * @param clesMin
 * @return
 */
int mincles(Noeud noeud, int clesMin) {
    int temp = clesMin;
    if(noeud->cles < temp)
        temp = noeud->cles;
    if(noeud->frere != NULL){
        return mincles(noeud->frere,temp);
    }
    return temp;
}

