#include <stdio.h>
#include <string.h>

int main() {
    char string[1000001];
    scanf("%[^\n]s", string);
    
    int i=0;
    if(string[i] == ' ') i++;
    
    int count = 0;
    char prev = ' ';
    for (;i<strlen(string);i++) {
        if (prev == ' ') count++;
        prev = string[i];
    }
    
    printf("%d", count);
}