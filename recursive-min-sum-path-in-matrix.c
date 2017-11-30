/**
 * @input A : 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output Integer
 */
int minPathSum(int** A, int n11, int n12) {
    if((n11==1)&&(n12==1))
        return A[0][0];
    if((n11==0)||(n12==0))
        return 100000007;
    int x=minPathSum(A,n11-1,n12);
    int y=minPathSum(A,n11,n12-1);
    if(x<y)
        return x+A[n11-1][n12-1];
    else
        return y+A[n11-1][n12-1];
    
    
}
