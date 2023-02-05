#include <stdio.h>
#include <math.h>

void prime(int x) {
    for (int i=2; i<=sqrt(x); i++) {
        if (x%i == 0) return;
    }
    printf("%d\n", x);
}

int main() {
    
    int N, M;
    scanf("%d %d", &N, &M);
    
    for (int i=N; i<=M; i++) {
        if (i != 1) prime(i);
    }
    
    return 0;
}