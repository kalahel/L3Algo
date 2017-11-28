
#include <stdio.h>
#include <stdlib.h>
#define nombre_sommet 6
#include <limits.h>
#include <string.h>

int i, j, a, b, u, v, n, ne = 1;
int minimum, mincost = 0, cost[9][9], parent[9];

typedef struct route{
    int source;
    int destination;
    int poids;
}*route;

typedef struct graph{
    int NSommet;
    int NRoute;
    route *route;
}*graph;

graph CreateGraph(int Nsommet,int Nroute){
    graph g = (graph)malloc(sizeof(graph));

    g->NRoute = Nroute;
    g->NSommet = Nsommet;
    return g;
}

typedef struct sous_ensemble{
    int papa;
    int rang;
}*sous_ensemble;

int Find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int Union(int i, int j) {
    if (i == j)
        return 0;
    parent[j] = i;
    return 1;
}


/*int Find(sous_ensemble se,int i) {
    if (se[i].papa !=i)
        se[i].papa = Find(se,se[i].papa);
    return i;
}

void Union(sous_ensemble se, int x, int y)
{
    int xroot = Find(se, x);
    int yroot = Find(se, y);

    // Attach smaller rank tree under root of high
    // rank tree (Union by Rank)
    if (se[xroot].rang < se[yroot].rang)
        se[xroot].papa = yroot;
    else if (se[xroot].rang > se[yroot].rang)
        se[yroot].papa = xroot;

    // If ranks are same, then make one as root and
    // increment its rank by one
    else
    {
        se[yroot].papa = xroot;
        se[xroot].rang++;
    }
}*/

int minimumKey(int *key, Booleen *mstSet)
{
    // Initialize min value
    int mini = INT_MAX;
    int min_index=0;
    int i;
    for (i = 0; i < nombre_sommet; i++)
        if ((mstSet[i] == Faux) && (key[i] < mini)){
            printf("key[%d] = %d\n",i,key[i]);
            mini = key[i];       //On cherche le minimum
            min_index = i;      //On prend le sommet minimum
        }
        printf("mini index = %d\n",min_index);
    return min_index;
}



void Prim(int graph[nombre_sommet][nombre_sommet]){

    int parent[nombre_sommet];  // Arbre couvrant minimal
    int key[nombre_sommet];     // les clés pour choisir les poids minimum
    Booleen matriceset[nombre_sommet]; //Les inclues ou non dans l'arbre final

    int i;
    for(i = 0;i < nombre_sommet;i++){
        key[i] = INT_MAX;           //toutes les clés sont initialisées à l'infini
        matriceset[i] = Faux;       //aucune clée n'est dans l'arbre final au debut
    }

    //On prend toujours le premier sommet
    key[0] = 0;                     //LE premier sommet est pris
    parent[0] = -1;                 //La racine
    int j;
    for(i = 0;i < nombre_sommet-1;i++){

        int u = minimumKey(key,matriceset);   // On prend le plus petit sommet
        matriceset[u] = Vrai;                 // Le sommmet va dans l'arbre couvrant minimal

        for(j = 0;j < nombre_sommet;j++){
            //On prend tous ceux inferieur à leuurs valeur de la key, et superieur à 0 (donc qui ont un lien)
            if (graph[u][j] && matriceset[j] == Faux && graph[u][j] <  key[j]){
                parent[j]  = u;
                key[j] = graph[u][j];
                printf("parent[%d] = %d\n",j+1,u+1);
                printf("key[%d] = graph[%d][%d]\n",j+1,u,j);
                printf("key[%d] = %d\n",j+1,graph[u][j]);
            }
        }
        printf("\n\n");
    }
    printf("Lien   Poids\n");
    int somme = 0;
    for (i = 1; i < nombre_sommet; i++){
        printf("%d - %d    %d \n", parent[i]+1, i+1, graph[i][parent[i]]);
        somme = somme + graph[i][parent[i]];
    }
    printf("Le poids minimum de cette arbre est de %d\n",somme);
}

