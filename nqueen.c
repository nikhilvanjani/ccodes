#include <stdio.h>
#include <stdlib.h>

int board[1000][1000];
int idx=0;
char ***B;

char** printBoard(int n){
	int i,j;
	char**A=(char**)malloc(n*sizeof(char*));
	for(i=0;i<n;i++)
		A[i]=(char*)malloc(n*sizeof(char));
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(board[i][j])
				A[i][j]='Q';
			else
				A[i][j]='.';
		}
	}
	return A;
}

int isSafe(int n, int row, int col){
	//printf("check2 row=%d col=%d\n",row,col);
	int i,j;
	for(i=0;i<col;i++)
		if(board[row][i])
			return 0;
	//printf("check21\n");
	for(i=row,j=col;(i>=0)&&(j>=0);i--,j--){
		//printf("i=%d j=%d\n",i,j );
		if(board[i][j])
			return 0;
	}
	//printf("check22\n");
	for(i=row,j=col;(i<n)&&(j>=0);i++,j--){
		//printf("i=%d j=%d\n",i,j );
		if(board[i][j])
			return 0;
	}
	//printf("check3\n");
	return 1;
}

int Solve(int n, int col){
	//printf("check1 col=%d\n",col );
	int i,j,k;

	if(col>=n){
		B[idx]=printBoard(n);
		// for(j=0;j<n;j++){
		// 	for(k=0;k<n;k++)
		// 		printf("%c ",B[idx][j][k]);
		// 	printf("\n");
		// }
		// printf("\n");
		idx++;
		return 1;
	}
	for(i=0;i<n;i++){
		if(isSafe(n,i,col)){
			//printf("trying row=%d for col=%d\n",i,col );
			board[i][col]=1;
			Solve(n,col+1);
				//printf("it is safe row=%d for col=%d\n",i,col);
				//return 1;
			
			//printf("Not safe row=%d for col=%d\n",i,col );
			board[i][col]=0;
		}
	}
	if(idx>0)
		return 1;
	else
		return 0;
}

char*** solveNQueens(int A, int *len1, int *len2) {
    B=(char***)malloc(1000*sizeof(char**));
    if(Solve(A,0)==0){
        *len1=0;
        *len2=0;
        return NULL;
    }
    else{
        *len1=idx;
        *len2=A;
        return B;
    }
    
}

int main(){
	int n;
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			board[i][j]=0;

	int*len1=(int*)malloc(sizeof(int));
	int*len2=(int*)malloc(sizeof(int));
	char***C=solveNQueens(n,len1,len2);
	printf("len1=%d\n",*len1 );
	for(i=0;i<*len1;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++)
				printf("%c ",C[i][j][k]);
			printf("\n");
		}
		printf("\n");
	}


	printf("----------------\n");
	// if(Solve(n,0)==0)
	// 	printf("Solution does not exist\n");
	// else{
	// 	printf("idx=%d\n",idx );
	// 	for(i=0;i<idx;i++){
	// 		for(j=0;j<n;j++){
	// 			for(k=0;k<n;k++)
	// 				printf("%c ",B[i][j][k]);
	// 			printf("\n");
	// 		}
	// 		printf("\n");
	// 	}
	// }

	return 0;
}