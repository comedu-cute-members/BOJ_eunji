#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int arr[N];
    int temp, max;
    for (int i=0; i<N; i++) {
        scanf("%d", &temp);
        if (i==0) {
            arr[i] = temp;
            max = temp;
        }
        else {
            if (arr[i-1] > 0) arr[i] = arr[i-1] + temp;
            else arr[i] = temp;
            
            if (arr[i] > max) max = arr[i];
        }
    }
    
    printf("%d", max);
    
    return 0;
}