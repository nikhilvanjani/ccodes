#include <stdio.h>
#include <stdlib.h>
/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int size;

int isPresent(int x, int**C, int B){
    int i;
    for(i=0;i<B;i++){
        if((C[i][0]==x)&&(C[i][1]>0))
            return i;
    }
    return -1;
}

int** remov(int x, int **C){
    int i=0;
    while(C[i][0]!=x)
        i++;
    C[i][1]--;
    if(C[i][1]<1)
        size--;
    return C;
}
 
int* dNums(int* A, int n1, int B, int *len1) {
    //printf("check3\n");
    *len1=n1-B+1;
    if(B>n1)
        return NULL;
    int *arr=(int*)malloc((n1-B+1)*sizeof(int));
    int **C=(int**)malloc(B*sizeof(int*));
    int i;
    //printf("check4\n");
    for(i=0;i<B;i++){
        C[i]=(int*)malloc(2*sizeof(int));
        C[i][1]=-1;
    }
    int j=0,x;
    //printf("check5\n");
    for(i=0;i<B;i++){
        x=isPresent(A[i],C, B);
        //printf("check51 A[i]=%d x=%d\n",A[i],x);
        if(x==-1){
            C[j][0]=A[i];
            C[j][1]=1;
            j++;
        }
        else{
            C[x][1]++;
        }
    }
    // for(i=0;i<B;i++)
    //     printf("%d ",C[i][0]);
    // printf("\n");
    // for(i=0;i<B;i++)
    //     printf("%d ",C[i][1]);
    // printf("\n");
    size=j;
    arr[0]=size;
    int k;
    // printf("check6\n");
    for(i=1;i<n1-B+1;i++){
        k=0;
        // printf("check9 size=%d\n",size);
        C=remov(A[i-1],C);        
        // printf("check10 size=%d\n",size);
        x=isPresent(A[i+B-1],C,B);
        // printf("check11 x=%d\n",x);
        if(x==-1){
            // printf("check112\n");
            while(C[k][1]>0)
                k++;
            C[k][0]=A[i+B-1];
            C[k][1]=1;
            size++;
        }
        else{
            C[x][1]++;
        }
        // printf("check12 size=%d\n",size );
        // for(j=0;j<B;j++)
        //     printf("%d ",C[j][0]);
        // printf("\n");
        // for(j=0;j<B;j++)
        //     printf("%d ",C[j][1]);
        // printf("\n");        
        arr[i]=size;
    }
    // printf("check7\n");
    // for(i=0;i<n1-B+1;i++)
    //     printf("%d ",arr[i]);
    // printf("\n");
    return arr; 
}

int main(){
    int i,n1;
    scanf("%d",&n1);
    int A[n1];
    for(i=0;i<n1;i++)
        scanf("%d",&A[i]);
    int B;
    scanf("%d",&B);
    int*len1=(int*)malloc(sizeof(int));
    printf("check1\n");
    int *C=dNums(A,n1,B,len1);
    printf("check2\n");
    for(i=0;i<*len1;i++)
        printf("%d ",C[i]);
    printf("\n");
    return 0;
}
