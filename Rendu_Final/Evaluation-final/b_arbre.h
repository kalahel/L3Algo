#include <stdio.h>
#include <stdlib.h>
#define degre (2)

typedef enum{Faux , Vrai} Booleen;
typedef struct noeud{
	int NFils, NCles;               //Number of children and keys
	int C[2*degre];                 //Array of keys
	Booleen Feuille;                //Leaf or not
	struct noeud *Fils[2*degre+1];  //Array of children
}*B_Arbre;


void DeleteKey(B_Arbre barbre,int key);

/**
*The function to create a B_Arbre with a malloc
*/
B_Arbre createTree();
B_Arbre createTree(){

    B_Arbre barbre;
    barbre = (B_Arbre)malloc(sizeof(*barbre));
    barbre->Feuille = Vrai;
    barbre->NCles = 0;

    return barbre;
}

/**
* The function to recursivly suppress a B_Arbre
*/
void FreeTree();
void FreeTree(B_Arbre barbre){
    int i;
    for(i = 0;i < barbre->NCles; i++){
        if(barbre->Feuille == Faux){
            FreeTree(barbre->Fils[i]);
        }
    }
    //Last child
    if(barbre->Feuille == Faux){
        FreeTree(barbre->Fils[i]);
    }
    free(barbre);
}

/**
* The function to search a key in a B_Arbre
* The function will parse the B_Arbre recursivly
*/

void FindKey(B_Arbre barbre,int key);
void FindKey(B_Arbre barbre,int key){

    //First, we have to check if the B_Arbre is empty
    if(barbre->NCles == 0){
        printf("Element %d is not in the tree\n",key);
        return;
    }

    //Then, we have to find in the arrey of keys
    int i=0;
    while((i<barbre->NCles)&&(key>barbre->C[i])){
        i++;
    }
    if(barbre->C[i] == key){
        printf("Element %d is in the tree\n",key);
        return;
    }
    if(barbre->Feuille == Vrai){
        printf("Element %d is not in the tree\n",key);
        return;
    }
    FindKey(barbre->Fils[i],key);
}

/**
* This function is here to split a node's child
* It has to be full
*/

void Split_Nodes(int i,B_Arbre barbre,B_Arbre arbre2){

    //We have to create a new node
    B_Arbre b2 = createTree();
    if(barbre->Feuille == Faux) b2->Feuille = Faux;   // Le nouveau B_Arbre créé sera une feuille si barbre en est une
    b2->NCles = degre -1; // Le nouveau B_Arbre contiendra degre-1 clés lors du split

    //we now have to copy the last keys (degre-1) from barbre to b2
    int j;
    for(j = 0;j < degre-1;j++){
        b2->C[j] = barbre ->C[j + degre];
    }

    //and we now have to cpy the last children (degre) from barbre to b2
    if(barbre->Feuille == Faux){
        for(j = 0;j < degre; j++){
            b2->Fils[j] = barbre->Fils[j+degre];
        }
    }

    //we reduce the number of keys in barbre
    barbre->NCles = degre-1;

    //Create new space for the new child
    for(j = arbre2->NCles;j >= i+1;j--){
        arbre2->Fils[j+1] = arbre2->Fils[j];
    }

    //link the new child
    arbre2->Fils[i+1] = b2;

    //We have to move a key from barbre to arbre2
    //We first have to move the greater keys ahead
    for(j = arbre2->NCles-1;j >= i;j--){
        arbre2->C[j+1] = arbre2->C[j];
    }

    //increment count of keys
    arbre2->NCles++;

    //And now copy the middle key
    printf("%d\n",barbre->C[degre-1]);
    arbre2->C[i] = barbre->C[degre-1];

}


