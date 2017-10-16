/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    int j;
    for (j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int BinarySearch(int*A, int n, int x, int flag){
    int low=0, high=n-1, result=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(A[mid]==x){
            result=mid;
            if(flag==0)
                return result;
            if(flag==1){
                if(A[mid-1]==x)
                    high=mid-1;
                else
                    return result;
            }
            if(flag==2){
                if(A[mid+1]==x)
                    low=mid+1;
                else
                    return result;
            }
        }
        else if(A[mid]<x)
            low=mid+1;
        else
            high=mid-1;
    }
    return result;
} 
 

int diffPossible(const int* A, int n1, int B) {
    if(n1==1)
        return 0;

    int*C=(int*)malloc(n1*sizeof(int));
    int i;
    for(i=0;i<n1;i++)
        C[i]=A[i];
    quickSort(C,0,n1-1);
    if(B==0){
        for(i=0;i<n1-1;i++)
            if(C[i]==C[i+1])
                return 1;
        return 0;
    }
    int location=-1;
    for(i=0;i<n1;i++){
        location=BinarySearch(C,n1,C[i]+B,0);
        if((location!=-1)&&(location!=i))
            break;
    }
    if(location!=-1)
        return 1;
    else 
        return 0;
    
    
}
