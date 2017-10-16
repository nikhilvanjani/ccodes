#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}node;


node* addNode(int x){
	node* new=(node*)malloc(sizeof(node));
	new->data=x;
	new->left=NULL;
	new->right=NULL;
	return new;	
}

void inorder(node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

node* insert(node* root, int x){
	if (root==NULL)
		root= addNode(x);
	else if(x<root->data){
		root->left=insert(root->left, x);
	}
	else if(x>root->data){
		root->right=insert(root->right, x);
	}
	return root;
}

node* minValueNode(node* root){
	while(root->left!=NULL)
		root=root->left;
	return root;
}

node* delete(node* root, int x){
	if(root==NULL)
		return root;
	if(root->data > x)
		root->left = delete(root->left, x);
	else if(root->data < x)
		root->right = delete(root->right, x);
	else{
		if(root->left == NULL){
			node*tmp=root->right;
			free(root);
			return tmp;
		}
		else if(root->right == NULL){
			node*tmp=root->left;
			free(root);
			return tmp;
		}
		else{
			node* tmp=minValueNode(root->right);
			root->data=tmp->data;
			root->right=delete(root->right, tmp->data);
		}
	}
	return root;
}

int binarySearch(node* root, int x){
	if(root==NULL)
		return 0;
	if(root->data==x)
		return 1;
	if(x<root->data)
		return binarySearch(root->left, x);
	if(x>root->data)
		return binarySearch(root->right, x);
}

int main(){
	node*root=NULL;
	int i,n;
	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++){
		scanf("%d ",&A[i]);
		root=insert(root,A[i]);
	}
	root=delete(root,A[0]);
	inorder(root);
	printf("\n");
	return 0;
}