#include <stdio.h>
#include <stdlib.h>
/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
 
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int removeDuplicates(int* A, int n1) {
    if(n1==1)
        return 1;
    int val=A[0];
    int m=A[n1-1]+1;
    printf("m=%d\n",m );
    int i,j;
    for(i=1;i<n1;i++){
        if(A[i]==val)
            A[i]=m;
        else
            val=A[i];
    }
    
    for(i=0;i<n1;i++)
        printf("%d ", A[i]);
    printf("\n");

    i=0,j=0;
    int flag=0;
    while((i<n1)&&(j<n1)){
        if(A[i]!=m){
            printf("check1\n");
            i++;
            continue;
        }
        if(flag==0){
            printf("check2\n");
            j=i+1;
            flag=1;
            continue;
        }
        if(A[j]==m){
            printf("check3\n");
            j++;
            continue;
        }
        printf("check4\n");
        swap(&A[i],&A[j]);
    }
    
    for(i=0;i<n1;i++)
        printf("%d ", A[i]);
    printf("\n");

    i=0;
    printf("m=%d\n", m);
    while(i<n1){
        printf("i=%d A[i]=%d\n", i,A[i]);
        if(A[i]!=m){
            i++;
            printf("%d\n", i);
        }
        else
            break;
    }
    printf("i=%d\n", i);
    return i;
}

int main(){
    int A[4]={2,3,3,3};
    int n1=4;
    int x=removeDuplicates(A,n1);
    printf("%d\n", x);
    return 0;
}
