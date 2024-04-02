#include <stdio.h>

int main () {
    int n = 0;
    scanf("%d", &n);
    char dk[n + 1];
    scanf("%s", dk);
    for (int i = 0; i < n; i++) {
        if (dk[i] == '?') {
            dk[i] = dk[n - 1 - i];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%c", dk[i]);
    }
    return 0;
}