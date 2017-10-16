#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int A[MAX_SIZE];
int front=-1;
int rear=-1;
int mod(int x,int n){
	if(x>=0)
		return x%n;
	else
		return (x%n)+n;
}

int isEmpty(){
	return ((front==-1)&&(rear==-1));
}

int isFull(){
	return (mod((rear-front),MAX_SIZE)==MAX_SIZE-1);
}

int size(){
	return (mod((rear-front),MAX_SIZE))+1;
}

void Enqueue(int x){
	if(isFull()){
		printf("Error: Queue is full\n");
		return;
	}
	else if(isEmpty()){
		front++;
		rear++;
		A[rear]=x;
	}
	else{
		rear=mod((rear+1),MAX_SIZE);
		A[rear]=x;
	}
}

void Dequeue(){
	if(isEmpty()){
		printf("No element to dequeue\n");
	}
	else if(front==rear){
		front=-1;
		rear=-1;
	}
	else
		front=mod((front+1),MAX_SIZE);
}

void Print(){
	int i=size();
	int j=front;
	printf("f=%d r=%d s=%d\n",front,rear,i);
	printf("Queue: ");
	while(i>0){
		printf("%d ",A[j] );
		j=mod((j+1),MAX_SIZE);
		i--;
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