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

treenode* insert(treenode* root, int x){
    if(root==NULL)
        root=treenode_new(x);
    else if(x <root->val){
        if(root->left==NULL)
            root->left=treenode_new(x);
        else
            insert(root->left,x);
    }
    else{
        if(root->right==NULL)
            root->right=treenode_new(x);
        else
            insert(root->right,x);
    }
    return root;
}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 
 * typedef struct TreeNode treenode;
 * 
 * treenode* treenode_new(int val) {
 *     treenode* node = (treenode *) malloc(sizeof(treenode));
 *     node->val = val;
 *     node->left = NULL;
 *     node->right = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Root pointer of the tree 
 * 
 * @Output Integer
 */
int maxDepth(treenode*A){
    if(A==NULL)
        return 0;
    int x=maxDepth(A->left);
    int y=maxDepth(A->right);
    if(x>y)
        return x+1;
    else
        return y+1;
    
}
int flag=1;
int isBalanced(treenode* A) {
    if(A==NULL)
        return 1;
    isBalanced(A->left);
    isBalanced(A->right);
    if(flag){
        int x=maxDepth(A->left);
        int y=maxDepth(A->right);
        printf("%d %d\n",x,y);
        if((x-y>1)||(y-x>1))
            flag=0;
    }
    return flag;
    
}

int main(){

    treenode *root=NULL;
    int n,p;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&p);
        root=insert(root,p);
    }

    int x=isBalanced(root);
    printf("x=%d\n",x);


    return 0;
}