#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        int N, M;
        scanf("%d %d", &N, &M);

        double count = 1.0;
        for (int j = 0; j < N; j++) {
            count *= M - j;
            count /= j + 1;
        }

        printf("%1.lf\n", count);
    }

    return 0;
}