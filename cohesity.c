#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

int** permute(int**A, int alen, int*len1, int*len2){
	// printf("check3 alen=%d\n",alen);
	if(alen==1){
		// printf("check9\n");
		*len1=A[0][0];
		*len2=1;
		int i;
		// printf("check10\n");
		int**C=(int**)malloc((*len1)*sizeof(int*));
		for(i=0;i<*len1;i++)
			C[i]=(int*)malloc((*len2)*sizeof(int));
		// printf("check11\n");
		for(i=1;i<=A[0][0];i++)
			C[i-1][0]=A[0][i];
		// printf("check12\n");
		return C;
	}
	// printf("check4\n");
	int*len3=(int*)malloc(sizeof(int));
	int*len4=(int*)malloc(sizeof(int));
	int**B=permute(A+1,alen-1,len3,len4);
	// printf("check5 len3=%d len4=%d\n",*len3,*len4);
	int i,j,k;
	// for(i=0;i<*len3;i++){
	// 	for(j=0;j<*len4;j++)
	// 		printf("%d ",B[i][j]);
	// 	printf("\n");
	// }
	*len1=A[0][0]*(*len3);
	*len2=*len4+1;
	int**C=(int**)malloc((*len1)*sizeof(int*));
	// printf("check6\n");
	for(i=0;i<*len1;i++)
		C[i]=(int*)malloc((*len2)*sizeof(int));
	// printf("check7\n");
	for(i=1;i<=A[0][0];i++){
		for(j=0;j<*len3;j++){
			C[(i-1)*(*len3)+j][0]=A[0][i];
			for(k=1;k<*len2;k++)
				C[(i-1)*(*len3)+j][k]=B[j][k-1];
		}
	}
	// printf("check8 len1=%d len2=%d\n",*len1,*len2);
	// for(i=0;i<*len1;i++){
	// 	for(j=0;j<*len2;j++)
	// 		printf("%d ",C[i][j]);
	// 	printf("\n");
	// }

	return C;
}

void answer(char**s, int slen, char**q, int qlen, int* m, int* n){
	int**A=(int**)malloc(qlen*sizeof(int*));
	int count;
	int i,j,k;
	for(j=0;j<qlen;j++){
		count=0;
		for(i=0;i<slen;i++)
			if(strcmp(s[i],q[j])==0)
				count++;
		if(count==0){
			*m=-1;
			*n=-1;
			return;
		}
		A[j]=(int*)malloc((count+1)*sizeof(int));
		A[j][0]=count;
		k=1;
		for(i=0;i<slen;i++){
			if(strcmp(s[i],q[j])==0){
				A[j][k]=i;
				k++;
			}
		}
		// for(i=0;i<=A[j][0];i++)
		// 	printf("%d ",A[j][i]);
		// printf("\n");	
	}
	int*len1=(int*)malloc(sizeof(int));
	int*len2=(int*)malloc(sizeof(int));
	// printf("check1\n");
	int**C=permute(A,qlen,len1,len2);
	int min,max,diff,didx;
	didx=0;
	diff=-1;
	// printf("check11\n");
	for(i=0;i<*len1;i++){
		min=C[i][0];
		max=C[i][0];
		for(j=0;j<*len2;j++){
			if(C[i][j]<min)
				min=C[i][j];
			if(C[i][j]>max)
				max=C[i][j];
		}
		if(i==0){
			diff=max-min;
			didx=i;
		}
		// printf("%d %d\n",diff,max-min);	
		if(diff>max-min){
			diff=max-min;
			didx=i;
		}
	}
	min=C[didx][0];
	max=C[didx][0];
	for(j=0;j<*len2;j++){
		if(C[didx][j]<min){
			min=C[didx][j];
			
		}
		if(C[didx][j]>max){
			max=C[didx][j];
			
		}
	}
	*m=min;
	*n=max;
	// printf("check2 didx=%d\n",didx);
	// printf("len1=%d len2=%d\n",*len1,*len2);
	// for(i=0;i<*len1;i++){
	// 	for(j=0;j<*len2;j++)
	// 		printf("%d ",C[i][j]);
	// 	printf("\n");
	// }

}

int main(){
	char S[MAX];
	char Q[MAX];
	gets(S);
	gets(Q);
	int i;
	int slen=1;
	for(i=0;i<strlen(S);i++)
		if((int)S[i]==(int)(' '))
			slen++;
	int qlen=1;
	for(i=0;i<strlen(Q);i++)
		if((int)Q[i]==(int)(' '))
			qlen++;
	char **s=(char**)malloc(slen*sizeof(char*));
	char **q=(char**)malloc(qlen*sizeof(char*));
	for(i=0;i<slen;i++)
		s[i]=(char*)malloc(1000*sizeof(char));
	for(i=0;i<slen;i++)
		q[i]=(char*)malloc(1000*sizeof(char));
	
	//printf("%s\n",S);
	//printf("%s\n",Q);
	int j,k;
	j=0,k=0;
	for(i=0;i<strlen(S);i++){
		if((int)S[i]==(int)(' ')){
			s[j][k]='\0';
			j++;
			k=0;
		}
		else{
			s[j][k]=S[i];
			k++;
		}
	}
	j=0,k=0;
	for(i=0;i<strlen(Q);i++){
		if((int)Q[i]==(int)(' ')){
			q[j][k]='\0';
			j++;
			k=0;
		}
		else{
			q[j][k]=Q[i];
			k++;
		}
	}	
	// printf("%d %d\n",slen,qlen );
	// for(i=0;i<slen;i++)
	// 	printf("%s\n",s[i]);
	// printf("s done. begin q\n");
	// for(i=0;i<qlen;i++)
	// 	printf("%s\n",q[i]);
	// printf("\n");
	int*m=(int*)malloc(sizeof(int));
	int*n=(int*)malloc(sizeof(int));
	answer(s,slen,q,qlen,m,n);
	printf("l=%d k=%d\n",*m,*n);
	return 0;
}