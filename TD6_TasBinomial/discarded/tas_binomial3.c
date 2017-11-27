#include <stdlib.h>
#include <stdio.h>


typedef struct noeud{
    int degre;
    int cle;
    struct noeud *pere, *pfg, *pfd;
}*Tas_Binomial;


Tas_Binomial creer_Arbre_Binomial(int k);
Tas_Binomial lier(Tas_Binomial aBinomial1, Tas_Binomial aBinomial2);
Tas_Binomial creer_Tas_Binomial();
Tas_Binomial ajouter_Cle(Tas_Binomial tasBinomial, Tas_Binomial aBinomial);
Tas_Binomial extraire_Min(Tas_Binomial tasBinomial);
Tas_Binomial fusionner(Tas_Binomial tasBinomial1, Tas_Binomial tasBinomial2);
Tas_Binomial Union(Tas_Binomial tasBinomial1, Tas_Binomial tasBinomial2);
Tas_Binomial supprimer_Min(Tas_Binomial tasBinomial);
int inverser_Liste(Tas_Binomial y);
Tas_Binomial modifier_Cle(Tas_Binomial H, Tas_Binomial aBinomial, int k);
Tas_Binomial decrementer_Cle(Tas_Binomial tasBinomial, Tas_Binomial aBinomial);
int afficher (Tas_Binomial H);
Tas_Binomial trouver_Noeud(Tas_Binomial H, int k);

Tas_Binomial H = NULL;
Tas_Binomial Hr = NULL;

Tas_Binomial creer_Arbre_Binomial(int k){
    Tas_Binomial aBinomial;
    aBinomial = (Tas_Binomial)malloc(sizeof(struct noeud));
    aBinomial->cle = k;
    return aBinomial;
}


Tas_Binomial lier(Tas_Binomial aBinomial1, Tas_Binomial aBinomial2){
    aBinomial1->pere = aBinomial2;
    aBinomial1->pfd = aBinomial2->pfg;
    aBinomial2->pfg = aBinomial1;
    aBinomial2->degre = ((int)aBinomial2->degre) + 1;
    return aBinomial2;
}

Tas_Binomial creer_Tas_Binomial(){
    Tas_Binomial tasBinomial;
    tasBinomial = NULL;
    return tasBinomial;
}

Tas_Binomial ajouter_Cle(Tas_Binomial tasBinomial, Tas_Binomial aBinomial){
    Tas_Binomial tasBinomial1 = creer_Tas_Binomial();
    aBinomial->pere = NULL;
    aBinomial->pfg = NULL;
    aBinomial->pfd = NULL;
    aBinomial->degre = 0;
    tasBinomial1 = aBinomial;
    tasBinomial = Union(tasBinomial,tasBinomial1);
    return tasBinomial;
}

Tas_Binomial extraire_Min(Tas_Binomial H1){
    int min;
    Tas_Binomial t = NULL;
    Tas_Binomial x = H1;
    Tas_Binomial Hr;
    Tas_Binomial p;
    Hr = NULL;
    if(x==NULL){
        printf("\n Rien à extraire");
        return x;
    }
    p = x;
    while (p->pfd != NULL){
        if ((p->pfd)->cle < min){
            min = (p->pfd)->cle;
            t = p;
            x = p->pfd;
        }
        p = p->pfd;
    }
    if (t == NULL && x->pfd == NULL)
        H1 = NULL;
    else if (t->pfd == NULL)
        t = NULL;
    else
        t->pfd = x->pfd;
    if (x->pfg!= NULL){
        inverser_Liste(x->pfg);
        (x->pfg)->pfd = NULL;
    }
    H = Union(H1,Hr);
    return x;
}

Tas_Binomial fusionner(Tas_Binomial H1, Tas_Binomial H2){
    Tas_Binomial H = creer_Tas_Binomial();
    Tas_Binomial  y;
    Tas_Binomial z;
    Tas_Binomial a;
    Tas_Binomial b;
    y = H1;
    z = H2;
    if (y != NULL){
        if (z != NULL && y->degre <= z->degre)
            H = y;
        else if (z != NULL && y->degre > z->degre)

            H = z;
        else
            H = y;
    }
    else {
        H = z;
    }
    while (y != NULL && z != NULL){
        if (y->degre < z->degre){
            y = y->pfd;
        }
        else if(y->degre == z->degre){
            a = y->pfd;
            y->pfd = z;
            y = a;
        }
        else{
            b = z->pfd;
            z->pfd = y;
            z = b;
        }
    }
    return H;
}

Tas_Binomial Union(Tas_Binomial H1, Tas_Binomial H2){
    Tas_Binomial prev_x;
    Tas_Binomial next_x;
    Tas_Binomial x;
    Tas_Binomial H = creer_Tas_Binomial();
    H = fusionner(H1,H2);
    if (H == NULL)
        return H;
    prev_x = NULL;
    x = H;
    next_x = x->pfd;
    while (next_x != NULL){
        if((x->degre != next_x->degre) || ((next_x->pfd != NULL) && (next_x->pfd)->degre == x->degre)){
            prev_x = x;
            x = next_x;
        }
        else {
            if (x->cle <= next_x->cle){
                x->pfd = next_x->pfd;
                lier(next_x, x);
            }
            else {
                if (prev_x == NULL)
                    H = next_x;
                else
                    prev_x->pfd = next_x;
                lier(x, next_x);
                x = next_x;
            }
        }
        next_x = x->pfd;
    }
    return H;
}

