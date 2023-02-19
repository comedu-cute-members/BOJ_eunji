#include <stdio.h>
#include <string.h>

int main() {
    char str[16];
    scanf("%s", str);
    
    int sum = 0;
    for (int i=0; i<strlen(str); i++) {
        if (str[i] >= 65 && str[i] <= 67) sum += 3;
        if (str[i] >= 68 && str[i] <= 70) sum += 4;
        if (str[i] >= 71 && str[i] <= 73) sum += 5;
        if (str[i] >= 74 && str[i] <= 76) sum += 6;
        if (str[i] >= 77 && str[i] <= 79) sum += 7;
        if (str[i] >= 80 && str[i] <= 83) sum += 8;
        if (str[i] >= 84 && str[i] <= 86) sum += 9;
        if (str[i] >= 87) sum += 10;
    }
    
    printf("%d", sum);
    
    return 0;
}