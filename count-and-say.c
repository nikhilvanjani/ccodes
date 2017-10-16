#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* countAndSay(int A) {
    char*str2="";
    char* str1="";
    int i,j;
    int k;
    char x;
    for(k=0;k<A;k++){
        if(k==0){
            str1="1";
            strcat(str1,"\0");
        }
        else{
            printf("check1\n");
            j=0;
            while((int)str1[j]!=(int)("\0")){
                printf("check11\n");
                i=1;
                x=str1[j];j++;
                printf("check12\n");
                while((int)str1[j]==(int)(x)){
                    i++;j++;
                }
                printf("check13\n");
                strcat(str2,(char)(i+48));
                printf("check14\n");
                strcat(str2,(char)(x+48));
                printf("str2: %s\n",str2 );
            }
            printf("check2\n");
            strcat(str2,"\0");
            str1=str2;
            str2="";
        }
    }
    return str1;
}

int main(){
    int A;
    scanf("%d",&A);
    char*B=countAndSay(A);
    printf("%s\n",B);
}