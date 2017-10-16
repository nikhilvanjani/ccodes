#include <stdlib.h>
#include <stdio.h>
/**
 * @input A : Read only ( DON'T MODIFY ) String termination by '\0'
 * 
 * @Output Integer
 */
int lengthOfLastWord(const char* A) {
    if(A[1]=='\0')
        return 1;
    int len=0;
    while((int)A[len]!=(int)('\0'))
        len++;
    int i=len-1;
    int j=0;
    while(i>=0 && (int)A[i]==(int)(' ')){
        i--;j++;
    }
    while(i>=0 && (int)A[i]!=(int)(' '))
        i--;
    printf("len=%d\ni=%d\nj=%d\n",len,i,j);
    if(i<0)
        return len-j;
    else
        return len-i-j-1;
    
}

int main(){
    char*A="World";
    int x=lengthOfLastWord(A);
    printf("x=%d\n",x );
}