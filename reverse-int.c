#include <stdlib.h>
#include <stdio.h>
/**
 * @input A : Integer
 * 
 * @Output Integer
 */
int reverse(int A) {
    // if(A>2147483647)
    //     return 0;
    // if(A<-2147483648)
    //     return 0;
    int flag=0;
    if(A<0){
        A=-A;
        flag=1;
    }
    int B[10];
    int k=0;
    int x=A;
    int i=0;
    while(x>0){
        B[i]=x%10;
        x=x/10;
        i++;
    }
    int y=0;
    for(k=0;k<i;k++){
        printf("k=%d y=%d\n",k,y );
        if(k==9){
            printf("check1\n%d>=2147483647\n",y);
            if(y>=214748364){
                printf("check2\n");
                if(y>214748364)
                    return 0;
                printf("check3\n");
                if(flag==0 && (B[k]>7))
                    return 0;
                if(flag==1 && (B[k]>8))
                    return 0;
            }
        }
        y=y*10;
        y=y+B[k];
    }
        
    
    if(flag==1)
        return -y;
    else
        return y;
    
}

int main(){
    signed int A;
    scanf("%d",&A);
    signed int B=reverse(A);
    printf("%d\n",B );
    return 0;
}
