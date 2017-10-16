#include <stdio.h>
#include <stdlib.h>

int main(){
	int*a ;
	a=(int*)malloc(1*sizeof(int));
	*a=1;
	printf("%d\n", *a);
	return 0;
}