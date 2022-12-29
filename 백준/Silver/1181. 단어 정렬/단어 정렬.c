#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int lenA = strlen((char*)a);
    int lenB = strlen((char*)b);
    if (lenA > lenB) {
        return 1;
    }
    else if (lenA == lenB) {
        return strcmp((char*)a, (char*)b);
    }
    else return -1;
}

int main() {
    int num;
    scanf("%d", &num);

    char words[num][51];
    for (int i = 0; i < num; i++) {
        scanf("%s", words[i]);
    }

    qsort(words, num, 51, compare);

    int prevIndex;
    for (int i = 0; i < num; i++) {
        if (i == 0) {
            printf("%s\n", words[i]);
            prevIndex = 0;
        }
        else if (strcmp(words[i], words[prevIndex])) {
            printf("%s\n", words[i]);
            prevIndex = i;
        }
    }

    return 0;
}