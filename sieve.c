#include <stdio.h>
#include <stdlib.h>

/**
 * @input A : Integer
 * 
 * @Output Integer
 */
int isPrime(int A) {
    if(A<=1)
        return 0;
    if(A==2 || A==3)
        return 1;
    if(A>=4){
        printf("%d\n", A);
        printf("check2\n");
        int *B=(int*)malloc((A+1)*sizeof(int));
        // int B[A+1];
        printf("check1\n");
        int i,j;
        for(i=0;i<=A;i++){
            B[i]=1;
        }
        B[0]=0;B[1]=0;
        for(i=2;i*i<=A;i++){
            if(B[i]==1){
                for(j=2;j*i<=A;j++){
                        B[j*i]=0;
                }            
            }
        }
        int k=0;
        for(i=0;i<A;i++){
            if(B[i])
                k++;
        }
        int *result = (int *) malloc(k * sizeof(int));
        j=0;
        printf("check1\n");
        for(i=0;i<A;i++){
            if(B[i]){
                result[j]=i;
                j++;
            }
        }
        //printf("check2\n");
        for(i=0;i<k;i++){
            //printf("check3\n");
            if(A%result[i]==0){
                //printf("result[%d]=%d\n",i,result[i]);
                return 0;
            }
                
        }
        //printf("check4\n");
        return 1;
    }
}

int main(){
    int A;
    scanf("%d", &A);
    //printf("check1\n");
    int x = isPrime(A);
    printf("x=%d\n",(int)sizeof(int) );
    return 0;
}
