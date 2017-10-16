#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/** 
 * @input A : String termination by '\0'
 * 
 * @Output Integer
 */
int findRank(char* A) {
//    printf("check11\n");
    int i=0,j;
    int size;
//    printf("check12\n");
    printf("%s\n", A);
    while(A[i]!='\0')
        i++;
    size=i;
    printf("size=%d\n", size);
    if(size==1)
        return 1;
    char*B=(char*)malloc(size*sizeof(char));
    for(i=0;i<size;i++){
        B[i]=A[i];
    }
    printf("B: ");
    for(i=0;i<size;i++)
        printf("%c ",B[i]);
    printf("\n");
    int flag;
    while(1){
        flag=0;
        for(i=0;i<size-1;i++){
            if((int)(B[i])>(int)(B[i+1])){
                char tmp=B[i];
                B[i]=B[i+1];
                B[i+1]=tmp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
    int location;
    printf("B: ");
    for(i=0;i<size;i++)
        printf("%c ",B[i]);
    printf("\n");
    for(i=0;i<size;i++){
        if(B[i]==A[0]){
            location=i;
            break;
        }
    }
    int result=location;
    printf("location=%d\n",location );
    for(i=1;i<size;i++){
        result=result*i;
        printf("result=%d\n",result );
    }
    
    return result+findRank(A+1);
}

int main(){
    char A[10];
    scanf("%s",A);
//    printf("check1\n");
//    printf("%d\n",(int)strlen(A) );
//    printf("check2\n");
//    printf("%s\n", A);
//    printf("check1\n");
    int B=findRank(A);
    printf("B=%d\n", B);
    printf("check2\n");
    return 0;
}