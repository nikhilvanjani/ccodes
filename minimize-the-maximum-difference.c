#include <stdlib.h>
#include <stdio.h>
/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer array
 * @input n2 : Integer array's ( B ) length
 * @input C : Integer array
 * @input n3 : Integer array's ( C ) length
 * 
 * @Output Integer
 */
int max(int x, int y){
    if(x>y)
        return x;
    else
        return y;
} 
int min(int x, int y){
    if(x>y)
        return y;
    else
        return x;
}
int BinarySearch1(const int* A, int n, int x) {
    int result=-1;
    if(n==1){
        result=A[0];
    }
    if(n>1){
        //printf("check2\n");
        //printf("x=%d A[0]=%d\n",x,A[0] );
        if(x<A[0]){
            //printf("check3\n");
            return A[0];
        }
        if(x>A[n-1]){
            //printf("check4\n");
            return A[n-1];
        }
        int low=0, high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            //printf("low=%d\nhigh=%d\nmid=%d\n\n",low, high, mid );
            if(A[mid]==x){
                result=A[mid];
                break;
            }
            else if(A[high]<x){
                result=A[high];
                break;
            }
            else if(A[low]>x){
                result=A[low-1];
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
int BinarySearch2(const int* A, int n, int x) {
    int result=-1;
    if(n==1){
        result=A[0];
    }
    if(n>1){
        //printf("check2\n");
        //printf("x=%d A[0]=%d\n",x,A[0] );
        if(x<A[0]){
            //printf("check3\n");
            return A[0];
        }
        if(x>A[n-1]){
            //printf("check4\n");
            return A[n-1];
        }
        int low=0, high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            //printf("low=%d\nhigh=%d\nmid=%d\n\n",low, high, mid );
            if(A[mid]==x){
                result=A[mid];
                break;
            }
            else if(A[high]<x){
                result=A[high+1];
                break;
            }
            else if(A[low]>x){
                result=A[low];
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

int solve(int* A, int n1, int* B, int n2, int* C, int n3) {
    int i;
    int x,y;
    int minima=-1;
    int val;
    for(i=0;i<n1;i++){
        if(A[i]-BinarySearch1(B,n2,A[i])>BinarySearch2(B,n2,A[i])-A[i])
            x=BinarySearch2(B,n2,A[i]);
        else
            x=BinarySearch1(B,n2,A[i]);
        if(A[i]-BinarySearch1(C,n3,A[i])>BinarySearch2(C,n3,A[i])-A[i])
            y=BinarySearch2(C,n3,A[i]);
        else
            y=BinarySearch1(C,n3,A[i]);
        val=max(A[i],max(x,y))-min(A[i],min(x,y));
        if(minima==-1)
            minima=val;
        if(minima>val)
            minima=val;
    }
    for(i=0;i<n2;i++){
        if(B[i]-BinarySearch1(A,n1,B[i])>BinarySearch2(A,n1,B[i])-B[i])
            x=BinarySearch2(A,n1,B[i]);
        else
            x=BinarySearch1(A,n1,B[i]);
        if(B[i]-BinarySearch1(C,n3,B[i])>BinarySearch2(C,n3,B[i])-B[i])
            y=BinarySearch2(C,n3,B[i]);
        else
            y=BinarySearch1(C,n3,B[i]);
        val=max(B[i],max(x,y))-min(A[i],min(x,y));
        if(minima==-1)
            minima=val;
        if(minima>val)
            minima=val;
    }
    for(i=0;i<n3;i++){
        if(C[i]-BinarySearch1(B,n2,C[i])>BinarySearch2(B,n2,C[i])-C[i])
            x=BinarySearch2(B,n2,C[i]);
        else
            x=BinarySearch1(B,n2,C[i]);
        if(C[i]-BinarySearch1(A,n1,C[i])>BinarySearch2(A,n1,C[i])-C[i])
            y=BinarySearch2(A,n1,C[i]);
        else
            y=BinarySearch1(A,n1,C[i]);

        val=max(C[i],max(x,y))-min(A[i],min(x,y));
        if(minima==-1)
            minima=val;
        if(minima>val)
            minima=val;
    }
    return minima;
    
}

// int solve(int* A, int n1, int* B, int n2, int* C, int n3) {
//     int i,j,k;
//     int minima=-1;
//     int val;
//     for(i=0;i<n1;i++){
//         for(j=0;j<n2;j++){
//             for(k=0;k<n3;k++){
//                 val=max(A[i],max(B[j],C[k]))-min(A[i],min(B[j],C[k]));   
//               if(minima==-1){
//                   minima=val;
//               } 
//               if(minima>val)
//                     minima=val;
//             }
//         }
//     }
//     return minima;
// }
