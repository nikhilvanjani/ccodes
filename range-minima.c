#include <stdio.h>
#include <stdlib.h>

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* genPowerof2(int x){
	int*A=(int*)malloc(x*sizeof(int));
	A[0]=0;
	A[1]=1;
	int i;
	for(i=2;i<x;i++){
		if(i==2*A[i-1])
			A[i]=i;
		else
			A[i]=A[i-1];
	}
	return A;
}

int* genLog(int x){
	int*B=(int*)malloc(x*sizeof(int));
	int i;
	for(i=0;i<x;i++)
		B[i]=-1;
	B[0]=0;
	B[1]=1;
	for(i=2;i<x;i=i*2)
		B[i]=B[i/2]+1;
	int j;
	for(i=1;i<x;i++){
		if(B[i]!=-1)
			j=B[i];
		else
			B[i]=j;
	}
	return B;
}

int** genDS(int*A,int len, int*Log){
	int **B=(int**)malloc(len*sizeof(int*));
	int i,j;
	for(i=0;i<len;i++)
		B[i]=(int*)malloc(Log[len]*sizeof(int));
	for(i=0;i<len;i++)
		B[i][0]=A[i];
	for(j=1;i<Log[len];j++){
		for(i=0;i<len;i++){
			if(B[i][j-1]<B[i+Log[j]][j-1])
				B[i][j]=B[i][j-1];
			else
				B[i][j]=B[i+Log[j]][j-1];
		}
	}

}


int rangeMinima(int*A, int len, int i, int j, int* Powerof2, int* Log, int**B){


	int L=j-i;
	int t=Powerof2[L];
	int k=Log[L];
	printf("check2\n");
	if(t==L){
		printf("check3\ti=%d\tk=%d\n",i,k);
		return B[i][k];
	}
	else{
		if(B[i][k]<B[j-t][k]){
			printf("check4\n");
			return B[i][k];
		}
		else{
			printf("check5\n");
			return B[j-t][k];
		}
	}
}

int* slidingMaximum(const int* A, int n1, int B, int *len1) {
	int *C=(int*)malloc((n1-B+1)*sizeof(int));
	int *Powerof2=genPowerof2(n1);
	int *Log=genLog(n1);
	int **D=genDS(A,n1,Log);
	int i;
	printf("check1\n");
	for(i=0;i<n1-B+1;i++)
		C[i]=rangeMinima(A,n1,i,i+B-1,Powerof2,Log,D);

	return C;

}

int main(){
	int A[1]={1};
	int n1=1;
	int B=1;
	int*len1=(int*)malloc(sizeof(int));
	int*C=slidingMaximum(A,n1,B,len1);
	return 0;
}


