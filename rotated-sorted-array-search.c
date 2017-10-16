#include <stdlib.h>
#include <stdio.h>

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int findMin(const int* A, int n1) {
    int low=0,high=n1-1,minima;
    int mid;
    if(A[low]>A[high]){
        while(low<=high){
            mid=(low+high)/2;
            //printf("low=%d high=%d\n",low,high );
            if(A[low]<A[mid])
                low=mid;
            else
                high=mid;
            if(low==high){
                //printf("check1\n");
                minima=low;
                break;
            }
            if(low==high-1){
                //printf("check2\n");
                minima=high;
                break;
            }
                
        }
    }
    else
        minima=0;
    return minima;
    
}

int BinarySearch(const int*A, int n, int l, int x){
    int low=l, high=n-1+l, result=-1;
    while(low<=high){
        int mid=((low+high)/2)%(2*n);
        //printf("low=%d\nhigh=%d\nmid=%d\n\n",low,high,mid );
        if(A[mid%n]==x){
            result=mid%n;
            break;
        }
        else if(A[mid%n]<x)
            low=(mid+1)%(2*n);
        else
            high=(mid-1)%(2*n);
    }
    return result;
} 

int search(const int* A, int n1, int B) {
    int l=findMin(A,n1);
    return BinarySearch((const int*)A,n1,l,B);
}

int main(){
    int n1=7;
    //int *A=(int*)malloc(n1*sizeof(int));
    int A[7]={4,5,6,7,0,1,2};
    int B=2;
    int mini=search(A,n1,B);
    printf("%d\n",mini );
    printf("%d\n",-1%20);

    return 0;
}
