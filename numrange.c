#include <stdlib.h>
#include <stdio.h>
/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * @input C : Integer
 * 
 * @Output Integer
 */
int numRange(int* A, int n1, int B, int C) {
    int i=0,j=0;
    int sum=A[0];
    int count=0;
    if(C<=0)
        return 0;
    for(i=0;i<n1;i++){
        sum=0;
        for(j=i;j<n1;j++){
            sum+=A[j];
            if((sum>=B)&&(sum<=C)){
                count++;
                printf("count=%d \ti=%d\tj=%d\tsum=%d\n",count,i,j,sum);
            }
            else if(sum>C)
                break;
        }
    }
    return count;
    
}


int main(){
    int A[26]={76, 22, 81, 77, 95, 23, 27, 35, 24, 38, 15, 90, 19, 46, 53, 6, 77, 96, 100, 85, 43, 16, 73, 18, 7, 66};
    int n1=26;
    int B=98;
    int C=290;
    int x=numRange(A,n1,B,C);
    printf("x=%d\n", x);
    return 0;
}


