#include <stdio.h>
#include <string.h>

int main() {
    char prev;
    
    int N, count = 0, flag;
    scanf("%d", &N);
    char word[101];
    
    for (int i=0; i<N; i++) {
        scanf("%s", word);
        int existAlphabet[26] = {0,};
        flag = 1;
        
        existAlphabet[word[0]-'a'] = 1;
        prev = word[0];
        for (int j=1; j<strlen(word); j++) {
            if (word[j] != prev) {
                if (existAlphabet[word[j] - 'a']) {
                    flag = 0;
                    break;
                }
                else {
                    existAlphabet[word[j] - 'a'] = 1;
                    prev = word[j];
                }
            }
        }
        if (flag) count++;
    }
    
    printf("%d", count);
    
    return 0;
}