#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	// char x[1];
	// sprintf(x,"%d",1);
	// printf("%s\n",x );
	// char *str1="asdf";
	// // char str2="g";
	// strcat(str1,x);
	// printf("%s\n",str1 );
	
	// char A[1];
	// A[0]='7';
	// char x=(char)(((int)A[0]-(int)('2'))*3+(int)('a'));
	// int y=(int)x;
	// char z=(char)y;
	// printf("%d\n",y);
	// printf("%c\n",x);
	// printf("%d\n",z);
	
	// char a[10];
	// scanf("%s",a);
	// printf("%s\n",a );

	// int a[3]={1,2,3};
	// int b[3]={4,5,6};
	// int i;
	// for(i=0;i<3;i++)
	// 	printf("%d ",a[i]);
	// printf("\n");
	// for(i=0;i<3;i++)
	// 	printf("%d ",b[i]);
	// printf("\n");
	// //a=b;
	// for(i=0;i<3;i++)
	// 	a[i]=b[i];
	
	// for(i=0;i<3;i++)
	// 	printf("%d ",a[i]);
	// printf("\n");
	
	// int *a=(int*)malloc(3*sizeof(int));
	// a[0]=1,a[1]=2,a[2]=3;
	// int b[3]={4,5,6};
	// int i;
	// for(i=0;i<3;i++)
	// 	printf("%d ",a[i]);
	// printf("\n");
	// for(i=0;i<3;i++)
	// 	printf("%d ",b[i]);
	// printf("\n");
	// a=b;
	// // for(i=0;i<3;i++)
	// // 	a[i]=b[i];
	
	// for(i=0;i<3;i++)
	// 	printf("%d ",a[i]);
	// printf("\n");

	int b[3]={1,2,3};
	//b=(int*)b;
	int*a=(int*)malloc(3*sizeof(int));
	a=(int*)b;
	int i;
	for(i=0;i<3;i++)
		printf("%d ",b[i]);
	printf("\n");

	for(i=0;i<3;i++)
		printf("%d ",a[i]);
	printf("\n");

	return 0;
}