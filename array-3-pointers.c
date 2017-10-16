#include <stdlib.h>
#include <stdio.h>
/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Read only ( DON'T MODIFY ) Integer array
 * @input n2 : Integer array's ( B ) length
 * @input C : Read only ( DON'T MODIFY ) Integer array
 * @input n3 : Integer array's ( C ) length
 * 
 * @Output Integer
 */
int mod(int x){
    if(x>0)
        return x;
    else
        return -x;
}
int max(int x, int y){
    if(x>y)
        return x;
    else
        return y;
}

int BinarySearch(const int* A, int n, int x) {
    int result=-1;
    if(n==1){
        result=A[0];
    }
    if(n>1){
        //printf("check2\n");
        //printf("x=%d A[0]=%d\n",x,A[0] );
        if(x<A[0]){
            //printf("check3\n");
            return A[0];
        }
        if(x>A[n-1]){
            //printf("check4\n");
            return A[n-1];
        }
        int low=0, high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            //printf("low=%d\nhigh=%d\nmid=%d\n\n",low, high, mid );
            if(A[mid]==x){
                result=A[mid];
                break;
            }
            else if(A[high]<x){
                result=A[high];
                break;
            }
            else if(A[low]>x){
                result=A[low-1];
                break;
            }
            else if(A[mid]<x)
                low=mid+1;
            else
                high=mid-1;
        }
    }
    return result;

}

int minimize(const int* A, int n1, const int* B, int n2, const int* C, int n3) {
    int i;
    int x,y;
    int min=-1;
    int val;
    for(i=0;i<n1;i++){
        x=BinarySearch(B,n2,A[i]);
        y=BinarySearch(C,n3,A[i]);
        val=max(mod(A[i]-x),max(mod(A[i]-y),mod(x-y)));
        if(min==-1)
            min=val;
        if(min>val)
            min=val;
        printf("i=%d\tmin=%d\n",i, min);
    }
    for(i=0;i<n2;i++){
        x=BinarySearch(A,n1,B[i]);
        y=BinarySearch(C,n3,B[i]);
        val=max(mod(B[i]-x),max(mod(B[i]-y),mod(x-y)));
        if(min>val)
            min=val;
        printf("i=%d\tmin=%d\n",i, min);
    }
    for(i=0;i<n3;i++){
        x=BinarySearch(B,n2,C[i]);
        y=BinarySearch(A,n1,C[i]);
        val=max(mod(C[i]-x),max(mod(C[i]-y),mod(x-y)));
        if(min>val)
            min=val;
        printf("i=%d\tmin=%d\n",i, min);
    }
    return min;
}

int main(){
    const int A[3]={1,4,10};
    const int B[3]={2,15,20};
    const int C[2]={10,12};
    int n1=3,n2=3,n3=2;
    int x=minimize(A,n1,B,n2,C,n3);
    printf("%d\n",x );
    return 0;
}