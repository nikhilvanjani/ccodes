#include <stdio.h>
#include <stdlib.h>
int trap(const int* A, int n)
{
    int left = 0; int right = n - 1;
            int res = 0;
            int maxleft = 0, maxright = 0;
            while(left <= right)
            {
                if(A[left] <= A[right])
                {
                    if(A[left] >= maxleft) maxleft = A[left];
                    else res += maxleft-A[left];
                    left++;
                }
                else
                {
                    if(A[right] >= maxright) maxright = A[right];
                    else res += maxright - A[right];
                    right--;
                }
            }
            return res;
        }
int main(){
    int n=550;
    int A[550]={67,35,53,100,42,11,64,98};
    int x=trap(A,n);
    printf("%d\n",x );
    return 0;
}