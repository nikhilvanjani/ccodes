#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @input A : String termination by '\0'
 * 
 * @Output string. Make sure the string ends with null character
 */


xstruct Node{
	char data;
	struct Node* next;
};
typedef struct Node node;
node* top=NULL;

void Push(char x){
	node* tmp=(node*)malloc(sizeof(node));
	tmp->data=x;
	tmp->next=top;
	top=tmp;
}

char Pop(){
	node* tmp;
	if(top==NULL)
		return;
	tmp=top;
	char val=tmp->data;
	top=top->next;
	free(tmp);
	return val;
}

int isEmpty(){
	if(top)
		return 1;
	else
		return 0;
}

void Print(){
	node* tmp=(node*)malloc(sizeof(node));
	tmp=top;
	while(tmp){
		printf("%c ",tmp->data);
		tmp=tmp->next;
	}
	printf("\n");
}
 

char* reverseString(char* A) {
    int len=strlen(A);
    int i=0;
    while(i<len){
        Push(A[i]);
        i++;
    }
    i=0;
    while(i<len){
        A[i]=Pop();
        i++;
    }
    return A;
}

int main(){
	char A[7]="()[]{}";
	printf("%s\n",reverseString(A));
	return 0;
}