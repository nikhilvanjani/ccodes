#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @input A : Integer
 * 
 * @Output string array. You need to malloc memory. 
 *   Fill in len1 as number of strings. Make sure every string ends with null character
 */
void myPar(char **result, int *count, char *temp, int c1, int A, int o, int c)
{
    int flag = 0;

    if((o == 0) && (c == 0))
    {
        result[*count] = (char *)malloc((2*A+1)*sizeof(char));
        strcpy(result[*count], temp);
        (*count)++;
    }

    if (o > 0)
    {
        temp[c1] = '(';
        myPar(result, count, temp, c1+1, A, o-1, c+1);
        //flag = 1;
    }
    if(c > 0)
    {
        temp[c1] = ')';
        myPar(result, count, temp, c1+1, A, o, c-1);
    }

    return;
}
 
char** generateParenthesis(int A, int *len1) {
    
    int size = 1000000;
    int len = (A * 2);
    int count = 0;
    char **result = (char **)malloc(size * sizeof(char *));
    char *temp = (char *)malloc((len+1) * sizeof(char));
    
    myPar(result, &count, temp, 0, A, A, 0);
    *len1 = count;
    return result;
}

int main(){
    int n;
    scanf("%d",&n);
    int*len1=(int*)malloc(sizeof(int));
    char**P=generateParenthesis(n,len1);
    printf("%d\n",*len1);
    return 0;
}