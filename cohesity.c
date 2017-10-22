#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

void answer(char**s, int slen, char**q, int qlen, int* l, int* k){
	int*A=(int*)malloc(slen*sizeof(int));
	int i,j;
	int flag;
	for(i=0;i<slen;i++)
		A[i]=-1;
	printf("qlen=%d slen=%d\n",qlen,slen );
	for(i=0;i<slen;i++)
		printf("%s\n",s[i]);
	for(i=0;i<qlen;i++)
		printf("%s\n",q[i]);
	for(j=0;j<qlen;j++){
		flag=0;
		for(i=0;i<slen;i++){
			printf("%s %s\n",q[j],s[i]);
			if(strcmp(s[i],q[j])==0){
				A[i]=j;
				flag=1;
			}
		}
		if(flag==0){
			*l=-1;
			*k=-1;
			return;
		}
	}
	for(i=0;i<slen;i++)
		if(A[i]!=-1)
			break;
	if(i<slen)		
		*l=i;
	else
		*l=-1;
	for(i=slen-1;i>=0;i--)
		if(A[i]!=-1)
			break;
	if(i>=0)
		*k=i;
	else
		*k=-1;
	for(i=0;i<slen;i++)
		printf("%d ",A[i]);
	printf("\n");

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