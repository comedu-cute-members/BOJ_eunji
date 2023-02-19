#include <stdio.h>

int isIn(char a, char b) {
    char chroatia[7][2] = {"c=", "c-", "d-", "lj", "nj", "s=", "z="};
    for (int i=0; i<7; i++) {
        if (a == chroatia[i][0] && b == chroatia[i][1]) return 1;
    }
    return 0;
}

int main() {
    char str[101];
    scanf("%s", str);
    
    int i=0;
    int count = 0;
    while (str[i] != '\0') {
        if (isIn(str[i], str[i+1])) i += 2;
        else if (str[i] == 'd' && str[i+1] == 'z' && str[i+2] == '=') i += 3;
        else i += 1;
        
        count++;
    }
    
    printf("%d", count);
    
    return 0;
}