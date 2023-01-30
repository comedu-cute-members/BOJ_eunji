#include <stdio.h>

int nextPrime(int* primeList, int current, int* primeCount) {
    int flag = 1;
    while (flag) {
        current++;
        flag = 0;
        for (int i = 0; i < *primeCount; i++) {
            if (current % primeList[i] == 0) {
                flag = 1;
                break;
            }
        }
    }
    primeList[*primeCount] = current;
    *primeCount++;
    return current;
}

int main() {
    int N;
    scanf("%d", &N);
    
    int primeList[N];
    primeList[0] = 2;
    int primeCount = 1;

    int prime = 2;
    int M = N;
    while (prime <= M) {
        if (M % prime == 0) {
            printf("%d\n", prime);
            M = M / prime;
        }
        else prime = nextPrime(primeList, prime, &primeCount);
    }

    return 0;
}