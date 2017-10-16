#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * @input A : String termination by '\0'
 * 
 * @Output Integer
 */
int findRank(char* A) {
   printf("check9\n");
    int i=0,j;
    int size;
//    printf("check12\n");
    printf("A: %s\n", A);
    while(A[i]!='\0')
        i++;
    size=i;
//    printf("size=%d\n", size);
    if(size==1)
        return 1;
    char*B=(char*)malloc(size*sizeof(char));
    for(i=0;i<size;i++){
        B[i]=A[i];
    }
//    printf("B: ");
//    for(i=0;i<size;i++)
//        printf("%c ",B[i]);
//    printf("\n");
    printf("check10\n");
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
    //printf("check3\n");
    int k=0;
    char val;
    i=0;
    while(i<size){
        val=B[i];
        k++;
        while(val==B[i]){
            i++;
        }
    }
    //printf("check4\n");
    int sizeC=k;
    char*C=(char*)malloc(sizeC*sizeof(char));
    //int D[sizeC];
    int *D=(int*)malloc(sizeC*sizeof(int));
    i=0;k=0;
    printf("check41\n");
    while(i<size){
        C[k]=B[i];
        D[k]=1;
        //printf("check411\n");
        i++;
        while(val==B[i]){
            printf("check42 %d\n",i);
            D[k]++;
            i++;
        }
        k++;
    }
    printf("check5\n");
    int location;
    // printf("B: ");
    // for(i=0;i<size;i++)
    //     printf("%c ",B[i]);
    // printf("\n");
    for(i=0;i<sizeC;i++){
        printf("check50\n");
        printf("C[%d]=%c\n",i,C[i]);
        printf("A: %s\n", A);
        printf("A[0]=%c\n",A[0]);
        if(C[i]==A[0]){
            printf("check53\n");
            location=i;
            printf("check51\n");
            D[i]--;
            printf("check52\n");
            break;
        }
        printf("check54\n");
    }
    printf("check6\n");
    int result=location;
//    printf("location=%d\n",location );
    for(i=1;i<size;i++){
        result=(result*i)% 1000003;
  //      printf("result=%d\n",result );
    }
    printf("check7\n");
    int result2=1;
    for(i=0;i<sizeC;i++){
        for(j=1;j<=D[i];j++)
            result2=(result2*j)% 1000003;
    }
    i=0;
    while((result+i*1000003)%result2!=0)
        i++;
    result=(result+i*1000003)/result2;
    printf("check8\n");
    printf("free1\n");
    free(D);
    printf("free2\n");
    free(C);
    printf("free3\n");
    free(B);
    printf("free4\n");
    return (result+findRank(A+1))% 1000003;
}

int main(){
    char A[10];
    scanf("%s",A);
//    printf("check1\n");
//    printf("%d\n",(int)strlen(A) );
//    printf("check2\n");
//    printf("%s\n", A);
    printf("check1\n");
    int B=findRank(A);
    printf("B=%d\n", B);
    printf("check2\n");
    return 0;
}