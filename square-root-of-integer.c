#include <stdlib.h>
#include <stdio.h>
/**
 * @input A : Integer
 * 
 * @Output Integer
 */
int Sqrt(int A) {
    int low=0,high=46341;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        printf("low=%d\nhigh=%d\nmid=%d\nmid*mid=%d\n\n",low,high,mid,mid*mid );
        if(mid*mid==A){
            //printf("check1\n");
            return mid;
        }
        if(mid*mid<A){
            //printf("check2\n");
            low=mid+1;
        }
        else{
            //printf("check3\n");
            high=mid-1;
        }
    }
    return high;

}

int main(){
    int A=930675566;
    A=Sqrt(A);
    printf("%d\n", A);

    return 0;
}
