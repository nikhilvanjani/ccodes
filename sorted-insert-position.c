#include <stdlib.h>
#include <stdio.h>
/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
int searchInsert(int* A, int n, int x) {
    int result=-1;
    if(n==1){
        printf("check1\n");
        if(x<=A[0])
            result=0;
        else
            result=1;
    }
    if(n>1){
        printf("check2\n");
        printf("x=%d A[0]=%d\n",x,A[0] );
        if(x<A[0]){
            printf("check3\n");
            return 0;
        }
        if(x>A[n-1]){
            printf("check4\n");
            return n;
        }
        int low=0, high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            printf("low=%d\nhigh=%d\nmid=%d\n\n",low, high, mid );
            if(A[mid]==x){
                result=mid;
                break;
            }
            else if(A[high]<x){
                result=high+1;
                break;
            }
            else if(A[low]>x){
                result=low;
                break;
            }
            else if(A[mid]<x)
                low=mid+1;
            else
                high=mid-1;
        }
    }
    return result;

}
int main(){
    int n=164;
    int A[164] ={ 3, 4, 18, 19, 20, 27, 28, 31, 36, 42, 44, 71, 72, 75, 82, 86, 88, 97, 100, 103, 105, 107, 110, 116, 118, 119, 121, 122, 140, 141, 142, 155, 157, 166, 176, 184, 190, 199, 201, 210, 212, 220, 225, 234, 235, 236, 238, 244, 259, 265, 266, 280, 283, 285, 293, 299, 309, 312, 317, 335, 341, 352, 354, 360, 365, 368, 370, 379, 386, 391, 400, 405, 410, 414, 416, 428, 433, 437, 438, 445, 453, 457, 458, 472, 476, 480, 485, 489, 491, 493, 501, 502, 505, 510, 511, 520, 526, 535, 557, 574, 593, 595, 604, 605, 612, 629, 632, 633, 634, 642, 647, 653, 654, 656, 658, 686, 689, 690, 691, 709, 716, 717, 737, 738, 746, 759, 765, 775, 778, 783, 786, 787, 791, 797, 801, 806, 815, 820, 822, 823, 832, 839, 841, 847, 859, 873, 877, 880, 886, 904, 909, 911, 917, 919, 937, 946, 948, 951, 961, 971, 979, 980, 986, 993 };
    int B = 902;
    int x=searchInsert(A,n,B);
    printf("x=%d\n",x );
    return 0;

}
