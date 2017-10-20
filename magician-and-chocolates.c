#include <stdio.h>
#include <stdlib.h>

/**
 * @input A : Integer
 * @input B : Integer array
 * @input n2 : Integer array's ( B ) length
 * 
 * @Output Integer
 */
 
int n=0;;
int a[100000];

void swap(int *b,int *a){
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}

void heapify(int a[],int m,int n){
	if((m+1)>(n/2))	return;
	int x;	
	if((m==(n/2)-1)&&(n%2==0))	x=2*m+1;	
	else{
		if(a[2*m+1]>=a[2*m+2])
			x=2*m+1;		
		else
			x=2*m+2;	
	}	
	if(a[m]<a[x]){		
		a[m]=a[m]+a[x];
		a[x]=a[m]-a[x];
		a[m]=a[m]-a[x];
		m=x;
		heapify(a,m,n);
	}
	else	return;
	
}

 
int extractMax(int a[]){
	int x=a[0];
	// int i=0;
	// while(2*i+2<m)
	// 	i=2*i+2;
	a[0]=a[n-1];
	// printf("a[0]=%d\n",a[0]);
	// printf("n=%d\n",n );
	n--;
	// printf("n=%d\n",n );
	heapify(a,0,n);
	return x;

}

void insert(int x,int a[]){
	a[n]=x;
	n++;
	int m=n-1;
	//printf("check1\tm=%d\t(m-1)/2=%d\n",m,(m-1)/2 );
	while((a[m]>a[(m-1)/2])&&(m>=0)){
		//printf("check1\tm=%d\t(m-1)/2=%d\n",m,(m-1)/2 );
		swap(&a[m],&a[(m-1)/2]);
		m=(m-1)/2;
	}
	
} 
int nchoc(int A, int* B, int n2) {
    int sum=0,i,x;
    int b=1000000007;
    for(i=0;i<n2;i++)
        insert(B[i],a);
    for(i=0;i<A;i++){
        x=extractMax(a);
        sum=(sum+(x%b))%b;
        insert(x/2,a);
    }
    return sum;
    
}

int main(){
	int A,n2,i;
	scanf("%d %d",&A,&n2);
	int B[n2];
	for(i=0;i<n2;i++)
		scanf("%d",&B[i]);
	for(i=0;i<n2;i++)
		printf("%d ",B[i]);
	printf("\n");
	int x=nchoc(A,B,n2);
	printf("x=%d\n",x);
	return 0;
}