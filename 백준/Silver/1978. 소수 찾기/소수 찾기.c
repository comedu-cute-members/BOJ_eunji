#include <stdio.h>

int primeCheck(int num) {
    if (num == 1) return 0;
    for (int i=2; i<num; i++) {
        if (num%i == 0) return 0;
    }
    return 1;
}

int main() {
    int N;
    scanf("%d", &N);
    
    int num, sum=0;
    for (int i=0; i<N; i++) {
        scanf("%d", &num);
        if (primeCheck(num)) sum++;
    }
    
    printf("%d", sum);
    
    return 0;
}