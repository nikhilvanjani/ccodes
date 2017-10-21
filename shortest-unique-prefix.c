#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @input A : array of strings termination by '\0'
 * @input n1 : number of strings in array A
 * 
 * @Output string array. You need to malloc memory. 
 *   Fill in len1 as number of strings. Make sure every string ends with null character
 */
typedef struct Node{
    char val;
    struct Node *up;
    struct Node *down;
    struct Node *left;
    struct Node *right;
}node;

node* newNode(char data){
    node*tmp=(node*)malloc(sizeof(node));
    tmp->val=data;
    tmp->up=NULL;
    tmp->down=NULL;
    tmp->right=NULL;
    tmp->left=NULL;
    return tmp;
}

node** B;

node* insert(node* toor, char* data, int idx){
    node* root=toor;
    node* prev=NULL;
    while((root!=NULL)&&((int)(root->val)!=(int)data[0])){
        prev=root;
        root=root->right;
    }
    if(root==NULL){
        node* new_=newNode(data[0]);
	    if(toor!=NULL){
	        prev->right=new_;
	        new_->left=prev;
	        root=new_;
	    }
        else if(toor==NULL){
            root=new_;
            toor=new_;
        }
    }
    int len=strlen(data);
    int i;
    for(i=1;i<len;i++){
        if(root->down==NULL){
            node*tmp=newNode(data[i]);
            root->down=tmp;
            tmp->up=root;
            root=root->down;
        }
        else{
            node*tmp1=root->down;
            node*prev1=NULL;
            while((tmp1!=NULL)&&((int)(tmp1->val)!=(int)data[i])){
                prev1=tmp1;
                tmp1=tmp1->right;
            }
            if(tmp1==NULL){
                node*new__=newNode(data[i]);
                prev1->right=new__;
                new__->left=prev1;
                new__->up=root;
                tmp1=new__;
            }
            root=tmp1;
        }
    }
    B[idx]=root;
    node*tester=B[idx];
    return toor;
}

char** prefix(char** A, int n1, int *len1) {
    int i,j,len,size;
    node*root=NULL;
    *len1=n1;
    B=(node**)malloc(n1*sizeof(node*));
    for(i=0;i<n1;i++)
        root=insert(root,A[i], i);
    char**C=(char**)malloc(n1*sizeof(char*));
    node*test=root;
    while(test!=NULL){
    	test=test->right;
    }
    for(i=0;i<n1;i++){
        size=strlen(A[i]);
        while((B[i]->left==NULL)&&(B[i]->right==NULL)&&(B[i]->up!=NULL)){
            B[i]=B[i]->up;
            size--;
        }
        C[i]=(char*)malloc((size+1)*sizeof(char));
        for(j=0;j<size;j++)
            C[i][j]=A[i][j];
        C[i][size]='\0';
    }
    return C;    
}

int main(){
	int n;
	scanf("%d",&n);
	char **A=(char**)malloc(n*sizeof(char*));
	int i,j;
	for(i=0;i<n;i++)
		A[i]=(char*)malloc(100*sizeof(char));
	for(i=0;i<n;i++)
		scanf("%s",A[i]);

	int*len1=(int*)malloc(sizeof(int));
	char**B=prefix(A,n,len1);
	for(i=0;i<*len1;i++)
		printf("%s\n",B[i]);

	return 0;
}