/**
* This function is here to add a key in a current B_Arbre
* We assume that the B_Arbre isn't full when this function is called
*/
void addKeyNode(B_Arbre barbre,int key);
void addKeyNode(B_Arbre barbre,int key){

    int i = barbre->NCles-1;

    //if this B_Arbre is a leaf
    if(barbre->Feuille == Vrai){

        //We search the best location for the key
        //And we moves all greater keys
        while((i >= 0) && (barbre->C[i] > key)){
            barbre->C[i+1] = barbre->C[i];
            i--;
        }

        //Then we insert the new key
        barbre->C[i+1] = key;
        barbre->NCles++;
    }

    //If this B_Arbre is not a leaf
    else{

        //Find the child which has to get the key
        while((i >= 0) && (barbre->C[i]>key)){
            i--;
        }

        //We check is the child is full
        if(barbre->Fils[i+1]->NCles == 2*degre-1){

            //If the child is full, we have to split it
            Split_Nodes(i+1,barbre->Fils[i+1],barbre);

            //the middle key goes up
            //the chield is splitted into two
            //We now have to see which one of these two will have the key
            if(barbre->C[i+1] < key){
                i++;
            }
        }
        addKeyNode(barbre->Fils[i+1],key);
    }
}


/**
* The function to add a key in a B_Arbre
* The function will find the best choice
* Moreover this function will check 3,possibilities:
*   - The B_Arbre is empty
*   - The B_Arbre is full
*   - The current B_Arbre can have the key
* In the two last possibilites, we have to insert the key thanks to an other function
*/
B_Arbre addKey(B_Arbre barbre,int key);
B_Arbre addKey(B_Arbre barbre,int key){

    // if the current B_Arbre is empty
    if(barbre == NULL){
        barbre = createTree();          // Create a new B_Arbre
        barbre->C[0] = key;             // Insert the key
        barbre->NCles = 1;              // Updating the number of keys
        return barbre;                  // The root is still barbre
    }
    // If the tree is not empty
    else{
        // If the barbre is full,
        if(barbre->NCles == 2*degre-1){

            B_Arbre b3 = createTree();  // We create a new B_Arbre
            b3->Feuille = Faux;         // Ce B_Arbre ne sera pas une feuille
            b3->Fils[0] = barbre;       // The barbre becomes the child of the new barbre
            Split_Nodes(0,barbre,b3);   // We split the old barbre and 1 key is fot the new root

            int i = 0;
            if(b3->C[0] < key){
                i++;
            }
            addKeyNode(b3->Fils[i],key);

            return b3;                  // The new root is the b3
        }

        //If the barbre is not full
        else{
            addKeyNode(barbre,key);
            return barbre;              // The root is still barbre
        }
    }
}

/**
* A function to get the predecessor of the key- where the key
* is present in the idx-th position in the node
*/
int getPred(B_Arbre barbre,int index){

    // Keep moving to the right most node until we reach a leaf
    B_Arbre cur = createTree();
    cur=barbre->Fils[index];
    while (cur->Feuille == Faux)
        cur = cur->Fils[cur->NCles];

    // Return the last key of the leaf
    return cur->C[cur->NCles-1];

}


/**
* A function to get the successor of the key- where the key
* is present in the idx-th position in the node
*/
int getSucc(B_Arbre barbre,int index){

    // Keep moving the left most node starting from C[idx+1] until we reach a leaf
    B_Arbre cur = createTree();
    cur = barbre->Fils[index+1];
    while (cur->Feuille == Faux)
        cur = cur->Fils[0];

    // Return the first key of the leaf
    return cur->C[0];
}


/**
* This function will check all the keys for each nodes in a B_Arbre
*/

void ShowTree(B_Arbre barbre,int hauteur);
void ShowTree(B_Arbre barbre,int hauteur){

    int i;

    // There are a maximum of NCles keys and NCles+1 children for each nodes
    for(i = 0;i < barbre->NCles; i++){

        //If this is not a a leaf, Show the children trees
        if(barbre->Feuille == Faux){
            ShowTree(barbre->Fils[i],hauteur+1);
        }
        printf("|%d|",barbre->C[i]);
        printf("\t\tElement n:%d",i);
        printf("---Hauteur n:%d\n",hauteur);
    }
    //Last child
    if(barbre->Feuille == Faux){
        ShowTree(barbre->Fils[i],hauteur+1);
    }
}

/**
* This unction will return the good index
*/
int SearchKey(B_Arbre barbre,int key);
int SearchKey(B_Arbre barbre,int key){
    int index = 0;
    while((index < barbre->NCles)&&(barbre->C[index] < key)){
        ++index;
    }
    return index;
}

