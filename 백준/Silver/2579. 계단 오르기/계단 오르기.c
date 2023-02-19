#include <stdio.h>

int max(int a, int b) {
    int result = a;
    if (b > result) result = b;
    
    return result;
}

int main() {
    int N;
    scanf("%d", &N);
    
    int sum[N][3];
    int weight;
    for (int i=0; i<N; i++) {
        scanf("%d", &weight);
        
        if (i==0) {
            sum[i][0] = 0;
            sum[i][1] = sum[i][2] = weight;
        } else {
            sum[i][0] = max(sum[i-1][1], sum[i-1][2]);
            sum[i][1] = sum[i-1][0] + weight;
            sum[i][2] = sum[i-1][1] + weight;
        }
    }
    
    printf("%d", max(sum[N-1][1], sum[N-1][2]));
    
    return 0;
}