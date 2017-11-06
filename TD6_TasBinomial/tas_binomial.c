#include <stdio.h>
#include <stdlib.h>

typedef struct noeud{
	int cle;
	int degre;
	struct noeud *pere,*pfg,*pfd,*pred; //  pfd correspond à premier Frere droit et non a premier fils droits
}*TasBinomial;

TasBinomial allouerCle(int cle);
TasBinomial allouer();
void lier(TasBinomial futurFils, TasBinomial futurPere);
TasBinomial cle_min(TasBinomial A);
TasBinomial fusion_tas(TasBinomial t1, TasBinomial t2);
TasBinomial union_tas(TasBinomial t1, TasBinomial t2);
TasBinomial inserer_tas(TasBinomial t, TasBinomial x);
TasBinomial diminuer_cle(TasBinomial t, TasBinomial x, int k);

void main(){
    TasBinomial tasPrincipale = allouerCle(5);
    TasBinomial nouveauNoeud = allouerCle(17);
    //tasPrincipale = inserer_tas(tasPrincipale,nouveauNoeud);

return 0;
}

TasBinomial allouerCle(int cle){
    TasBinomial tas = (TasBinomial) malloc (sizeof(struct noeud));
    tas->cle=cle;
    tas->degre=0;
    tas->pere=NULL;
    tas->pred=NULL;
    tas->pfg=NULL;
    tas->pfd=NULL;
    return tas;
}
TasBinomial allouer(){
    TasBinomial tas = (TasBinomial) malloc (sizeof(struct noeud));
    /*tas->cle=0;
    tas->degre=0;
    tas->pere=NULL;
    tas->pred=NULL;
    tas->pfg=NULL;
    tas->pfd=NULL;*/
    return tas;
}
/**
* Va lier un noeud, futurFils à un tas, futurPere
*/
void lier(TasBinomial futurPere, TasBinomial futurFils){
    futurFils->pere = futurPere;
    futurFils->pfd = futurPere->pfg;
    futurPere->pfg = futurFils;
    futurPere->degre = futurPere->degre + 1;
}

/**
* Retourne le noeud avec la plus petite clé
* La clé minimale se trouve dans une racine des arbres du tas binomial.
*/
TasBinomial cle_min(TasBinomial A){
    int minCle = 1000000;   // c <- infinis
    TasBinomial B,C;
    B = A;
    C = A;
    while(B != NULL){
        if(B->cle < minCle){
            minCle = B->cle;
            C = B;
        }
        B = B->pfd;
    }
    return C;

}
/**
* Va fusioner deux tas pour en former un seul, sans ce soucier d'avoir plusieurs sous tas de meme degré
*/
TasBinomial fusion_tas(TasBinomial t1, TasBinomial t2){
    TasBinomial t = allouer();
    while((t1 != NULL) && (t2 != NULL)){
        if(t1->degre == t2->degre){
            t = inserer_tas(t,t1);
            t = inserer_tas(t,t2);
            t1 = t1->pfd;
            t2 = t2->pfd;
        }
        else if(t1->degre < t2->degre){
            t = inserer_tas(t,t1);
            t1 = t1->pfd;
        }
        else{
            t = inserer_tas(t,t2);
            t2 = t2->pfd;
        }
    }
    while(t1 != NULL){
        t = inserer_tas(t,t1);
        t1 = t1->pfd;
    }
    while(t2 != NULL){
        t = inserer_tas(t,t2);
        t2 = t2->pfd;
    }

    return t;
}
/**
* Va fusionner des tas et ajuster les différents sous tas pour avoir réellement un tas binomial avec des degrés valide
*/
TasBinomial union_tas(TasBinomial t1, TasBinomial t2){
    TasBinomial t = allouer();
    t = fusion_tas(t1,t2);
    if(t == NULL){
        return t;
    }
    else{
        TasBinomial pred = NULL;
        TasBinomial x = t;
        TasBinomial succ = x->pfd;
        while(succ != NULL){
            if((x->degre != succ->degre) || (succ->pfd != NULL) && (succ->pfd->degre == x->degre)){
                pred = x;
                x = succ;
            }
            else if(x->cle <= succ->cle){
                x->pfd = succ ->pfd;
                lier(succ,x);   // Peut etre une erreur dans le cours, va théoriquement conduire à un tas max, à vérifier
            }
            else{
                if(pred == NULL){
                    t = succ;
                }
                else{
                    pred->pfd = succ; // Peut etre une erreur dans le cours, va théoriquement conduire à un tas max, à vérifier
                }
                lier(x,succ);
                x = succ;
            }
            succ = x->pfd;
        }
        return t;
    }

}
TasBinomial inserer_tas(TasBinomial t, TasBinomial x){
    TasBinomial t1 = allouer();
    x->pere = NULL;
    x->pfg = NULL;
    x->pfd = NULL;
    x->degre = 0;
    t1 = x; // Voir avec le proffesseur, dans le cours "Tete[T1] <- x", aucune autre mension de tete
    t1 = union_tas(t1,t);
    return t1;
}
TasBinomial diminuer_cle(TasBinomial t, TasBinomial x, int k){
    TasBinomial y,z;
    int tempValue;
    if(k > x->cle){
        return NULL;
    }
    else{
        x->cle = k;
        y = x;
        x = y->pere;
        while((x != NULL) && (y->cle < x->cle)){
            tempValue = y->cle;
            y->cle = x->cle;
            x->cle = tempValue;
            y = x;
            x = y->pere;
        }
        return t;
    }
}

TasBinomial getPred(TasBinomial tas){
    return tas->pred;
}

TasBinomial getPere(TasBinomial tas){
    return tas->pere;
}

TasBinomial getPfg(TasBinomial tas){
    return tas->pfg;
}
TasBinomial getPfd(TasBinomial tas){
    return tas->pfd;
}
int getCle(TasBinomial tas){
    return tas->cle;
}
int getDegre(TasBinomial tas){
    return tas->degre;
}