/**
* A function to merge idx-th child of the node with (idx+1)th child of
* the node
*/
void Merge_Tree(B_Arbre barbre,int index){

    B_Arbre child = createTree();
    B_Arbre sibling = createTree();
    child = barbre->Fils[index];
    sibling = barbre->Fils[index+1];

    // Pulling a key from the current node and inserting it into (t-1)th
    // position of C[idx]
    child->C[degre-1] = barbre->C[index];

    // Copying the keys from C[idx+1] to C[idx] at the end
    int i;
    for (i=0; i<sibling->NCles; ++i)
        child->C[i+degre] = sibling->C[i];

    // Copying the child pointers from C[idx+1] to C[idx]
    if (child->Feuille == Faux)
    {
        for(i=0; i<=sibling->NCles; ++i)
            child->Fils[i+degre] = sibling->Fils[i];
    }

    // Moving all keys after idx in the current node one step before -
    // to fill the gap created by moving keys[idx] to C[idx]
    for (i=index+1; i< barbre->NCles; ++i)
        barbre->C[i-1] = barbre->C[i];

    // Moving the child pointers after (idx+1) in the current node one
    // step before
    for (i=index+2; i<=barbre->NCles; ++i)
        barbre->Fils[i-1] = barbre->Fils[i];

    // Updating the key count of child and the current node
    child->NCles += sibling->NCles+1;
    barbre->NCles--;

    // Freeing the memory occupied by sibling
    free(sibling);
    return;
}

/**
* A function to remove the key present in idx-th position in
* this node which is a leaf
*/
void removeFromLeaf(B_Arbre barbre,int index){

    // Move all the keys after the idx-th pos one place backward
    int i;
    for (i = index+1; i < barbre->NCles; ++i){
        barbre->C[i-1] = barbre->C[i];
    }

    // Reduce the count of keys
    barbre->NCles--;

    return;
}

/**
* A function to borrow a key from the C[idx-1]-th node and place
* it in C[idx]th node
*/
void borrowFromPrev(B_Arbre barbre,int index){

    B_Arbre child = createTree();
    B_Arbre sibling = createTree();
    child=barbre->Fils[index];
    sibling=barbre->Fils[index-1];

    // The last key from C[idx-1] goes up to the parent and key[idx-1]
    // from parent is inserted as the first key in C[idx]. Thus, the  loses
    // sibling one key and child gains one key
    // Moving all key in C[idx] one step ahead

    int i;
    for (i=child->NCles-1; i >=0 ; --i)
        child->C[i+1] = child->C[i];

    // If C[idx] is not a leaf, move all its child pointers one step ahead
    if (child->Feuille == Faux)
    {
        for(i=child->NCles; i>=0; --i)
            child->Fils[i+1] = child->Fils[i];
    }

    // Setting child's first key equal to keys[idx-1] from the current node
    child->C[0] = barbre->C[index-1];

    // Moving sibling's last child as C[idx]'s first child
    if (child->Feuille == Faux)
        child->Fils[0] = sibling->Fils[sibling->NCles];

    // Moving the key from the sibling to the parent
    // This reduces the number of keys in the sibling
    barbre->C[index-1] = sibling->C[sibling->NCles-1];

    child->NCles += 1;
    sibling->NCles -= 1;

    return;
}

/**
* A function to borrow a key from the C[idx+1]-th node and place it
* in C[idx]th node
*/
void borrowFromNext(B_Arbre barbre,int index){

    B_Arbre child = createTree();
    B_Arbre sibling = createTree();
    child=barbre->Fils[index];
    sibling=barbre->Fils[index+1];
    int i;
    // keys[idx] is inserted as the last key in C[idx]
    child->C[(child->NCles)] = barbre->C[index];

    // Sibling's first child is inserted as the last child
    // into C[idx]
    if (child->Feuille == Faux)
        child->Fils[child->NCles+1] = sibling->Fils[0];

    //The first key from sibling is inserted into keys[idx]
    barbre->C[index] = sibling->C[0];

    // Moving all keys in sibling one step behind
    for (i=1; i<sibling->NCles; ++i)
        sibling->C[i-1] = sibling->C[i];

    // Moving the child pointers one step behind
    if (sibling->Feuille == Faux)
    {
        for(i=1; i<=sibling->NCles; ++i)
            sibling->Fils[i-1] = sibling->Fils[i];
    }

    // Increasing and decreasing the key count of C[idx] and C[idx+1]
    // respectively
    child->NCles += 1;
    sibling->NCles -= 1;

    return;
}


