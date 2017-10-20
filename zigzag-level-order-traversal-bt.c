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
 * @Return 2D int array. You need to malloc memory. Fill in the number of rows in the array as len1. 
 * Then for each row, the first element should correspond to the number of entries in the row. 
 */
int max(int x, int y){
    if(x>y)
        return x;
    else
        return y;
}

int flag=1;
 
int ** zigzagLevelOrder(treenode* A, int *len1) {
    /*
     * Example :  Lets say you want to return [[1], [2, 3]]. 
     * *len1 = 2; 
     * int **ret = (int **)malloc(*len1 * sizeof(int *));
     * ret[0] = (int *)malloc(2 * sizeof(int));
     * ret[1] = (int *) malloc(3 * sizeof(int));
     * ret[0][0] = 1;
     * ret[0][1] = 1;
     * ret[1][0] = 2;
     * ret[1][1] = 2;
     * ret[1][2] = 3;
     * return ret;
     */
    if(A==NULL){
        *len1=0;
        return NULL;
    }
    int*len2=(int*)malloc(sizeof(int));
    int*len3=(int*)malloc(sizeof(int));
    // printf("flag=%d\n",flag);
    //int tmp=flag;
    int**B=zigzagLevelOrder(A->left, len2);
    //flag=tmp;
    int**C=zigzagLevelOrder(A->right, len3);
    // printf("len2=%d\nlen3=%d\n",*len2,*len3 );
    *len1=max(*len2, *len3)+1;
    int i,j,k,h;
    int x,y,z;
    int**D=(int**)malloc((*len1)*sizeof(int*));
    D[0]=(int*)malloc(2*sizeof(int));
    D[0][0]=1;
    // printf("check2 %d\n",A->val );
    D[0][1]=A->val;
    flag=1;
    for(i=1;i<*len1;i++){
        // printf("--- i=%d ---\n",i);
        if(i-1<*len2)
            x=B[i-1][0];
        else 
            x=0;
        if(i-1<*len3)
            y=C[i-1][0];
        else
            y=0;
        z=x+y;
        // printf("z=%d\n",z );
        D[i]=(int*)malloc((z+1)*sizeof(int));
        D[i][0]=z;
        k=1;
        if(flag==0){
   //      	printf("entering flag=%d\ti=%d\n",flag,i);
		 //    printf("---B---\n");
			// for(h=0;h<*len2;h++){
			// 	for(j=1;j<=B[h][0];j++)
			// 		printf("%d ",B[h][j]);
			// 	printf("\n");
			// }    
			// printf("---C---\n");
			// for(h=0;h<*len3;h++){
			// 	for(j=1;j<=C[h][0];j++)
			// 		printf("%d ",C[h][j]);
			// 	printf("\n");
			// }    

            for(j=x;(j>=1)&&(i-1<*len2);j--){
                // printf("i=%d\tj=%d\tk=%d\n",i,j,k);
                // printf("B[i-1][j]=%d\n",B[i-1][j]);
                D[i][k]=B[i-1][j];
                // printf("check22\n");
                k++;
            }
            for(j=y;(j>=1)&&(i-1<*len3);j--){
                // printf("i=%d\tj=%d\tk=%d\n",i,j,k);
                // printf("C[i-1][j]=%d\n",C[i-1][j]);
                //printf("D[i][k]=%d\n",D[i][k]);
                D[i][k]=C[i-1][j];
                // printf("check1\n");
                k++;
            }
            // printf("check222\n");
            flag=1;
            continue;

            // return D;
        }
        else {
   //      	printf("entering flag=%d\ti=%d\n",flag,i);
		 //    printf("---B---\n");
			// for(h=0;h<*len2;h++){
			// 	for(j=1;j<=B[h][0];j++)
			// 		printf("%d ",B[h][j]);
			// 	printf("\n");
			// }    
			// printf("---C---\n");
			// for(h=0;h<*len3;h++){
			// 	for(j=1;j<=C[h][0];j++)
			// 		printf("%d ",C[h][j]);
			// 	printf("\n");
			// }    


            for(j=y;(j>=1)&&(i-1<*len3);j--){
                // printf("i=%d\tj=%d\tk=%d\n",i,j,k);
                // printf("C[i-1][j]=%d\n",C[i-1][j]);
                //printf("D[i][k]=%d\n",D[i][k]);
                D[i][k]=C[i-1][j];
                // printf("check1\n");
                k++;
            }
            for(j=x;(j>=1)&&(i-1<*len2);j--){
                // printf("i=%d\tj=%d\tk=%d\n",i,j,k);
                // printf("B[i-1][j]=%d\n",B[i-1][j]);
                D[i][k]=B[i-1][j];
                // printf("check11\n");
                k++;
            }
            // printf("check111\n");
            flag=0;

            // return D;
        }        
    }
	// printf("---B---\n");
	// for(h=0;h<*len2;h++){
	// 	for(j=1;j<=B[h][0];j++)
	// 		printf("%d ",B[h][j]);
	// 	printf("\n");
	// }    
	// printf("---C---\n");
	// for(h=0;h<*len3;h++){
	// 	for(j=1;j<=C[h][0];j++)
	// 		printf("%d ",C[h][j]);
	// 	printf("\n");
	// }    
	
	// printf("---D---\n");
	// for(i=0;i<*len1;i++){
	// 	for(j=1;j<=D[i][0];j++)
	// 		printf("%d ",D[i][j]);
	// 	printf("\n");
	// }    

    return D;

}

void inorderTraversal(treenode* root){
    if(root==NULL)
        return NULL;
    inorderTraversal(root->left);
    printf("%d ",root->val);
    inorderTraversal(root->right);
    
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

	// root=insert(root,4);
	// root=insert(root,2);
	// root=insert(root,6);
	// root=insert(root,1);
	// root=insert(root,3);
	// root=insert(root,5);
	// root=insert(root,8);
	// root=insert(root,7);
	printf("\n");
	inorderTraversal(root);
	printf("\n");
	int*len1=(int*)malloc(sizeof(int));
	int**D=zigzagLevelOrder(root,len1);
	int j;
	printf("len1=%d\n",*len1);
	for(i=0;i<*len1;i++){
		for(j=1;j<=D[i][0];j++)
			printf("%d ",D[i][j]);
		printf("\n");
	}
}
