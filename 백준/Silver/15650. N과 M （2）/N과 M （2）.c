#include <stdio.h>

void printSet(int* set, int M) {
    printf("\n");
    for (int i = 0; i < M; i++) printf("%d ", set[i]);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int set[M];
    for (int i = 1; i <= M; i++) {
        set[i-1] = i;
        printf("%d ", i);
    }

    while (1) {
        int i = M - 1;
        while (i >= 0) {
            if (set[i] + 1 <= N - M + i + 1) {
                set[i] = set[i] + 1;
                for (int j = i + 1; j < M; j++) {
                    set[j] = set[i] + j - i;
                }
                break;
            }
            else {
                i--;
            }
        }
        if (i == -1) break;
        printSet(set, M);
    }

    return 0;
}