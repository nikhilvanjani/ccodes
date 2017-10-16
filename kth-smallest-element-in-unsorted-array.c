#include <stdlib.h>
#include <stdio.h>
/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */

int kthsmallest(const int* A, int n1, int k) {
    int i,j;
    int index=0;
    int count=0;
    int max=A[0];
    for(i=0;i<n1;i++)
        if(max<A[i])
            max=A[i];
    int min=max+1;
    int pmin=-1;
    for(i=0;i<k;i++){
        if(count>0){
            printf("check3\n");
            count--;
            printf("index=%d\tA[index]=%d\n",index,A[index]);
            continue;
        }
        if(i>0)
            pmin=min;
        min=max+1;
        for(j=0;j<n1;j++){
            printf("i=%d\tj=%d\tA[j]=%d\tcount=%d\n",i,j,A[j],count);
            if((min>A[j])&&((pmin==-1)||(A[j]>pmin))){
                printf("check1\n");
                min=A[j];
                count=1;
                index=j;
                printf("min=%d\tindex=%d\n",min,index );
            }
            else if((min==A[j])&&((pmin==-1)||(A[j]>pmin))){
                printf("check2\n");
                count++;
            }
        }
        count--;
        printf("index=%d\tA[index]=%d\n",index,A[index]);        
    }
    return A[index];
    
}

int main(){
    const int A[2]={47,7 };
    int n1=2;
    int k=2;
    printf("%d\n",kthsmallest(A,n1,k));
    return 0;
}

