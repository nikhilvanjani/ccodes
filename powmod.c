#include <stdlib.h>
#include <stdio.h>
/**
 * @input x : Integer
 * @input n : Integer
 * @input d : Integer
 * 
 * @Output Integer
 */
int powmod(int x, int y, int p) {
    if(x==0)
        return 0;
    if(p==1){
        return 0; 
    }
    int res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1){
            int z=x;
            int w=0;
            while(z>0){
                w=w*10+(z%10);
                z=z/10;
            }
            while(w>0){
                if(res<0)
                    res+=p;
                res=(res*10)%p;
                res=(res+(w%10))%p;
                w=w/10;
            }
        }
         // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
        printf("x=%d\nres=%d\n\n",x,res);  
    }
    if(res<0)
        res=res+p;
    return res;    
}

int main(){
    int x=-1;
    int n=2;
    int d=20;
    int res=powmod(x,n,d);
    printf("%d\n", res);
    return 0;
}