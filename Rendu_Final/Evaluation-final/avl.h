#include <stdio.h>
#include <stdlib.h>
#define MAX(A,B) A > B ? A : B

typedef struct Noeud{
    int Cle;
    int Hauteur;
    int FacteurEquilibrage;
    struct Noeud *Fg,*Fd,*Pere;
}*Avl;

Avl creer_Avl();
Avl creer_Value_Avl(int cle, int hauteur,Avl pere);
Avl SAG(Avl node);
Avl SAD(Avl node);
Avl min_cle(Avl node);
Avl max_cle(Avl node);
int hauteur(Avl node);
void hauteurV2(Avl node);
Avl rotation_droite(Avl node);
Avl rotation_gauche(Avl node);
Avl rotation_gauche_droite(Avl node);
Avl rotation_droite_gauche(Avl node);
void hauteurUpdate(Avl arbre);
void hauteurUpdateV2(Avl arbre);
void equilibrageSetValue(Avl node);
void equilibrageUpdate(Avl arbre);
Avl equilibrage(Avl arbre);
Avl equilibrageParcours(Avl arbre);
Avl suppressionCle(Avl arbre,int cle);
void insertionNoeudFd(Avl arbre, Avl NoeudAInserer);
int maxValue(int a, int b);
void insertion_cle_arbreBinaire(Avl arbre,int cle);
void menuAfficheArbre(Avl node);
void menuAfficheNoeud(Avl node);
void freeArbre(Avl arbre);


Avl creer_Avl(){
    Avl node = NULL;
    return node;
}
Avl creer_Value_Avl(int cle, int hauteur,Avl pere){
    //printf("Creation 1\n");
    // Bien allouer la structure et non le pointeur
    Avl node = malloc(sizeof(struct Noeud));
    //printf("CREATION ALLOCATION DONE\n");
    node->Cle = cle;
    //printf("CREATION ATTRIBRUTION CLE DONE, CLE : %d\n",cle);

    //node->Hauteur = -1;
    node->Hauteur = hauteur - 1;
    node->FacteurEquilibrage = 0;
    node->Pere = pere;
    node->Fd = NULL;
    node->Fg = NULL;
    return node;
}

Avl SAG(Avl node){
    return (node->Fg);
}
Avl SAD(Avl node){
    return (node->Fd);
}
Avl min_cle(Avl node){
    if(node == NULL)
        return NULL;
    if(node->Fg == NULL)
        return node;
    else
        return (min_cle(SAG(node)));
}
Avl max_cle(Avl node){
    if(node == NULL)
        return NULL;
    if(node->Fd == NULL)
        return node;
    else
        return (min_cle(SAD(node)));
}
int hauteur(Avl node){
   if (node == NULL)
        return -1;
   else
        return MAX(hauteur(node->Fg), hauteur(node->Fd)) + 1;

}
void hauteurUpdate(Avl arbre){
    arbre->Hauteur = hauteur(arbre);
    if(arbre->Fg != NULL)
        hauteurUpdate(arbre->Fg);
    if(arbre->Fd != NULL)
        hauteurUpdate(arbre->Fd);
}

Avl rotation_droite(Avl node){
    Avl temp;
    temp = node->Fg;
    node->Fg = temp->Fd;
    temp->Fd = node;
    node->Hauteur = hauteur(node);
    temp->Hauteur = hauteur(temp);
    return temp;
}

Avl rotation_gauche(Avl node){
    Avl temp;
    temp = node->Fd;
    node->Fd = temp->Fg;
    temp->Fg = node;
    node->Hauteur = hauteur(node);
    temp->Hauteur = hauteur(temp);
    return temp;

}

Avl rotation_gauche_droite(Avl node){
    node->Fg = rotation_gauche(node->Fg);
    return (rotation_droite(node));
}
Avl rotation_droite_gauche(Avl node){
    node->Fd = rotation_droite(node->Fd);
    return (rotation_gauche(node));
}
// Affichage préfixe de l'arbre
void menuAfficheArbre(Avl node){
    menuAfficheNoeud(node);
    if(node->Fg != NULL)
        menuAfficheArbre(node->Fg);
    if(node->Fd != NULL)
        menuAfficheArbre(node->Fd);
}
// affiche uniquement un Noeud, sa clé et sa hauteur, affiche aussi ses fils en fonctions de la hauteurs
void menuAfficheNoeud(Avl node){
    int DEBUGMOD = 1;

    if(DEBUGMOD == 0){
        printf("Noeud, Hauteur : %d Cle : %d \n",node->Hauteur,node->Cle);
    }
    else{
        printf("Noeud, Hauteur : %d Cle : %d Facteur Equilibrage : %d ",node->Hauteur,node->Cle,node->FacteurEquilibrage);
        if(node->Fg != NULL)
            printf(" ,FG : %d ",node->Fg->Cle);
        if(node->Fd != NULL)
            printf(" ,FD : %d ",node->Fd->Cle);
        printf("\n");
    }
}

