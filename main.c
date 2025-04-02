#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3

void print(int A[N][N]){
    for(int i=0; i<N; i++){
        printf("|");
        for(int j=0; j<N; j++) printf(" %d", A[i][j]);
        printf(" |\n");
    }
    printf("\n");
}

void makeBoolMat(int A[N][N]){
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) A[i][j]=rand()%2;
    print(A);
}

void computeBoolMat(int A[N][N], int B[N][N]){
    int join[N][N], meet[N][N], product[N][N];
    
    for(int i=0; i<N; i++) for(int j=0; j<N; j++){
        join[i][j] = A[i][j]|B[i][j];
        meet[i][j] = A[i][j]&B[i][j];
        
        product[i][j]=0;
        for(int k=0; k<N; k++) product[i][j]|=A[i][k]&B[k][j];
    }
    print(join);print(meet);print(product);
}

void multiply(int A[N][N], int B[N][N]){
    int C[N][N];
    
    for(int i=0; i<N; i++) for(int j=0; j<N; j++){
        C[i][j]=0;
        for(int k=0; k<N; k++) C[i][j]+=A[i][k]*B[k][j];
    }
    print(C);
}

int determinant(int A[N][N]){
    int sumR=0, sumL=0;
    int deter;
    
    for(int i=0; i<N; i++){
        int j=(i+1)%N;
        int k=(i+2)%N;
        
        sumR+=A[0][i]*A[1][j]*A[2][k];
        sumL+=A[0][i]*A[1][k]*A[2][j];
        
        deter=sumR-sumL;
    }
    return deter;
}

int main()
{
    // int A[N][N], B[N][N];
    // srand(time(NULL));
    
    // makeBoolMat(A);
    // makeBoolMat(B);
    
    // computeBoolMat(A,B);
    
    int A[N][N]={
         {3,0,1},{-4,2,1},{5,-3,5}
    };
    printf("%d\n", determinant(A));
    
    // int A[N][N]={
    //     {1,0,-2},{2,-1,3},{3,5,-2}
    // };
    // int B[N][N]={
    //     {-3,8,2},{1,-1,6},{4,1,0}
    // };
    
    // multiply(A,B);

    return 0;
}