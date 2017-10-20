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
 * @input B : Integer
 * 
 * @Output root pointer of tree.
 */
treenode* find(treenode* root, int data){
    if(root==NULL)
        return NULL;
    while((root!=NULL)&&(root->val!=data)){
        if(data < root->val)
            root=root->left;
        else
            root=root->right;
    }
    return root;
}

treenode* findMin(treenode* root){
    if(root==NULL)
        return NULL;
    while(root->left!=NULL)
        root=root->left;
    return root;
} 
 
treenode* getSuccessor(treenode* root, int data) {
    treenode* current=find(root, data);
    if(current==NULL)
        return NULL;
    else{
        if(current->right!=NULL)
            return findMin(current->right);
        else{
            treenode* successor=NULL;
            treenode* ancestor=root;
            while(ancestor!=current){
                if(current->val<ancestor->val){
                    successor=ancestor;
                    ancestor=ancestor->left;
                }
                else
                    ancestor=ancestor->right;
            }
            return successor;
        }
    }
    
}
