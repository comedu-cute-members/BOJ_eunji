#include <stdio.h>
#include <math.h>

int main() {
    int num;
    scanf("%d", &num);

    int number = 666;
    int a, b, c;
    while (num > 0) {
        int digit = 1;
        for (int i = 1;; i++) {
            if (number / (int)pow(10, i) == 0) break;
            else digit++;
        }
        for (int i = 0; i < digit - 2; i++) {
            int tens = pow(10, i);
            a = (number / tens) % 10;
            b = (number / (tens*10)) % 10;
            c = (number / (tens*100)) % 10;
            if (a == 6 && b == 6 && c == 6) {
                num--;
                break;
            }
        }
        number++;
    }

    printf("%d", number - 1);
    return 0;
}