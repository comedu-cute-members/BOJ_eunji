#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int base[100][100] = {{0,},};
    int x, y;
    for (int i=0; i<N; i++) {
        scanf("%d %d", &x, &y);
        for (int j=0; j<10; j++) {
            for (int k=0; k<10; k++) {
                base[y+j][x+k] = 1;
            }
        }
    }
    
    int sum = 0;
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            if (base[i][j]) sum++;
        }
    }
    
    printf("%d", sum);
    
    return 0;
}