// On va inserer la clé dans l'arbre sans se soucier de l'équilibrage
void insertion_cle_arbreBinaire(Avl arbre,int cle){
    if(cle > arbre->Cle){
        if(arbre->Fd != NULL){
            insertion_cle_arbreBinaire(arbre->Fd,cle);
        }
        else{
            arbre->Fd = creer_Value_Avl(cle,arbre->Hauteur,arbre);
            return;
        }
    }
    else if(cle < arbre->Cle){
        if(arbre->Fg != NULL){
            insertion_cle_arbreBinaire(arbre->Fg,cle);
        }
        else{
            arbre->Fg = creer_Value_Avl(cle,arbre->Hauteur,arbre);
            return;
        }
    }
}
// Fonction mettant à jours la hauteur d'un Noeud par rapport à celui de ces fils
void hauteurV2(Avl node){
    // Si feuille alors
    if((node->Fd == NULL) && (node->Fg == NULL)){
        node->Hauteur = 0;
    }
    else if (node->Fg == NULL){
        //node->Hauteur = (node->Fd->Hauteur + 1);
        node->Hauteur = (node->Fd->Hauteur + 1);
    }
    else if (node->Fd == NULL){
        //node->Hauteur = 0 - (node->Fg->Hauteur + 1);
        node->Hauteur = (node->Fg->Hauteur + 1);
    }
    else {
        //node->Hauteur = (node->Fd->Hauteur - node->Fg->Hauteur);
        node->Hauteur = maxValue(node->Fd->Hauteur,node->Fg->Hauteur) + 1;

    }

}
// On procedera en faisant un parcours infixe pour remonter jusqu'à la racine
void hauteurUpdateV2(Avl arbre){
    if(arbre->Fg != NULL){
        hauteurUpdateV2(arbre->Fg);
    }
    if(arbre->Fd != NULL){
        hauteurUpdateV2(arbre->Fd);
    }
    hauteurV2(arbre);
}
// Retourne la valeur max des deux
int maxValue(int a, int b){
    if (a > b ){
        return a;
    }
    else{
        return b;
    }
}
void menuPrincipal(){
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
/**
 * Mets à jours la hauteurs des Noeuds
 * @param node
 */
void equilibrageSetValue(Avl node) {
    // Si feuille alors
    if((node->Fd == NULL) && (node->Fg == NULL)){
        node->FacteurEquilibrage = 0;
    }
    else if (node->Fg == NULL){
        node->FacteurEquilibrage = (node->Fd->Hauteur + 1);
    }
    else if (node->Fd == NULL){
        node->FacteurEquilibrage = 0 - (node->Fg->Hauteur + 1);
    }
    else {
        node->FacteurEquilibrage = (node->Fd->Hauteur - node->Fg->Hauteur);
    }

}
/**
 * Parcours postfixe de l'arbre, applique la fonction equilibrageSetValue
 * @param arbre
 */
void equilibrageUpdate(Avl arbre) {
    if(arbre->Fg != NULL){
        equilibrageUpdate(arbre->Fg);
    }
    if(arbre->Fd != NULL){
        equilibrageUpdate(arbre->Fd);
    }
    equilibrageSetValue(arbre);
}

void freeArbre(Avl arbre) {
    if(arbre != NULL){
        freeArbre(arbre->Fg);
        freeArbre(arbre->Fd);
        free(arbre);
    }

}
/**
 * Equilibre les Noeuds
 * @param arbre
 * @return
 */
Avl equilibrage(Avl arbre) {
    if(arbre->FacteurEquilibrage == 2 ){
        if(arbre->Fd->FacteurEquilibrage == 1)
            arbre = rotation_gauche(arbre);
        else
            arbre = rotation_droite_gauche(arbre);
    }
    else if(arbre->FacteurEquilibrage == -2){
        if(arbre->Fg->FacteurEquilibrage == -1)
            arbre = rotation_droite(arbre);
        else
            arbre = rotation_gauche_droite(arbre);
    }
    return arbre;
}

/**
 * Va parcrourir tout l'arbre, traitera chaque Noeud mal équilibré le plus bas possible
 * Parcours préfixe
 * @param arbre
 * @return
 */
Avl equilibrageParcours(Avl arbre) {
    if(arbre->FacteurEquilibrage == 2 || arbre->FacteurEquilibrage == -2){
        arbre = equilibrage(arbre);
    }
    else{
        if(arbre->Fg != NULL)
            arbre->Fg = equilibrageParcours(arbre->Fg);
        if(arbre->Fd != NULL)
            arbre->Fd = equilibrageParcours(arbre->Fd);
    }
    return arbre;
}
/**
 * Cette fonction va parcourir l'arbre jusqu'a trouver la clé à supprimer
 * Une fois trouvé, on rattachera son fils droit comme fils droit de son fils gauche
 * Si l'arbre n'a pas de fils droit la racine deviendra simplement le fils gauche
 * @param arbre
 * @param cle
 * @return
 */
Avl suppressionCle(Avl arbre, int cle) {
    if(arbre->Cle == cle){
        if(arbre->Fd != NULL) {
            Avl temp = arbre->Fd;
            if(arbre->Fd->Fg != NULL){
                if (arbre->Fg != NULL) {
                    insertionNoeudFd(arbre->Fg, temp->Fg);
                    temp->Fg = arbre->Fg;
                }
            }
            else{
                if(arbre->Fg != NULL){
                    temp->Fg = arbre->Fg;
                }
            }
            arbre = temp;
            return arbre;
        }
        else if(arbre->Fg != NULL){
            arbre = arbre->Fg;
            return arbre;
        }
        else return NULL;
    }
    else{
        if(arbre->Fg != NULL)
            arbre->Fg = suppressionCle(arbre->Fg, cle);
        if(arbre->Fd != NULL)
            arbre->Fd = suppressionCle(arbre->Fd,cle);
    }
    return arbre;
}

void insertionNoeudFd(Avl arbre, Avl NoeudAInserer) {
    if(arbre->Fd == NULL)
        arbre->Fd = NoeudAInserer;
    else
        insertionNoeudFd(arbre->Fd,NoeudAInserer);
}