Tas_Binomial supprimer_Min(Tas_Binomial H){
    Tas_Binomial np;
    if (H == NULL){
        printf("\nTas binomial vide");
        return H;
    }
    modifier_Cle(H, extraire_Min(H), -1000);
    np = extraire_Min(H);
    if (np == NULL){
        printf("erreur");
    }
    else{
        printf ("\n noeud supprimé");
    }
}

Tas_Binomial modifier_Cle(Tas_Binomial H, Tas_Binomial aBinomial, int k){
    int temp;
    Tas_Binomial p;
    Tas_Binomial y;
    Tas_Binomial z;
    p = aBinomial;
    if (aBinomial == NULL){
        printf("\n Noeud à décrementer null");
    }
    if(k > p->cle){
        printf("\n La clé est plus grande que la clé actuel");
    }
    p->cle = k;
    y = p;
    z = p->pere;
    while(z!=NULL && y->cle < z->cle){
        temp = y->cle;
        y->cle = z->cle;
        z->cle = temp;
        y = z;
        z = z->pere;
    }
    printf("\n Clé decrementé");
}

Tas_Binomial decrementer_Cle(Tas_Binomial H, Tas_Binomial aBinomial){
    int temp;
    Tas_Binomial p;
    Tas_Binomial y;
    Tas_Binomial z;
    p = aBinomial;
    if (aBinomial == NULL){
        printf("\n Noeud à décrementer null");
    }
    p->cle = p->cle - 1;
    y = p;
    z = p->pere;
    while(z!=NULL && y->cle < z->cle){
        temp = y->cle;
        y->cle = z->cle;
        z->cle = temp;
        y = z;
        z = z->pere;
    }
    printf("\n Clé decrementé");
}

int inverser_Liste(Tas_Binomial y){
    if (y->pfd != NULL){
        inverser_Liste(y->pfd);
        (y->pfd)->pfd = y;
    }
    else {
        Hr = y;
    }
}

Tas_Binomial trouver_Noeud(Tas_Binomial H, int k){
    Tas_Binomial x = H;
    Tas_Binomial p = NULL;
    if(x->cle == k){
        p = x;
        return p;
    }
    if(x->pfg != NULL && p==NULL){
        p = trouver_Noeud(x->pfg, k);
    }
    if(x->pfd != NULL && p == NULL){
        p = trouver_Noeud(x->pfd, k);
    }
    return p;
}

int afficher (Tas_Binomial H){
    Tas_Binomial p;
    if (H == NULL) {
        printf("\nTas vide");
        return 1;
    }
    printf("\nLes noeuds racines sont:-\n");
    p = H;
    while (p != NULL) {
        printf("%d", p->cle);
        if (p->pfd != NULL)
            printf("-->");
        p = p->pfd;
    }
    printf("\n");
    return 0;
}

int main(){
    int i, n, m, l;
    Tas_Binomial p;
    Tas_Binomial np;
    char ch;
    printf("\nEntrez le nombre d'éléments:");
    scanf("%d", &n);
    printf("\nEntrez les éléments:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &m);
        np = creer_Arbre_Binomial(m);
        printf("cle : %d / degre : %d\n",np->cle, np->degre);
        H = ajouter_Cle(H, np);
    }
    afficher(H);
    do {
        printf("\nMENU:-\n");
        printf(
                "\n1)INSERER UN ELEMENT\n2)EXTRAIRE LE MINIMUM\n3)DIMINUER UNE CLE\n4)SUPPRIMER UN NOEUD\n5)QUITTER\n");
        scanf("%d", &l);
        switch (l) {
            case 1:
                do {
                    printf("\nENTREZ LE NOEUD A INSERER:");
                    scanf("%d", &m);
                    p = creer_Arbre_Binomial(m);
                    H = ajouter_Cle(H, p);
                    printf("\nAFFICHAGE DU TAS BINOMIAL:\n");
                    afficher(H);
                    printf("\nINSERER PLUS(y/Y)= \n");
                    fflush(stdin);
                    scanf("%c", &ch);
                } while (ch == 'Y' || ch == 'y');
                break;
            case 2:
                do {
                    printf("\nEXTRACTION DU MINIMUM");
                    p = extraire_Min(H);
                    if (p != NULL)
                        printf("\nLE NOEUD EXTRAIT EST %d", p->cle);
                    printf("\nAFFICHAGE DU TAS BINOMIAL:\n");
                    afficher(H);
                    printf("\nEXTRAIRE PLUS(y/Y)\n");
                    fflush(stdin);
                    scanf("%c", &ch);
                } while (ch == 'Y' || ch == 'y');
                break;
            case 3:
                do {
                    printf("\nENTREZ LA CLE DU NOEUD A DIMINUER:");
                    scanf("%d", &m);
                    Tas_Binomial noeud = trouver_Noeud(H, m);
                    printf("\nENTER LA NOUVELLE CLE : ");
                    scanf("%d", &l);
                    modifier_Cle(H, noeud, l);
                    printf("\nAFFICHAGE DU TAS BINOMIAL:\n");
                    afficher(H);
                    printf("\nDIMINUER PLUS(y/Y)\n");
                    fflush(stdin);
                    scanf("%c", &ch);
                } while (ch == 'Y' || ch == 'y');
                break;
            case 4:
                do {
                    printf("\nENTREZ LA CLE A SUPPRIMER: ");
                    supprimer_Min(H);
                    printf("\nSUPPRIMER PLUS(y/Y)\n");
                    fflush(stdin);
                    scanf("%c", &ch);
                } while (ch == 'y' || ch == 'Y');
                break;
            case 5:
                printf("\nMERCI\n");
                break;
            default:
                printf("\nENTREE INVALIDE...REESSAYE....\n");
        }
    } while (l != 5);
    return 0;
}
