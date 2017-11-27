#include <stdio.h>
#include "PFL.h"

typedef int Element;

void print_str(char *str) {
    int i = 0;
    while (str[i])
        putchar(str[i++]);
}

int show_menu_piles() {
    int c = 0;

    print_str("Que voulez-vous faire ?\n1. Afficher la pile\n2. Empiler un element\n3. Depiler\n");
    scanf("%d", &c);
    return c;
}

int show_menu_files() {
    int c = 0;

    print_str("Que voulez-vous faire ?\n1. Afficher la file\n2. Enfiler un element\n3. Defiler\n");
    scanf("%d", &c);
    return c;
}

int show_menu() {
    int c = 0;

    print_str("Que voulez-vous faire ?\n1. Piles\n2. Files\n");
    scanf("%d", &c);
    return c;
}

void Afficher_File(File f) {
    int n = 0, min = f.Tete, max = f.Queue;
    for (n = min; n < max; n++)
        printf("-> %d ", f.F[n]);
    putchar('\n');
}

void Afficher_Pile(Pile p) {
    if (Pile_Vide(p))
        return;
    Pile p1 = p;
    while (p1) {
        printf("-> %d ", p1->Valeur);
        p1 = p1->Suivant;
    }
    putchar('\n');
}

void gestion_files() {
    int c;
    File f = {0};
    Element e = 0;

    while (1) {
        c = show_menu_files();
        switch (c) {
            case 1:
                printf("Affichage de la File :\n");
                Afficher_File(f);
                break;
            case 2 :
                printf("Quel element voulez-vous enfiler ?\n");
                scanf("%d", &e);
                f = Enfiler(f, e);
                break;
            case 3:
                printf("La premiere valeur a ete defilee.\n");
                f = Defiler(f);
                break;
            default :
                return;
        }
    }
}

void gestion_piles() {
    int c;
    Pile p = Creer_Pile();
    Element e = 0;

    while (1) {
        c = show_menu_piles();
        switch (c) {
            case 1:
                printf("Affichage de la Pile :\n");
                Afficher_Pile(p);
                break;
            case 2 :
                printf("Quel element voulez-vous empiler ?\n");
                scanf("%d", &e);
                p = Empiler(p, e);
                break;
            case 3 :
                printf("La premiere valeur a ete depilee.\n");
                p = Depiler(p);
                break;
            default :
                return;
                break;
        }
    }
}

int main() {
    switch(show_menu()) {
        case 1 :
            gestion_piles();
            break;
        case 2:
            gestion_files();
            break;
    }
    return 0;
}
