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
                minima=A[low];
                break;
            }
            if(low==high-1){
                //printf("check2\n");
                minima=A[high];
                break;
            }
                
        }
    }
    else
        minima=A[0];
    return minima;
    
}

int main(){
    int n1=7;
    //int *A=(int*)malloc(n1*sizeof(int));
    int A[7]={4,5,6,7,0,1,2};
    int mini=findMin(A,n1);
    printf("%d\n",mini );
}
