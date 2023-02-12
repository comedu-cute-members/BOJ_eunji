#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a > *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);
    
    int arr[N];
    for (int i=0; i<N; i++) scanf("%d", &arr[i]);
    
    int x;
    scanf("%d", &x);
    
    qsort(arr, N, sizeof(arr[0]), compare);
    
    int p1=0, p2=N-1;
    int count = 0;
    while(p1 != p2) {
        if (arr[p1] + arr[p2] == x) {
            count++;
            p1++;
        }
        else if (arr[p1] + arr[p2] > x) p2--;
        else p1++;
    }
    
    printf("%d", count);
    
    return 0;
}