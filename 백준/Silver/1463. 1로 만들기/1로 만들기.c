#include <stdio.h>

int min(int a, int b, int c) {
    int result = a;
    if (result > b) result = b;
    if (result > c) result = c;
    return result;
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    arr[0] = 0;
    arr[1] = arr[2] = 1;

    int three, two, one;
    for (int i = 4; i <= N; i++) {
        three = two = i-1;
        if (i % 3 == 0) three = arr[i / 3 - 1] + 1;
        if (i % 2 == 0) two = arr[i / 2 - 1] + 1;
        one = arr[i - 2] + 1;

        arr[i-1] = min(three, two, one);
    }

    printf("%d", arr[N - 1]);

    return 0;
}