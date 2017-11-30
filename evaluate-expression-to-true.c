#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @input A : String termination by '\0'
 * 
 * @Output Integer
 */
int cnttrue(char* A) {
    // printf("check3\n");
    //printf("%s\n",A);
    int alen=strlen(A)/2;
    // printf("check30 alen=%d\n",alen);
    //int no_of_symbols=alen/2;
    // printf("check300\n");
    //ith symbol : A[2*i+1]
    int i,j,k;
    // printf("check31 alen=%d\n",alen );
    int**Tr=(int**)malloc((alen+1)*sizeof(int*));
    int**Fa=(int**)malloc((alen+1)*sizeof(int*));
    // printf("check32\n");
    for(i=0;i<alen+1;i++){
        // printf("check33 i=%d\n",i);
        Tr[i]=(int*)malloc((alen+1)*sizeof(int));
        Fa[i]=(int*)malloc((alen+1)*sizeof(int));
    }
    // printf("check4\n");
    for(i=0;i<alen+1;i++){

        if((int)A[2*i]==(int)('T')){
            Tr[i][i]=1;
            Fa[i][i]=0;
        }
        else{
            Tr[i][i]=0;
            Fa[i][i]=1;
        }
    }
    // printf("check5\n");
    for(i=1;i<=alen;i++){
        for(j=0;j<=alen-i;j++){
            Tr[j][j+i]=0;
            for(k=j;k<j+i;k++){
                // printf("check6\n");
                if((int)A[2*k+1]==(int)('&')){
                    Tr[j][j+i]+=Tr[j][k]*Tr[k+1][j+i];
                    Tr[j][j+i]=Tr[j][j+i]%1003;
                    Fa[j][j+i]+=Fa[j][k]*Fa[k+1][j+i]+Tr[j][k]*Fa[k+1][j+i]+Fa[j][k]*Tr[k+1][j+i];
                    Fa[j][j+i]=Fa[j][j+i]%1003;
                }
                else if((int)A[2*k+1]==(int)('|')){
                    Tr[j][j+i]+=Tr[j][k]*Tr[k+1][j+i]+Tr[j][k]*Fa[k+1][j+i]+Fa[j][k]*Tr[k+1][j+i];
                    Tr[j][j+i]=Tr[j][j+i]%1003;
                    Fa[j][j+i]+=Fa[j][k]*Fa[k+1][j+i];
                    Fa[j][j+i]=Fa[j][j+i]%1003;
                }
                else if((int)A[2*k+1]==(int)('^')){
                    Tr[j][j+i]+=Tr[j][k]*Fa[k+1][j+i]+Fa[j][k]*Tr[k+1][j+i];
                    Tr[j][j+i]=Tr[j][j+i]%1003;
                    Fa[j][j+i]+=Tr[j][k]*Tr[k+1][j+i]+Fa[j][k]*Fa[k+1][j+i];
                    Fa[j][j+i]=Fa[j][j+i]%1003;
                }
            }    
        }
    }
    return Tr[0][alen]%1003;    
}

int main(){
  char A[1000];
  scanf("%s",A);
  printf("check1 %s\n",A);
  int x=cnttrue(A);
  printf("check2\n");
  printf("x=%d\n",x);
  return 0;
}
