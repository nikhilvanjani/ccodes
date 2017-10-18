#include<stdio.h>
#include<stdlib.h>

/*void swap(int &b,int &a){
	int tmp;
	tmp=a;
	a=b;
	b=tmp;
}*/

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

int main(){
	int i,n;
	scanf("%d",&n);
	int a[n],b[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);	
	}
	heapsort(a,b,n);
	for(i=0;i<n;i++)
		printf("%d ",b[i]);

	return 0;

}
