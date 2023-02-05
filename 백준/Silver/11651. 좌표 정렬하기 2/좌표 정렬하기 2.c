#include <stdio.h>
#include <stdlib.h>

int compare(const void* first, const void* second) {
    if (*(int*)first > *(int*)second) return 1;
    else if (*(int*)first == *(int*)second) {
        if (*((int*)first + 1) > *((int*)second + 1)) return 1;
        else return -1;
    }
    else return -1;
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N][2];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &arr[i][1], &arr[i][0]);
    }

    qsort(arr, N, sizeof(int) * 2, compare);

    for (int i = 0; i < N; i++) {
        printf("%d %d\n", arr[i][1], arr[i][0]);
    }

    return 0;
}