void creationMatrice(int graph[nombre_sommet][nombre_sommet]){
    int i;
    int j;
    int choix;
    for(i = 0;i < nombre_sommet;i++){
        for(j = 0;j < nombre_sommet;j++){
            printf("Poids entre %d et %d ?\n",i,j);
            scanf("%d",&choix);
            graph[i][j] = choix;
        }
    }
}

void affichageMatrice(int graph[nombre_sommet][nombre_sommet]){
    int i;
    int j;
    printf("Matrice[%d][%d] = {\n",nombre_sommet,nombre_sommet);
    for(i = 0;i < nombre_sommet;i++){
            printf("\t\t{");
        for(j = 0;j < nombre_sommet;j++){
            printf("%d,",graph[i][j]);
        }
        printf("}\n");
    }
    printf("\t\t};\n");
}

void resetMatrice(int graph[nombre_sommet][nombre_sommet]){
    int i;
    int j;
    for(i = 0;i < nombre_sommet;i++){
        for(j = 0;j < nombre_sommet;j++){
            graph[i][j] = 0;
        }
    }
}

void libereMatrice(int graph[nombre_sommet][nombre_sommet]){
    int i;
    int j;
    for(i = nombre_sommet-1;i >= 0;i--){
        for(j = nombre_sommet-1;j < 0;j--){
            free((int*)graph[i][j]);
        }
    }
}

void exempleMatrice(int graph[nombre_sommet][nombre_sommet],int exemple[nombre_sommet][nombre_sommet]){
    int i;
    int j;
    for(i = 0;i < nombre_sommet;i++){
        for(j = 0;j < nombre_sommet;j++){
            graph[i][j] = exemple[i][j];
        }
    }
}
/*
// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int Comparaison(const void* a, const void* b)
{
    route a1 = (route) a;
    route b1 = (route)b;
    return a1->poids > b1->poids;
}

void Krustal(graph graph){
    int sommet = graph->NSommet;        //Nombre de sommet du graphe
    route arbre_final[sommet];   //arbre final
    int i = 0;

    //Etape N°1 : classer les routes par ordre croissant de leurs poids
    qsort(graph->route,graph->NRoute,sizeof(graph->route[0]),Comparaison);

    //on crée maintenant autant de sous ensemble qu'il y a de sommets
    sous_ensemble se = (sous_ensemble)malloc(sommet*sizeof(sous_ensemble));

    //on initialise les sous ensembles
    for(i = 0; i < sommet;i++){
        se[i].papa = i;
        se[i].rang = 0;
    }

    //Nombre de route dans cette algorithme est egal au nombre de sommet moins 1
    i=0;
    int Nroute = 0;
    while(i < sommet-1){

        //etape 2 : on choisit la route avec le plus petit poids
        route nouvelle_route = graph->route[Nroute++];

        int x = Find(se,nouvelle_route->source);
        int y = Find(se,nouvelle_route->destination);

        //On regarde si la route ne créé pas de cycle
        if(x != y){
            arbre_final[i++] = nouvelle_route;
            Union(se,x,y);
        }
        //Sinon on ignore
    }
    int j;
    printf("Following are the edges in the constructed MST\n");
    for (j = 0; j < i; ++j)
        printf("%d -- %d == %d\n", arbre_final[i]->source, arbre_final[i]->destination,
                                                 arbre_final[i]->poids);
    return;
}

graph conversionMatrice(int M[nombre_sommet][nombre_sommet]){
    int i,j;
    graph g;
    int Nroute=0;
    for(i = 0;i < nombre_sommet;i++){
        for(j = 0;j < nombre_sommet;j++){
            if(M[i][j] !=0){
                Nroute++;
            }
        }
    }
    g = CreateGraph(nombre_sommet,Nroute);
    Nroute=0;
    for(i = 0;i < nombre_sommet;i++){
        for(j = 0;j < nombre_sommet;j++){
            if(M[i][j] !=0){
                g->route[Nroute]->source = i;
                g->route[Nroute]->destination = j;
                g->route[Nroute]->poids = M[i][j];
                Nroute++;
            }
        }
    }
    return g;
}*/
