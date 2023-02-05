#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int arr[N+1];
    arr[0] = 0;
    int temp;
    for (int i=0; i<N; i++) {
        scanf("%d", &temp);
        arr[i] = arr[i-1] + temp;
    }
    
    for (int i=0; i<M; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        
        printf("%d\n", arr[e-1] - arr[s-2]);
    }
    
    return 0;
}