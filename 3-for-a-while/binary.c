#include <stdio.h>
#include <math.h>
int main () {
    int len = 0;
    scanf("%d", &len);
    char s[len + 1];
    scanf("%s", s);
    int sum = 0;
    for (int i = 0; i < len; i++) {
        int count = 0;
        if (s[i] == '1') {
            count = (int)pow(2, len - i - 1);
        }
        sum = sum + count;
    }
    printf("%d", sum);

    return 0;
}