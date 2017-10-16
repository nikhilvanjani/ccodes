#include <stdlib.h>
#include <stdio.h>

struct ListNode {
	int val;
    struct ListNode *next;
};
typedef struct ListNode listnode;

listnode* listnode_new(int val) {
    listnode* node = (listnode *) malloc(sizeof(listnode));
    node->val = val;
    node->next = NULL;
    return node;
}
 
/**
 * @input A : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */

listnode * deleteNode(listnode*p1, listnode*p2){
    p1->next=p2->next;
    return p1;
}
 
listnode * insertNode(listnode* p1, listnode* p2){
    listnode*p3=p2->next;
    p2->next=p1->next;
    p1->next=p2;
    return p3;
}
listnode* insertionSortList(listnode* A) {
    listnode *head,*p, *headprev, *pprev;
    head=A;
    headprev=NULL;
    pprev=A;
    p=A->next;
    if(A->next==NULL)
        return A;
    head=A;
    while(p!=NULL){
    	printf("check0\n");
        while((head->val<p->val)&&(head->next!=p)){
            headprev=head;
            head=head->next;
            printf("check2\n");
        }
        if((head->next==p)&&(head->val<p->val)){
            pprev=p;
            p=p->next;
            printf("check3\n");
        }
        else{

            pprev=deleteNode(pprev,p);
            if(headprev==NULL){
            	listnode* tmp=A;
                p->next=tmp;
                A=p;
            	printf("check4\n");
            }
            else{
                p=insertNode(headprev,p);
            	printf("check5\n");
            }
            head=A;
            headprev=NULL;
        }
    }
    return A;
}

int main(){
	listnode*A=listnode_new(2);
	listnode*head=A;
	listnode*x=listnode_new(3);
	listnode*y=listnode_new(1);
	//listnode* y=NULL;
	A->next=x;
	x->next=y;
	y->next=NULL;
	printf("check1\n");
	A=insertionSortList(A);
	x=A;
	while(x!=NULL){
		printf("%d --> ", x->val);
		x=x->next;
	}
	printf("\n");
	return 0;

}
