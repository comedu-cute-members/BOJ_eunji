#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int RGB[3];
    int cost[3] = {0, 0, 0};
    for (int i=0; i<N; i++) {
        scanf("%d %d %d", &RGB[0], &RGB[1], &RGB[2]);
        for (int j=0; j<3; j++) {
            int a = RGB[j] + cost[(j+1)%3];
            int b = RGB[j] + cost[(j+2)%3];
            if (a <= b) RGB[j] = a;
            else RGB[j] = b;
        }
        cost[0] = RGB[0];
        cost[1] = RGB[1];
        cost[2] = RGB[2];
    }
    
    int min = cost[0];
    if (min > cost[1]) min = cost[1];
    if (min > cost[2]) min = cost[2];
    
    printf("%d", min);
    
    return 0;
}