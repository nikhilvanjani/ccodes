#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
typedef struct Node node;
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

int main(){
	Enqueue(1);Print();
	Enqueue(2);Print();
	Enqueue(3);Print();
	Enqueue(4);Print();
	Enqueue(5);Print();
	Dequeue();Print();
	Enqueue(6);Print();
	return 0;
} 