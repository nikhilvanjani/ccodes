#include <stdio.h>
#include <stdlib.h>
/**
 * @input A : String termination by '\0'
 * 
 * @Output Integer
 */
int romanToInt(char* A) {
    int i=0;
    int val1;
    int val2;
    char x;
    int j;
    int result=0;
    while((int)A[i]!=(int)('\0')){
        x=A[i];
        if((int)x==(int)('I'))
            val1=1;
        if((int)x==(int)('V'))
            val1=5;
        if((int)x==(int)('X'))
            val1=10;
        if((int)x==(int)('L'))
            val1=50;
        if((int)x==(int)('C'))
            val1=100;
        if((int)x==(int)('D'))
            val1=500;
        if((int)x==(int)('M'))
            val1=1000;
        val2=val1;
        i++;
        while((int)x==(int)A[i]){
            val2+=val1;
            i++;
        }
        if(((int)x==(int)('I'))&&((int)A[i]==(int)('V')))
            val2=-val2;
        if(((int)x==(int)('I'))&&((int)A[i]==(int)('X')))
            val2=-val2;
        if(((int)x==(int)('V'))&&((int)A[i]==(int)('X')))
            val2=-val2;
        if(((int)x==(int)('X'))&&((int)A[i]==(int)('L')))
            val2=-val2;
        if(((int)x==(int)('X'))&&((int)A[i]==(int)('C')))
            val2=-val2;
        if(((int)x==(int)('L'))&&((int)A[i]==(int)('C')))
            val2=-val2;
        if(((int)x==(int)('C'))&&((int)A[i]==(int)('D')))
            val2=-val2;
        if(((int)x==(int)('C'))&&((int)A[i]==(int)('M')))
            val2=-val2;
        if(((int)x==(int)('D'))&&((int)A[i]==(int)('M')))
            val2=-val2;
        result+=val2;
        // printf("val1=%d\n",val1);
        // printf("val2=%d\n",val2);
        // printf("result=%d\n",result );
    }
    return result;
}

int main(){
	char A[10];
	scanf("%s",A);
	int result=romanToInt(A);
	printf("result=%d\n",result );
	return 0;
}
