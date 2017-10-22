#include <stdio.h>
#include <stdlib.h>
/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int* longestIncreasingSubsequence(const int*A, int n1){
    int*B=(int*)malloc(n1*sizeof(int));
    B[0]=1;
    int i,j;
    int max=0;
    for(i=1;i<n1;i++){
        max=0;
        for(j=i-1;j>=0;j--)
            if((A[j]<A[i])&&(B[j]>max))
                max=B[j];
        B[i]=max+1;
    }
    return B;
}

int* longestDecreasingSubsequence(const int*A, int n1){
    int*B=(int*)malloc(n1*sizeof(int));
    B[n1-1]=1;
    int i,j;
    int max=0;
    for(i=n1-2;i>=0;i--){
        max=0;
        for(j=i+1;j<n1;j++)
            if((A[j]<A[i])&&(B[j]>max))
                max=B[j];
        B[i]=max+1;
    }
    return B;
}


int longestSubsequenceLength(const int* A, int n1) {
    if(n1==0)
        return 0;
    int*B=longestIncreasingSubsequence(A,n1);
    int*C=longestDecreasingSubsequence(A,n1);
    int i;
    for(i=0;i<n1;i++)
        printf("%d ",B[i]);
    printf("\n");
    for(i=0;i<n1;i++)
        printf("%d ",C[i]);
    printf("\n");
    int max=-1;
    for(i=0;i<n1;i++)
        if(B[i]+C[i]-1>max)
            max=B[i]+C[i]-1;
    return max;
    
}

int main(){
    int n;
    scanf("%d",&n);
    const int A[n];
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    int ans=longestSubsequenceLength(A,n);
    printf("ans=%d\n",ans);

    return 0;
}