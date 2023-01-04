#include <stdio.h>

int dupCheck(int* seq, int length) {
    for(int i=0; i<length; i++) {
        for (int j=0; j<i; j++) {
            if (seq[i] == seq[j]) {
                return 1;
            }
        }
    }
    return 0;
}

void next(int* seq, int length, int max) {
    int changePosition = length - 1;
    for(int i=0; i<length; i++) {
        if (changePosition == 0 && seq[changePosition] == max) {
            seq[changePosition]++;
            break;
        }
        if (seq[changePosition] < max) {
            seq[changePosition]++;
            break;
        }
        else {
            for (int j=changePosition; j<length; j++) {
                seq[j] = 1 + j-changePosition;
            }
            changePosition--;
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int seq[M];
    for (int i=0; i<M; i++) {
        seq[i] = 1;
    }
    
    while(seq[0] <= N) {
        if (!dupCheck(seq, M)) {
            for (int i=0; i<M; i++) {
                printf("%d ", seq[i]);
            }
            printf("\n");
        }
        next(seq, M, N);
    }
}