#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @input A : String termination by '\0'
 * @input B : Integer
 * 
 * @Output string. Make sure the string ends with null character
 */
char* convert(char* A, int B) {
    int len=strlen(A);
    char *C=(char*)malloc((len+1)*sizeof(char));
    int l=0;
    int i,j;
    int k;
    int lambda;
    if(B>1){
      k=(len-1)%(B-1);
      lambda=(len-1)/(B-1);
    }
    //printf("check3\n");
    if(((int)(len/B)>1)&&(B>1)){
        for(i=0;i<len;i++)
          C[i]='-';
        C[len]='\0';
        printf("C: %s\n",C );
        if(lambda%2==0){
            //printf("check6\n");
            for(i=0;i<B;i++){
                for(j=0;j<=lambda/2;j++){
                    //printf("check7 i=%d j=%d\n",i,j);
                    if(i==0){
                        //printf("check8\n");
                        C[l]=A[2*j*(B-1)];l++;
                    }
                    else if(i==B-1){
                        //printf("check9\n");
                        if(j<lambda/2)
                            C[l]=A[(2*j+1)*(B-1)];l++;
                    }
                    else{
                        if(2*j*(B-1)-i>0){
                            //printf("check10\n");  
                            C[l]=A[2*j*(B-1)-i];l++;
                        }
                        if((j!=lambda/2)||(i<=k)){
                            //printf("check11\n");
                            C[l]=A[2*j*(B-1)+i];l++;
                        }
                    }
                }    
            }
        }
        else{
           for(i=0;i<B;i++){
               for(j=0;j<=(lambda/2)+1;j++){
                   printf("C: %s\n", C);
                   if(i==0){
                      if(2*j*(B-1)<len){
                        C[l]=A[2*j*(B-1)];l++;
                      }
                   }
                   else if(i==B-1){
                      if((2*j+1)*(B-1)<len){
                        C[l]=A[(2*j+1)*(B-1)];l++;
                      }
                   }
                   else{

                       if(((j==0)&&(2*j*(B-1)-i>0))||((2*j!=lambda+1)||(i>B-k-2))) {
                           C[l]=A[2*j*(B-1)-i];l++;
                       }
                       if(2*j*(B-1)+i<len){
                           C[l]=A[2*j*(B-1)+i];l++;
                          printf("j=%d i=%d val=%d\n",j,i,2*j*(B-1)+i);
                          //printf("C: %s\n", C);
                       }
                   }
               }
           } 
        }
    }
    else{
        //printf("check5\n");
        for(i=0;i<len;i++)
            C[i]=A[i];
    }
    //printf("check4\n");
    C[len]='\0';
    printf("C: %s\n", C);
    
    return C;
}

int main(){
  char A[1000];
  scanf("%s",A);
  int B;
  scanf("%d",&B);
  //printf("check1\n");
  char *C=convert(A,B);
  //printf("check2\n");
  printf("C: %s\n", C);
  return 0;
}
