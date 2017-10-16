#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}node;

typedef struct gNode{
	int data;
	struct gNode* ptr;
}

node* front=NULL;
node* rear=NULL;

void Enqueue(int x){
	node* tmp=(node*)malloc(sizeof(node));
	tmp->data=x;
	tmp->next=NULL;
	if(front){
		rear->next=tmp;
		rear=tmp;
	}
	else{
		front=tmp;
		rear=tmp;
	}
}

void Dequeue(){
	node* tmp;
	if(front==NULL)
		return;
	tmp=front;
	front=front->next;
	free(tmp);
}

int isEmpty(){
	if(front)
		return 1;
	else
		return 0;
}

void Print(){
	node* tmp=(node*)malloc(sizeof(node));
	tmp=front;
	while(tmp){
		printf("%d ",tmp->data);
		tmp=tmp->next;
	}
	printf("\n");
}


int bfs(){

}

int main(){

	return 0;
}