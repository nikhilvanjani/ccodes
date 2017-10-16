#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @input A : String termination by ' * 
 * @Output string array. You need to malloc memory. 
 *   Fill in len1 as number of strings. Make sure every string ends with null character
 */
char** letterCombinations(char* A, int *len1) {
    int lenA=strlen(A);
    int i,j,k;
    if(lenA==1){
        //printf("check1\n");
        if((int)A[0]==(int)('0')){
            char**B=(char**)malloc(sizeof(char*));
            B[0]=(char*)malloc(sizeof(char));
            B[0][0]='0';
            *len1=1;
            return B;
        }
        else if((int)A[0]==(int)('1')){
            char**B=(char**)malloc(sizeof(char*));
            B[0]=(char*)malloc(sizeof(char));
            B[0][0]='1';
            *len1=1;
            return B;
        }
        else if((int)A[0]==(int)('2')||(int)A[0]==(int)('3')||(int)A[0]==(int)('4')||(int)A[0]==(int)('5')||(int)A[0]==(int)('6')){
            //printf("check3\n");
            char**B=(char**)malloc(3*sizeof(char*));
            B[0]=(char*)malloc(sizeof(char));
            B[1]=(char*)malloc(sizeof(char));
            B[2]=(char*)malloc(sizeof(char));
            B[0][0]=(char)(((int)A[0]-(int)('2'))*3+(int)('a'));
            B[1][0]=(char)(((int)A[0]-(int)('2'))*3+(int)('b'));
            B[2][0]=(char)(((int)A[0]-(int)('2'))*3+(int)('c'));
            *len1=3;
            //printf("check4\n");
            return B;
        }
        else if((int)A[0]==(int)('7')){
            char**B=(char**)malloc(4*sizeof(char*));
            B[0]=(char*)malloc(sizeof(char));
            B[1]=(char*)malloc(sizeof(char));
            B[2]=(char*)malloc(sizeof(char));
            B[3]=(char*)malloc(sizeof(char));
            B[0][0]='p';
            B[1][0]='q';
            B[2][0]='r';
            B[3][0]='s';
            *len1=4;
            return B;
        }
        else if((int)A[0]==(int)('8')){
            char**B=(char**)malloc(3*sizeof(char*));
            B[0]=(char*)malloc(sizeof(char));
            B[1]=(char*)malloc(sizeof(char));
            B[2]=(char*)malloc(sizeof(char));
            B[0][0]='t';
            B[1][0]='u';
            B[2][0]='v';
            *len1=3;
            return B;
        }
        else if((int)A[0]==(int)('9')){
            char**B=(char**)malloc(4*sizeof(char*));
            B[0]=(char*)malloc(sizeof(char));
            B[1]=(char*)malloc(sizeof(char));
            B[2]=(char*)malloc(sizeof(char));
            B[3]=(char*)malloc(sizeof(char));
            B[0][0]='w';
            B[1][0]='x';
            B[2][0]='y';
            B[3][0]='z';
            *len1=4;
            return B;
        }
    }
    else{
        //printf("check2\n");
        int *len2=(int*)malloc(sizeof(int));
        char**C=letterCombinations(A+1,len2);
        //printf("check5: len2=%d\n",*len2);

        if((int)A[0]==(int)('0')){
            char**B=(char**)malloc((*len2)*sizeof(char*));
            for(i=0;i<(*len2);i++){
                B[i]=(char*)malloc(lenA*sizeof(char));
                B[i][0]='0';
                for(j=1;j<lenA;j++)
                    B[i][j]=C[i][j-1];
            }
            *len1=*len2;
            return B;
        }
        else if((int)A[0]==(int)('1')){
            ////printf("check7\n");
            char**B=(char**)malloc((*len2)*sizeof(char*));
            ////printf("check9\n");
            for(i=0;i<(*len2);i++){
                ////printf("\ncheck10 i=%d\n",i );
                B[i]=(char*)malloc(lenA*sizeof(char));
                B[i][0]='1';
                ////printf("check12 lenA=%d\n",lenA);
                for(j=1;j<lenA;j++){
                    ////printf("check13 j=%d\n C[i][j-1]=%c\n",j,C[i][j-1] );
                    B[i][j]=C[i][j-1];
                }
                ////printf("check11 i=%d\n",i );
            }
            *len1=*len2;
            ////printf("check8\n");
            return B;
        }
        else if((int)A[0]==(int)('2')||(int)A[0]==(int)('3')||(int)A[0]==(int)('4')||(int)A[0]==(int)('5')||(int)A[0]==(int)('6')){
            char**B=(char**)malloc(3*(*len2)*sizeof(char*));
            for(k=0;k<3;k++){
                for(i=0;i<(*len2);i++){
                    B[k*(*len2)+i]=(char*)malloc(lenA*sizeof(char));
                    B[k*(*len2)+i][0]=(char)(((int)A[0]-(int)('2'))*3+(int)('a')+k);
                    for(j=1;j<lenA;j++){
                        B[k*(*len2)+i][j]=C[i][j-1];
                    }
                }
            }
            *len1=3*(*len2);
            return B;
        }
        else if((int)A[0]==(int)('7')){
            //printf("check6\n");
            char**B=(char**)malloc(4*(*len2)*sizeof(char*));
            for(k=0;k<4;k++){
                for(i=0;i<(*len2);i++){
                    B[k*(*len2)+i]=(char*)malloc(lenA*sizeof(char));
                    B[k*(*len2)+i][0]=(char)((int)('p')+k);
                    for(j=1;j<lenA;j++){
                        B[k*(*len2)+i][j]=C[i][j-1];
                    }
                }
            }
            *len1=4*(*len2);
            return B;
        }
        else if((int)A[0]==(int)('8')){
            char**B=(char**)malloc(3*(*len2)*sizeof(char*));
            for(k=0;k<3;k++){
                for(i=0;i<(*len2);i++){
                    B[k*(*len2)+i]=(char*)malloc(lenA*sizeof(char));
                    B[k*(*len2)+i][0]=(char)((int)('t')+k);
                    for(j=1;j<lenA;j++){
                        B[k*(*len2)+i][j]=C[i][j-1];
                    }
                }
            }
            *len1=3*(*len2);
            return B;
        }
        else if((int)A[0]==(int)('9')){
            char**B=(char**)malloc(4*(*len2)*sizeof(char*));
            for(k=0;k<4;k++){
                for(i=0;i<(*len2);i++){
                    B[k*(*len2)+i]=(char*)malloc(lenA*sizeof(char));
                    B[k*(*len2)+i][0]=(char)((int)('w')+k);
                    for(j=1;j<lenA;j++){
                        B[k*(*len2)+i][j]=C[i][j-1];
                    }
                }
            }
            *len1=4*(*len2);
            return B;
        }        
    }
    
}


int main(){
    char*A="172";
    int*len1=(int*)malloc(sizeof(int));
    char**B=letterCombinations(A,len1);
    //printf("len1: %d\n",*len1);
    int i;
    for(i=0;i<*len1;i++){
        //printf("%s\n",B[i]);
    }
    return 0;
}


