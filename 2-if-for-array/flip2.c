#include <stdio.h>

int main () {
    int i = 0;
    int j = 0;
    int n = 0;
    scanf("%d", &n);
    int a[n];

    for (i = 1; i <= n; i++) {
        a[i] = 0;
        for (j = 1; j <= i; j++) {
            if (i % j == 0) {
                a[i] = !a[i];
            }
        } if (a[i] == 1) {
            printf("%d ", i);
        }
    }
}