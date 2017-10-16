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
 

int main(){
    int n1=10;
    int *A=(int*)malloc(n1*sizeof(int));
    A={2,3,4,4,4,5,6,6,7,7};
    int B=4;
    int flag=1;
    //flag=0 : any occurence
    //flag=1 : first occurence
    //flag=2 : last occurence
    int location = BinarySearch(A,n1,B,flag);
    printf("count=%d\n", count);
    return 0;
}