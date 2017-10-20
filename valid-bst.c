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
 
int A[1000000];
int idx=0;

void inorderTraversal(treenode* root){
    if(root==NULL)
        return NULL;
    inorderTraversal(root->left);
    A[idx]=root->val;
    idx++;
    inorderTraversal(root->right);
    
}
    
int isValidBST(treenode* root) {
    int i;
    inorderTraversal(root);
    int flag=1;
    // for(i=0;i<idx;i++)
    //     printf("%d ",A[i]);
    // printf("\n");
    for(i=0;i<idx-1;i++){
        if(A[i]>A[i+1]){
            flag=0;
            break;
        }
    }
    return flag;
    
}
