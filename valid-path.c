#include <stdio.h>
#include <stdlib.h>
/**
 * @input A : Integer
 * @input B : Integer
 * @input C : Integer
 * @input D : Integer
 * @input E : Integer array
 * @input n5 : Integer array's ( E ) length
 * @input F : Integer array
 * @input n6 : Integer array's ( F ) length
 * 
 * @Output string. Make sure the string ends with null character
 */
char* solve(int x, int y, int N, int R, int* E, int n5, int* F, int n6) {
    int**A=(int**)malloc((2*R+1)*sizeof(int*));
    int i,j,k;
    for(i=0;i<2*R+1;i++)
        A[i]=(int*)malloc((2*R+1)*sizeof(int));
    for(i=0;i<2*R+1;i++){
        for(j=0;j<2*R+1;j++){
            if((i-R)*(i-R)+(j-R)*(j-R)<=R*R){
                A[i][j]=0;
            }
            else A[i][j]=1;
        }
    }
    int**B=(int**)malloc((x+1)*sizeof(int*));
    for(i=0;i<x+1;i++){
        B[i]=(int*)malloc((y+1)*sizeof(int));
        for(j=0;j<y+1;j++)
            B[i][j]=1;
    }
    for(k=0;k<N;k++){
        for(i=0;i<2*R+1;i++){
            for(j=0;j<2*R+1;j++){
                if((E[k]+i-R>=0)&&(E[k]+i-R<=x)&&(F[k]+j-R>=0)&&(F[k]+j-R<=y)&&(A[i][j]==0)){
                    B[E[k]+i-R][F[k]+j-R]=0;
                }
            }
        }
    }
    if((B[0][0]==0)||(B[x][y]==0))
        return "NO";
    B[0][0]=2;
    for(k=0;k<x+y+1;k++){
        for(i=k,j=0;i>=0,j<=k;i--,j++){
            if((i<=x)&&(j<=y)){
                if(B[i][j]==2){
                    if((i+1<=x)&&(B[i+1][j]==1))
                        B[i+1][j]=2;
                    if((j+1<=y)&&(B[i][j+1]==1))
                        B[i][j+1]=2;                
                    
                }
            }
        }
    }
    for(i=0;i<=x;i++){
        for(j=0;j<=y;j++)
            printf("%d ",B[i][j]);
        printf("\n");
    }
    if(B[x][y]==2)
        return "YES";
    else
        return "NO";
}

int main(){
    int x,y,N,R;
    scanf("%d%d%d%d",&x,&y,&N,&R);
    int E[N+1];
    int F[N+1];
    int i;
    for(i=0;i<=N;i++)
        scanf("%d",&E[i]);
    for(i=0;i<=N;i++)
        scanf("%d",&F[i]);
    char*val=solve(x,y,N,R,E+1,N,F+1,N);
    printf("--%s--\n",val);
    return 0;
}
