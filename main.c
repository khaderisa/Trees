#include <stdio.h>
#include <stdlib.h>

//struct of trees
struct tree{
    int Data;
    struct tree *Right;
    struct tree *Left;
};
typedef struct tree* Tree;

//creat an empty tree
Tree creatTree(int data);

//add data to entered tree
void Add(int data,Tree tr);

//delete data from a tree
void Delete(int data,Tree tree);

void addTree(Tree l, Tree tree);
//print aal elements in a tree
void Print (Tree tree);

//bst
Tree find (int data,Tree tree);

//find mini number
Tree findMin(Tree tree);

//find max number
Tree findMax(Tree tree);

int main() {
    Tree A = creatTree(4);
    Add(2, A);
    Add(1, A);
    Add(3, A);
    Add(7, A);

//    Print(A);

    Tree B = findMax(A);
    if (B == NULL) {
        printf("df");
    } else {
        printf("%d", B->Data);
    }

    return 0;
}
Tree creatTree(int data){
    Tree tree;
    tree=(Tree) malloc(sizeof (struct tree));
    tree->Data=data;
    tree->Right=NULL;
    tree->Left=NULL;
    return tree;
}
void Add(int data,Tree tr){
    Tree p;
    int d=data;
    p=(Tree) malloc(sizeof (struct tree));
    p->Data=data;
    p->Right=NULL;
    p->Left=NULL;
    if (tr->Data == data) {
        printf("exist data!\n");
    } else if (data < tr->Data) {
        if(tr->Left==NULL)
            tr->Left=p;
        else
            Add(d,tr->Left);
    }else{
        if(tr->Right==NULL)
            tr->Right=p;
        else
            Add(d,tr->Right);
    }
}
void Delete (int data,Tree tree) {

    if (tree->Data == data) {
        if (tree->Left==NULL && tree->Right==NULL) {
            free(tree);
        } else if (tree->Left == NULL){
            tree=tree->Right;
        } else if (tree->Right == NULL) {
            tree=tree->Left;
        } else {
            addTree(tree->Left, tree->Right);
            tree=tree->Left;
        }
    }else if (data < tree->Data && tree->Left!=NULL) {
        if (tree->Left->Data == data) {
            if(tree->Left->Right == NULL && tree->Left->Left == NULL) {
                tree->Left=NULL;
            } else if (tree->Left->Left == NULL) {
                tree->Left=tree->Left->Right;
            } else if (tree->Left->Right == NULL) {
                tree->Left=tree->Left->Left;
            } else {
                addTree(tree->Left->Right, tree->Left->Left);
                tree->Left=tree->Left->Left;
            }
        }else{
            Delete(data, tree->Left);
        }
    }else if (data > tree->Data && tree->Right != NULL) {
        if (tree->Right->Data == data) {
            if (tree->Right->Right == NULL && tree->Right->Left == NULL) {
                tree->Right = NULL;
            } else if (tree->Right->Left == NULL) {
                tree->Right=tree->Right->Right;
            } else if (tree->Right->Right == NULL) {
                tree->Right=tree->Right->Left;
            } else {
                addTree(tree->Right->Left, tree->Right->Right);
                tree->Right=tree->Right->Right;
            }
        } else{
            Delete(data, tree->Right);
        }
    } else {
        printf("not found \n");
    }
}
void Print (Tree tree){
//    Tree pointer =tree;
    printf("%d\n",tree->Data);
    if(tree->Left!=NULL)
        Print(tree->Left);
    if(tree->Right!=NULL)
        Print(tree->Right);




}
void addTree(Tree l, Tree tree){
    if ((l->Data) < (tree->Data)) {
        if(tree->Left==NULL)
            tree->Left=l;
        else
            addTree(l, tree->Left);
    }else{
        if(tree->Right==NULL)
            tree->Right=l;
        else
            addTree(l, tree->Right);
    }
}
Tree find (int data,Tree tree){
    if (tree->Data == data && tree!=NULL)
        return tree;
    else if (data < tree->Data && tree->Left!=NULL)
        find(data, tree->Left);
    else if (data > tree->Data && tree->Right!=NULL)
        find(data, tree->Right);
    else
        return NULL;
}
Tree findMin(Tree tree){
    if (tree != NULL)
        while (tree->Left != NULL)
            tree=tree->Left;
    return tree;
}
Tree findMax(Tree tree){
    if (tree != NULL)
        while (tree->Right != NULL)
            tree=tree->Right;
    return tree;
}