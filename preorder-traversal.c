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
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int *A; 
int idx=0;
void pT(treenode* root){
    A[idx]=root->val;
    idx++;
    if(root->left!=NULL)
        pT(root->left);
    if(root->right!=NULL)
        pT(root->right);
    
}

int* preorderTraversal(treenode* root, int *len1) {
    if(root==NULL){
        *len1=0;
        return;
    }
    A=(int*)malloc(3000000*sizeof(int));
    pT(root);
    // A[idx]=root->val;
    // idx++;
    // int *len2=(int*)malloc(sizeof(int));
    // int *len3=(int*)malloc(sizeof(int));
    // if(root->left!=NULL)
    //     preorderTraversal(root->left,len2);
    // if(root->right!=NULL)
    //     preorderTraversal(root->right, len3);
    *len1=idx;
    return A;
}
