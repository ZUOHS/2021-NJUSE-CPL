#include <stdio.h>
#include <math.h>
int main () {
    int n = 0;
    int k = 0;
    scanf("%d", &n);
    scanf("%d", &k);
    int a[n + 1];
    for (int i = 0; i <= n; i++) {
        a[i] = 0;
    }
    int i = 1;
    for (int m = 1; m < n; m++) {
        int count = 0;
        int judge = 0;
        while (judge == 0) {
            if (a[i] == 0) {
                count++;
            }
            if (count == k) {
                a[i] = 1;
                judge = 1;
            }
            if (i == n) {
                i = 1;
            } else {
                i++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            printf("%d", i);
        }
    }
    return 0;
}