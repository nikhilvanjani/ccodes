#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode treenode;

treenode* treenode_new(int val) {
    treenode* node = (treenode *) malloc(sizeof(treenode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
 
/**
@input A : Root pointer of the tree 

@Output 2D int array. You need to malloc memory. Fill in len1 as row
For each row i, A[i][0] should indicate the number of columns in row i.
Then A[i][1] to A[i][col] should have the values in those columns.
 */

typedef struct Node{
    treenode* data;
    int level;
    struct Node* next;
}node;

node*front=NULL;
node*rear=NULL;
 
void Enqueue(treenode* val, int depth){
    node* tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->level=depth;
    tmp->next=NULL;
    if(front){
        rear->next=tmp;
        rear=tmp;
    }
    else{
        front=tmp;
        rear=tmp;
    }
} 

node* Dequeue(){
    node*tmp;
    if(front==NULL)
        return;
    tmp=front;
    front=front->next;
    return tmp;
}

int isEmpty(){
    if(front)
        return 0;
    else
        return 1;
}
int ** levelOrder(treenode* A, int *len1) {
    printf("check0\n");
    int C[1000][1000];
    int i;
    for(i=0;i<1000;i++)
        C[i][0]=0;
    Enqueue(A,0);
    node*B;
    while(!isEmpty()){
        printf("check1\n");
        B=Dequeue();
        if(B->data->left!=NULL)
            Enqueue((B->data)->left,(B->level)+1);
        if(B->data->right!=NULL)
            Enqueue((B->data)->right,(B->level)+1);
        C[B->level][C[B->level][0]]=(B->data)->val;
        C[B->level][0]++;
    }
    i=0;
    while(C[i][0]!=0)
        i++;
    *len1=i;
    return C;
    
}
