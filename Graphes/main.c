#include <stdio.h>

int i, j, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];

int find(int);

int uni(int, int);

int main() {
    printf("\n\tAlgorithme de Kruskal\n\tGestion des Graphes\n");
    printf("\nQuel est le nombre de sommets ?");
    scanf("%d", &n);
    printf("\nMatrice d'agencement ? Format :\nx1 x2 ... xn\ny1 y2 ... yn\nz1 z2 ... zn\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    printf("Les couts minimaux des aretes de l'arbre sont : \n");
    while (ne < n) {
        for (i = 1, min = 999; i <= n; i++)
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        u = find(u);
        v = find(v);
        if (uni(u, v)) {
            printf("%d. Arete (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nCout minimal = %d\n", mincost);

    return 0;
}

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i == j)
        return 0;
    parent[j] = i;
    return 1;
}
