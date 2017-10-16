#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *left;
	struct Node *right;
	int height;
}node;

node* newnode(int key){
	node* noode=(node*)malloc(sizeof(node));
	noode->data=key;
	noode->left=NULL;
	noode->right=NULL;
	noode->height=1;
	return noode;
}

int height(node* node){
	if(node==NULL)
		return 0;
	return node->height;
}
int max(int a,int b){
	if(a>=b)	return a;
	else		return b;
}

node* rightrotate(node *y){
	node *x=y->left;
	node *t2=x->right;
	x->right=y;
	y->left=t2;
	y->height=max(y->left->height,y->right->height)+1;
	x->height=max(x->left->height,x->right->height)+1;
	return x;
}

node* leftrotate(node *x){
	node *y=x->right;
	node *t2=y->left;
	y->left=x;
	x->right=t2;
	x->height=max(x->left->height,x->right->height)+1;
	y->height=max(y->left->height,y->right->height)+1;
	return y;
}

int getbalance(node* node){
	if(node==NULL)
		return 0;
	else
		return (node->left->height)-(node->right->height);
}

node* insert(node* node,int key){
	if(node==NULL)
		return newnode(key);
	else if(key<node->left->data)
		node->left=insert(node->left,key);
	else
		node->right=insert(node->right,key);
	node->height=max(node->left->height,node->right->height)+1;
	int balance=getbalance(node);
	if(balance>1){
		if(key<node->left->data)
			rightrotate(node);
		else	
			leftrotate(node);	
	}
	if(balance<-1){
		if(key<node->right->data)
			rightrotate(node);
		else
			leftrotate(node);
	}
	return node;
}

void inorder(node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

int main(){
	node* root=NULL;
	int n,i,key;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&key);		
		insert(root,key);
	}
	inorder(root);
	return 0;
}
