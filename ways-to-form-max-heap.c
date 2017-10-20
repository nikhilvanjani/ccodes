#include <stdio.h>
#include <stdlib.h>
/**
 * @input A : Integer
 * 
 * @Output Integer
 */
int c=1000000007;
int magic[101][2];
int fl=1;
int answer[101];


long long int ncr(int n, int r){
    long long int x=1;
    int i;
    if(r>n-r)
        return ncr(n,n-r);
    for(i=1;i<=r;i++){
        x=(x*(n-r+i));
        x=x/i;
        x=x%c;
    }
    return x;
}


int solve(int A) {
    int i,j;
    if(A==1)
        return 1;
    if(A==2)
        return 1;
    if(fl==1){
        //printf("--build--\n");
        int flag=1;
        magic[0][0]=0;
        magic[0][1]=0;
        magic[1][0]=0;
        magic[1][1]=0;
        for(i=2;i<=100;i++){
            if(flag==1){
                magic[i][0]=magic[i-1][0]+1;
                magic[i][1]=magic[i-1][1];
                if(magic[i][0]==2*magic[i][1]+1)
                    flag=0;
                //printf("%d:\t%d\t%d\tflag=%d\n",i,magic[i][0], magic[i][1],flag);

            }
            else{
                magic[i][0]=magic[i-1][0];
                magic[i][1]=magic[i-1][1]+1;
                if(magic[i][0]==magic[i][1])
                    flag=1;
                //printf("%d:\t%d\t%d\tflag=%d\n",i,magic[i][0], magic[i][1],flag);
            }
            
        }
        for(i=0;i<=100;i++)
            answer[i]=-1;
        answer[1]=1;
        answer[2]=1;
        for(i=3;i<=100;i++)
            answer[i]= (((ncr(i-1,magic[i][0])*answer[magic[i][0]])%c)*answer[magic[i][1]])%c;
        // for(i=1;i<=100;i++)
        //     printf("%d %d\n",magic[i][0], magic[i][1]);
        fl=0;    
    }
    //printf("solving for A=%d\tdivide into %d %d\n",A,magic[A][0],magic[A][1]);
    // for(i=1;i<=10;i++)
    //     printf("%d %d\n",magic[i][0], magic[i][1]);

    //printf("check1 x=%d y=%d\n",x,y);
    return answer[A];
    
}

int main(){
    int A;
    scanf("%d",&A);
    int x=solve(A);
    printf("answer=%d\n",x);
    return 0;
}
