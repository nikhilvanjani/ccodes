#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
/**
 * @input A : String termination by '\0'
 * 
 * @Output string. Make sure the string ends with null character
 */


struct Node{
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


void Pop(int x){
	node* tmp;
	int i;
    for(i=0;i<x;i++){
    	if(top==NULL){
    		Push('/');
            break;
        }
    	tmp=top;
    	char val=tmp->data;
    	top=top->next;
    	free(tmp);
    }
}

int isEmpty(){
	if(top)
		return 0;
	else
		return 1;
}

char Top(){
    if(!isEmpty())
        return top->data;
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
 
char* simplifyPath(char* A) {
    int i=0;
    int len=strlen(A);
    int flag=0;
    // printf("check0\n");
    while((int)A[i]!=(int)('\0')){
        //printf("check0\n");

        if(((int)Top()==(int)('/'))&&(flag==1)){
            //printf("check1\n");
            Pop(2);
            flag=0;
        }
        else if(((int)Top()==(int)('/'))&&(flag==2)){
            //printf("check2\n");
            Pop(5);
            flag=0;
        }        
        Push(A[i]);
        if((int)A[i]==(int)('.'))
            flag++;
        i++;
        //Print();
    }
    if(((int)Top()==(int)('/'))&&(flag==1)){
        //printf("check1\n");
        Pop(2);
        flag=0;
    }
    else if(((int)Top()==(int)('/'))&&(flag==2)){
        //printf("check2\n");
        Pop(5);
        flag=0;
    }      
    if((int)Top()==(int)('/'))
        Pop(1);
    if(isEmpty())
        Push('/');
    i=len-1;
    //Print();
    node* temp=(node*)malloc(sizeof(node));
    temp=top;    
    while(temp){
        //cout << "check91\ti="<<i<<"\tdata="<< temp->data <<"\tA[i]="<<A[i] << flush;
        //cout<<"check92\n" << flush;
        A[i]=temp->data;
        temp=temp->next;
        //printf("check93\n");
        i--;
        //printf("check94\n");

    }
    //printf("check95\n");
    return A+i+1;
    
}

int main(){
    char A[]="/a/./b/../../c/";

    printf("%s\n",simplifyPath(A));
    return 0;
}
