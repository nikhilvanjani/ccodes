/**
 * @input A : 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output Integer
 */
int min(int x, int y){
    if(x<y)
        return x;
    else
        return y;
} 
int minPathSum(int** A, int n11, int n12) {
    int i,j;
    int**B=(int**)malloc(n11*sizeof(int*));
    for(i=0;i<n11;i++)
        B[i]=(int*)malloc(n12*sizeof(int));
    B[0][0]=A[0][0];
    for(i=1;i<n11;i++)
        B[i][0]=B[i-1][0]+A[i][0];
    for(i=1;i<n12;i++)
        B[0][i]=B[0][i-1]+A[0][i];
    for(i=0;i<n11+n12-1;i++){
        for(j=1;j<=i-1;j++){
            if((i-j<n11)&&(j<n12))
                B[i-j][j]=min(B[i-j-1][j],B[i-j][j-1])+A[i-j][j];
        }
    }
    return B[n11-1][n12-1];
}