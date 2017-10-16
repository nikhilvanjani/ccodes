#include <stdio.h>
#include <stdlib.h>
/**
 * @input n : Integer
 * @input k : Integer
 * 
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row, len2 as columns 
 */
 
int ** combine(int n, int k, int *len1, int *len2) {
    *len2=k;
    *len1=1;
    int i,j;
    for(i=1;i<=k;i++){
        *len1=(*len1)*(n-k+i);
        *len1=(*len1)/i;
    }
    if(n<k)
        return;
    int**A=(int**)malloc((*len1)*sizeof(int*));
    for(i=0;i<(*len1);i++)
        A[i]=(int*)malloc(k*sizeof(int));
    
    if(n==k){
        for(i=0;i<k;i++)
            A[0][i]=i+1;
        return A;
    }
    else if(k==1){
        for(i=0;i<n;i++)
            A[i][0]=i+1;
        return A;
    }
    else{
        int*len3=(int*)malloc(sizeof(int));
        int*len4=(int*)malloc(sizeof(int));
        int*len5=(int*)malloc(sizeof(int));
        int*len6=(int*)malloc(sizeof(int));
        int**B=combine(n-1,k-1,len3,len4);
        int**C=combine(n-1,k,len5,len6);
        for(i=0;i<*len3;i++)
            A[i][0]=1;
        for(i=0;i<*len3;i++){
            for(j=1;j<=*len4;j++){
                printf("%d ",B[i][j-1]);
                A[i][j]=B[i][j-1]+1;
            }
            printf("\n");
        }
        printf("---------\n");
        for(i=*len3;i<(*len3)+(*len5);i++)
            for(j=0;j<(*len6);j++)
                A[i][j]=C[i-(*len3)][j]+1;
        for(i=0;i<*len3;i++){
            for(j=0;j<*len4;j++)
                printf("%d ",B[i][j]);
            printf("\n");
        }
        printf("--------\n");
        for(i=0;i<*len5;i++){
            for(j=0;j<*len6;j++)
                printf("%d ",C[i][j]);
            printf("\n");
        }        
        printf("--------\n");
        return A;
    }    
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int *len1=(int*)malloc(sizeof(int));
    int *len2=(int*)malloc(sizeof(int));
    int **A=combine(n,k,len1,len2);
    int i,j;
    for(i=0;i<*len1;i++){
        for(j=0;j<*len2;j++)
            printf("%d ",A[i][j]);
        printf("\n");
    }
    return 0;
}
