#include <stdio.h>
#include <stdlib.h>
#define MAX(A,B) A > B ? A : B

typedef struct noeud{
    int Cle;
    int Hauteur;
    struct noeud *Fg,*Fd,*Pere;
}*Avl;

Avl creer_Avl();
Avl creer_Value_Avl(int cle, int hauteur,Avl pere);
Avl SAG(Avl node);
Avl SAD(Avl node);
Avl min_cle(Avl node);
Avl max_cle(Avl node);
int hauteur(Avl node);
void swapKey(Avl node_a,Avl node_b);
Avl rotation_droite(Avl node);
Avl rotation_gauche(Avl node);
Avl rotation_gauche_droite(Avl node);
Avl rotation_droite_gauche(Avl node);
Avl insertion_cle(Avl arbre,int cle);
void insertion_cle_arbreBinaire(Avl arbre,int cle);
void menuAfficheArbre(Avl node);
void menuAfficheNoeud(Avl node);

int main(){
    //Avl arbrePrincipal = creer_Avl();
    Avl arbrePrincipal = creer_Value_Avl(50,2,NULL);
    arbrePrincipal->Fg = creer_Value_Avl(17,arbrePrincipal->Hauteur,arbrePrincipal);
    //arbrePrincipal->Fd = creer_Value_Avl(76,arbrePrincipal->Hauteur,arbrePrincipal);
    insertion_cle_arbreBinaire(arbrePrincipal,76);
    insertion_cle_arbreBinaire(arbrePrincipal,54);
    insertion_cle_arbreBinaire(arbrePrincipal,72);

    menuAfficheArbre(arbrePrincipal);
    return 0;
}

Avl creer_Avl(){
    Avl node = NULL;
    return node;
}
Avl creer_Value_Avl(int cle, int hauteur,Avl pere){
    Avl node = malloc(sizeof(Avl));
    node->Cle = cle;
    //node->Hauteur = -1;
    node->Hauteur = hauteur - 1;
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
void swapKey(Avl node_a,Avl node_b){
    int z = node_a->Cle;
    node_a->Cle = node_b->Cle;
    node_b->Cle = z;
}

//REMPLACER PAR CELLE DANS ROTATION GAUCHE
Avl rotation_droite(Avl node){
   /* Avl node_to_return = node->Fg;
    node_to_return->Fd = node;
    node->Fg = NULL;
    return node_to_return;
    */
    Avl temp;
    temp = node->Fg;
    node->Fg = temp->Fd;
    temp->Fd = node;
    node->Hauteur = hauteur(node);
    temp->Hauteur = hauteur(temp);
    return temp;
}

Avl rotation_gauche(Avl node){
   /* Avl node_to_return = node->Fd;
    node_to_return->Fg = node;
    node->Fd = NULL;
    return node_to_return;
    */
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
// affiche uniquement un noeud, sa clé et sa hauteur
void menuAfficheNoeud(Avl node){
    printf("Noeud, Hauteur : %d Cle : %d \t",node->Hauteur,node->Cle);
}
Avl insertion_cle(Avl arbre,int cle){
return arbre;
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
