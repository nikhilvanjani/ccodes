#include <stdio.h>
#include <stdlib.h>

/**
 * @input A : Integer
 * 
 * @Output 2D int array. You need to malloc memory. Fill in number_of_rows as row, number_of_columns as columns 
 */
int ** generateMatrix(int N, int *nr, int *nc) {
	// SAMPLE CODE
        /*
         * *number_of_rows = A;
         * *number_of_columns = A;
         * int **result = (int **)malloc(A * sizeof(int *));
         * // DO STUFF HERE
         * return result;
         */
	// DO STUFF HERE
// 	*length_of_array = n11 * n12; // length of result array
// 	int *result = (int *) malloc(*length_of_array * sizeof(int));
	nr=(int*)malloc(sizeof(int));nr=&N;
	nc=(int*)malloc(sizeof(int));nc=&N;
    // printf("N=%d,nr=%d, nc=%d\n",N, *nr,*nc );
	int i,j;
	int **A = (int **)malloc((*nr) * sizeof(int *));
    for (i = 0; i < (*nr); i++) {
        A[i] = (int *)malloc((*nc) * sizeof(int));
    }
    // printf("%d\n",(int)((*nr)*sizeof(int*)));
    // printf("%d\n",(int)((*nc)*sizeof(int)));
    // printf("%d\n",(int)sizeof(A));
    // printf("%d\n",(int)sizeof(A[0]));
    // printf("%d\n",(int)(sizeof(A)/sizeof(int)) );
    // printf("%d\n",(int)(sizeof(A[0])/sizeof(int)) );

	int **B = (int **)malloc((*nr) * sizeof(int *));
    for (i = 0; i < (*nr); i++) {
        B[i] = (int *)malloc((*nc) * sizeof(int));
    }
    for(i=0;i<(*nr);i++){
        for(j=0;j<(*nc);j++){
            B[i][j]=0;
        }
    }
    int k=0;
    int flag=0;
    i=0,j=0;
    while(k<(*nr)*(*nc)){
        // result[k]=A[i][j];
        A[i][j]=k+1;
        B[i][j]=1;
        k++;
        if(flag==0){//moving right
            if((j+1<(*nc))&&(B[i][j+1]==0))
                j++;
            else{
                flag=1;
                i++;
            }
        }
        else if(flag==1){//moving down
            if((i+1<(*nr))&&(B[i+1][j]==0))
                i++;
            else{
                flag=2;
                j--;
            }
        }
        else if(flag==2){//moving left
            if((j-1>=0)&&(B[i][j-1]==0))
                j--;
            else{
                flag=3;
                i--;
            }
        }
        else if(flag==3){//move up
            if((i-1>=0)&&(B[i-1][j]==0))
                i--;
            else{
                flag=0;
                j++;
            }
        }
    }
    // for(i=0;i<(*nr);i++){
    //     for(j=0;j<(*nc);j++){
    //         printf("%d ",A[i][j] );
    //     }
    //     printf("\n");
    // }
    return A;
}

int main(){
    int N;
    scanf("%d",&N);
    int* nr,*nc;
    int i,j;
    int **A = (int **)malloc((N) * sizeof(int *));
    for (i = 0; i < (N); i++) {
        A[i] = (int *)malloc((N) * sizeof(int));
    }
    A=generateMatrix(N,nr,nc);
    for(i=0;i<(N);i++){
        for(j=0;j<(N);j++){
            printf("%d ",A[i][j] );
        }
        printf("\n");
    }

    return 0;
}
