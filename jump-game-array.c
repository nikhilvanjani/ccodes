#include <stdio.h>
#include <stdlib.h>
/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int canJump(int* A, int n1) {
    if(n1==1)
        return 1;
    int i;
    i=n1-1;
    while((A[i]!=0)&&(i>=0))
        i--;
    if(i<0)
        return 1;
    int j=i;
    i--;
    while((A[i]<=j-i)&&(i>=0))
        i--;
    if(i<0)
        return 0;
    else
        return canJump(A,i+1);
    
}


int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    int x=canJump(A,n);
    printf("x=%d\n",x);
    return 0;
}