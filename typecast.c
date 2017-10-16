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
	char A[1];
	A[0]='7';
	char x=(char)(((int)A[0]-(int)('2'))*3+(int)('a'));
	int y=(int)x;
	char z=(char)y;
	printf("%d\n",y);
	printf("%c\n",x);
	printf("%d\n",z);
	return 0;
}