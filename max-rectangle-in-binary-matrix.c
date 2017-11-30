#include <stdio.h>
#include <stdlib.h>
/**
 * @input A : 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output Integer
 */
struct Node{
    int data;
    int index;
    struct Node* next;
};
typedef struct Node node;
node* top=NULL;

void Push(int x, int index){
    node* tmp=(node*)malloc(sizeof(node));
    tmp->data=x;
    tmp->index=index;
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
    if(top!=NULL)
        return 0;
    else
        return 1;
}

int Top(int x){
    if(!isEmpty()){
        if (x==0)
            return top->data;
        else
            return top->index;
    }
    else 
        return -1;
}

void Print(){
    node* tmp=(node*)malloc(sizeof(node));
    tmp=top;
    while(tmp){
        // printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    // printf("\n");
}

int* nearestSmaller(int* A, int n1) {
    int *B=(int*)malloc(n1*sizeof(int));
    int i;
    for(i=0;i<n1;i++){
        if(isEmpty()){
            B[i]=-1;
        }
        else if(Top(0)<A[i])
            B[i]=Top(1);
        else{
            while((Top(0)>=A[i])&&(!isEmpty()))
                Pop();
            if(isEmpty())
                B[i]=-1;
            else
                B[i]=Top(1);
        }
        Push(A[i],i);    
    }
    return B;
}
int* nextSmaller(int* A, int n1) {
    int *B=(int*)malloc(n1*sizeof(int));
    int i;
    for(i=n1-1;i>=0;i--){
        if(isEmpty()){
            B[i]=-1;
        }
        else if(Top(0)<A[i])
            B[i]=Top(1);
        else{
            while((Top(0)>=A[i])&&(!isEmpty()))
                Pop();
            if(isEmpty())
                B[i]=-1;
            else
                B[i]=Top(1);
        }
        Push(A[i],i);    
    }
    return B;
}

int largestRectangleArea(int* A, int n1) {
    if(n1==1)
        return A[0];
    int *B=nearestSmaller(A,n1);
    int *C=nextSmaller(A,n1);
    int i;
    //for(i=0;i<n1;i++)
            // printf("%d : B[%d]=%d\n",A[i],i,B[i]);
    // for(i=0;i<n1;i++)
    //        printf("%d : C[%d]=%d\n",A[i],i,C[i]);

    for(i=0;i<n1;i++){
        if(B[i]==-1)
            B[i]=i+1;
        else
            B[i]=i-B[i];
    }
    //for(i=0;i<n1;i++)
            // printf("%d : B[%d]=%d\n",A[i],i,B[i]);
    for(i=0;i<n1;i++){
        if(C[i]==-1)
            C[i]=n1-i;
        else
            C[i]=C[i]-i;
    }
    //for(i=0;i<n1;i++)
            // printf("%d : C[%d]=%d\n",A[i],i,C[i]);
    for(i=0;i<n1;i++){
        C[i]=(C[i]+B[i]-1)*A[i];
    }
    //for(i=0;i<n1;i++)
            // printf("%d : C[%d]=%d\n",A[i],i,C[i]);
    //printf("check2\n");
    int max=0;
    for(i=0;i<n1;i++)
        if(max<C[i])
            max=C[i];
    //printf("check3\n");
    return max;
}


int max(int x, int y){
    if(x>y)
        return x;
    else
        return y;
}
int maximalRectangle(int** A, int n11, int n12) {
    int**B=(int**)malloc(n11*sizeof(int*));
    int i,j;
    for(i=0;i<n11;i++){
        B[i]=(int*)malloc(n12*sizeof(int));
    }
    for(i=0;i<n12;i++)
        B[n11-1][i]=A[n11-1][i];
    for(i=n11-2;i>=0;i--){
        for(j=0;j<n12;j++){
            if(A[i][j]==1)
                B[i][j]=B[i+1][j]+1;
            else
                B[i][j]=0;
        }
    }
    for(i=0;i<n11;i++){
        for(j=0;j<n12;j++)
            printf("%d ",B[i][j]);
        printf("\n");
    }
    int result=-1;
    for(i=0;i<n11;i++){
        printf("result=%d\trect=%d\n",result,largestRectangleArea(B[i],n12) );
        result=max(result,largestRectangleArea(B[i],n12));
        printf("result=%d\n",result );
    }
    return result;

}

int main(){
    int n11,n12;
    scanf("%d %d",&n11,&n12);
    int i,j;
    int **A=(int**)malloc(n11*sizeof(int*));
    for(i=0;i<n11;i++){
        A[i]=(int*)malloc(n12*sizeof(int));
        for(j=0;j<n12;j++)
            scanf("%d",&A[i][j]);
    }
    //printf("check1\n");
    int x=maximalRectangle(A,n11,n12);
    printf("x=%d\n",x);
    return 0;
}
