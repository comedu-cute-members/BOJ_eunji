#include <stdio.h>
#include <stdlib.h>

int fib(int n, int* count) {
    if (n == 1 || n == 2) {
        *(count) += 1;
        return 1;
    }
    else return (fib(n-1, count) + fib(n-2, count));
}

int fibonacci(int n, int* count) {
    int *f = malloc(n * sizeof(int));
    f[0] = 1;
    f[1] = 1;
    for (int i=2; i<n; i++) {
        *(count) += 1;
        f[i] = f[i-1] + f[i-2];
    }
    
    return f[n];
}

int main() {
    
    int n;
    scanf("%d", &n);
    
    int fibCount = 0, fibonacciCount = 0;
    int result1 = fib(n, &fibCount);
    int result2 = fibonacci(n, &fibonacciCount);
    
    printf("%d %d", fibCount, fibonacciCount);
    
    return 0;
}