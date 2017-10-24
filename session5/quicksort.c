
void swap(int tab[],int i, int j);
int partition(int tab[],int inf,int sup);
int main(void){

return 0;
}

void swap(int tab[],int i, int j){
    int swapper = tab[i];
    tab[i] = tab[j];
    tab[j] = swapper;
    return;
}
int partition(int tab[],int inf,int sup){
    int j = inf;
    int pivot = tab[inf];
    int i;
    for(i = inf + 1; i <= sup; i++){
        if(tab[i]<pivot){            j++;
            swap(tab,i,j);
        }
    }
    swap(tab,j,inf);
    return(j);
}
