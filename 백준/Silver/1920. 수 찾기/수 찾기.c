#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    if (*(int*)a > *(int*)b) return 1;
    else if (*(int*)a < *(int*)b) return -1;
    else return 0;
}

int main() {
    int N, M;

    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    qsort(A, N, sizeof(A[0]), compare);

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int target;
        scanf("%d", &target);

        int start = 0, end = N - 1, mid;
        while (1) {
            if (start > end || start == end && A[start] != target) {
                printf("0\n");
                break;
            }

            mid = (start + end) / 2;
            if (A[mid] == target) {
                printf("1\n");
                break;
            }
            else if (A[mid] > target) end = mid - 1;
            else start = mid + 1;
        }
    }

    return 0;
}