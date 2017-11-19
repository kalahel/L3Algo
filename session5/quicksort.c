#include <stdio.h>

#define TABSIZE 10
#define DEBUGMODE 0 // 1 Pour avoir un affichage détaillé des opérations réalisé

int partitionnement(int *tab, int debutTab, int sizetab);

void triRapide(int *tab, int debutTab, int sizetab);

void menuAffichageTable(int *tab, int sizetab);

void swapValues(int *valeur1, int *valeur2);

int main() {

    int tableauATrier[TABSIZE] = {3, 2, 5, 9, 4, 6, 10, 1, 14, 8};
    menuAffichageTable(tableauATrier, TABSIZE);
    triRapide(tableauATrier, 0, TABSIZE - 1);
    menuAffichageTable(tableauATrier, TABSIZE);
    return 0;
}


void menuAffichageTable(int *tab, int sizetab) {
    int i = 0;
    printf("\nTableau :\n");
    for (i = 0; i < sizetab; i++) {
        printf("%d\t", tab[i]);
    }
}

void triRapide(int *tab, int debutTab, int sizetab) {

    if (debutTab < sizetab) {
        int index_pivot = partitionnement(tab, debutTab, sizetab);
        triRapide(tab, debutTab, index_pivot - 1);
        triRapide(tab, index_pivot + 1, sizetab);
    }
}

int partitionnement(int *tab, int debutTab, int sizetab) {
    int i = debutTab - 1;
    int j = debutTab;
    int emplacementPivot = sizetab;
    int pivot = tab[emplacementPivot];

    if (DEBUGMODE)
        printf("\n\npivot  : %d\n", pivot);

    while (j != emplacementPivot) {
        if (tab[j] < pivot) {
            i++;
            if (DEBUGMODE)
                printf("Echange : %d et %d\n", tab[i], tab[j]);
            swapValues(&tab[i], &tab[j]);
        }
        j++;
    }
    swapValues(&tab[i + 1], &tab[emplacementPivot]);
    if (DEBUGMODE) {
        printf("Nouvel index pour le pivot : %d\n", i + 1);
        menuAffichageTable(tab, TABSIZE);
    }
    return i + 1;
}

void swapValues(int *valeur1, int *valeur2) {
    int temp = *valeur1;
    *valeur1 = *valeur2;
    *valeur2 = temp;
}
