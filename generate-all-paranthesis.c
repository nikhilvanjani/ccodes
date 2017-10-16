#include <stdio.h>
#include <stdlib.h>
/**
 * @input A : String termination by '\0'
 * 
 * @Output Integer
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

char Top(){
    return top->data;
}

void Print(){
	node* tmp=(node*)malloc(sizeof(node));
	tmp=top;
	while(tmp){
		//printf("%c ",tmp->data);
		tmp=tmp->next;
	}
	//printf("\n");
} 
 
int isValid(char* A) {
    int flag=1;
    int i;
    while((int)A[i]!=(int)('\0')){
    	//printf("A[i]=%c\n",A[i] );
        if(((int)A[i]==(int)('('))||((int)A[i]==(int)('['))||((int)A[i]==(int)('{'))){
            Push(A[i]);
            i++;
            //printf("check1\n");
        }
        else if(((int)A[i]==(int)(')'))||((int)A[i]==(int)(']'))||((int)A[i]==(int)('}'))){
            if(isEmpty()){
                flag=0;
                //printf("check2\n");
                break;
            }
            else {
            	if(((int)A[i]==(int)(')'))&&((int)('(')==(int)Top())) {
	                Pop();
	                i++;
	                //printf("check31\n");
            	}
            	else if(((int)A[i]==(int)(']'))&&((int)('[')==(int)Top())) {
	                Pop();
	                i++;
	                //printf("check32\n");
            	}
            	else if(((int)A[i]==(int)('}'))&&((int)('{')==(int)Top())) {
	                Pop();
	                i++;
	                //printf("check33\n");
            	}
            	else{
	                flag=0;
	                break;
	                //printf("check4\n");
            	}            	
            }
        }
    }
    if(isEmpty())
        return flag;
    else 
        return 0;
    
}

int main(){
	char A[7]="(){}[]";
	// int i;
	// for(i=0;i<7;i++){
	// 	//printf("%c\n",A[i] );
	// }
	// int i=((int)A[6]==(int)('\0'));
	int i=isValid(A);
	//printf("%d\n",i);
	return 0;
}