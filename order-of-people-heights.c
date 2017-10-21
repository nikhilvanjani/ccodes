/**
 * @input heights : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input infronts : Integer array
 * @input n2 : Integer array's ( B ) length
 * In this case, n1 = n2. 
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */

void swap(int*a, int*b){
    int t=*a;
    *a=*b;
    *b=t;
} 

int partition(int A[], int low, int high, int B[]){
    int pivot=A[low];
    int i=low+1,j=high;
    while(i<j){
        if(A[i]>pivot){
            swap(&A[i],&A[j]);
            swap(&B[i],&B[j]);
            j--;
        }
        else{
            i++;
        }
    }
    if(A[i]<pivot){
        swap(&A[i],&A[low]);
        swap(&B[i],&B[low]);
        return i;
    }
    else{
        swap(&A[i-1],&A[low]);
        swap(&B[i-1],&B[low]);
        return i-1;
    }
} 
 
void quicksort(int *A,int low, int high,int*B){
    if(low<high){
        int p=partition(A,low,high,B);
        quicksort(A,low,p-1,B);
        quicksort(A,p+1,high,B);
    }
}
 
int* order(int* heights, int n1, int* infronts, int n2, int *len1) {
    quicksort(heights,0,n1-1,infronts);
    int *ret=(int*)malloc(n1*sizeof(int));
    *len1=n1;
    int i,j;
    for(i=0;i<n1;i++){
        j=0;
        while(infronts[j]!=0)
            j++;
        ret[i]=heights[j];
        while(j>=0){
            infronts[j]--;
            j--;
        }
    }
    return ret;
    
}
