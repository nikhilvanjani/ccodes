#include <stdlib.h>
#include <stdio.h>
/**
 * @input A : Integer
 * 
 * @Output 2D int array. You need to malloc memory for result 2D array. 
 * Fill in number_of_rows as row, number_of_columns as columns 
 */
int ** prettyPrint(int A, int *nr, int *nc) {
	// SAMPLE CODE
	/*
	 * *number_of_rows = A;
	 * *number_of_columns = A;
	 * int **result = (int **)malloc(A * sizeof(int *));
	 * // DO STUFF HERE
	 * return result;
	 */
	 //printf("check2\n");
	 //printf("A=%d\n",A );
	 *nr=2*A-1;
	 *nc=2*A-1;
	 //printf("*nr=%d,*nc=%d\n",*nr,*nc );
	 int **B=(int**)malloc((2*A-1)*sizeof(int*));
	 int i;
	 for(i=0;i<2*A-1;i++){
	     B[i]=(int*)malloc((2*A-1)*sizeof(int));
	 }
	 if(A==1){
	     B[0][0]=1;
	     //printf("check5\n");
	     return B;
	 }
	 int*nr1=(int*)malloc(sizeof(int));
	 int*nc1=(int*)malloc(sizeof(int));
	 //printf("check3\n");
	 int**C;
	 //printf("check31\n");
	 C=prettyPrint(A-1,nr1,nc1);
	 //printf("check4\n");
	 //printf("2*A-1=%d\n",2*A-1 );
	 for(i=0;i<2*A-1;i++){
	 	//printf("check41\n");
	    B[0][i]=A;
	 	//printf("check42\n");
	    B[i][0]=A;
	 	//printf("check43\n");
	    B[2*A-2][i]=A;
	 	//printf("check44\n");
	    B[i][2*A-2]=A;
	 	//printf("check45\n");
	 }
	 //printf("check6\n");
	 int j;
	 for(i=0;i<2*(A-1)-1;i++){
	     for(j=0;j<2*(A-1)-1;j++){
	         B[i+1][j+1]=C[i][j];
	     }
	 }
	 //printf("check7\n");
	 return B;
	    
}

int main(){
	int A;
	scanf("%d",&A);
	int *nr=(int*)malloc(sizeof(int));
	int *nc=(int*)malloc(sizeof(int));
	int **C=(int**)malloc((2*A-1)*sizeof(int*));
	int i;
	for(i=0;i<A;i++){
	    C[i]=(int*)malloc((2*A-1)*sizeof(int));
	}
	//printf("check1\n");
	C=prettyPrint(A,nr,nc);
	int j;
	//printf("*nr=%d\n",*nr);
	//printf("*nc=%d\n",*nc);
	for(i=0;i<2*A-1;i++){
		for(j=0;j<2*A-1;j++){
			printf("%d ",C[i][j] );
		}
		printf("\n");
	}

	return 0;
}
