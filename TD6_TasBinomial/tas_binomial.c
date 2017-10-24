#include <stdio.h>

typedef struct noeud{
	int cle;
	int degre;
	struct noeud *pere,*pfg,*pfd,*pred; //  pfd correspond à premier Frere droit et non a premier fils droits
}*TasBinomial;

TasBinomial allouer(int cle){
    TasBinomial tas = (TasBinomial) malloc (sizeof(struct noeud));
    tas->cle=cle;
    tas->degre=0;
    tas->pere=NULL;
    tas->pred=NULL;
    tas->pfg=NULL;
    tas->pfd=NULL;
    return tas;
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
