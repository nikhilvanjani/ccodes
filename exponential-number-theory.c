#include <stdio.h>

int mod(int a, int b){
    int x=a%b;
    if(x>=0)
        return x;
    else
        return b+x;
}

int gcd(int a, int b){
    if(b==0)
        return a;
    gcd(b,mod(a,b));
}

int bical(int bi, int bx, int by, int c){
    int bj=bi;
    bi=mod(bi*1000,c);
    bi=mod(bi*bx,c);
    bj=mod(bj*by,c);
    bi=mod(bi+bj,c);
    return bi;
}

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        int b,n;
        scanf("%d %d",&b,&n);
        int bx=b/1000;
        int by=b%1000;
        int c=1000000007;
        int bi=1;
        int sum=0;
        int j,x;
        for(j=1;j<=n;j++){
            bi=bical(bi,bx,by,c);
            x=mod(gcd(j,n),c);
            sum=mod(sum+mod(bi*x,c) ,c);
            //printf("sum=%d\n",sum );
        }
        printf("%d\n",sum);
        
    }
    return 0;
}
