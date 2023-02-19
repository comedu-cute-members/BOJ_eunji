#include <stdio.h>

int isPrime(int a) {
    for (int i = 2; i <= a / 2; i++) {
        if (a % i == 0) return 0;
    }
    return 1;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);

        x /= 2;
        for (int j = 0; j < x; j++) {
            if (isPrime(x - j) && isPrime(x + j)) {
                printf("%d %d", x - j, x + j);
                break;
            }
        }
        printf("\n");
    }

    return 0;
}