/**
* A function to remove the key present in idx-th position in
* this node which is a non-leaf node
*/
void removeFromNonLeaf(B_Arbre barbre,int index){

    int k = barbre->C[index];

    // If the child that precedes k (C[idx]) has atleast t keys,
    // find the predecessor 'pred' of k in the subtree rooted at
    // C[idx]. Replace k by pred. Recursively delete pred
    // in C[idx]
    if (barbre->Fils[index]->NCles >= degre)
    {
        int pred = getPred(barbre,index);
        barbre->C[index] = pred;
        DeleteKey(barbre->Fils[index],pred);
    }

    // If the child C[idx] has less that t keys, examine C[idx+1].
    // If C[idx+1] has atleast t keys, find the successor 'succ' of k in
    // the subtree rooted at C[idx+1]
    // Replace k by succ
    // Recursively delete succ in C[idx+1]
    else if  (barbre->Fils[index+1]->NCles >= degre)
    {
        int succ = getSucc(barbre,index);
        barbre->C[index] = succ;
        DeleteKey(barbre->Fils[index+1],succ);
    }

    // If both C[idx] and C[idx+1] has less that t keys,merge k and all of C[idx+1]
    // into C[idx]
    // Now C[idx] contains 2t-1 keys
    // Free C[idx+1] and recursively delete k from C[idx]
    else
    {
        Merge_Tree(barbre,index);
        DeleteKey(barbre->Fils[index],k);
    }
    return;

}

/**
* A function to fill up the child node present in the idx-th
* position in the C[] array if that child has less than t-1 keys
*/
void FillTree(B_Arbre barbre,int index){

    // If the previous child(C[idx-1]) has more than t-1 keys, borrow a key
    // from that child
    if ((index != 0) && (barbre->Fils[index-1]->NCles >= degre)){
        borrowFromPrev(barbre,index);
    }

    // If the next child(C[idx+1]) has more than t-1 keys, borrow a key
    // from that child
    else if ((index != barbre->NCles) && (barbre->Fils[index+1]->NCles >= degre)){
        borrowFromNext(barbre,index);
    }

    // Merge Fils[index] with its sibling
    // If Fils[index] is the last child, merge it with with its previous sibling
    // Otherwise merge it with its next sibling
    else{
        if (index != barbre->NCles){
            Merge_Tree(barbre,index);
        }
        else{
            Merge_Tree(barbre,index-1);
        }
    }
    return;
}




/**
* Function to delete a key from a B_Arbre
* This function will call other functions
*/

void DeleteKey(B_Arbre barbre,int key){

    int index = SearchKey(barbre,key);

    // The key to be removed is present in this node
    if ((index < barbre->NCles) && (barbre->C[index] == key)){
        // If the node is a leaf node
        if (barbre->Feuille == Vrai){
            removeFromLeaf(barbre,index);
        }
        //otherwise
        else{
            removeFromNonLeaf(barbre,index);
        }
    }
    else{

        // If this node is a leaf
        if (barbre->Feuille == Vrai){
            printf("the key is not in the tree\n");
            return;
        }

        // The key to be removed is present in the sub-tree rooted with this node
        // The flag indicates whether the key is present in the sub-tree rooted
        // with the last child of this node
        Booleen flag;
        if(index == barbre->NCles){
            flag = Vrai;
        }
        else{
            flag = Faux;
        }
        // If the child where the key is supposed to exist has less that t keys,
        // we fill that child
        if (barbre->Fils[index]->NFils < degre){
            FillTree(barbre->Fils[index],index);
        }

        // If the last child has been merged, it must have merged with the previous
        // child and so we recurse on the (idx-1)th child. Else, we recurse on the
        // (idx)th child which now has atleast t keys
        if ((flag == Vrai) && (index > barbre->NCles)){
            DeleteKey(barbre->Fils[index-1],key);
        }
        else{
            DeleteKey(barbre->Fils[index],key);
        }
    }
    return;
}

