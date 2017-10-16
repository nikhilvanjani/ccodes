#include <stdio.h>
#include <stdlib.h>
/**
 * @input A : String termination by '\0'
 * 
 * @Output Integer
 */
 #include <string.h>
int isPalindrome(char* A) {
    int lenA=strlen(A);
    char B[lenA+1];
    int i=0;
    int j=0;
//    printf("check1\n");
    while((int)A[i]!=(int)('\0')){
        if((((int)A[i]>=(int)('0')) && ((int)A[i]<=(int)('9')))||(((int)A[i]>=(int)('a'))&&((int)A[i]<=(int)('z')))) {
           B[j]=A[i];
           //printf("B[%d]=%c\n",j,B[j] );
           j++;
        }
        if(((int)A[i]>=(int)('A'))&&((int)A[i]<=(int)('Z'))){
            //printf("check4\n");
            B[j]=A[i]-'A'+'a';
            j++;
            //printf("B[%d]=%c\n",j,B[j] );
        }
        i++;
    }
//    printf("check2\n");
    B[j]='\0';
    int lenB=strlen(B);
    int flag=1;
    for(i=0;i<=lenB/2;i++){
        if((int)B[i]!=(int)B[lenB-1-i]){
            flag=0;
            break;
        }
    }
//    printf("B: %s\n",B );
//    printf("check3\n");
    return flag;
}

int main(){
    char A[100]="A man, a plan, a canal: Panama";
    //scanf("%s",A);
    printf("A: %s\n",A );
    printf("%d\n",isPalindrome(A) );
    return 0;
}