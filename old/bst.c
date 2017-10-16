#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *l;
	struct Node *r;
}node;

node *insert(node* root,int data){
	if(root==NULL){
		node *tmp;
		tmp=(node*)malloc(sizeof(node));
		tmp->data=data;
		tmp->l=NULL;tmp->r=NULL;
		return tmp;	
	}
	if(data>root->data)
		root->r=insert(root->r,data);	
	else if(data<root->data)
		root->l=insert(root->l,data);
	else return;
	return root;
}
node *inorder(node *root){
	if(root==NULL)	return;
	inorder(root->l);
	printf("%d ",root->data);
	inorder(root->r);
}
node *preorder(node *root){
	if(root==NULL)	return;
	printf("%d ",root->data);
	inorder(root->l);
	inorder(root->r);
}
node *postorder(node *root){
	if(root==NULL)	return;
	inorder(root->l);
	inorder(root->r);
	printf("%d ",root->data);
}

int main(){
	int i,n,a;
	scanf("%d",&n);
	node *root=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&a);
		root=insert(root,a);	
	}	
	inorder(root);printf("\n");
	preorder(root);printf("\n");
	postorder(root);

}
