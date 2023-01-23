#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int card[N];
    for (int i = 0; i < N; i++) scanf("%d", &card[i]);

    int sum[N * (N - 1) * (N - 2) / 6];
    int index = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                sum[index] = card[i] + card[j] + card[k];
                index++;
            }
        }
    }

    int maxIndex = 0;
    while (sum[maxIndex] > M) {
        maxIndex++;
    }

    int max = sum[maxIndex];
    for (int i = maxIndex; i < N * (N - 1) * (N - 2) / 6; i++) {
        if (sum[i] <= M && sum[i] > max) max = sum[i];
    }

    printf("%d", max);

    return 0;
}