#include <stdio.h>

int main() {
    int N, M, K;
    
    scanf("%d %d", &N, &M);
    int A[N][M];
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    scanf("%d %d", &M, &K);
    int B[M][K];
    for (int i=0; i<M; i++) {
        for (int j=0; j<K; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    
    int sum;
    for (int i=0; i<N; i++) {
        for (int j=0; j<K; j++) {
            sum = 0;
            for (int k=0; k<M; k++){
                sum += A[i][k] * B[k][j];
            }
            printf("%d ", sum);
        }
        printf("\n");
    }
    
    
    return 0;
}