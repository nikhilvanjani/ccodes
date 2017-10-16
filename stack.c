#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int A[MAX_SIZE];
int top=-1;

void Push(int x){
	if(top==MAX_SIZE-1){
		printf("Error: stack overflow\n");
		return;
	}
	top++;
	A[top]=x;
}

void Pop(){
	if(top==-1){
		printf("No element to pop\n");
		return;
	}
	top--;
}

void Print(){
	int i;
	printf("Stack: ");
	for(i=0;i<=top;i++)
		printf("%d ",A[i] );
	printf("\n");
}

int isEmpty(){
	return (top==-1);
}
int size(){
	return top+1;
}

int main(){
	Push(2);Print();
	Push(5);Print();
	Push(10);Print();
	Pop();Print();
	Push(3);Print();


	return 0;
} 