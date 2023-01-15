#include <stdio.h>
#include <stdlib.h>

struct count {
    int white;
    int blue;
};

int isOneColor(int *paper, int N) {
    int first = paper[0];
    int returnValue = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (paper[i * N + j] == first) continue;
            else {
                returnValue = 0;
                break;
            }
        }
    }
    return returnValue;
}

struct count countPaper(int* paper, int N) {
    struct count result;
    result.blue = 0;
    result.white = 0;
    if (isOneColor(paper, N)) {
        (paper[0] == 1) ? (result.blue++) : (result.white++);
        return result;
    }
    else {
        int size = N / 2 * N / 2 * sizeof(int);
        int* small1 = malloc(size);
        int* small2 = malloc(size);
        int* small3 = malloc(size);
        int* small4 = malloc(size);
        
        for (int i = 0; i < N/2; i++) {
            for (int j = 0; j < N/2; j++) {
                small1[i * (N / 2) + j] = paper[i * N + j];
                small2[i * (N / 2) + j] = paper[i * N + j + N/2];
                small3[i * (N / 2) + j] = paper[i * N + j + N/2 * N];
                small4[i * (N / 2) + j] = paper[i * N + j + N/2 * N + N/2];
            }
        }

        struct count count1 = countPaper(small1, N / 2);
        struct count count2 = countPaper(small2, N / 2);
        struct count count3 = countPaper(small3, N / 2);
        struct count count4 = countPaper(small4, N / 2);

        result.white = count1.white + count2.white + count3.white + count4.white;
        result.blue = count1.blue + count2.blue + count3.blue + count4.blue;

        return result;
    }
}

int main() {

    int N;
    scanf("%d", &N);

    int paper[N * N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &paper[i*N + j]);
        }
    }

    struct count result = countPaper(paper, N);
    printf("%d\n%d", result.white, result.blue);

    return 0;
}