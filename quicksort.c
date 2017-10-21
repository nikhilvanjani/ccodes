#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
void swap(int*a, int*b){
    int t=*a;
    *a=*b;
    *b=t;
} 

int partition(int A[], int low, int high){
    int pivot=A[low];
    int i=low+1,j=high;
    while(i<j){
        if(A[i]<pivot){
            swap(&A[i],&A[j]);
            j--;
        }
        else{
            i++;
        }
    }
    if(A[i]>pivot){
        swap(&A[i],&A[low]);
        return i;
    }
    else{
        swap(&A[i-1],&A[low]);
        return i-1;
    }
} 
 
void quicksort(int A[],int low, int high){
    if(low<high){
        int p=partition(A,low,high);
        quicksort(A,low,p-1);
        quicksort(A,p+1,high);
    }
}
 