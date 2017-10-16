#include <stdio.h>
#include <stdlib.h>

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row, len2 as columns 
 */

int C[1000];
int flag=1;

int ** permute(int* A, int n1, int *len1, int *len2) {
    int i,j;
    if(flag==1){
        for(i=0;i<1000;i++)
            C[i]=1;
        flag=0;
    }
    *len2=n1;
    *len1=1;
    for(i=1;i<=n1;i++)
        (*len1)=(*len1)*i;
    int **B=(int**)malloc((*len1)*sizeof(int*));
    for(i=0;i<*len1;i++)
        B[i]=(int*)malloc((*len2)*sizeof(int));
    if(n1==1){
        i=0;
        while(C[i]!=1)
            i++;
        B[0][0]=A[i];
        return B;
    }
    int k=0,h;
    for(i=0;i<n1;i++){
        while(C[k]!=1)
            k++;
        for(j=0;j<(*len1)/n1;j++){
            B[i*(*len1)/n1+j][0]=A[k];
        }
        C[k]=0;
        int*len3=(int*)malloc(sizeof(int));
        int*len4=(int*)malloc(sizeof(int));
        int **D=permute(A,n1-1,len3,len4);
        // for(j=0;j<*len3;j++){
        //     for(h=0;h<*len4;h++)
        //         printf("%d ",D[j][h]);
        //     printf("\n");
        // }
        // //printf("------\n");
        for(j=0;j<(*len1)/n1;j++){
            for(h=1;h<n1;h++)
                B[i*(*len3)+j][h]=D[j][h-1];
        }
        C[k]=1;
        k++;
    }
    return B;
    
}

int main(){
    int n1;
    scanf("%d\n",&n1);
    int A[n1];
    int i,j;
    for(i=0;i<n1;i++)
        scanf("%d ",&A[i]);
    int *len1=(int*)malloc(sizeof(int));
    int *len2=(int*)malloc(sizeof(int));
    int **B=permute(A,n1,len1,len2);
    for(i=0;i<*len1;i++){
        for(j=0;j<*len2;j++)
            printf("%d ",B[i][j]);
        printf("\n");
    }
    return 0;
}