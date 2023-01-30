#include <stdio.h>
#include <stdlib.h>

int* madeStar(int N, int isStar) {
    int* arr = (int*)malloc(sizeof(int) * N * N);
    
    if (N == 3) {
        if (isStar) {
        	arr[0] = arr[1] = arr[2] = arr[3] = arr[5] = arr[6] = arr[7] = arr[8] = 1;
        	arr[4] = 0;
        }
        else {
        	arr[0] = arr[1] = arr[2] = arr[3] = arr[4] = arr[5] = arr[6] = arr[7] = arr[8] = 0;
        }
        return arr;
    }
    
    for (int i = 0; i < 9; i++) {
        int* temp = madeStar(N / 3, isStar && (i != 4));
        for (int j = 0; j < N / 3; j++) {
            for (int k = 0; k < N / 3; k++) {
                arr[(i / 3) * (N / 3 * N) + (i % 3) * (N / 3) + j * N + k] = temp[j * (N / 3) + k];
            }
        }
    }
    return arr;
}

int main() {
    int N;
    scanf("%d", &N);

    int* star = madeStar(N, 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", star[i*N + j]? '*':' ');
        }
        if (i != N-1) printf("\n");
    }

    return 0;
}