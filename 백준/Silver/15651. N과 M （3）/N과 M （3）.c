#include <stdio.h>

void print(int* arr, int M) {
    for (int i=0; i<M; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int arr[M];
    for (int i=0; i<M; i++) arr[i] = 1;
    print(arr, M);
    
    int change;
    while(1) {
        change = M-1;
        while(change >= 0) {
            if (arr[change] + 1 > N) change--;
            else break;
        }
        
        if (change == -1) break;
        
        arr[change]++;
        for (int i=change+1; i<M; i++) {
            arr[i] = 1;
        }
        
        print(arr, M);
    }
    
    return 0;
}