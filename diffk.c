#include <stdio.h>
#include <stdlib.h>
/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
int diffPossible(int* A, int n1, int B) {
    int i,j;
    int flag=0;
    j=0;
    if (n1==1)
        return flag;
    for(i=n1-1;i>=0;i--){
        if(i==j)
            j--;
        if(j<0)
            return flag;
        while(A[i]-A[j]<B){
            if(j==0)
                return flag;
            if(j>0)
                j--;
        }
        for(;j<i;j++){
            if(A[i]-A[j]==B){
                flag=1;
                return flag;
            }
            if(A[i]-A[j]<B){
                j++;
                break;
            }
        }
        j--;
    }
    return flag;
}


int main(){
    int A[15]={ 2, 14, 18, 23, 25, 36, 40, 44, 44, 53, 54, 68, 71, 80, 94 };
    int B=82;
    int n1=15;
    int val=diffPossible(A,n1,B);
    printf("%d\n", val);
    return 0;
}


