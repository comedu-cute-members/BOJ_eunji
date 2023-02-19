#include <stdio.h>
#include <stdlib.h>

int** divide(int** arr, int N, int i) {
    int** result;
    result = malloc(sizeof(int*) * (N / 2));
    for (int j = 0; j < N / 2; j++) {
        result[j] = malloc(sizeof(int) * N / 2);
    }
    for (int j = 0; j < N / 2; j++) {
        for (int k = 0; k < N / 2; k++) {
            result[j][k] = arr[(i / 2) * (N / 2) + j][(i % 2) * (N / 2) + k];
        }
    }
    return result;
}

void zip(int** arr, int N) {
    int start = arr[0][0];

    int flag = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] != start) {
                flag = 0;
                break;
            }
        }
    }

    if (flag) printf("%d", start);
    else {
        int** sub1 = divide(arr, N, 0);
        int** sub2 = divide(arr, N, 1);
        int** sub3 = divide(arr, N, 2);
        int** sub4 = divide(arr, N, 3);

        printf("(");
        zip(sub1, N / 2);
        zip(sub2, N / 2);
        zip(sub3, N / 2);
        zip(sub4, N / 2);
        printf(")");
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int** arr = malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++) arr[i] = malloc(sizeof(int) * N);
    char str[N+1];

    for (int i = 0; i < N; i++) {
        scanf("%s", str);
        for (int j = 0; j < N; j++) {
            arr[i][j] = (str[j] == '1') ? 1 : 0;
        }
    }

    zip(arr, N);

    return 0;
}