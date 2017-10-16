#include <stdlib.h>
#include <stdio.h>

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
int BinarySearch(int*A, int n, int x, int flag){
    int low=0, high=n-1, result=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(A[mid]==x){
            result=mid;
            if(flag==0)
                return result;
            if(flag==1){
                if(A[mid-1]==x)
                    high=mid-1;
                else
                    return result;
            }
            if(flag==2){
                if(A[mid+1]==x)
                    low=mid+1;
                else
                    return result;
            }
        }
        else if(A[mid]<x)
            low=mid+1;
        else
            high=mid-1;
    }
    return result;
} 
 
int findCount(const int* A, int n1, int B) {
    int x=BinarySearch(A,n1,B,1);
    int y=BinarySearch(A,n1,B,2);
    if(x==-1 || y==-1)
        return 0;
    else
        return y-x+1;
}

int main(){
    int n1=10;
    int *A=(int*)malloc(n1*sizeof(int));
    A={2,3,4,4,4,5,6,6,7,7};
    int B=4;
    int count = findCount(A,n1,B);
    printf("count=%d\n", count);
    return 0;
}