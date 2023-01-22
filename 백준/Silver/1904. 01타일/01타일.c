#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    if (N == 1) printf("1");
    else if (N == 2) printf("2");
    else {
        int tile[N];
        tile[0] = 1;
        tile[1] = 2;
    
        for (int i=2; i<N; i++) {
            tile[i] = (tile[i-1] + tile[i-2]) % 15746;
        }
        
        printf("%d", tile[N-1]);
    }
   
    return 0;
}