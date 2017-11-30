#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}node;

 
node** Enqueue(node* front, node* rear, int val){
    node* tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->next=NULL;
    if(front){
        rear->next=tmp;
        rear=tmp;
    }
    else{
        front=tmp;
        rear=tmp;
    }
    return {front, rear};
} 

node** Dequeue(node* front, node* rear){
    node*tmp;
    if(front==NULL)
        return NULL;
    tmp=front;
    front=front->next;
    return {tmp, front, rear};
}

int isEmpty(node* front){
    if(front)
        return 0;
    else
        return 1;
}

int* BFS(int**G,int n,int x){
    node**queue=(node**)malloc(2*sizeof(node*));
    queue[0]=(node*)malloc(sizeof(node));
    queue[1]=(node*)malloc(sizeof(node));
    queue[0]=NULL;
    queue[1]=NULL;
    int*Distance=(int*)malloc(n*sizeof(int));
    int*Visited=(int*)malloc(n*sizeof(int));
    int i;
    for(i=0;i<n;i++){
        Distance[i]=-1;
        Visited[i]=0;
    }
    Distance[x]=0;
    queue=Enqueue(queue[0],queue[1],x);
    Visited[x]=1;
    node*v;
    node**dequeue=(node**)malloc(3*sizeof(node*));
    dequeue[0]=(node*)malloc(sizeof(node));
    dequeue[1]=(node*)malloc(sizeof(node));
    dequeue[2]=(node*)malloc(sizeof(node));
    int i;
    while(!isEmpty(queue[0])){
        dequeue=Dequeue(queue[0],queue[1]);
        queue=dequeue+1;
        v=dequeue[0];
        for(i=0;i<n;i++){
            if((G[v->data][i]==1)&&(Distance[i]==-1)){
                Distance[i]=Distance[v->data]+1
                Visited[i]=1;
                queue=Enqueue(queue[0],queue[1],i);
            }
        }
    }
    return Distance;

}

int main(){
    int n,x;
    scanf("%d%d",&n,x);
    int G[n][n];
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",G[i][j]);
        }
    }
    int*Distance=BFS(G,n,x);
    for(i=0;i<n;i++){
        printf("%d ",Distance[i]);
    }
    printf("\n");

    return 0;
}

