#include <stdlib.h>
#include <stdio.h>
/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
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
 
int* searchRange( int* A, int n1, int B, int *len1) {
    int x=BinarySearch(A,n1,B,1);
    int y=BinarySearch(A,n1,B,2);
    printf("x=%d y=%d\n",x,y );
    len1=(int*)malloc(sizeof(int));
    if(y==-1 && x==-1){
        *len1=0;
        printf("check1\n");        
    }
    else{
        printf("check2\n");
        *len1=y-x+1;
        printf("%d\n",*len1 );
    }
    int *C=(int*)malloc(2*sizeof(int));
    C[0]=x;
    C[1]=y;
    printf("%d\n",*len1 );
    
    return C;
}

int main(){
    int n1=6;
    int A[6] = { 1, 1 ,1, 3, 3, 4 };
    int B = 3;
    int *len1;
    int *C=searchRange(A,n1,B,len1);
    printf("C: %d %d\n",C[0],C[1] );
    printf("%d\n", *len1);
    return 0;
}
