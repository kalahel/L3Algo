#include <stdio.h>
#include <stdlib.h>

#define DEBUGMODE 1
typedef struct Node {
    int cle, degre;
    struct Node *fils, *frere, *pere;
} *Noeud;

Noeud allouerNoeud(int cle);

Noeud fusionTas(Noeud noeud1, Noeud noeud2);

void displayNode(Noeud noeud);

void displayTouteTete(Noeud noeud);

void displayToutTas(Noeud noeud);

void menuPrincipal();

int checkDegreTas(Noeud noeud, int validiteTas);

Noeud insereNoeud(int cle, Noeud teteTas);

Noeud equilibreTas(Noeud noeud);

void freeTas(Noeud noeud);

int minCle(Noeud noeud, int cleMin);

int main() {
    menuPrincipal();
    return 0;
}

Noeud allouerNoeud(int cle) {
    Noeud noeud = malloc(sizeof(struct Node));
    noeud->degre = 0;
    noeud->cle = cle;
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
    if (noeud1->cle > noeud2->cle) {

        noeud1->pere = noeud2;
        noeud1->frere = noeud2->fils;
        noeud2->fils = noeud1;
        noeud2->degre++;
        noeud2->frere = tempFrere;

        return noeud2;

    } else {

        noeud2->pere = noeud1;
        noeud2->frere = noeud1->fils;
        noeud1->fils = noeud2;
        noeud1->degre++;
        noeud1->frere = tempFrere;
        return noeud1;
    }
}

/**
 * Affiche toute les informations d'un noeuds
 * @param noeud
 */
void displayNode(Noeud noeud) {
    printf("Cle : %d, Degre : %d", noeud->cle, noeud->degre);
    if (DEBUGMODE) {
        if (noeud->fils != NULL)
            printf(", Fils : %d", noeud->fils->cle);
        if (noeud->frere != NULL)
            printf(" ,Frere : %d", noeud->frere->cle);
        if (noeud->pere != NULL)
            printf(" ,Pere : %d", noeud->pere->cle);
    }
    printf("\n");
}

/**
 * Va parcourir toute les racines des tas, si deux tas on le meme degré renverra 1 sinon 0.
 * @param noeud
 * @return
 */
int checkDegreTas(Noeud noeud, int validiteTas) {
    if (noeud->frere != NULL) {
        if (noeud->frere->degre == noeud->degre) {
            validiteTas = 1;
        } else {
            checkDegreTas(noeud->frere, validiteTas);
        }
    }
    return validiteTas;
}

/**
 * Va inserer la nouvelle clé au début de la liste de tete de tas
 * Tant qu'il reste des noeuds déséquilibré, les rééquilibres
 * @param cle
 * @param teteTas
 * @return
 */
Noeud insereNoeud(int cle, Noeud teteTas) {
    Noeud noeud = allouerNoeud(cle);
    noeud->frere = teteTas;

    while (checkDegreTas(noeud, 0)) {
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
        if (noeud->degre == noeud->frere->degre) {
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

void menuPrincipal() {
    char cleString[255];
    char selection[255];


    printf("Premiere valeur de l'arbre :\n");
    scanf("%s", cleString);
    int cleValue = atoi(cleString);
    Noeud tasPrincipal = allouerNoeud(cleValue);

    while (1) {
        printf("Menu de selection\n\t1)Afficher tas\n\t2)Inserer cle\n\t3)Suppression cle\n\t4)Affichage Min cle\n\t5)Quitter\n");
        printf("Selection : \n");
        scanf("%s", selection);
        int value = atoi(selection);
        switch (value) {
            case 1:
                displayToutTas(tasPrincipal);
                break;

            case 2:
                printf("cle : \n");
                scanf("%s", cleString);
                int cleValue = atoi(cleString);
                printf("Valeur cle : %d\n", cleValue);
                tasPrincipal = insereNoeud(cleValue, tasPrincipal);
                break;
            case 3:
                /*printf("cle : \n");
                scanf("%s", cleString);
                int cleASuppr = atoi(cleString);
                printf("Valeur cle : %d\n", cleASuppr);
                arbrePrincipal = suppressionCle(arbrePrincipal, cleASuppr);
                hauteurUpdateV2(arbrePrincipal);
                equilibrageUpdate(arbrePrincipal);
                //arbrePrincipal = equilibrage(arbrePrincipal);
                arbrePrincipal = equilibrageParcours(arbrePrincipal);
                equilibrageUpdate(arbrePrincipal);*/
                break;

            case 4:
                printf("Min cle : %d\n",minCle(tasPrincipal,100000));
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
 * @param cleMin
 * @return
 */
int minCle(Noeud noeud, int cleMin) {
    int temp = cleMin;
    if(noeud->cle < temp)
        temp = noeud->cle;
    if(noeud->frere != NULL){
        return minCle(noeud->frere,temp);
    }
    return temp;
}

