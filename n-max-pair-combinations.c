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

int idx=0;
int C[1000];
int n=0;

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


void heapify(int **a, int m,int n){
    if((m+1)>(n/2)) return;
    int x;  
    if((m==(n/2)-1)&&(n%2==0))  x=2*m+1;    
    else{
        if(a[2*m+1][0]>=a[2*m+2][0])
            x=2*m+1;        
        else
            x=2*m+2;    
    }   
    if(a[m][0]<a[x][0]){      
        swap(&a[m][0],&a[x][0]);
        swap(&a[m][1],&a[x][1]);
        swap(&a[m][2],&a[x][2]);
        m=x;
        heapify(a,m,n);
    }
    else    return;
    
}
int* extractMax(int **a){
    int *x=(int*)malloc(3*sizeof(int));
    x[0]=a[0][0];
    x[1]=a[0][1];
    x[2]=a[0][2];
    a[0][0]=a[n-1][0];
    a[0][1]=a[n-1][1];
    a[0][2]=a[n-1][2];
    n--;
    heapify(a,0,n);
    return x;
}

void insert(int A[],int i,int B[],int j,int **a){
    //printf("check41 n=%d\n",n);
    a[n][0]=A[i]+B[j];
    //printf("check42\n");
    a[n][1]=i;
    //printf("check43\n");
    a[n][2]=j;
    //printf("check44\n");
    n++;
    //printf("check45\n");
    int m=n-1;
    //printf("check5\n");
    while((a[m][0]>a[(m-1)/2][0])&&(m>=0)){
        //printf("check6 m=%d\n",m );
        swap(&a[m][0],&a[(m-1)/2][0]);
        swap(&a[m][1],&a[(m-1)/2][1]);
        swap(&a[m][2],&a[(m-1)/2][2]);
        m=(m-1)/2;
    }
}

int isInserted(int A[],int i, int B[], int j, int **a){
    int flag=0,k;
    for(k=0;k<n;k++){
        if((a[k][1]==i)&&(a[k][2]==j)){
            flag=1;
            break;
        }
    }
    return flag;

}
int* solve(int* A, int n1, int* B, int n2, int *len1) {
    ////printf("n1=%d\n",n1 );
    static int flag=1;
    quicksort(A,0,n1-1);
    quicksort(B,0,n2-1);
    *len1=n1;
    int i,j;
    int**a=(int**)malloc(3*n1*sizeof(int));
    for(i=0;i<3*n1;i++)
        a[i]=(int*)malloc(3*sizeof(int));
    i=0,j=0;
    //printf("check3\n");
    insert(A,i,B,j,a);
    //printf("check4\n");
    int *d=(int*)malloc(3*sizeof(int));
    while(idx<n1){
        //printf("check4\n");
        d=extractMax(a);
        C[idx]=d[0];
        idx++;
        if(isInserted(A,d[1],B,d[2]+1,a)==0)  
            insert(A,d[1],B,d[2]+1,a);    
        if(isInserted(A,d[1]+1,B,d[2],a)==0)  
            insert(A,d[1]+1,B,d[2],a);    
    }
    return C;
    
}

int main(){
    int n1;
    scanf("%d",&n1);
    int A[n1],B[n1];
    int i;
    for(i=0;i<n1;i++)
        scanf("%d",&A[i]);
    for(i=0;i<n1;i++)
        scanf("%d",&B[i]);
    int*len1=(int*)malloc(sizeof(int));
    //printf("check1\n");
    solve(A,n1,B,n1,len1);
    //printf("check2\n");
    for(i=0;i<*len1;i++)
        printf("%d ",C[i]);
    printf("\n");
    return 0;
}