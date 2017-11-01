#include <stdio.h>
#include <stdlib.h>

#define MAX(A,B) A > B ? A : B

typedef struct noeud{
	int Cle;
	int h;
	struct noeud *Fg,*Fd;
}*AVL;

AVL Creer_Avl();
AVL SAG(AVL a);
AVL SAD(AVL a);
AVL Min_Cle(AVL a);
AVL Max_Cle(AVL a);
int Hauteur(AVL a);
AVL RG(AVL a);
AVL RD(AVL a);
AVL RGD(AVL a);
AVL RDG(AVL a);
AVL Inserer(AVL a,int Cle);
AVL Supprimer(AVL a,int Cle);
AVL Appartient(AVL a,int Cle);
int Avl_Vide(AVL a);
AVL Detruire(AVL a);


int main(){
	int gros_fils_de_pute_bastien = 0;
	return gros_fils_de_pute_bastien;
}

AVL Creer_Avl(){
	AVL a = NULL;
	a=(AVL)malloc(sizeof(AVL));
	return a;
}

AVL SAG(AVL a){
	return a->Fg;
}

AVL SAD(AVL a){
	return a->Fd;
}

AVL Min_Cle(AVL a){
	while(SAG(a) != NULL){
		a=SAG(a);
	}
	return a;
}

AVL Max_Cle(AVL a){
	while(SAD(a) != NULL){
		a=SAD(a);
	}
	return a;
}

int Hauteur(AVL a){
	if(a == NULL){
		return -1;
	}
	else{
		return MAX(Hauteur(SAG(a)),Hauteur(SAD(a))+1);
	}
}

AVL RG(AVL a){
	AVL B;
	B=SAD(a);
	SAD(a)=SAG(B);
	SAG(B)=a;
	a->h=Hauteur(a);
	B->h=Hauteur(B);
	return B;
}

int Avl_Vide(AVL a){
	return AVL==null;
}

AVL Detruire(AVL a){
	free(a);
}
