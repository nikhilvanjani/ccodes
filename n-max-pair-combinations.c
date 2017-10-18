#include <stdio.h>
#include <stdlib.h>

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer array
 * @input n2 : Integer array's ( B ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
void swap(int*a, int*b){
    int t=*a;
    *a=*b;
    *b=t;
} 
 
int partition(int A[], int low, int high){
    int pivot=A[low];
    int i=low+1,j=high;
    while(i<j){
        if(A[i]<pivot){
            swap(&A[i],&A[j]);
            j--;
        }
        else{
            i++;
        }
    }
    if(A[i]>pivot){
        swap(&A[i],&A[low]);
        return i;
    }
    else{
        swap(&A[i-1],&A[low]);
        return i-1;
    }
} 
 
void quicksort(int A[],int low, int high){
    if(low<high){
        int p=partition(A,low,high);
        quicksort(A,low,p-1);
        quicksort(A,p+1,high);
    }
}

int C[1000];
int idx=0;
    
int* solve(int* A, int n1, int* B, int n2, int *len1) {
    //printf("n1=%d\n",n1 );
    static int flag=1;
    if(flag==1){
        quicksort(A,0,n1-1);
        quicksort(B,0,n2-1);
        flag=0;
    }
    int i,j;
    int val=A[1]+B[1];;
    i=0;
    //printf("check1\tidx=%d\n",idx);
    while((A[0]+B[i]>=val)&&(idx<3*n1)&&(i<n2)){
        C[idx]=A[0]+B[i];
        //printf("C[%d]=%d\n",idx,C[idx]);
        i++;
        idx++;
    }
    i=1;
    //printf("check2\tidx=%d\n",idx);
    while((A[i]+B[0]>=val)&&(idx<3*n1)&&(i<n1)){
        C[idx]=A[i]+B[0];
        //printf("C[%d]=%d\n",idx,C[idx]);
        i++;
        idx++;
    }
    //printf("check3\tidx=%d\n",idx);
    if(idx<3*n1){
        int*len2=(int*)malloc(sizeof(int));
        solve(A+1,n1-1,B+1,n2-1,len2);
    }
    //printf("check4\n");
    *len1=n1;
    for(i=0;i<idx;i++)
        //printf("%d ",C[i]);
    //printf("\n");
    quicksort(C,0,idx-1);
    int*D=(int*)malloc(n1*sizeof(int));
    for(i=0;i<n1;i++)
        D[i]=C[i];
    return D;
    
}


int main(){
    int n1,n2;
    scanf("%d%d",&n1,&n2);
    int A[n1],B[n2];
    int i;
    for(i=0;i<n1;i++)
        scanf("%d",&A[i]);
    for(i=0;i<n2;i++)
        scanf("%d",&B[i]);
    int*len1=(int*)malloc(sizeof(int));
    int *C=solve(A,n1,B,n2,len1);
    //printf("len1=%d\n",*len1);
    for(i=0;i<*len1;i++)
        printf("%d ",C[i]);
    printf("\n");
    return 0;
}