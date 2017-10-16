#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
typedef struct Node node;
node* top=NULL;

void Push(int x){
	node* tmp=(node*)malloc(sizeof(node));
	tmp->data=x;
	tmp->next=top;
	top=tmp;
}

void Pop(){
	node* tmp;
	if(top==NULL)
		return;
	tmp=top;
	top=top->next;
	free(tmp);
}

int isEmpty(){
	if(top)
		return 0;
	else
		return 1;
}

void Print(){
	node* tmp=(node*)malloc(sizeof(node));
	tmp=top;
	while(tmp){
		printf("%d ",tmp->data);
		tmp=tmp->next;
	}
	printf("\n");
}

int main(){
	Push(2);Print();
	Push(5);Print();
	Push(10);Print();
	Pop();Print();
	Pop();Print();
	Pop();Print();
	Pop();Print();
	Push(3);Print();


	return 0;
} 