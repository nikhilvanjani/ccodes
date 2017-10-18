#include<stdio.h>
#include<stdlib.h>

void swap(int *b,int *a){
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}

int n;
int a[1000];
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

void build_maxheap(int a[],int n){
	int i;	
	for(i=(n/2)-1;i>=0;i--)
		heapify(a,i,n);
}

void heapsort(int a[],int b[],int n){
	int i;
	for(i=0;i<n;i++){	
		build_maxheap(a,n-i);		
		b[i]=a[0];
		a[0]=a[n-1-i];
	}
}

void extractMax(int a[]){
	// int i=0;
	// while(2*i+2<m)
	// 	i=2*i+2;
	a[0]=a[n-1];
	// printf("a[0]=%d\n",a[0]);
	// printf("n=%d\n",n );
	n--;
	// printf("n=%d\n",n );
	heapify(a,0,n);

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

int main(){
	int i;
	//scanf("%d",&n);
	// int b[n];
	// for(i=0;i<n;i++){
	// 	scanf("%d",&a[i]);	
	// }
	// heapsort(a,b,n);
	// for(i=0;i<n;i++)
	// 	printf("%d ",b[i]);
	// printf("\n");
	// extractMax(b,n);
	// printf("_n=%d\n",n );
	// for(i=0;i<n;i++)
	// 	printf("%d ",b[i]);
	// printf("\n");
	n=0;
	insert(3,a);
	insert(2,a);
	insert(1,a);
	insert(4,a);
	insert(5,a);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	extractMax(a);
	extractMax(a);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
